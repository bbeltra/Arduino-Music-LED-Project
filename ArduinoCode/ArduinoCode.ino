void setup() {
  pinMode(9, OUTPUT);  // Red LED (Fast Tempo)
  pinMode(10, OUTPUT); // Green LED (Slow Tempo)
  pinMode(11, OUTPUT); // Yellow LED (Fast Tempo)
  pinMode(12, OUTPUT); // Blue LED (Slow Tempo)
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  if (Serial.available() > 0) {  // Check if data is coming from Python
    char command = Serial.read();  // Read command ('F' or 'S')

    if (command == 'F') {  // Fast Tempo (Red & Yellow)
      digitalWrite(9, HIGH);  // Turn ON Red
      digitalWrite(11, HIGH); // Turn ON Yellow
      digitalWrite(10, LOW);  // Turn OFF Green
      digitalWrite(12, LOW);  // Turn OFF Blue
      Serial.println("Fast Tempo: Red & Yellow ON");
    }
    else if (command == 'S') {  // Slow Tempo (Blue & Green)
      digitalWrite(9, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, HIGH);  // Turn ON Green
      digitalWrite(12, HIGH);  // Turn ON Blue
      Serial.println("Slow Tempo: Blue & Green ON");
    }
    else {  // If anything else is received, turn off all LEDs
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      Serial.println("All LEDs OFF");
    }
  }
}

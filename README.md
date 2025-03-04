# Arduino-Music-LED-Project
This project uses an Arduino Mega 2560 and relevant hardware, as well as Python to control LED's on a breadboard based on a song's tempo
The LED's light up at different speeds and colors depending on the song
# Hardware Required
Arduino Mega 2560
Breadboard
4 LED's: Red, Yellow, Blue, Green
4 Resistors
Jumper Wires
USB Cable and Adapter (if necessary)
# Wiring
Insert long leg of each LED into column e, and the short leg into column d. Do this in the following rows:
Red: Row 5
Green: Row 10
Yellow: Row 15
Blue: Row 20
# Resistors
Connect one end of the resistor into column C, right by the short leg of the LED. Connect the other end into the blue ground rail.
# Connect Arduino Pins
Red: Pin 9
Green: Pin 10
Yellow: Pin 11
Blue: Pin 12
# Ground Wire
Connect one jumper wirte from the blue ground rail on the breadboard to any Arduino GND pin
# Software Setup
On python, go to terminal and pip install pyserial librosa numpy soundfile
Assure you are using an MP3 file for best compatibilty
On Arduino IDE, go to Tools. Verify that Board is "Arduino Mega 2560"
Select the correct port in Tools, and ensure that this port is on the Python code.
Upload code on Arduino IDE
Now, run the Python script. On terminal, navigate to the project FOLDER. Not the project itself. enter: cd "/Users/YourUsername/Documents/project/etc"
On terminal, run the script. Enter python3 project.py
The LED's will light up based on their tempo
On Arduino IDE, go to Tools, Serial Monitor. If working, you should see a message such as "Slow Tempo: Blue & Green ON". 

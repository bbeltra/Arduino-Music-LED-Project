import librosa
import serial
import time

# Set up serial communication with Arduino
ser = serial.Serial('/dev/cu.usbmodem101', 9600)  
time.sleep(2)  # Wait for Arduino to initialize

def analyze_tempo(audio_path):
    y, sr = librosa.load(audio_path, sr=None)
    onset_env = librosa.onset.onset_strength(y=y, sr=sr)
    tempo, _ = librosa.beat.beat_track(onset_envelope=onset_env, sr=sr)
    print(f"Detected Tempo: {tempo} BPM")
    return tempo

def control_leds(tempo):
    if tempo > 120:
        ser.write(b'F')  # Fast Tempo
        print("Sending: Fast Tempo (Red & Yellow)")
    else:
        ser.write(b'S')  # Slow Tempo
        print("Sending: Slow Tempo (Blue & Green)")

def main():
    audio_path = '/Users/bridgetteb/Music/Music/Media.localized/Music/Unknown Artist/Unknown Album/01 Confesárselo.mp3'  # Change this to your actual file
    tempo = analyze_tempo(audio_path)
    control_leds(tempo)

if __name__ == "__main__":
    main()

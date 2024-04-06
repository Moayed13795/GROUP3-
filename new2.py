import serial
import time

# Define the serial port and baud rate
serial_port = 'COM5'  # Change this to your Arduino's serial port
baud_rate = 9600

# Initialize the serial connection
ser = serial.Serial(serial_port, baud_rate, timeout=1)

def detect_gesture(acceleration_x, gyro_x, gesture_threshold):
    # Define conditions to recognize specific gestures
    # For simplicity, assuming turning right increases X-axis value and turning left decreases X-axis value
    if gyro_x > gesture_threshold:
        return "Gesture 1"
    elif gyro_x < -gesture_threshold:
        return "Gesture 2"
    # Add more gesture conditions as needed
    return "No Gesture Detected"

try:
    while True:
        # Read data from Arduino
        data = ser.readline().decode().strip()
        print("data:", data)  # Print received data for debugging
        # Split the data into accelerometer and gyroscope readings
        sensor_values = data.split(',')
        if len(sensor_values) == 6:
            acceleration_x, acceleration_y, acceleration_z, gyro_x, gyro_y, gyro_z = map(int, sensor_values)

            # Set threshold and detect gesture
            gesture_threshold = 1000
            gesture = detect_gesture(acceleration_x, gyro_x, gesture_threshold)

            # Print detected gesture
            print("Detected Gesture:", gesture)
        
        # Add a small delay
        time.sleep(0.1)

except KeyboardInterrupt:
    # Close the serial connection on Ctrl+C
    ser.close()

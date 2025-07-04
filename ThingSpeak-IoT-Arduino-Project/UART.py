import serial
import datetime

# configure the serial port
ser = serial.Serial('COM1', 9600, timeout=1)

# pack the data
data = [0x01, 0x02, 0x03]
packed_data = bytes(data)

# send the data
ser.write(packed_data)

# receive the data
received_data = ser.read(3)

# unpack the data
unpacked_data = list(received_data)

print(unpacked_data)

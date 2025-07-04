import serial # using serial library
import datetime # using date time library

ser = serial.Serial('/dev/tty.usbmodem14201',9600) # open serial port, change to yours!
ser.flushInput()

while True:
    try:
        ser_bytes = ser.readline() # read one line from serial port
# and grab the data

        decoded_bytes = ser_bytes[0:len(ser_bytes)-2].decode("utf-8")

        now = datetime.datetime.now() # create timestamp

        now = now.strftime("%Y-%m-%d %H:%M:%S") # put on readable format

        data = ( "
                 ’{}’,{}\r\n".format(now,decoded_bytes) ) # prepare data to write

        print(data) # display it on screen

        f = open("serialdata.csv","a") # open a CSV file to write

        f.write(data) # write the data to file

        f.close() # close the CSV file

    except:

        print("Keyboard Interrupt") # stop when CTRL-C is detected

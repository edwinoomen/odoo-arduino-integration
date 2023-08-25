import time
import serial
import serial.tools.list_ports

ARDUINO_UNO='Arduino Uno'

for comport in serial.tools.list_ports.comports():
    if comport.usb_description() == ARDUINO_UNO:
        device = comport
        print(f"Found {ARDUINO_UNO} on com port {device}")
        arduino = serial.Serial(port=comport.device, baudrate=115200)
        time.sleep(5);
        print("sending message")
        arduino.write(bytes('ODOO\n', 'utf-8'))
        
        while True:
            data = arduino.readline();
            print(f"Received: {data.decode()}");

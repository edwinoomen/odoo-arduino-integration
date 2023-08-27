import argparse
import serial
import serial.tools.list_ports

import time
from xmlrpc import client

# Board parameters 
BOARD_NAME='Arduino Uno'    
BOARD_CONNECT_TIMEOUT=2
BOARD_INIT_MESSAGE='ODOO\n'
            
class OdooArduinoDemo:
    def __init__(self, url, db, user, password):
        self.url = url
        self.db = db
        self.user = user
        self.password = password
        self.uid = None
        self.board = None
        print(f'Demo settings: url: {url}, db:{db}, user:{user}, password:{password}')
        
    def connect_to_board(self):
        for comport in serial.tools.list_ports.comports():
            if comport.usb_description() == BOARD_NAME:
                device = comport
                print(f'Found {BOARD_NAME} on com port {device}')
                self.board = serial.Serial(port=comport.device, baudrate=115200)
                print(f'Connecting with {BOARD_NAME}...')
                time.sleep(BOARD_CONNECT_TIMEOUT);
                self.board.write(bytes(BOARD_INIT_MESSAGE, 'utf-8'))
                print(f'Connected to {BOARD_NAME}')
                

    def handle_board_events(self):
        try:
            while True:
                data = self.board.readline();
                print(f"Received: {data.decode().strip()}");
        except:
            print(f'Connection with board terminated, exiting')
            exit(0)    

    def print_version(self):
        common = client.ServerProxy(f'{self.url}/xmlrpc/2/common')
        print(f'Connecting to odoo version: {common.version()} at {self.url}')

    def authenticate(self):
        common_api = client.ServerProxy(f'{self.url}/xmlrpc/2/common')
        self.uid = common_api.authenticate(self.db, self.user, self.password, {})
        print(f'Authenticated odoo user id of user {self.user}: {self.uid}')

    def check_access_rights(self, model, operation):
        object_api = client.ServerProxy(f'{self.url}/xmlrpc/2/object')

        model_access = object_api.execute_kw(self.db, self.uid, self.password, model, 'check_access_rights', [operation],
                                         {'raise_exception': False})

        print(f'User {self.uid} permission for {operation} on model {model}: {model_access}')


if __name__ == '__main__':
    # Example of invocation:
    # python3 external_api_demo.py -u 'https://edwin-oomen-alpiek-odoo-technical-training-developme-9361121.dev.odoo.com' -d 'edwin-oomen-alpiek-odoo-technical-training-developme-9361121'

    argParser = argparse.ArgumentParser()
    argParser.add_argument("-u", "--url", help="url of odoo instance")
    argParser.add_argument("-d", "--db", help="database name")

    # For defaults to work, add the user + password to the database first.
    argParser.add_argument("-n", "--user", help="user name", default="external-api-user")
    argParser.add_argument("-p", "--password", help="user password or token", default="api!")

    args = argParser.parse_args()
    demo = OdooArduinoDemo(args.url, args.db, args.user, args.password)
    
    # Setup connection with provided Odoo database
    #demo.print_version()
    #demo.authenticate()
    #demo.check_access_rights('res.partner', 'read')
    #demo.check_access_rights('res.partner', 'write')
    
    # Create connection with board
    demo.connect_to_board()
    
    # Start listening to board events
    demo.handle_board_events()


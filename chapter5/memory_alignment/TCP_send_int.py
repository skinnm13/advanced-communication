#!/usr/bin/env python3

########################################################################

import socket
import argparse
import sys
import struct

########################################################################
# Echo-Client class
########################################################################

class Client:

    SERVER = "localhost"
    PORT = int(input("Enter the server's port number: "))
    
    RECV_SIZE = 256

    # SEND THE FOLLOWING 3 INTEGERS TO THE SERVER:
    #
    # si = 1 (a short int, 16-bits)
    # i  = 2 (an int, 32-bits)
    # li = 3 (a long int, 64-bits)

    ####################################################################
    # Assume that we know that the receiving host is little-endian.
    # Manually encode the ints into Python bytes objects for
    # transmission in little-endian byte order. This is a non-portable
    # solution!

    """

    si_le = b'\x01\x00'                         # short int 1.
    i_le  = b'\x02\x00\x00\x00'                 # int 2.
    li_le = b'\x03\x00\x00\x00\x00\x00\x00\x00' # long int 3.

    bytes_to_send = si_le + i_le + li_le

    """

    ####################################################################
    # An alternate way to encode the data using Python methods. Then,
    # send while server listens for struct. This also requires
    # knowledge of the receiver's endianness and is therefore not
    # portable.

    # """

    si_le = (1).to_bytes(2, byteorder='little')
    i_le  = (2).to_bytes(4, byteorder='little')
    li_le = (3).to_bytes(8, byteorder='little')

    bytes_to_send = si_le + i_le + li_le

    # """

    ####################################################################    

    def __init__(self):
        self.get_socket()
        self.connect_to_server()
        self.connection_send()

    def get_socket(self):
        try:
            self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        except Exception as msg:
            print(msg)
            sys.exit(1)

    def connect_to_server(self):
        try:
            self.socket.connect((Client.SERVER, Client.PORT))
        except Exception as msg:
            print(msg)
            sys.exit(1)

    def connection_send(self):
        try:
            self.socket.sendall(Client.bytes_to_send)
        except Exception as msg:
            print(msg)
            sys.exit(1)

########################################################################
# Process command line arguments if run directly.
########################################################################

if __name__ == '__main__':
    Client()
    
########################################################################







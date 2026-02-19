#!/usr/bin/env python3

########################################################################

import socket

########################################################################

# Show how socket.htonl works.

# ip_address = "130.113.10.149"
ip_address = "1.2.3.4"

# inet_pton converts an IP address string in dotted quad
# (presentation) format, to a bytes object in network byte
# (big-endian) order.
ip_address_bytes_network = socket.inet_pton(socket.AF_INET, ip_address)
print(ip_address_bytes_network)

# Convert the IP address bytes object back into an int, in
# big-endian byte order.
ip_address_int = int.from_bytes(ip_address_bytes_network, byteorder='big')
print(ip_address_int)

# Print it out the way the little-endian machine stores it.
print(int.to_bytes(ip_address_int, length=4, byteorder='little'))
print(int.from_bytes(int.to_bytes(ip_address_int, length=4, byteorder='little'), byteorder='big'))

# Switch these two lines to see the affect of socket.htonl.
# h = ip_address_int
h = socket.htonl(ip_address_int)
print(h)

# Note: can also use byteorder=sys.byteorder.
i = int.to_bytes(h, length=4, byteorder='big')
print(i)
print(int.from_bytes(i, byteorder='little'))

print(int.to_bytes(h, length=4, byteorder='little'))
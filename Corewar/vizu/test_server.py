# !/usr/bin/python3

import websocket
import socket
import thread
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Bind the socket to the port
server_address = ("127.0.0.1", 8888)
#sys.stderr.write('starting up on %s port %s' % server_address)
print('starting up on %s port %s' % server_address)
sock.bind(server_address)
# Listen for incoming connections
sock.listen(1)
#while was before sock.accept() !!
new_socket, client_address = sock.accept()
while 1:
    # Wait for a connection
    # print >>sys.stderr, 'waiting for a connection'
    # try:
        # print >>sys.stderr, 'connection from', client_address
        # Receive the payload in small chunks and retransmit it
        # while True:
    payload = new_socket.recv(1024)
    if payload:
    	print('Rec: "%s"' % payload.decode())
    else
    	print('End of payload.')
		exit()
            # if payload:
                # print >>sys.stderr, 'sending payload back to the client'
                # connection.sendall(payload)
            # else:
                # print >>sys.stderr, 'no more payload from', client_address
                # break
            
    # finally:
        # Clean up the connection
        # connection.close()
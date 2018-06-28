# !/usr/bin/python3

# import websocket
# import thread
import socket
import sys

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Bind the socket to the port
server_address = ("127.0.0.1", 8888)
#sys.stderr.write('starting up on %s port %s' % server_address)
print("starting up on %s port %d" % server_address)
sock.bind(server_address)
# Listen for incoming connections
sock.listen(1)

buf = []
payload = None

while 1:
	new_socket, client_address = sock.accept()
	i = 0
	j = 0
	while j < 50:
		if i == 0: # pipe waiting for players
			while not payload or "]" not in payload:
				payload = new_socket.recv(2).decode()
				buf.append(payload)
				print("%s" % payload, end='')
			j += 1
		elif i == 1: # pipe waiting for hex dump
			payload = new_socket.recv(12288).decode()
			i = 2
			# print("%s" % payload, end='')
		elif i == 2: # pipe waiting for player map
			payload = new_socket.recv(8193).decode()
			i = 1
			# print("%s" % payload, end='')
		if payload:
			# print("%c" % payload.decode(), end='') # 
			pass
		else:
			print("End of payload.\nDo we wait for the next game? [y/n]")
			c = sys.stdin.read(1)
			if (c == 'y' or c == 'Y'):
				break
			else:
				sock.close()
				sys.exit(0)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    websocket_pipe.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/28 22:07:30 by pde-rent          #+#    #+#              #
#    Updated: 2018/06/28 22:07:34 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import logging
import os
from websocket_server import WebsocketServer

uri = os.getenv("WS_HOST", "127.0.0.1")
port = os.getenv("WS_PORT", "8082")
address = "ws://" + uri + ":" + port

# Called for every client connecting (after handshake)
def new_client(client, server):
	print("New connection: Client #%d" % client['id'])
	#server.send_message_to_all("New client")

# Called for every client disconnecting
def client_left(client, server):
	print("Client #%d disconnected" % client['id'])

# Called when a client sends a message
def message_received(client, server, message):
	server.send_message_to_all(message)
	# print(message)

server = WebsocketServer(int(port), host=uri, loglevel=0)
print("URI ws://%s:%s is now open for web communication" % (uri, port))
server.set_fn_new_client(new_client)
server.set_fn_client_left(client_left)
server.set_fn_message_received(message_received)
server.run_forever()

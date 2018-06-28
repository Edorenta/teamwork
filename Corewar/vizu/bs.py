# !/usr/bin/python3

from websocket import create_connection
import os
import sys
import time

uri = os.getenv("WS_HOST", "127.0.0.1")
port = os.getenv("WS_PORT", "8082")
address = "ws://" + uri + ":" + port

ws = create_connection(address)

while 1:
	ws.send("Hi!")
	time.sleep(1)

# ws.close()
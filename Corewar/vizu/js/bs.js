var uri = "127.0.0.1";
var port = "8082";
var address = "ws://" + uri + ":" + port;
var ws = new WebSocket(address);

var mem_div = document.getElementById("mem");
var cmd_div = document.getElementById("cmd");

if (window.WebSocket === undefined)
{
	// state.innerHTML = "sockets not supported";
	// state.className = "fail";
	console.log("Error: sockets not supported");
}
else
{
	window.addEventListener("load", on_load, false);
}

function on_load()
{
	console.log('Pipe loaded');
	//socket = new WebSocket(socket_url);
	//callbacks
	addEventListener('open',function(event) { on_open(event) });
	addEventListener('close', function(event) { on_close(event) });
	addEventListener('message', function(event) { on_message(event) });
	addEventListener('error', function(event) { on_error(event) });
}
function on_open(event)
{
	// state.className = "success";
	// state.innerHTML = "Connected to server";
	console.log("Server connection established");
}
  
function on_close(event)
{
	// state.className = "fail";
	// state.innerHTML = "Not connected";
	// connected.innerHTML = "0";
	console.log("Server connection terminated");
}
 
function on_message(event)
{
	//receiving either memo hex dump or player command
	var msg = event.data;
	console.log(msg);
	/*
	if (msg.startsWith("dump\n")) //receiving memory dump
	{
		msg = msg.slice("dump\n".length);
		mem_div.innerHTML = msg;	
	}
	else //receiving command
	{
		console.log(msg);
		cmd.innerHTML = msg;	
	}
	*/
}
 
function on_error(event)
{ 
	// state.className = "fail";
	// state.innerHTML = "Communication error";
	console.log("Error: server communication failed");
}

function send_msg(msg)
{
	ws.send(msg);
}
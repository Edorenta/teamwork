var socket_url = "ws://localhost:8080"; 
var socket = new WebSocket(socket_url);
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
	//socket = new WebSocket(socket_url);
	//callbacks
	addEventListener('open',function(event) { on_open(event) });
	addEventListener('close', function(event) { on_close(event) });
	addEventListener('message', function(event) { get_msg(event) });
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
 
function get_msg(event)
{
	//receiving either memo hex dump or player command
	var msg = event.data;
	if (msg.startsWith("dump\n")) //receiving memory dump
	{
		msg = msg.slice("dump\n".length);
		mem_div.innerHTML = msg;	
	}
	else //receiving command
	{
		cmd.innerHTML = msg;	
	}
}
 
function on_error(event)
{ 
	// state.className = "fail";
	// state.innerHTML = "Communication error";
	console.log("Error: server communication failed");
}

function send_msg(msg)
{
	socket.send(msg);
}
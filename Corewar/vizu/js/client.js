var uri = "127.0.0.1";
var port = "8082";
var address = "ws://" + uri + ":" + port;
var ws;

function init()
{
	ws = new WebSocket(address);
	if (window.WebSocket === undefined)
		console.log("Error: WebSockets not supported");
	//callbacks:
	ws.onopen = function(event){
		console.log("Access to WebSocket " + address + " granted");
	};

	ws.onmessage = function(event){
		console.log("Received:\n" + event.data);
	};

	ws.onclose = function(){
		console.log("WebSocket " + address + " closed");
	};
	ws.onerror = function(event){
		console.log("Communication error with " + address);
		console.log(event);
	};
}

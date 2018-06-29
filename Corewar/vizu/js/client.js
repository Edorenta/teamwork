var uri = "127.0.0.1";
var port = "8082";
var address = "ws://" + uri + ":" + port;
var ws;

var in_set;
var in_hex;
var in_map;

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
		let data = event.data;
		let type = data.slice(0, 5);
		console.log("Rec:" + type);
		// console.log("Rec:" + type);
		switch (type){
			case "<set>": in_set = data.slice(5, data.length); break;
			case "<hex>": in_hex = data.slice(5, data.length); break;
			case "<map>": in_map = data.slice(5, data.length); break;
		}

	};

	ws.onclose = function(){
		console.log("WebSocket " + address + " closed");
	};
	ws.onerror = function(event){
		console.log("Communication error with " + address);
		console.log(event);
	};
}

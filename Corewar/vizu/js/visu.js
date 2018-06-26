"use strict";

//keyboard mapping
var
_up = false,
_down = false,
_left = false,
_right = false,
_1 = false,
_2 = false,
_3 = false,
_4 = false,
_5 = false,
_6 = false,
_7 = false,
_8 = false,
_9 = false,
_r = false,
_plus = false,
_minus = false;

//viewport size tracker
var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};
//interface colors tracker
var clrs = {
    a_in : "rgb(45,45,45)",
    b_in : "rgb(45,45,45)",
    a_out : "rgb(211,140,0)",
    b_out : "rgb(0,180,0)",
    back : "rgb(0,0,0)",
    txt : "rgb(0,255,255)",
    txt_back : "rgb(45,45,45)"
};

//global variables
var title;
var memory_dump;
var lines = [];
var data = [];
var canvas;
var nb_lines;
var mem_div;
var cmd_div;
var back_img;

//min max of array as .this function
Array.prototype.max = function(){
    return Math.max.apply(null, this);
};

Array.prototype.min = function(){
    return Math.min.apply(null, this);
};

//canvas resize on viewport change
function canvas_resize(){
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}

class Player{
    constructor(name, msg){
        this.name = name;
        this.msg = msg;
        console.log("New player:", this.name);
    }
    set_name(name){
        this.name = name;
    }
    get_name(){
        return this.name;
    }
};

function get_mem(){
    //...
}

function draw_rooms(){
    //...
}

//initialization function
function setup(){
    //noLoop();
    mem_div = document.getElementById("mem");
    //mem = JSON.parse(mem_div.innerHTML).mem;
    //nb_lines = mem.length;
    //console.log(mem_div.innerHTML);
    frameRate(30);
    canvas = createCanvas(win.w, win.h); //WEBGL);
    title = document.getElementById('title');
    back_img = loadImage("../assets/corewar_background.png");
    textFont('Courier New');
    textSize(12);
    rectMode(CENTER);
}

function keyPressed(){
    switch (keyCode){
		//multi
        case 37: _left = _left ? false : true; _right = false; break;
        case 38: _up = _up ? false : true; _down = false; break;
        case 39: _right = _right ? false : true; _left = false; break;
        case 40: _down = _down ? false : true; _up = false; break;
	    case 82: _r = true; break;
        case 107: _plus = _plus ? false : true; _minus = false; break;
        case 109: _minus = _minus ? false : true; _plus = false; break;
		//windows
        case 97: _1 = _1 ? false : true; _3 = false; break;
        case 98: _2 = _2 ? false : true; _8 = false; break;
        case 99: _3 = _3 ? false : true; _1 = false; break;
        case 100: _4 = _4 ? false : true; _6 = false; break;
        case 101: _5 = _5 ? false : true; break;
        case 102: _6 = _6 ? false : true; _4 = false; break;
        case 103: _7 = _7 ? false : true; break;
        case 104: _8 = _8 ? false : true; _2 = false; break;
        case 105: _9 = _9 ? false : true; break;
	    //mac
        case 49: _1 = _1 ? false : true; _3 = false; break;
        case 50: _2 = _2 ? false : true; _8 = false; break;
        case 51: _3 = _3 ? false : true; _1 = false; break;
        case 52: _4 = _4 ? false : true; _6 = false; break;
        case 53: _5 = _5 ? false : true; break;
        case 54: _6 = _6 ? false : true; _4 = false; break;
        case 55: _7 = _7 ? false : true; break;
        case 56: _8 = _8 ? false : true; _2 = false; break;
        case 57: _9 = _9 ? false : true; break;
   	}
}

function mouseWheel(event){
    //...
    return false;
}

var str;
var fontsize;
//p5js loop function at every FPS (OPS)
function draw(){
    canvas_resize();
    background(back_img);
    textSize(win.w / 175); //textSize(Math.min(win.h, win.w) / 90);
    str = mem_div.innerHTML;
    fill(255);
    text(str, win.w / 3.48, win.h / 30); //win.w * 18 / 20, win.h * 18 / 20);
    //...
}

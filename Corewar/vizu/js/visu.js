"use strict";

//interface colors tracker
var clrs = {
    blue : "rgb(0,110,255)",   //blue
    green : "rgb(15,185,0)",   //green
    red : "rgb(230,0,0)",      //red
    purple : "rgb(230,0,230)", //purple
    yellow : "rgb(250,250,0)", //yellow
    grey : "rgb(80,80,80)"  //grey
};

var text_mode = true;
var block_mode = true;
var text_mode_bold = false;
var arena_block_shape = ['round', 1];
var arena_block_clr = clrs.grey;

//keyboard mapping
/*
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
*/
//viewport size tracker
var win = {
    w : Math.max(document.documentElement.clientWidth, window.innerWidth || 0),
    h : Math.max(document.documentElement.clientHeight, window.innerHeight || 0),
};

//global variables
var title;
var canvas;
var mem_div;
var cmd_div;
var back_img;
var joystix_font;
var str;
var trim;
var fontsize;
var block = [];
var start_x = 557;
var start_y = 40;
var itx = 0;
var ity = 0;
var space_x = 20.7;
var space_y = 14.4;

//min max of array as .this function
Array.prototype.max = function(){
    return Math.max.apply(null, this);
};

Array.prototype.min = function(){
    return Math.min.apply(null, this);
};

String.prototype.rpl = function(from, to) {
    let target = this;
    return target.replace(new RegExp(from, 'g'), to);
};

//canvas resize on viewport change
function canvas_resize(){
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}

function get_mem(){
    //...
}

function draw_rooms(){
    //...
}
/*
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
*/
function mouseWheel(event){
    //...
    return false;
}

class Block{
    constructor(x, y, player){
        this.x = x;
        this.y = y;
        this.shape = player ? player.shape : arena_block_shape;
        this.clr = player ? player.clr : arena_block_clr;
        this.player = player ? player : null;
        //console.log(this.clr);
    }
    set_shape(shape){
        this.shape = shape;
    }
    set_clr(clr){
        this.clr = clr;
    }
    draw(){
        fill(this.clr);
        switch (this.shape[0]){
            case 'square' :
                rect(this.x, this.y, space_x-this.shape[1], space_y-this.shape[1]);
                break;
            case 'round' :
                ellipse(this.x, this.y, space_x-this.shape[1], space_y-this.shape[1]);
                break;
            case 'triangle' :
                triangle(this.x - space_x/2, this.y-space_y/2+(space_y-this.shape[1]),
                this.x-space_x/2+((space_x-this.shape[1])/2), this.y-space_y/2,
                this.x-space_x/2+(space_x-this.shape[1]), this.y-space_y/2+(space_y-this.shape[1]));
                break;
        }
    }
};

//Player shapes: square / triangle / round

class Player{
    constructor(name, msg, clr, shape){
        this.name = name;
        this.msg = msg;
        this.clr = clr;
        this.shape = shape;
        console.log("New player:", this.name);
    }
    set_name(name){
        this.name = name;
    }
    get_name(){
        return this.name;
    }
};

//initialization function
function preload(){
    back_img = loadImage("../assets/corewar_background_2.png");
    joystix_font = loadFont("../fonts/joystix_monospace.ttf");
    title = document.getElementById('title');
    mem_div = document.getElementById("mem");
}

function setup(){
    //noLoop();

    frameRate(30);
    canvas = createCanvas(1920, 1000); //WEBGL);
    rectMode(CENTER);
    noStroke();
    for (let i = 0; i < 4096; i++){
        block[i] = new Block(start_x + (itx % 1326), start_y + (ity % 926), null);
        itx = itx > 1290 ? 0 : itx + space_x;
        ity = itx == 0 ? ity + space_y : ity;
        //if (i > 2023 && i < 3000) block[i].clr = clrs.red;
        if (i >= (64 * 32) && i < (64 * 40)) block[i].clr = clrs.blue;
        if (i >= (64 * 0) && i < (64 * 8)) block[i].clr = clrs.green;
    }
}

function draw(){
    //canvas_resize();
    background(0);
    //print player names
    textAlign(CENTER, CENTER);
    textFont('Courier New');
    textFont('Joystix Monospace');
    textStyle(BOLD);
    textSize(30);
    fill(255,255,255,255);
    text("Player 1 vs Player 2", 1213, 950);
    //initiate font for arena printing
    textAlign(LEFT, TOP);
    textFont('Courier New');
    text_mode_bold ? textStyle(BOLD) : textStyle(NORMAL);
    textSize(11.5);
    background(back_img);
    if (block_mode == true){
        //update_clrs();
        for (let i = 0; i < 4096; i++){
            block[i].draw();
        }
    }
    if (text_mode == true){
        str = mem_div.innerHTML;
        trim = str.rpl(/0x0.*: /, '')
        fill(255,255,255,200);
        text(trim, 550, 20); //win.w * 18 / 20, win.h * 18 / 20);
    }
    //...
}

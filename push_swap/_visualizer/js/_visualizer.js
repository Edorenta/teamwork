/*  This code intends to make it easy to visualise and optimize push_swap (42 project)
    it has been built on top of p5js for canvas rendering and this file is the only core
    of the visualizer.
    Built by pde-rent @42 (paul de renty) this code is unlicenced, use at your own risk
*/

"use strict";

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

//other global variables
var ptr = [];
var txt_obj;
var title;
var details_pane;
var clr_button;
var start_button;
var clr_pane;
var clr_option;
var clr_caption;
var details_box;
var speed_slider;
var speed_box;
var container;
var commands_list;
var unsorted_list;
var op_details;
var op_count;
var op_list;
var int_list;

var max;
var min;
var mult;
var data;
var stack = [];
var bars = [];
var it = 0;
var canvas;
var nb_int;
var nb_op;

var bar_w;
var x_g_pad = win.w / 9.2;
var x_pad = x_g_pad / 4;
var looping = false;


//min max of array as .self function
Array.prototype.max = function() {
    return Math.max.apply(null, this);
};

Array.prototype.min = function() {
    return Math.min.apply(null, this);
};

//let's load and init iro.js as our UI color picker
var color_picker = new iro.ColorPicker("#picker", {
  width: win.h / 4.8,
  height: win.h / 4.8,
  color: {r: 255, g: 0, b: 0},
  markerRadius: 10,
  padding: 0,
  sliderMargin: 10,
  sliderHeight: 20,
  borderWidth: 2,
  borderColor: "#b4b4b4",
  anticlockwise: true,
});

//see for more info about this color picker:
//https://rakujira.jp/projects/iro/docs/guide.html#color-change

//Stack class
class Stack {
    constructor(op, a, b) {
        this.a = a;
        this.b = b;
        this.op = op;
    }
}

//Bars class
class Bars {
    constructor(pass) {
        this.a = [];
        this.b = [];
        this.op = pass.op;
        this.na = pass.a ? Object.keys(pass.a).length : 0;
        this.nb = pass.b ? Object.keys(pass.b).length : 0;
        this.nx = this.na + this.nb;
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        for (let i = 0; i < this.na; i++) 
            this.a[i] = pass.a[i] - min + 1;
        for (let i = 0; i < this.nb; i++)
            this.b[i] = pass.b[i] - min + 1;
    }
    display() {
        for(let i = 0; i < 8; i++) ptr[i].classList.add("hidden");
        this.step = (win.w / 2.2) / Math.max(this.na, this.nb);
        let x;
        let y;
        let moved_a = [];
        let moved_b = [];
        op_count = 'Operation #' + it;
        switch (this.op) {
            case 'init':
                op_details = 'INIT >> stacks a and b initialized';
                break;
            case 'sa':
                op_details = 'SA >> swaps a[0] and a[1]'
                moved_a[0] = 0;
                moved_a[1] = 1;
                break;
            case 'sb':
                op_details = 'SB >> swaps b[0] and b[1]'
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'ss':
                op_details = 'SS >> swaps a[0] with a[1] and b[0] with b[1]'
                moved_a[0] = 0;
                moved_a[1] = 1;
                moved_b[0] = 0;
                moved_b[1] = 1;
                break;
            case 'pa':
                op_details = 'PA >> swaps a[0] with a[last]'
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'pb':
                op_details = 'PB >> swaps b[0] with b[last]'
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            case 'ra':
                op_details = 'RA >> rotates a >> pushs a[last] to front of a[0] and removes a[last]'
                moved_a[0] = this.na - 1;
                break;
            case 'rb':
                op_details = 'RB >> rotates b >> pushs b[last] to front of b[0] and removes b[last]'
                moved_b[0] = this.nb - 1;
                break;
            case 'rr':
                op_details = 'RR >> rotates a and b: >> pushs a[last] to front of a[0] and removes a[last] >> pushs b[last] to front of b[0] >> removes b[last]'
                moved_a[0] = this.na - 1;
                moved_b[0] = this.nb - 1;
                break;
            case 'rra':
                op_details = 'RRA >> reverse rotates a >> pushs a[0] after a[last] and pops a[0]'
                moved_a[0] = 0;
                break;
            case 'rrb':
                op_details = 'RRB >> reverse rotates b >> pushs b[0] after b[last] and pops b[0]'
                moved_b[0] = 0;
                break;
            case 'rrr':
                op_details = 'RRA >> reverse rotates a and b'
                moved_a[0] = 0;
                moved_b[0] = 0;
                break;
            default:
                moved_a[0] = this.na;
                moved_a[1] = this.na;
                moved_b[0] = this.nb;
                moved_b[1] = this.nb;
        }
        details_pane.innerHTML = op_count + ": " + op_details;
        strokeWeight(1);
        stroke(color(clrs.a_out));
        fill(color(clrs.a_in));
        let ptr_index = 0;
        for (let i = 0; i < this.na; i++) {
            y = this.a[i] * mult;
            x = x_pad + (this.step) * i;
            if (i == moved_a[0] || i == moved_a[1]) {
                move_ptr(x, ptr_index++);
                fill(color(clrs.a_out));
                stroke(color(clrs.a_in));
                rect(x, -y, this.step - 2, y);
                stroke(color(clrs.a_out));
                fill(color(clrs.a_in));
            }
            else rect(x, -y, this.step - 2, y);
        }
        stroke(color(clrs.b_out));
        fill(color(clrs.b_in));
        for (let i = 0; i < this.nb; i++) {
            y = this.b[i] * mult;
            x = (win.w / 2) + x_pad + (this.step) * i;
            if (i == moved_b[0] || i == moved_b[1]) {
                move_ptr(x, ptr_index++);
                fill(color(clrs.b_out));
                stroke(color(clrs.b_in));
                rect(x, -y, this.step - 2, y);
                stroke(color(clrs.b_out));
                fill(color(clrs.b_in));
            }
            else rect(x, -y, this.step - 2, y);
        }
        if (looping && it == (nb_op)) {
            start_button.innerHTML = looping ? "▶ START" : "▣ STOP";
            looping ? noLoop() : loop();
            looping = looping ? false : true;
        }
    }
}

//move bar indicators
function move_ptr(x, i) {
    ptr[i].style.left = x - (win.w * 0.014) + 'px';
    ptr[i + 4].style.left = x - (win.w * 0.007) + 'px';
    ptr[i].classList.remove("hidden");
    ptr[i + 4].classList.remove("hidden");
}

//stacks interpreter
function get_stacks(int_list, op_list) {
    nb_op = op_list.length;
    for (let i = 0; i <= nb_op; i++) {
        if (i == 0) {
            stack[i] = new Stack('init', int_list, null);
            //console.log("i:", i, "list[0]: ", stack[i].a[0], "list[1]: ", stack[i].a[1], "op:", stack[i].op); console.log(stack[i].a);
        }
        else
        {
            let dump_a = stack[i - 1].a ? stack[i - 1].a.slice(0) : null;
            let dump_b = stack[i - 1].b ? stack[i - 1].b.slice(0) : null;
            stack[i] = new Stack(op_list[i - 1], dump_a, dump_b);
            let A4 = stack[i].a ? stack[i].a.length - 1 : 0;
            let B4 = stack[i].b ? stack[i].b.length - 1 : 0;
            switch (stack[i].op) {
                case 'ss':
                case 'sa':
                    if (stack[i].a && typeof stack[i].a[0] !== 'undefined' && typeof stack[i].a[1] !== 'undefined'){
                        [stack[i].a[0], stack[i].a[1]] = [stack[i].a[1], stack[i].a[0]];
                    }
                    if (stack[i].op == 'sa')
                        break;
                case 'sb':
                    if (stack[i].b && typeof stack[i].b[0] !== 'undefined' && typeof stack[i].b[1] !== 'undefined')
                        [stack[i].b[0], stack[i].b[1]] = [stack[i].b[1], stack[i].b[0]]; 
                    break;
                case 'pa':
                    if (stack[i].b) {
                        if (!(stack[i].a)) stack[i].b = [];
                        stack[i].a.unshift(stack[i].b[0]);
                        stack[i].b.shift();
                    }
                    break;
                case 'pb':
                    if (stack[i].a) {
                        if (!(stack[i].b)) stack[i].b = [];
                        stack[i].b.unshift(stack[i].a[0]);
                        stack[i].a.shift();
                    }
                    break;
                case 'rr':
                case 'ra':
                    if (stack[i].a && typeof stack[i].a[A4] !== 'undefined') {
                        stack[i].a.push(stack[i].a[0]);
                        stack[i].a.shift();
                    }
                    if (stack[i].op == 'ra')
                        break;
                case 'rb':
                    if (stack[i].b && typeof stack[i].b[B4] !== 'undefined') {
                        stack[i].b.push(stack[i].b[0]);
                        stack[i].b.shift();
                    }
                    break;
                case 'rrr':
                case 'rra':
                    if (stack[i].a && typeof stack[i].a[A4] !== 'undefined') {
                        stack[i].a.unshift(stack[i].a[A4]);
                        stack[i].a.pop();
                    }
                    if (stack[i].op == 'rra')
                        break;
                case 'rrb':
                    if (stack[i].b && typeof stack[i].b[B4]) {
                        stack[i].b.unshift(stack[i].b[B4]);
                        stack[i].b.pop();
                    }
                    break;
            }
            //console.log("i:", i, "op:", stack[i].op); console.log("A:", stack[i].a, "B:", stack[i].b);
        }
    }
}

//initialization function
function setup() {
    noLoop();
    ptr[0] = document.getElementById('ptr_1');
    ptr[1] = document.getElementById('ptr_2');
    ptr[2] = document.getElementById('ptr_3');
    ptr[3] = document.getElementById('ptr_4');
    ptr[4] = document.getElementById('ptr_5');
    ptr[5] = document.getElementById('ptr_6');
    ptr[6] = document.getElementById('ptr_7');
    ptr[7] = document.getElementById('ptr_8');
    title = document.getElementById('title');
    txt_obj = document.getElementsByClassName("txt");
    clr_button = document.getElementById('bt0');
    start_button = document.getElementById('bt1');
    details_box = document.getElementById("show_details");
    details_pane = document.getElementById("details_pane");
    clr_pane = document.getElementById("clr_pane");
    clr_option = document.getElementById("clr_select");
    clr_caption = document.getElementById("clr_caption");
    speed_slider = document.getElementById('speed_slider');
    speed_box = document.getElementById('speed_box');
    container = document.getElementById('speed_set');
    commands_list = document.getElementById('commands').innerHTML;
    unsorted_list = document.getElementById('int_list').innerHTML;
    canvas = createCanvas(win.w, win.h);
    //canvas.position(0, 0);
    //canvas.style('display', 'absolute');
    bar_w = container.offsetWidth;
    speed_slider.addEventListener('input', refresh_box);
    speed_box.addEventListener('input', refresh_box);
    //document.getElementById("title_div").className '+=' "rubberBand animated";
    op_list = JSON.parse(commands_list).commands;
    int_list = JSON.parse(unsorted_list).unsorted_list;
    //nb_int = Object.keys(int_list).length;
    nb_int = int_list.length;
    nb_op = op_list.length;
    max = int_list.max();
    min = int_list.min();
    mult = (win.h / 1.52) / (max - min);
    get_stacks(int_list, op_list);
    for (let pass = 0; pass <= nb_op; pass++)
        bars[pass] = new Bars(stack[pass]);
}

//canvas resize on viewport change
function canvas_resize() {
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}

//window resize on viewport change
function windowResized() {
    canvas_resize();
    set_origin();
    set_speed();
    bars[it].display();
}

//change canvas origin
function set_origin() {
    translate(0, height / 6 * 5); //set bottom left as origin
    background(color(clrs.back));
    stroke(color(clrs.txt_back));
    strokeWeight(1);
    line(0, 0, win.w, 0);
    line(win.w / 2, 0, win.w / 2, -win.h / 6 * 4.15);
}

//p5js loop function at every FPS (OPS)
function draw() {
    canvas_resize();
    set_origin();
    set_speed();
    bars[it].display();
    if (looping && it < nb_op) it++;
}

//buttons callback functions

//reset stacks to initial state
function _reset() {
    it = 0;
    redraw();
    looping == false ? noLoop() : 0;
}

//next op
function _next() {
    //for(let i = 0; i < 8; i++) ptr[i].classList.remove("hidden");
    start_button.innerHTML = "▶ START";
    looping = false;
    it = it < nb_op ? ++it : it;
    redraw();
    noLoop();
}

//previous op
function _prev() {
    //for(let i = 0; i < 8; i++) ptr[i].classList.remove("hidden");
    start_button.innerHTML = "▶ START";
    looping = false;
    it = it > 1 ? --it : 0;
    redraw();
    noLoop();
}

//start / stop
function _switch() {
    start_button.innerHTML = looping ? "▶ START" : "▣ STOP";
    //if (looping) for(let i = 0; i < 4; i++) ptr[i].classList.remove("hidden"); //toggle = add or remove depending on previous state
    if (!looping) for(let i = 0; i < 8; i++) ptr[i].classList.add("hidden");
    noLoop();
    looping ? noLoop() : loop();
    looping = looping ? 0 : 1;
    it == nb_int ? _reset() : 0;
}

//ui buttons callback functions

//toggle operation details
function toggle_details() {
    if (details_box.checked == true) details_pane.classList.remove("hidden");
    else details_pane.classList.add("hidden");
}

//toggle color picker
var clr_pane_on = 0;
function toggle_colors() {
    clr_pane_on ^= 1;
    clr_button.innerHTML = clr_pane_on ? "OK ✓" : "COLORS";
    if (clr_pane_on == true) clr_pane.classList.remove("hidden");
    else clr_pane.classList.add("hidden");
}

//color picker callback function
color_picker.on("color:change", function(clr){
    if (clr_caption) {
        clr_caption.innerHTML = [
        "hex: " + clr.hexString,
        "rgb: " + clr.rgbString,
        "hsl: " + clr.hslString,
        ].join("<br>");
        color_switch(clr_option.options[clr_option.selectedIndex].value, clr);
    }
});

function color_switch(option, clr) {
    switch (option) {
        case "1":
            clrs.back = clr.rgbString;
            document.body.style.backgroundColor = clr.back;
            break; 
        case "2":
            clrs.txt_back = clr.rgbString;
            for (let i = 0; i < txt_obj.length; i++)
                txt_obj[i].style.backgroundColor = clrs.txt_back;
            title.style.backgroundColor = "transparent";
            break;
        case "3":
            clrs.txt = clr.rgbString;
            for (let i = 0; i < txt_obj.length; i++)
                txt_obj[i].style.color = clrs.txt;
            break;
        case "4": clrs.a_out = clr.rgbString; break;
        case "5": clrs.b_out = clr.rgbString; break;
        case "6": clrs.a_in = clr.rgbString; break;
        case "7": clrs.b_in = clr.rgbString; break;
    }
    draw();
    console.log(option, clr.rgbString, clrs.a_out);
    //console.log("clr changed: " + option + clr.rgbString);
}

//callback function to update OPS slidebar
function refresh_box() {
    bar_w = container.offsetWidth;
    speed_box.style.left = Math.round(((bar_w - 14) * (speed_slider.value) / 60) - 21, 0) + 'px';
    set_speed();
}

//callback to change speed (FPS) on OPS slidebar change
function set_speed() {
    frameRate(speed_box.value * 1);
}

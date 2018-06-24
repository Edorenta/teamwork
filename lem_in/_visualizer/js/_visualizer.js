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
    scl : 50
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

var env = {
        x : 0,
        y : 0,
        z : 0,
        //camX : win.w/2,
        //camY : win.h/2,
        //camZ : (win.h/2.0) / Math.tan(Math.PI*30.0 / 180.0),
        camX : 0,
        camY : 0,
        camZ : -500,
        centerX : 0,
        centerY : 0,
        centerZ : 0,
        upX : 0,
        upY : 1,
        upZ : 0,
        count : 0,
        clr : 0,
        nb_ants : 0,
        nb_rooms : 0,
        nb_links : 0
};

var df = [];

class Room{
    constructor(name, x, y, z) {
        this.name = name;
        this.x = x;
        this.y = y;
        this.z = z;
        this.is_start = false;
        this.is_end = false;
        this.link = [];
        this.is_fw = false;
        console.log("New room:", this.name);
    }
    set_start(){
        this.is_start = true;
    }
    set_end(){
        this.is_end = true;
    }
    add_link(room){
        this.link.push(room);
    }
    set_fw(){
        this.is_fw = true;
    }
    get_name(){
        return this.name;
    }
};

//other global variables
var txt_obj;
var title;
var start_button;
var container;
var lines_json;
var lines = [];
var data = [];
var canvas;
var nb_lines;
var data;
var turn;
var zoom = 1.00;
var zMin = 0.05;
var zMax = 9.00;
var accuracy = 0.0005;

//min max of array as .this function
Array.prototype.max = function() {
    return Math.max.apply(null, this);
};

Array.prototype.min = function() {
    return Math.min.apply(null, this);
};

//canvas resize on viewport change
function canvas_resize() {
    win.w = Math.max(document.documentElement.clientWidth, window.innerWidth || 0);
    win.h = Math.max(document.documentElement.clientHeight, window.innerHeight || 0);
    resizeCanvas(win.w, win.h, true);
}
/*
function mouseReleased() {
    env.count += 1;
    for (let i = 0; i < env.nb_rooms; i++){
        if (df[i].is_end){
            for (let j = 0; j < ((df[i].move.length)); j++){
                //print "env.clr = ", env.clr
                if (env.count == df[i].move[j])
                    env.clr += (255 / (int(env.nb_ants) + 1));
            }
        }
    }
    if (env.count == turn + 1){
        env.count = 0;
        //env.clr = 255 / int(env.nb_ants);
        env.clr = 0;
    }
}
*/
function work_out(data){
    //print "nb_ants = ", nb_ants
    let z = 0;
    let j = 0;
    turn = 1;
    for (let i = 0; i < nb_lines; i++){
        //console.log("A");
        if (!data[i])
            continue ;
        else if (data[i][0].includes("#")){
            //console.log("B");
            //next(myiter, None);
            if (data[i].includes("##start")){
                i += 1;
                df[j] = new Room(data[i][0], int(data[i][1])*win.scl, int(data[i][2])*win.scl, int(z)*win.scl*2);
                df[j].set_start();
                //print df[j].name, df[j].x, df[j].y, df[j].z, df[j].is_start, df[j].is_end;
                env.nb_rooms += 1;
                //i -= 1;
                //continue;
                j += 1;
            }
            else if (data[i].includes("##end")){
                i += 1;
                //print data[i];
                df[j] = new Room(data[i][0], int(data[i][1])*win.scl, int(data[i][2])*win.scl, int(z)*win.scl*2);
                df[j].set_end();
                //print df[j].name, df[j].x, df[j].y, df[j].z, df[j].is_start, df[j].is_end;
                env.nb_rooms += 1;
                //i -= 1;
                //continue;
                j += 1;
            }
        }
        else if (data[i][0].includes("-") && !(data[i][0].includes("L"))){
            //console.log("C");
            let link_room = data[i][0].split("-");
            for (let k = 0; k < (env.nb_rooms); k++){
                //console.log("k =",k);
                let room_name = df[k].get_name();
                if (room_name == link_room[0]){
                    for (let l = 0; l < (env.nb_rooms); l++){
                        let link_name = df[l].get_name();
                        if (link_name == link_room[1]){
                            df[k].add_link(df[l]);
                            //print "room = ", df[k].name, "link = ", df[k].link;
                            break ;
                        }
                    }
                    break ;
                }
            }
        }
        else if (data[i][0].includes("L")){
            //console.log("D");
            //print "data[i] = ", data[i]
            for (j = 0; j < ((data[i].length)); j++){
                let move_line = data[i][j].split("-");
                //console.log(move_line);
                for (let m = 0; m < env.nb_rooms; m++){
                    let room_name = df[m].get_name();
                    //print "room_name = ", room_name;
                    //print "move_line[1] = ", move_line[1];
                    if (room_name == move_line[1]){
                        df[m].set_fw();
                        console.log(df[m]);
                        //console.log("df[m].move =", df[m].move);
                    }
                }
            }
            turn += 1
            //print "move_line = ", move_line;
            //print data[i];
            //pass;
        }
        else if (data[i][1] && data[i][2]){
            //console.log("E");
            df[j] = new Room(data[i][0], int(data[i][1])*win.scl,
                int(data[i][2])*win.scl, int(z)*win.scl*2)
            //print df[j].name, df[j].x, df[j].y, df[j].z, df[j].is_start, df[j].is_end
            env.nb_rooms += 1
            j += 1
        }
        z += 1
    }
    console.log(df);
    return (1);
}

function draw_lines(){
    for (let j = 0; j < env.nb_rooms; j++){
        if ((df[j].link)){
            push();
            strokeWeight(2);
            stroke(200,200,200);
            for (let i = 0; i < ((df[j].link.length)); i++){
                if ((df[j].is_fw || df[j].is_start) && (df[j].link[i].is_fw || df[j].link[i].is_end)){
                    stroke(0,255,0);
                    strokeWeight(4);
                }
                line(df[j].x, df[j].y, df[j].z + win.scl*2,
                    df[j].link[i].x, df[j].link[i].y, df[j].link[i].z + win.scl*2);
            }
            pop();
        }
    }
}

function base_lights(){
    ambientLight(128, 128, 128);
    directionalLight(128, 128, 128, 0, 0, -1);
    //lightFalloff(1, 0, 0);
    //lightSpecular(0, 0, 0);
}

function x_max(){
    let x = 0;
    for (let i = 0; i < env.nb_rooms; i++)
        if (df[i].x > x)
            x = df[i].x;
    return (x);
}
function x_min(){
    let x = 1000000;
    for (let i = 0; i < env.nb_rooms; i++)
        if (df[i].x < x)
            x = df[i].x;
    return (x);
}
function y_max(){
    let y = 0;
    for (let i = 0; i < env.nb_rooms; i++)
        if (df[i].y > y)
            y = df[i].y;
    return (y);
}
function y_min(){
    let y = 1000000;
    for (let i = 0; i < env.nb_rooms; i++)
        if (df[i].y < y)
            y = df[i].y;
    return (y);
}

function draw_rooms(){
    for (let i = 0; i < env.nb_rooms; i++){
        strokeWeight(1)
        if (df[i].is_start){
            push();
            //noStroke();
            stroke(255);
            fill(255, 0, 255);
            //base_lights();
            translate(df[i].x, df[i].y, df[i].z+win.scl*2);
            box(win.scl);
            pop();
        }
        else if (df[i].is_end){
            push();
            stroke(255);
            fill(0, 200, 200, env.clr);
            //base_lights();
            translate(df[i].x, df[i].y, df[i].z+win.scl*2);
            box(win.scl);
            pop();
        }
        else if (!(df[i].is_start) && !(df[i].is_end)){
            push();
            //base_lights();
            //noStroke();
            stroke(0);
            fill(255);
            /*
            for (let j = 0; j < ((df[i].move.length)); j++){
                //console.log("df[i].name =", df[i].name);
                //console.log("df[i].move =", df[i].move[j]);
                //console.log("len = ", (df[i].move.length));
                //delay(5000)
                if (env.count != df[i].move[j]){
                    fill(255);
                }
                    //print "df[i].name = ", df[i].name
                else{
                    fill(100);
                    break ;
                }
            }
            */
            //print "turn = ", turn
            translate(df[i].x, df[i].y, df[i].z+win.scl*2);
            box(win.scl/1.5);
            pop();
        }
    }
    //print df[i].name, df[i].x, df[i].y, df[i].z, df[i].is_start, df[i].is_end, df[i].link
}

//initialization function
function setup() {
    //noLoop();
    frameRate(30);
    canvas = createCanvas(win.w, win.h, WEBGL);
    title = document.getElementById('title');
    translate(win.w / 2, win.h / 2);
    rectMode(CENTER);
    lines_json = document.getElementById('lines').innerHTML;
    lines = JSON.parse(lines_json).lines;
    nb_lines = lines.length;
    for (let i = 0; i < nb_lines; i++)
        data[i] = lines[i].split(" ");
    env.nb_ants = data[0];
    //console.log(data[0]);
    //console.log("env.nb_ants = ", env.nb_ants);
    //console.log("env.clr = ", env.clr);
    env.clr = 255; // int(env.nb_ants)
    console.log("lines:", lines);
    console.log("data:", data);
    console.log("env.clr =", env.clr);
    console.log("env.nb_ants =", env.nb_ants);
    console.log("nb lines:", nb_lines);
    work_out(data);
    env.centerX = (x_min() + x_max()) / 2;
    env.centerY = (y_min() + y_max()) / 2;
    env.camX = (x_min() + x_max()) / 2;
    env.camY = (y_min() + y_max()) / 2;
}

function keyPressed(){
    switch (keyCode){
        case 37: _left = true; break;
        case 38: _up =  true; break;
        case 39: _right = true; break;
        case 40: _down = true; break;
        case 97: _1 = true; break;
        case 98: _2 = true; break;
        case 99: _3 = true; break;
        case 100: _4 = true; break;
        case 101: _5 = true; break;
        case 102: _6 = true; break;
        case 103: _7 = true; break;
        case 104: _8 = true; break;
        case 105: _9 = true; break;
        case 82: _r = true; break;
        case 107: _plus = true; break;
        case 109: _minus = true; break;
    }
    if (_r){ //RESET settings
        x = 0;
        y = 0;
        z = 0;
        camX = 0;
        camY = 0;
        camZ = -500;
        centerX = 0;
        centerY = 0;
        centerZ = 0;
        upX = 0;
        upY = 1;
        upZ = 0;
        zoom = 1.00;
        zMin = 0.05;
        zMax = 9.00;
        accuracy = 0.0005;
        change_view();
    }
    console.log("cam centerX:", env.centerX, "cam centerY:", env.centerY);
    console.log("X max:", x_max(), "X min:", x_min());
    console.log("Y max:", y_max(), "Y min:", y_min());
    console.log(keyCode);
}

function keyReleased(){
    switch (keyCode){
        case 37: _left = false; break;
        case 38: _up =  false; break;
        case 39: _right = false; break;
        case 40: _down = false; break;
        case 97: _1 = false; break;
        case 98: _2 = false; break;
        case 99: _3 = false; break;
        case 100: _4 = false; break;
        case 101: _5 = false; break;
        case 102: _6 = false; break;
        case 103: _7 = false; break;
        case 104: _8 = false; break;
        case 105: _9 = false; break;
        case 82: _r = false; break;
        case 107: _plus = false; break;
        case 109: _minus = false; break;
    }
}

function change_view(){
    /*
    translate((x_min() + x_max()) / 2, (y_min() + y_max()) / 2);
    env.centerX = 0;
    env.centerY = 0;
    env.camX = 0;
    env.camY = 0;
    */
    camera(env.camX, env.camY, env.camZ, env.centerX, env.centerY,
        env.centerZ, env.upX, env.upY, env.upZ);
}

function mouseWheel(event) {
  zoom += accuracy * event.delta;
  zoom = constrain(zoom, zMin, zMax);
  return false;
}

//p5js loop function at every FPS (OPS)
function draw() {
    background(0);
    base_lights();
    _8 ? env.x += 3 : 0;
    _2 ? env.x -= 3 : 0;
    _6 ? env.y += 3 : 0;
    _4 ? env.y -= 3 : 0;
    _3 ? env.z += 3 : 0;
    _1 ? env.z -= 3 : 0;
    _plus ? env.camZ += 30 : 0;
    _minus ? env.camZ -= 30 : 0;
    _left ? env.centerX -= 20 : 0;
    _right ? env.centerX += 20 : 0;
    _up ? env.centerY += 20 : 0;
    _down ? env.centerY -= 20 : 0;
    translate((x_min() + x_max()) / 2, (y_min() + y_max()) / 2);
    change_view();
    scale(zoom);
    //translate((x_min() + x_max()) / 2, (y_min() + y_max()) / 2);
    rotateX(env.x * 0.015);
    rotateY(env.y * 0.015);
    rotateZ(env.z * 0.015);
    //translate(win.w / 8, win.h / 8);
    draw_rooms();
    draw_lines();
}

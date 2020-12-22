/*Día 25 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */
//código Processing

import oscP5.*;
import netP5.*;
OscP5 oscp5;
NetAddress direcSC;

int val1, val2, diam, cambio;
float px, py, px2, py2, long1, long2;

void setup() {
  size(1920, 1080);
  background(0);

  oscp5 = new OscP5(this, 4445);
  direcSC = new NetAddress("127.0.0.1", 57120);
}

void draw() {
  fill(0, 2);
  noStroke();
  rect(0, 0, width, height);

  cambio=int(random(8, 16));

  frameRate(cambio);

  val1 = int(random(1, 3));
  val2 = int(random(1, 2));

  strokeWeight(0.5);
  noStroke();
  if (val1==2) {
    long1 = random(10, 50);
    px = random(width-long1);
    py = random(height-long1);
    //dibujar
    fill(random(255), 0, random(255));
    stroke(255);
    rect(px, py, long1, long1);
    //mensaje
    OscMessage mensajeSC2 = new OscMessage("/freqSC2");
    mensajeSC2.add(px);
    mensajeSC2.add(py);
    mensajeSC2.add(long1);
    mensajeSC2.add(val1);
    oscp5.send(mensajeSC2, direcSC);
  }
  stroke(255);
  if (val1==1) {
    long2 = random(50, 100);
    px2 = random(width-long2);
    py2 = random(height-long2);
    //dibujar
    fill(random(255), 50);
    rect(px2, py2, long2, long2);
    //mensaje
    OscMessage mensajeSC = new OscMessage("/freqSC");
    mensajeSC.add(px2);
    mensajeSC.add(py2);
    mensajeSC.add(long2*0.02);
    mensajeSC.add(val1);
    oscp5.send(mensajeSC, direcSC);
  }
  println(cambio);
  if (mousePressed) {
    saveFrame("GA_25.png");
    delay(500);
    exit();
  }
}

//Código de SuperCollider
/*
s.boot;
 n=NetAddr("127.0.0.1", 57120);
 (
 (
 SynthDef(\ag25, {
 |freq1=120, freq2=12.8 fase=0, mul=1, amp=1, gate=1, pan=0|
 var env, paneo, son1, son2, onda;
 son1=SinOsc.ar(freq1, 0, mul*0.15);
 son2=Pulse.ar(freq1/4, 0.5, 0.5, mul*0.1);
 onda=son1+son2;
 paneo=Pan2.ar(onda, pan);
 env=EnvGen.kr(Env.perc(0.005, 0.05, 1, -8), doneAction:
 2);
 Out.ar(0, paneo*env);
 }
 ).send(s)
 );
 (
 SynthDef(\ag25b, {
 |freq1=120, freq2=12.8 fase=0, mul=0.1, amp=1, gate=1, pan=0|
 var env, paneo, son1, son2, onda;
 son1=VarSaw.ar(freq1, 0.5, 0.5, mul);
 son2=LFPulse.ar(freq2, 0.5, 0.5);
 onda=son1+son2;
 paneo=Pan2.ar(onda, pan);
 env=EnvGen.kr(Env.perc(0.005, 0.05, 1, -8), doneAction:
 2);
 Out.ar(0, paneo*env);
 }
 ).send(s)
 ); 
 (
 i=OSCresponder(nil, "/freqSC", {
 | ...msg|
 msg[2].postln;
 Synth(\ag25, [\freq1, 100+((msg[2][1])/10), \freq2, (msg[2][1]), \mul, (msg[2][3]) ]);
 }
 ).add
 );
 (
 k=OSCresponder(nil, "/freqSC2", {
 | ...msg|
 msg[2].postln;
 Synth(\ag25b, [\freq1, (msg[2][1])+(msg[2][3]), \freq2, (msg[2][2])]);
 }
 ).add
 )
 )
 */

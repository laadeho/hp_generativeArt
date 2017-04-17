/*Día 20 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */
//arte generativo dia 20
//verdad
PFont tex;
float px=0, py=0, opa=0;
int nada;

void setup() {
  size(1600, 800);
  background(255);
  smooth();

  tex = loadFont("CourierNew36.vlw"); 
  textFont(tex);
}

void draw() {
  strokeWeight(5);
  stroke(0, 25);
  for (int x=0; x<=width; x+=5) {
    for (int y=0; y<=height; y+=5) {
      point(px+noise(x)*random(width*2), py+noise(y)*random(height*2));
    }
  }
  scale(0.5);
  fill(255);
  text("la verdad se revelará tarde o temprano", width-width*0.9, height-height*0.9);
  scale(2);
  fill(255, opa);
  text("VERDAD?", width-width/8, height-height/8);
  opa+=0.1;
}
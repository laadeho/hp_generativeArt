/*Día 4 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */

float rota=0;
float dista=0;

void setup() {
  size(1920, 1080, P3D);
  background(0);
  smooth(4);
}

void draw() {
  noStroke();
  fill(0, 5);
  translate(width/2, height/2); 
  stroke(200);
  strokeWeight(0.5);

  float noivel=noise(dista)*800;

  rotate(rota);

  float maxdis=height*0.45;

  line(noivel, 0, maxdis, 0);
  line(noivel*0.5, 0, noivel*0.2, 0);
  noStroke();
  fill(255);
  ellipse(noivel*0.2, 0, 2, 2);
  ellipse(noivel*0.5, 0, 2, 2);
  fill(random(0, 255));
  ellipse(maxdis, 0, 3, 3);
  rota+=0.01;
  dista+=noivel;
  if (mousePressed) {
    saveFrame("GA_04.png");
    delay(500);
    exit();
  }
}

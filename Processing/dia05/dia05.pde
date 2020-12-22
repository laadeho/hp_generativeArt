/*Día 5 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */
float posi=0;
float dista=0;
float col=0;
int sw=1;

void setup() {
  size(1920, 1080);
  background(255);
  smooth();
}

void draw() {
  noStroke();
  fill(0, 5);

  stroke(50);
  strokeWeight(0.1);

  float alt1=noise(dista)*height;

  translate(posi, 0);
  float pox = alt1;

  line(0, 0, 0, height);

  noStroke();

  fill(col, 50);
  float lado = 5;
  translate(0, pox);
  rect(-lado/2, -lado/2, lado, lado);

  if (posi > width) {
    posi=0;
    col=random(200);
  }
  posi+=5;
  dista+=alt1;
  if (mousePressed) {
    saveFrame("GA_05.png");
    delay(500);
    exit();
  }
}

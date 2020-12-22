/*Día 13 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */


Pm pm;

float posx, posy, pas=40, mur=6, ang=0, dirx=0, diry=0;
int caso;
void setup() {
  size(1920, 1080);
  background(0);
  smooth();
  posx=random(width); 
  posy=random(height);
  pm = new Pm();
}

void draw() {
  fill(250, 240, 160, 100);
  for (int i=0; i<width; i+=35) {
    for (int j=0; j<height; j+=35) {
      ellipse(20+i, 20+j, 3, 3);
    }
  }
  pushMatrix();
  translate(posx, posy);
  pm.draw();
  posx+=dirx;
  posy+=diry;

  if (posx>width+50) {
    posx=10;
  } else if ( posx<-50) {
    posx=width-10;
  } else if (posy>height+50) {
    posy=10;
  } else if (posy<-50) {
    posy=height-10;
  }
  switch(caso) {
  case 1: 
    println("derecha");
    dirx=15;
    diry=0;
    ang=0;
    break;

  case 2: 
    println("abajo");
    dirx=0;
    diry=15;
    ang=90;
    break;

  case 3: 
    println("izquierda");
    dirx=-15;
    diry=0;
    ang=180;
    break;
  case 4: 
    println("arriba");
    dirx=0;
    diry=-15;
    ang=270;
    break;
  }
  popMatrix();

  if (mousePressed) {
    saveFrame("GA_13.png");
    delay(500);
    exit();
  }
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == RIGHT) {
      caso = 1;
    } else if (keyCode == DOWN) {
      caso = 2;
    } else if (keyCode == LEFT) {
      caso = 3;
    } else if (keyCode == UP) {
      caso = 4;
    }
  } else {
  }
}

////////////

class Pm {

  float rad=PI/180;
  float dx=pas/2, dy=0;
  int sact;
  int sant;

  void draw() {
    frameRate(20);
    int s=second();
    int m=millis();
    noStroke();
    fill(250, 240, 60);
    pushMatrix();

    ellipse(0, 0, pas-pas/8, pas-pas/8);
    fill(0);
    rotate(ang*rad);
    triangle(0, 0, dx, dy, dx, -dy);
    popMatrix();

    if (int(m*0.01)%2 == 0) {
      dy=pas/2;
    } else {
      dy=0;
    }
  }
}

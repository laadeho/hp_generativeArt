/*Día 12 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */

//import processing.opengl.*;

Centro c;
float rad=PI/180;
float px=0;
float py=height-4;
int s=second();
int cuenta=0;
float cr=255;
float cg=255;
float cb=255;

void setup() {
  //size(800, 400, OPENGL);
  size(1920, 1080);
  smooth();
  background(0);
  c= new Centro();
}

void draw() {
  cr=random(150, 255);
  cg=random(150, 255);
  cb=random(150, 255);
  s=second();
  println(s);
  frameRate(20);
  // fill(0);
  // rect(0, 0, width, height);
  float inc=random(0, 120);

  stroke(255);
  strokeWeight(2);
  line(0, py, width, py);
  translate(px, py);
  scale(random(0.05, 0.25));
  c.dibuja();
  px+=inc;

  if (px>width) {
    px=1;
    cuenta=cuenta+1;
  }
  //POSICIONES EN Y
  if (cuenta == 0) {
    py=height-4;
  }
  if (cuenta == 2) {
    py=height-height/4;
  }

  if (cuenta == 4) {
    py=height-height/2;
  }

  if (cuenta == 6) {
    py=height-(height/4)*3;
  }
  if (cuenta == 8) {
    cuenta=0;
  }
  if (mousePressed) {
    saveFrame("GA_12.png");
    delay(500);
    exit();
  }
}

//////////////

class Brazo {
  Cabeza ca;
  //variables 
  float px=0, py=0, lony=40;
  int diam=7;
  Brazo() {
    ca= new Cabeza();
  }
  void dibuja() {
    pushMatrix();
    translate(0, py-2*lony+(-lony*1.5/2));
    ca.dibuja();
    stroke(cr, cg, cb, 210);
    strokeWeight(2);
    line(px, py, px, py+2*lony);
    pushMatrix();
    translate(0, 2*lony);
    noStroke();
    fill(cr, cg, cb);
    ellipse(px, py, lony/10, lony/10);
    popMatrix();
    popMatrix();
  }
}

///////////////

class Cabeza {
  //también conocida como cípsela (ay we)

  float px=0, py=0, diaca=8, rfy[], lony[];
  int nfi=20; //número de filamentos



  Cabeza() {
    rfy=new float[nfi];
    lony=new float[nfi];

    for (int i=0; i<nfi; i++) {
      rfy[i]=random(8, 12);
      lony[i]=random(30, 40);
    }
  }
  void dibuja() {
    noStroke();
    fill(cr, cg, cb);
    ellipse(0, 0, 8, 8);
    stroke(cr, cg, cb);
    strokeWeight(0.5);
    pushMatrix();
    rotate(-65*rad);
    for (int i=0; i<nfi; i++) {
      rotate(8*rad);
      pushMatrix();
      line(px, py, px, -lony[i]);
      popMatrix();
    }
    popMatrix();
  }
}

////////////////////

class Centro {
  Brazo bra;
  int nb=18; //numero de brazos
  float rx[], lony=40; //rotación de cada brazo

  Centro() {
    bra= new Brazo();
    rx= new float[nb];
  }

  void dibuja() {
    for (int i=0; i<nb; i++) { //posición de cada brazo
      rx[i]=random(15, 30)*rad;
    }

    pushMatrix();
    translate(0, -200);
    scale(0.5);
    noStroke();
    fill(cr, cg, cb);
    ellipse(0, 0, lony*1.5, lony*1.5);
    stroke(cr, cg, cb);
    pushMatrix(); 
    for (int i=0; i<nb; i++) {
      rotate(rx[i]);
      bra.dibuja();
    }
    popMatrix();
    stroke(cr, cg, cb);
    strokeWeight(4);
    line(0, 0, 0, 10*lony);
    popMatrix();
  }
}

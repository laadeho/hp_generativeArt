/*Día 11 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */

//import processing.opengl.*;
import peasy.*;
//http://mrfeinberg.com/peasycam/
PeasyCam cam;

Centro c;
float rad=PI/180, rx=5, ry=5;

void setup() {
  // size(800*2, 400*2, OPENGL);
  size(1920, 1080, P3D);
  cam = new PeasyCam(this, 150);
  cam.setMinimumDistance(350);
  cam.setMaximumDistance(500);
  cam.lookAt(0, 0, 0);

  smooth();
  c= new Centro();
}
void draw() {
  lights();
  //translate(width/2, height/2);
  background(0);
  pushMatrix();
  c.dibuja();
  popMatrix();
  if (mousePressed) {
    saveFrame("GA_11.png");
    delay(500);
    exit();
  }
}

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
    stroke(220, 210);
    strokeWeight(2);
    line(px, py, px, py+2*lony);
    pushMatrix();
    translate(0, 2*lony);
    noStroke();
    fill(250, 230, 190, 100);
    sphere(lony/10);
    popMatrix();
    popMatrix();
  }
}

class Cabeza {
  //también conocida como cípsela (ay we)

  float px=0, py=0, diaca=8, rfy[], lony[];
  int nfi=int(random(30, 45)); //número de filamentos



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
    fill(250, 230, 190);
    sphere(diaca/2);
    stroke(255, 80);
    strokeWeight(0.5);
    pushMatrix();
    for (int i=0; i<nfi; i++) {
      rotateY(rfy[i]*rad);
      pushMatrix();
      rotateZ(65*rad);
      line(px, py, px, -lony[i]);
      popMatrix();
    }
    popMatrix();
  }
}

class Centro {
  Brazo bra;
  int nb=80; //numero de brazos
  float rx[], ry[], rz[], lony=40; //rotación de cada brazo

  Centro() {
    bra= new Brazo();
    rx= new float[nb];
    ry= new float[nb];
    rz= new float[nb];

    for (int i=0; i<nb; i++) { //posición de cada brazo
      rx[i]=random(360*rad);
      ry[i]=random(360*rad);
      rz[i]=random(360*rad);
    }
  }

  void dibuja() {
    noStroke();
    fill(250, 230, 190);
    sphere(lony*1.5/2);
    stroke(255);
    pushMatrix(); 
    for (int i=0; i<nb; i++) {
      rotateX(rx[i]);
      rotateY(ry[i]);
      rotateZ(rz[i]);
      bra.dibuja();
    }
    popMatrix();
    stroke(200);
    strokeWeight(8);
    line(0, 0, 0, 0, 12*lony, 0);
  }
}

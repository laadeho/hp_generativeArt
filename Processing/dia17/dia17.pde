/*Día 17 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */
//arte generativo dia 17
Curva cur;
Horizontal hor;
Vertical ver;

int qlv = int(random(3, 10));
int qlh = int(random(3, 10));
int qlc = int(random(2, 5));

void setup() {
  size(1920, 1080);
  background(0);

  cur = new Curva();
  ver = new Vertical();
  hor = new Horizontal();
  smooth();
}

void draw() {
  ver.draw();
  hor.draw();
  cur.draw();

  if (mousePressed) {
    saveFrame("GA_01.png");
    delay(500);
    exit();
  }
}

class Curva {
  float lcgros[], lccol[], lcpix[], lcpiy[], lcvel[], lclong[], ang[], radio[];

  Curva() {
    lcgros = new float[qlc];
    lcpix = new float[qlc];
    lcpiy = new float[qlc];
    lcvel = new float[qlc];
    lccol = new float[qlc];
    lclong = new float[qlc];
    ang = new float[qlc];
    radio = new float[qlc];

    for (int i=0; i<qlc; i++) {
      ang[i] = random(radians(360));
      lclong[i] = ang[i]*2;
      radio[i] = random(5, 200);
      lcpix[i] = random(width);
      lcpiy[i] = random(height);
      lccol[i] = random(100, 255);
      lcgros[i] = random(0.75, 2);
      lcvel[i] = random(0.005, 0.03);
    }
  }

  void draw() {
    for (int i=0; i<qlc; i++) {
      stroke(lccol[i], lccol[i]);
      strokeWeight(lcgros[i]);
      pushMatrix();
      translate(lcpix[i], lcpiy[i]);
      point(cos(ang[i])*radio[i], sin(ang[i])*radio[i]);
      popMatrix();
      ang[i]+=lcvel[i];
      if (ang[i]>lclong[i]) {
        ang[i]=0;
        lcpix[i] = random(width);
        lcpiy[i] = random(height);
        ang[i] = random(radians(360));
        lclong[i] = ang[i]*2;
        radio[i] = random(5, 200);
      }
    }
  }
}

class Horizontal {
  float lhgros[], lhcol[], lhpix[], lhpiy[], lhincx[], lhvel[], lhlong[];

  Horizontal() {
    lhgros = new float[qlh];
    lhincx = new float[qlh];
    lhpix = new float[qlh];
    lhpiy = new float[qlh];
    lhvel = new float[qlh];
    lhcol = new float[qlh];
    lhlong = new float[qlh];

    for (int i=0; i<qlh; i++) {
      lhpix[i] = random(width);
      lhpiy[i] = random(height);
      lhcol[i] = random(100, 255);
      lhgros[i] = random(0.5, 3);
      lhvel[i] = random(0.1, 3);
      lhlong[i]=random(height/10, height/2);
    }
  }

  void draw() {
    for (int i=0; i<qlh; i++) {
      stroke(lhcol[i], lhcol[i]);
      strokeWeight(lhgros[i]);
      point(lhpix[i]+lhincx[i], lhpiy[i]);
      lhincx[i]+=lhvel[i];
      if (lhincx[i]>=lhlong[i]) {
        lhincx[i]=0;
        lhlong[i]=random(height/10, height/2);
        lhpix[i]=random(width);
        lhpiy[i]=random(height);
      }
    }
  }
}

class Vertical {
  float lvgros[], lvcol[], lvpix[], lvpiy[], lvincy[], lvvel[], lvlong[];

  Vertical() {
    lvgros = new float[qlv];
    lvincy = new float[qlv];
    lvpix = new float[qlv];
    lvpiy = new float[qlv];
    lvvel = new float[qlv];
    lvcol = new float[qlv];
    lvlong = new float[qlv];

    for (int i=0; i<qlv; i++) {
      lvpix[i] = random(width);
      lvpiy[i] = random(height);
      lvcol[i] = random(100, 255);
      lvgros[i] = random(0.4, 3);
      lvvel[i] = random(0.8, 1.5);
      lvlong[i]=random(height/10, height/2);
    }
  }

  void draw() {
    for (int i=0; i<qlv; i++) {
      stroke(lvcol[i], lvcol[i]);
      strokeWeight(lvgros[i]);
      point(lvpix[i], lvpiy[i]+lvincy[i]);
      lvincy[i]+=lvvel[i];
      if (lvincy[i]>=lvlong[i]) {
        lvincy[i]=0;
        lvlong[i]=random(height/10, height/2);
        lvpix[i]=random(width);
        lvpiy[i]=random(height);
      }
    }
  }
}

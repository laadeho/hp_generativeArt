/*Día 8 del hackpact de arte generativo
 Por Eduardo H Obieta
 http://artegenerativo.laad.com.mx 
 */

float pos1[ ];
float pos2[ ];
float velx[ ];
float vely[ ];
float col[ ];
int q = 2000;
void setup() {
  size(1600, 800, P3D);
  background(0);
  smooth();

  velx = new float[q];
  vely = new float[q];
  pos1= new float[q];
  pos2= new float[q];
  col = new float[q];

  for (int i=0; i<q; i++) {

    pos1[i]= random(width);
    pos2[i]= random(height);
    col[i]= random(255);
  }
}

void draw() {
  strokeWeight(0.75);
  for (int i=0; i<q; i++) {
    velx[i] = random(-5, 5);
    vely[i] = random(-5, 5);
    stroke(col[i]);
    point(pos1[i], pos2[i]);
    pos1[i]+=random(velx[i]);
    pos2[i]+=random(vely[i]);

    if ((pos1[i] >= width) || (pos1[i] <= 0)) {
      pos1[i] = random(width);
    }
    if ((pos2[i] >= height) || (pos2[i] <= 0)) {
      pos2[i] = random(height);
    }
  }
}
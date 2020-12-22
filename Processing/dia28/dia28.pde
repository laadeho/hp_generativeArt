//definiendo variables
//tipo    nombre de variable
float     incy, incx, inc1[], inc2[], px[], py[];
int       cant=10;

void setup() {
  size(1920, 1080);
  background(0);
  for (int i=0; i<cant; i++) {
    px= new float[cant];
    py= new float[cant];
    inc1= new float[cant];
    inc2= new float[cant];
  }
  for (int i=0; i<cant; i++) {
    px[i]=int(random(100, width-100));
    py[i]=int(random(100, height-100));
    inc1[i]= random(10, 15);
    inc2[i]= inc1[i];
  }
}

void draw() {
  frameRate(100);
  noStroke();
  fill(0, 5);
  rect(0, 0, width, height);
  stroke(255);
  fill(random(255), random(255), random(255));
  for (int i=0; i<cant; i++) {
    rect(px[i], py[i], 10, 10);
    px[i]+=incx+inc1[i];
    py[i]+=incy+inc2[i];

    if (px[i]>width) {
      inc1[i]=inc1[i]*-1;
    }
    if (px[i]<0) {
      inc1[i]=inc1[i]*-1;
    }

    if (py[i]>height) {
      inc2[i]=inc2[i]*-1;
    }
    if (py[i]<0) {
      inc2[i]=inc2[i]*-1;
    }
  }
  if (mousePressed) {
    saveFrame("GA_28.png");
    delay(500);
    exit();
  }
}
/*

 }
 
 void update() {
 if (px>width) {
 incx=random(10, 15);
 }
 if (px<0) {
 incx=random(-10, -15);
 }
 if (py>height) {
 incy=random(10, 15);
 }
 if (py<0) {
 incy=random(-10, -15);
 }
 }
 */

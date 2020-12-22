//artegenerativo27
PGraphics pg;
float px, py, incx, incy, pgpx, pgpy, pgincx, pgincy, pgdiam;
int ancho, alto;

void setup() {
  size(1920, 1080, P3D);
  background(0);
  ancho = 100;
  alto = 100;
  pg = createGraphics(ancho, alto, P3D);
  px=width/2; 
  py=height/2;
  incx=random(7, 15);
  incy=random(13, 15);
  pgpx=50; 
  pgpy=50;
  pgincx=random(2, 5);
  pgincy=random(2, 5);
  pgdiam=10;
}

void draw() {
  fill(0, 2);
  noStroke();
  rect(0, 0, width, height);
  px+=incx; 
  py+=incy;

  pg.beginDraw();
  pg.background(0, 0);
  pg.fill(255);
  pgpx+=pgincx;
  pgpy+=pgincy;

  if ((pgpx>pg.width-pgdiam)||(pgpx<pg.width-pg.width+pgdiam)) {
    pgincx*=-1;
  }
  if ((pgpy>pg.height-pgdiam)||(pgpy<pg.height-pg.height+pgdiam)) {
    pgincy*=-1;
  }
  pg.fill(255);
  pg.ellipse(pgpx, pgpy, pgdiam, pgdiam); 
  pg.noStroke();
  pg.fill(100, 100);
  //pg.rect(0, 0, width, height);
  pg.endDraw();

  image(pg, px, py);

  if ((px>width-ancho)||(px<0)) {
    incx*=-1;
  }

  if ((py>height-alto)||(py<0)) {
    incy*=-1;
  }
  if (mousePressed) {
    saveFrame("GA_27.png");
    delay(500);
    exit();
  }
}

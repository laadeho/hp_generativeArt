#ifndef _DIENTE2D
#define _DIENTE2D
#include "ofMain.h"

class Diente2d {
public:

	Diente2d();
	~Diente2d();

	void setup();
	void update();
	void draw();
	void dibujaBrazo();
	void dibujaCabeza();
	void dibujaCentro();

	float rad = PI / 180;
	float px = 0;
	float py = 0;
	int cuenta = 0;
	float cr, cg, cb;

	//variables 
	float px2 = 0, py2 = 0, lony2 = 40;
	int diam = 7;
	float px3 = 0, py3 = 0, diaca = 8;
	int nfi3 = 20; //número de filamentos
	float rfy3[20];
	float lony3[20];

	int nb = 18; //numero de brazos
	float rx[20]; //rotación de cada brazo
	//float lony4 = 40;

};
#endif
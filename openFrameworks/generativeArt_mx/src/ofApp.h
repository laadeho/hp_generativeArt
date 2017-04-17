#pragma once

#include "ofMain.h"
#include "Diente.h"
#include "Diente2D.h"
#include "PacMan.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// GLOBALES
		bool fondo = false, estado = true;
		int escena = 0;
		int iniciaTodo = false;

		// COMO SE DEFINEN ARRAYS
		// HP01
		int n = 50;
		float rota[50];
		float pos1[50];
		float pos2[50];
		float vel[50];
		float blx[50];
		float bly[50];
		// HP02
		float rotacActual = 0;
		float perlinPos = 0;
		float perlinVel = 0.1;
		// HP03
		float vel3 = 12;
		float movx = 0;
		float movy = 0.2;
		// HP04
		float noivel;
		float rota4 = 0;
		float dista4 = 0.1;
		// HP 05
		float alt1;
		float posi = 0.1;
		float dista = 1;
		float col = 55;
		float lado = 5;
		// HP 06
		int q6 = 10;
		float px6[10], py6[10], pz6[10], rad6[10], incx6[10], incy6[10], incz6[10], ancho75 = ofGetHeight()*0.75;
		// HP 07
		int q7 = 10;
		float px7[10], py7[10], incx7[10], incy7[10], ruix7[10], ruiy7[10];
		float vel7 = 10, sep7 = 0.1;
		// HP 08
		float pos18[2000], pos28[2000], velx8[2000], vely8[2000], col8[2000];
		int q8 = 2000;
		// HP 09
		int gota = 800, tmin = 1, tmax = 4;
		float px9[800], py9[800], vel9[800], dirx9[800], diry9[800], tam9[800], varia = 5;
		// HP 10
		int ca10 = 5;
		float vari10[5], rx10[5], ry10[5], rz10[5], distx10[5], multix10[5], multiy10[5], multiz10[5];
		// HP 11
		Diente diente;
		// HP 12
		Diente2d diente2d;
		// HP 13
		PacMan pacMan;
		// HP 14
		float px1, px2, pix, pfx, piy, pfy, piz, pfz, py1, py2, lim2, inc = 10;
		// HP 15
		int part = 300, part2 = 10;
		float cx, cy, radio = 1, radio2 = 1, radio3 = 1, piy15;
		float ang = TWO_PI / (float)part;
		// HP 16
		void evaluar();
		float pixT, piyT, pfxT, pfyT;
		int q = 100, s, opac = 255, comienza = 0;
		// HP 17
		int qlv = 7;
		int qlh = 8;
		int qlc = 5;
		float lcgros[5], lccol[5], lcpix[5], lcpiy[5], lcvel[5], lclong[5], ang17[5], radio17[5];
		float lhgros[8], lhcol[8], lhpix[8], lhpiy[8], lhincx[8], lhvel[8], lhlong[8];
		float lvgros[7], lvcol[7], lvpix[7], lvpiy[7], lvincy[7], lvvel[7], lvlong[7];
		// HP 18
		float di = 450, col18 = 0;
		// HP 19
		int part19 = 500; 
		float ang19 = 1, radio19[500], px19[500], py19[500], pz19[500], aleat[500], vcol19, rx19;
		bool inicia19 = false;
		// HP 20
		int nada;
		float px20 = 0, py20 = 0, opa20 = 0;
		// HP 21
		float px21 = 50, py21 = 80, inc21 = 16;
		int escoge21, lon21, renglon21, cambio21 = 0, brake21 = 0, s1, s2, s3, s4;
		string letras = "ab cdef ghi j k lmnop qrstquvwxyz1234567890";// = new String(abc);
		// HP 22
		bool env01 = true;
		int part23 = 1000;
		float px23[1000], py23[1000], velx23[1000], vely23[1000];
		// HP 24
		int pun24 = 800, s24, si24, inicia24;
		float dista24[800], px24[800], py24[800], pz24[800], ang24[800], vel24[800];
		// HP 25

		// HP 26
		ofFbo rec;

};
#ifndef _PACMAN
#define _PACMAN
#include "ofMain.h"

class PacMan {
public:

	PacMan();

	void setup();
	void update();
	void draw();
	void mono();

	float posx, posy, pas = 40, mur = 6, ang = 0, dirx = 0, diry = 0;
	int caso;

	float rad = PI / 180;
	float dx = pas / 2, dy = 0;
	int sact;
	int sant;
};

#endif
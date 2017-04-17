#include "PacMan.h"

PacMan::PacMan() {

}

void PacMan::setup() {
	posx = ofRandom(ofGetWidth());
	posy = ofRandom(ofGetHeight());
}

void PacMan::update() {
	posx += dirx;
	posy += diry;

	if (posx>ofGetWidth() + 50) {
		posx = 10;
	}
	else if (posx<-50) {
		posx = ofGetWidth() - 10;
	}
	else if (posy>ofGetHeight() + 50) {
		posy = 10;
	}
	else if (posy<-50) {
		posy = ofGetHeight() - 10;
	}
	switch (caso) {
	case 1:
		//println("derecha");
		dirx = 15;
		diry = 0;
		ang = 0;
		break;

	case 2:
		//println("abajo");
		dirx = 0;
		diry = 15;
		ang = 90;
		break;

	case 3:
		//println("izquierda");
		dirx = -15;
		diry = 0;
		ang = 180;
		break;
	case 4:
		//println("arriba");
		dirx = 0;
		diry = -15;
		ang = 270;
		break;
	}
}

void PacMan::draw() {
	ofSetColor(250, 240, 160, 100);
	ofFill();
	for (int i = 0; i<ofGetWidth(); i += 35) {
		for (int j = 0; j<ofGetHeight(); j += 35) {
			ofEllipse(20 + i, 20 + j, 3, 3);
		}
	}
	ofPushMatrix();
	ofTranslate(posx, posy);
	mono();
	ofPopMatrix();
}

void PacMan::mono() {
	int s = ofGetElapsedTimeMillis()/1000;
	int m = (int)ofGetElapsedTimeMillis();
	ofSetColor(250, 240, 60);
	ofFill();
	ofPushMatrix();
	ofEllipse(0, 0, pas - pas / 8, pas - pas / 8);
	ofSetColor(0);
	ofFill();
	ofRotate(ofRadToDeg(ang*rad));
	ofTriangle(0, 0, dx, dy, dx, -dy);
	ofPopMatrix();

	if (int(m*0.01) % 2 == 0) {
		dy = pas / 2;
	}
	else {
		dy = 0;
	}

}
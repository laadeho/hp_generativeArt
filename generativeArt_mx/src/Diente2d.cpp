#include "Diente2d.h"

Diente2d::Diente2d() {
}
Diente2d::~Diente2d() {
}

void Diente2d::setup() {
	for (int i = 0; i<nfi3; i++) {
		rfy3[i] = ofRandom(8, 12);
		lony3[i] = ofRandom(30, 40);
	}
}

void Diente2d::update() {
	for (int i = 0; i<nb; i++) { //posición de cada brazo
		rx[i] = ofRandom(15, 30)*rad;
	}
	float inc = ofRandom(0, 120);
	px2 += inc;

	if (px2>ofGetWidth()) {
		px2 = 1;
		cuenta = cuenta + 1;
	}
	//POSICIONES EN Y
	if (cuenta == 0) {
		py2 = ofGetHeight() - 4;
	}
	if (cuenta == 2) {
		py2 = ofGetHeight() - ofGetHeight() / 4;
	}

	if (cuenta == 4) {
		py2 = ofGetHeight() - ofGetHeight() / 2;
	}

	if (cuenta == 6) {
		py2 = ofGetHeight() - (ofGetHeight() / 4) * 3;
	}
	if (cuenta == 8) {
		cuenta = 0;
	}
	cr = ofRandom(150, 255);
	cg = ofRandom(150, 255);
	cb = ofRandom(150, 255);
}

void Diente2d::draw() {
	ofPushStyle();
	ofSetColor(255);
	//stroke(255);
	ofSetLineWidth(2);
	//strokeWeight(2);
	ofLine(0, py2, ofGetWidth(), py2);
	ofTranslate(px2, py2);
	float esc = ofRandom(0.05, 0.25);
	ofScale(esc, esc, 1);
	dibujaCentro();
	ofPopStyle();
}

void Diente2d::dibujaBrazo() {
		ofPushMatrix();
		ofTranslate(0, py3 - 2 * lony2 + (-lony2*1.5 / 2));
		dibujaCabeza();
		ofSetColor(cr, cg, cb, 210);
		ofNoFill();
//		stroke(cr, cg, cb, 210);
		ofSetLineWidth(1);// strokeWeight(2);
		ofLine(px3, py3, px3, py3 + 2 * lony2);
		ofPushMatrix();
		ofTranslate(0, 2 * lony2);
		ofSetColor(cr, cg, cb);
		//noStroke();
		ofFill();
		ofEllipse(px3, py3, lony2 / 10, lony2 / 10);
		ofPopMatrix();
		ofPopMatrix();
}

void Diente2d::dibujaCabeza() {
	// noStroke();
	ofSetColor(cr, cg, cb);
	ofFill();
	ofEllipse(0, 0, 8, 8);
	ofSetColor(cr,cg,cb);
	//stroke(cr, cg, cb);
	ofNoFill();
	ofSetLineWidth(0.5);
	ofPushMatrix();
	ofRotate(ofRadToDeg(-65 * rad));
	for (int i = 0; i<nfi3; i++) {
		ofRotate(ofRadToDeg(8 * rad));
		ofPushMatrix();
		ofLine(px, py, px, -lony3[i]);
		ofPopMatrix();
	}
	ofPopMatrix();
}

void Diente2d::dibujaCentro() {
	ofPushMatrix();
	ofTranslate(0, -200);
	ofScale(0.5f, 0.5f, 1.0f);
	//noStroke();
	ofSetColor(cr, cg, cb);
	ofFill();
	ofEllipse(0, 0, lony2*1.5, lony2*1.5);
	ofSetColor(cr, cg, cb);
	ofNoFill();
	ofPushMatrix();
	for (int i = 0; i<nb; i++) {
		ofRotate(ofRadToDeg(rx[i]));
		dibujaBrazo();
	}
	ofPopMatrix();
	ofSetColor(cr, cg, cb);
	ofNoFill();
	ofSetLineWidth(2);
	ofLine(0, 0, 0, 10 * lony2);
	ofPopMatrix();
}
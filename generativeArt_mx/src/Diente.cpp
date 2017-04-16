#include "Diente.h"

Diente::Diente() {
}
Diente::~Diente() {
}

void Diente::setup() {
	for (int i = 0; i<nfi; i++) {
		rfy[i] = ofRandom(8, 12);
		lonyc[i] = ofRandom(30, 40);
	}
	for (int i = 0; i<nb; i++) { //posición de cada brazo
		rx[i] = ofRandom(360 * rad);
		ry[i] = ofRandom(360 * rad);
		rz[i] = ofRandom(360 * rad);
	}
}

void Diente::update() {

}

void Diente::draw() {
	ofLight();
	
	ofPushStyle();
	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//ofRotateZ(ofRadToDeg(5));
	ofRotateY(ofGetFrameNum()*0.2);
	dibuja();
	ofPopStyle();
}

void Diente::dibuja() {
	//noStroke();
	ofSetColor(250, 230, 190);
	ofFill();
	ofSphere(lony*1.5 / 2);
	//stroke(255);
	ofPushMatrix();
	for (int i = 0; i<nb; i++) {
		ofRotateX(ofRadToDeg(rx[i]));
		ofRotateY(ofRadToDeg(ry[i]));
		ofRotateZ(ofRadToDeg(rz[i]));
		dibujaBrazo();
	}
	ofPopMatrix();
	//stroke(200);
	//strokeWeight(8);
	ofSetColor(200);
	ofNoFill();
	ofSetLineWidth(8);
	ofLine(0, 30, 0, 0, 12 * lony, 0);
}

void Diente::dibujaBrazo() {
	ofPushMatrix();
	ofTranslate(0, py - 2 * lony + (-lony*1.5 / 2));
	dibujaCabeza();
	//stroke(220, 210);
	ofSetColor(220, 210);
	ofNoFill();
	ofSetLineWidth(2);
	//strokeWeight(2);
	ofLine(px, py, px, py + 2 * lony);
	ofPushMatrix();
	ofTranslate(0, 2 * lony);
	//noStroke();
	ofSetColor(250, 230, 190, 100);
	ofFill();
	ofSphere(lony / 10);
	ofPopMatrix();
	ofPopMatrix();
}
void Diente::dibujaCabeza() {
	//noStroke();
	ofSetColor(250, 230, 190);
	ofFill();
	ofSphere(diaca / 2);
	ofSetColor(255,80);
	ofNoFill();
	//stroke(255, 80);
	//strokeWeight(0.5);
	ofPushMatrix();
	for (int i = 0; i<nfi; i++) {
		ofRotateY(ofRadToDeg(rfy[i] * rad));
		ofPushMatrix();
		ofRotateZ(ofRadToDeg(65 * rad));
		ofLine(pxc, pyc, pxc, -lonyc[i]);
		ofPopMatrix();
	}
	ofPopMatrix();
}
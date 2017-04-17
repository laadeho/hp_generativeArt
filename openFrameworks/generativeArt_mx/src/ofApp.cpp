#include "ofApp.h"
#include "Diente.h"
#include "Diente2D.h"
#include "PacMan.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetBackgroundAuto(false);
	ofSetFrameRate(60);

	ofEnableSmoothing();

	for (int i = 0; i<n; i++) {
		vel[i] = ofRandom(0.05);
		pos1[i] = ofRandom(ofGetWidth() / 2);
		pos2[i] = ofRandom(ofGetHeight() / 2);
	}
	// HP 06
	for (int i = 0; i<q6; i++) {
		//posiciones iniciales
		px6[i] = ofRandom(ancho75);
		py6[i] = ofRandom(ancho75);
		pz6[i] = ofRandom(ancho75);
		//tamaño
		rad6[i] = ofRandom(2, 4);
		//incrementos
		incx6[i] = ofRandom(7.5);
		incy6[i] = ofRandom(7.5);
		incz6[i] = ofRandom(7.5);
	}
	// HP 07
	for (int i = 0; i < q7; i++) {
		px7[i] = ofRandom(100, ofGetWidth() - 100);
		py7[i] = ofRandom(100, ofGetHeight() - 100);
		incx7[i] = ofRandom(-sep7, sep7)*vel7;
		incy7[i] = ofRandom(-sep7, sep7)*vel7;
	}
	// HP 08
	for (int i = 0; i<q8; i++) {
		pos18[i] = ofRandom(ofGetWidth());
		pos28[i] = ofRandom(ofGetHeight());
		col8[i] = ofRandom(255);
	}
	// HP 09
	for (int p = 0; p<gota; p++) {
		px9[p] = ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2);
		py9[p] = ofRandom(-ofGetHeight() / 2, ofGetHeight() / 2);
		vel9[p] = ofRandom(tmin, tmax - 2);
		tam9[p] = ofRandom(tmin, tmax);
	}
	// HP 10
	for (int i = 0; i<ca10; i++) {
		rx10[i] = ofRandom(-180, 180);
		ry10[i] = ofRandom(-180, 180);
		rz10[i] = ofRandom(-180, 180);
		distx10[i] = ofRandom(450, 600);
		multix10[i] = ofRandom(0.01, 0.06);
		multiy10[i] = ofRandom(0.01, 0.06);
		multiz10[i] = ofRandom(0.01, 0.06);
	}
	// HP 11
	diente.setup(); 
	// HP 12
	diente2d.setup();
	// HP 13
	pacMan.setup();
	// HP 14
	int lim = ofGetWidth() / 2, lim2 = ofGetHeight() / 3;
	pix = ofRandom(-lim, lim);
	pfx = ofRandom(-lim, lim);
	piy = ofRandom(-lim, lim);
	pfy = ofRandom(-lim, lim);
	piz = ofRandom(-lim, lim);
	pfz = ofRandom(-lim, lim);
	// HP 16
	pixT = ofRandom(ofGetWidth());
	piyT = ofRandom(ofGetHeight());
	pfxT = ofRandom(ofGetWidth() - pixT);
	pfyT = ofRandom(ofGetHeight() - piyT);
	// HP 17
	for (int i = 0; i<qlc; i++) {
		ang17[i] = ofRandom(ofDegToRad(360));
		lclong[i] = ang17[i] * 2;
		radio17[i] = ofRandom(5, 200);
		lcpix[i] = ofRandom(ofGetWidth());
		lcpiy[i] = ofRandom(ofGetHeight());
		lccol[i] = ofRandom(100, 255);
		lcgros[i] = ofRandom(0.75, 2);
		lcvel[i] = ofRandom(0.005, 0.03);
	}
	for (int i = 0; i<qlh; i++) {
		lhpix[i] = ofRandom(ofGetWidth());
		lhpiy[i] = ofRandom(ofGetHeight());
		lhcol[i] = ofRandom(100, 255);
		lhgros[i] = ofRandom(0.5, 3);
		lhvel[i] = ofRandom(0.1, 3);
		lhlong[i] = ofRandom(ofGetHeight() / 10, ofGetHeight() / 2);
	}
	for (int i = 0; i<qlv; i++) {
		lvpix[i] = ofRandom(ofGetWidth());
		lvpiy[i] = ofRandom(ofGetHeight());
		lvcol[i] = ofRandom(100, 255);
		lvgros[i] = ofRandom(0.4, 3);
		lvvel[i] = ofRandom(0.8, 1.5);
		lvlong[i] = ofRandom(ofGetHeight() / 10, ofGetHeight() / 2);
	}
	// HP 18
	vcol19 = ofRandom(20);
	rx19 = ofRandom(250, 300);
	for (int i = 0; i<part; i++) {
		px19[i] = ofRandom(500);
		py19[i] = ofRandom(500);
		aleat[i] = ofRandom(-90, 90);
		radio19[i] += i*0.99;
	}
	// HP 21
	s1 = int(ofRandom(3, 15));
	s2 = int(ofRandom(3, 15));
	s3 = int(ofRandom(3, 15));
	s4 = int(ofRandom(3, 15));
	lon21 = letras.length();
	// HP 22
	for (int i = 0; i<part23; i++) {
		px23[i] = ofGetWidth() / 2;
		py23[i] = ofGetHeight() / 2;
		velx23[i] = ofRandom(-1.5, 1.5);
		vely23[i] = ofRandom(-1.5, 1.5);
	}
	// HP 26
	rec.allocate(400, 400, GL_RGBA);

}


//--------------------------------------------------------------
void ofApp::update(){
	if (escena == 0) {
		for (int i = 0; i<n; i++) {
			ofRotate(-rota[i]);
			blx[i] = ofNoise(pos1[i]) * 300;
			bly[i] = ofNoise(pos2[i]) * 300;
			rota[i] += 0.05;
			pos1[i] += vel[i];
			pos2[i] += vel[i];
		}
	}
	else if (escena == 4) {
		alt1 = ofNoise(posi+col);
		alt1 = ofMap(alt1, 0, 1, 0, ofGetHeight());
		if (posi > ofGetWidth()) {
			posi = 0;
			col = ofRandom(220);
		}
	}
	else if (escena == 7) {
		for (int i = 0; i < q8; i++) {
			velx8[i] = ofRandom(-5, 5);
			vely8[i] = ofRandom(-5, 5);

			pos18[i] += ofRandom(velx8[i]);
			pos28[i] += ofRandom(vely8[i]);

			if ((pos18[i] >= ofGetWidth()) || (pos18[i] <= 0)) {
				pos18[i] = ofRandom(ofGetWidth());
			}
			if ((pos28[i] >= ofGetHeight()) || (pos28[i] <= 0)) {
				pos28[i] = ofRandom(ofGetHeight());
			}
		}
	}
	else if (escena == 8) {
		float m = ofMap(mouseX, 0, ofGetWidth(), -4, 4);
		for (int i = 0; i < gota - 1; i++) {
			vel9[i] = 1 + mouseY*0.003;
			px9[i] += dirx9[i];
			py9[i] += vel9[i];
			dirx9[i] = m*ofNoise(varia)*1.5;
			if (px9[i]>ofGetWidth() / 2) {
				px9[i] = -ofGetWidth() / 2 + ofRandom(0.01, 2);
			}
			if (px9[i]<-ofGetWidth() / 2) {
				px9[i] = ofGetWidth() / 2 - ofRandom(0.01, 2);
			}
			if (py9[i]>ofGetHeight() / 2) {
				py9[i] = -ofGetHeight() / 2 + ofRandom(0.01, 2);
				px9[i] = ofRandom(-ofGetWidth() / 2, ofGetWidth() / 2);
			}
			if (py9[i]<-ofGetHeight() / 2) {
				py9[i] = ofGetHeight() / 2 - ofRandom(0.01, 2);
			}
		}
	}
	else if (escena == 11) {
		diente2d.update();
	}
	else if (escena == 12) {
		pacMan.update();
	}
	else if (escena == 13) {
		if (px1>lim2) {
			px1 = 0;
			px2 = 0;
			pix = ofRandom(-500, 500);
			pfx = ofRandom(-500, 500);
			piy15 = ofRandom(-500, 500);
			pfy = ofRandom(-500, 500);
			piz = ofRandom(-500, 500);
			pfz = ofRandom(-500, 500);
		}
		px1 += inc;
		px2 += inc;
	}
	else if (escena == 16) {
		// Curvo
		for (int i = 0; i < qlc; i++) {
			ang17[i] += lcvel[i];
			if (ang17[i] > lclong[i]) {
				ang17[i] = 0;
				lcpix[i] = ofRandom(ofGetWidth());
				lcpiy[i] = ofRandom(ofGetHeight());
				ang17[i] = ofRandom(ofDegToRad(360));
				lclong[i] = ang17[i] * 2;
				radio17[i] = ofRandom(5, 200);
			}
		}
		// Horizontal
		for (int i = 0; i<qlh; i++) {
			if (lhincx[i] >= lhlong[i]) {
				lhincx[i] = 0;
				lhlong[i] = ofRandom(ofGetHeight() / 10, ofGetHeight() / 2);
				lhpix[i] = ofRandom(ofGetWidth());
				lhpiy[i] = ofRandom(ofGetHeight());
			}
			lhincx[i] += lhvel[i];
		}
		// Vertical
		for (int i = 0; i<qlv; i++) {
			if (lvincy[i] >= lvlong[i]) {
				lvincy[i] = 0;
				lvlong[i] = ofRandom(ofGetHeight() / 10, ofGetHeight() / 2);
				lvpix[i] = ofRandom(ofGetWidth());
				lvpiy[i] = ofRandom(ofGetHeight());
			}
			lvincy[i] += lvvel[i];
		}

	}
	else if (escena == 17) {
		col18 += 1;
		di -= ofNoise(ofGetElapsedTimef());
		if (di <= 15) {
			di += 150;
		}
		if (col18 >= 90) {
			col18 = 0;
		}
	}
	else if (escena == 18) {
		for (int i = 0; i < part19; i++) {
			px19[i] = cos(ang19*aleat[i])*radio19[i] + ofNoise(50);
			py19[i] = sin(-ang19*aleat[i])*radio19[i];
			pz19[i] = pz19[i] + sin(60);
			pz19[i] += 0.001;
			radio19[i] += 0.25;

			if (pz19[i] < -600) {
				pz19[i] = 0;
				ang19 = 1;
				rx19 = ofRandom(250, 300);
				vcol19 = ofRandom(20);
				radio19[i] += 0.1;
			}
		}
		ang19 += 0.001;
		vcol19 += 0.01;
	}
	else if (escena == 19) {
		opa20 += 0.1;
	}
	else if (escena == 20) {
		px21 += inc21;
		if (px21>ofGetWidth() * 2 - 50) {
			px21 = 60;
			py21 = py21 + 60 + brake21;
			renglon21 = renglon21 + 1;
		}
		brake21 = 0;
		// cout << ", letra: " << escoge21;
		if (py21>ofGetHeight()* 2) {
			px21 = 50, py21 = 80, inc21 = 16;
			renglon21 = 0, cambio21 = 0, brake21 = 0;
			s1 = int(ofRandom(3, 15));
			s2 = int(ofRandom(3, 15));
			s3 = int(ofRandom(3, 15));
			s4 = int(ofRandom(3, 15));
			fondo = true;
		}
		if (s1 == renglon21) {
			brake21 = 60;
		}
		if (s2 == renglon21) {
			brake21 = 60;
		}
		if (s3 == renglon21) {
			brake21 = 60;
		}
		if (s4 == renglon21) {
			brake21 = 60;
		}
		escoge21 = int(ofRandom(lon21));
	}

	else if (escena == 22) {
		for (int i = 0; i<part23; i++) {
			px23[i] += velx23[i];
			py23[i] += vely23[i];
			if ((py23[i]>ofGetHeight()) || (px23[i]>ofGetWidth()) || (py23[i]<0) || (px23[i]<0)) {
				py23[i] = ofGetMouseY();
				vely23[i] = ofRandom(-0.5, 0.5)*ofNoise(10) * 10;
				px23[i] = ofGetMouseX();
				velx23[i] = ofRandom(-0.5, 0.5)*ofNoise(10) * 10;
				px23[i] += velx23[i] * 2;
				py23[i] += vely23[i] * 2;
			}
		}
	}
	else if (escena == 23) {
		s24 = ofGetElapsedTimeMillis() / 1000;
		for (int i = 0; i<pun24; i++) {
			if (s24 >= si24 + 3) {
				inicia24 = 1;
			}
			if (inicia24 == 1) {
				vel24[i] = ofRandom(0.000001, 0.000002);
				ang24[i] += i*vel24[i];
				py24[i] = sin(ofRadToDeg(ang24[i])) * 200;
				pz24[i] = cos(ofRadToDeg(ang24[i])) * 200;
			}
		}
	}

	escena = escena % 26;
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (!iniciaTodo) {
		ofDrawBitmapString("OPRIME s PARA INICIAR", ofGetWidth() / 2, ofGetHeight() / 2);
		ofDrawBitmapString("Oprime mouse para cambiar escenas", ofGetWidth() / 2, 50+ofGetHeight() / 2);

	}
		
	if (!estado && iniciaTodo) {
		if (escena == 0) {
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			//ofNoFill();
			ofSetColor(255);
			ofRotateZ(ofGetElapsedTimeMillis()*0.1);
			for (int i = 0; i < n; i++) {
				ofPoint(blx[i], bly[i]);
				ofEllipse(blx[i], bly[i], 1, 1);
			}
		}
		else if (escena == 1) {
			//ofSetColor(255, 0.1);
			//ofFill();
			//ofBox(150, 150, 150);
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2, -200);

			float modifica = ofNoise(perlinPos) * 50;
			ofTranslate(0, -100);
			float transporta = ofNoise(perlinPos*perlinVel) * 400;
			float escala = ofNoise(transporta) * 150;

			ofPushMatrix();
			// rotateX(noise(rotacActual)*3);
			ofRotateY(rotacActual*0.6);
			ofRotateZ(rotacActual);
			ofTranslate(0, transporta);
			ofSetColor(255, 70);
			ofNoFill();
			//		stroke(255, 100);

			float val1 = -400 + escala;
			float val2 = 400 - escala + modifica;
			ofDrawLine(val1, 0, val2, 0);

			//noStroke();
			ofSetColor(255);
			ofFill();
			ofPushMatrix();
			ofTranslate(val1, 0);
			ofSphere(2.5);
			ofPopMatrix();

			ofPushMatrix();
			ofTranslate(val2, 0);
			ofBox(5, 5, 5);
			ofPopMatrix();
			ofPopMatrix();

			perlinPos += perlinVel;
			rotacActual += 0.25;
		}
		else if (escena == 2) {
			if (ofGetFrameNum() % 3 == 0) {
				//noStroke();
				//ofColor(255, 2);
				//ofFill();
				//ofRect(0, 0, ofGetWidth(), ofGetHeight());

				float col = ofRandom(30, 60);
				float tamx = ofRandom(10, 40);
				float tamy = ofRandom(10, 40);
				float incx = ofNoise(vel3);

				movx += vel3 + incx;

				movy = ofRandom(ofGetHeight());

				ofSetColor(255, 50);
				ofFill();
				ofRect(movx, movy, tamx, tamy);


				ofSetColor(255, ofRandom(100));
				ofNoFill();

				ofLine(0, 0, movx, movy);
				ofLine(ofGetWidth(), 0, movx + tamx, movy);
				ofLine(ofGetWidth(), ofGetHeight(), movx + tamx, movy + tamy);
				ofLine(0, ofGetHeight(), movx, movy + tamy);

				ofPushMatrix();
				ofTranslate(movx + (tamx / 2), movy + (tamy / 2));
				ofLine(-10, 0, 10, 0);
				ofLine(0, -10, 0, 10);
				ofPopMatrix();

				if ((movx > ofGetWidth()) || (movx < 0)) {
					vel3 = vel3 * -1;
				}
			}
		}
		else if (escena == 3)
		{
			noivel = ofNoise(dista4) * 800;
			//noStroke();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			ofSetColor(255, 5);
			ofFill();
			ofSetColor(200, 60);
			ofNoFill();
			//setStrokeWidth(0.2);
			//strokeWeight(0.2);			

			ofRotate(rota4);

			float maxdis = ofGetHeight()*0.8;

			ofLine(noivel, 0, maxdis, 0);
			ofLine(noivel*0.6, 0, noivel*0.25, 0);
			//noStroke();
			ofSetColor(255);
			ofFill();
			ofEllipse(noivel*0.25, 0, 1, 1);
			ofEllipse(noivel*0.6, 0, 1, 1);
			ofSetColor(ofRandom(255));
			ofFill();
			ofEllipse(maxdis, 0, 2, 2);
			rota4 += 0.5;
			dista4 += 2;
			//ofLogNotice() << "noivel: " << noivel;
		}
		else if (escena == 4)
		{
			ofSetColor(150, 50);
			ofNoFill();
			ofLine(posi, 0, posi, ofGetHeight());
			ofSetColor(col, 255);
			ofFill();
			ofRect(-lado / 2 + posi, (-lado / 2) + alt1, lado, lado);
			posi += 5;
			dista++;
		}
		else if (escena == 5) {
			ofTranslate((ofGetWidth() / 2), 0, -ofGetHeight()*0.80);
			ofRotateX(-0.5);
			ofRotateY(0.05*ofGetElapsedTimeMillis()*0.5);
			ofSetColor(255, 20);

			ofNoFill();
			//strokeWeight(0.15);
			ofLine(0, 0, 0, ancho75, 0, 0);
			ofLine(0, 0, 0, 0, ancho75, 0);
			ofLine(0, 0, 0, 0, 0, ancho75);
			ofLine(0, 0, ancho75, 0, ancho75, ancho75);
			ofLine(0, ancho75, 0, 0, ancho75, ancho75);
			ofLine(0, ancho75, 0, ancho75, ancho75, 0);
			ofLine(0, ancho75, ancho75, ancho75, ancho75, ancho75);
			ofLine(0, 0, ancho75, ancho75, 0, ancho75);
			ofLine(ancho75, 0, ancho75, ancho75, 0, 0);
			ofLine(ancho75, ancho75, 0, ancho75, 0, 0);
			ofLine(ancho75, 0, ancho75, ancho75, ancho75, ancho75);
			ofLine(ancho75, ancho75, 0, ancho75, ancho75, ancho75);

			//noStroke();
			ofSetColor(ofRandom(255));
			ofFill();
			for (int p = 0; p < q6; p++) {

				ofPushMatrix();
				ofTranslate(px6[p], py6[p], pz6[p]);
				ofSphere(rad6[p]);
				ofPopMatrix();

				px6[p] += incx6[p];
				py6[p] += incy6[p];
				pz6[p] += incz6[p];

				if ((px6[p] > ancho75) || (px6[p] < 0)) {
					incx6[p] = incx6[p] * -1;
				}
				if ((py6[p] > ancho75) || (py6[p] < 0)) {
					incy6[p] = incy6[p] * -1;
				}
				if ((pz6[p] > ancho75) || (pz6[p] < 0)) {
					incz6[p] = incz6[p] * -1;
				}
			}
		}
		else if (escena == 6) {
			for (int i = 0; i < q7; i++) {
				//noStroke();
				ofSetColor(20);
				ofFill();
				ofEllipse(px7[i], py7[i], 4, 4);
				px7[i] += incx7[i] * ruix7[i];
				py7[i] += incy7[i] * ruiy7[i];
				ruix7[i] = ofNoise(px7[i]) * 3;
				ruiy7[i] = ofNoise(py7[i]) * 3;
			}
			//stroke(50, 0, 50, 50);
			ofSetColor(50, 0, 50, 50);
			ofNoFill();
			for (int i = 0; i < q7 - 1; i++) {
				ofLine(px7[i], py7[i], px7[i + 1], py7[i + 1]);
			}
			//stroke(50, 50, 50, 20);
			ofSetColor(50, 50, 50, 20);
			ofNoFill();
			ofLine(px7[0], py7[0], px7[q7 - 1], py7[q7 - 1]);

			for (int l = 0; l < q7; l++) {
				if ((px7[l] >= ofGetWidth() - 2) || (px7[l] <= 2)) {
					incx7[l] = -incx7[l];
				}
				if ((py7[l] > ofGetHeight() - 2) || (py7[l] <= 2)) {
					incy7[l] = -incy7[l];
				}
			}
		}
		else if (escena == 7) {
			//strokeWeight(0.75);
			for (int i = 0; i < q8; i++) {
				ofSetColor(col8[i]);
				ofNoFill();
				//stroke(col8[i]);
				//ofPoint(pos18[i], pos28[i],0);
				ofEllipse(pos18[i], pos28[i], 1.5, 1.5);
			}
		}
		else if (escena == 8) {
			//trasladar
			ofPushMatrix();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			//noStroke();
			ofSetColor(0);
			ofFill();
			ofRect(-ofGetWidth() / 2, -ofGetHeight() / 2, ofGetWidth(), ofGetHeight());
			for (int i = 0; i < gota - 1; i++) {
				ofSetColor(255, 40 + ofRandom(tmax * 15));
				ofFill();
				//ofSetLineWidth(tam9[i]*10);
				//strokeWeight(tam[i]);
				//ofPoint(px9[i], py9[i]);
				ofEllipse(px9[i], py9[i], tam9[i], tam9[i]);
			}
			ofSetColor(255, 80);
			//stroke(255, 45);
			ofNoFill();
			//strokeWeight(1.25);
			ofSetLineWidth(2);
			for (int i = 0; i < gota / 60 - 1; i++) {
				ofLine(px9[i], py9[i], px9[i + 1], py9[i + 1]);
			}
			ofLine(px9[0], py9[0], px9[gota / 60 - 1], py9[gota / 60 - 1]);
			ofPopMatrix();
		}
		else if (escena == 9) {
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			for (int i = 0; i < ca10; i++) {

				vari10[i] = 150 + ofNoise(distx10[i]) * 30;
				ofRotateX(rx10[i] + ofGetElapsedTimeMillis()*multix10[i]);
				ofRotateY(ry10[i] + ofGetElapsedTimeMillis()*multiy10[i]);
				ofRotateZ(rz10[i] + ofGetElapsedTimeMillis()*multiz10[i]);
				//stroke(121, 87, 9);
				ofSetColor(121, 87, 9);
				//strokeWeight(1);
				ofSetLineWidth(1);
				//ofPoint(vari10[i], 0);
				ofEllipse(vari10[i], 0, 1, 1);
				//strokeWeight(0.1);
				ofSetLineWidth(0.5);
				//stroke(121, 87, 9, 20);
				ofSetColor(121, 87, 9, 50);
				ofNoFill();
				ofLine(vari10[i], 0, 100, 0);
				distx10[i] += 0.1;
			}

		}
		else if (escena == 10) {
			ofBackground(0);
			ofPushMatrix();
			diente.draw();
			ofPopMatrix();
		}
		else if (escena == 11) {
			diente2d.draw();
		}
		else if (escena == 12) {
			pacMan.draw();
		}
		else if (escena == 13) {
			ofPushMatrix();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			ofSetColor(255, ofRandom(40, 60));
			ofNoFill();
			ofSetLineWidth(0.5f);
			ofBeginShape();
			ofVertex(pix, piy15, piz);
			ofBezierVertex(px1, px1, px2, px1, px1, px2, pfx, pfy, pfz);
			ofEndShape();
			//ofSetLineWidth(4);
			ofSetColor(255);
			ofFill();
			ofEllipse(pix, piy15, piz, 4, 4);
			ofEllipse(pfx, pfy, pfz, 4, 4);
			ofPopMatrix();
		}
		else if (escena == 14) {
			ofPushMatrix();
			ofPushStyle();
			ofSetColor(255);
			ofNoFill();
			ofSetLineWidth(0.5);
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			ofEllipse(0, 0, 1, 1);
			ofSetColor(223, 235);
			ofNoFill();
			ofRotateX(ofRadToDeg(-20));
			for (int i = 0; i < part; i++) {
				for (int s = 0; s < radio / 30; s += 40) {
					ofEllipse(radio*sin(ang*i) + s, radio*cos(ang*i) + s, 1, 1);
					ang += i;
					radio += 0.01;
				}
			}
			for (int i = 0; i < part2; i++) {
				ofEllipse(radio2*sin(ang*i), radio2*cos(ang*i), 1.5, 1.5);
				// ang+=i+1.5;
				radio2 += 5;
			}
			for (int i = 0; i < part / 30; i++) {
				ofEllipse(radio3*sin(ang*i), radio3*cos(ang*i), sin(i), 2, 2);
				// ang+=i+1.5;
				radio3 += 1;
			}
			for (int i = 0; i < part / 100; i++) {
				ofEllipse(radio3*sin(ang*i), radio3*cos(ang*i), sin(i), 3, 3);
			}
			ofPopStyle();
			ofPopMatrix();
		}
		else if (escena == 15) {
			ofSetColor(0, 0, 200, 10);
			ofFill();
			//noStroke();
			ofRect(0, 0, ofGetWidth(), ofGetHeight());
			ofSetColor(255, opac);
			ofFill();
			if (comienza == 0) {
				ofPushMatrix();
				ofScale(0.4f, 0.4f, 1.0f);
				ofDrawBitmapString("Se ha encontrado un problema y Windows ha sido apagado para evitar daños al equipo.", 100, 70);
				ofDrawBitmapString("Si esta es la primera vez que ve esta pantalla de error de detección, reinicie su equipo.", 100, 140);
				ofDrawBitmapString("Si esta pantalla aparece otra vez, siga los siguientes pasos:", 100, 210);
				ofDrawBitmapString("Compruebe que tiene el espacio en disco adecuado. Si un controlador está identificado en el mensaje de detención,", 100, 280);
				ofDrawBitmapString("deshabilite el controlador o pregunte al fabricante por controladores actualizados. Pruebe a cambiar los adaptadores de video.", 100, 350);
				ofDrawBitmapString("Compruebe con su proveedor de hardware si existen actualizaciones de la BIOS.", 100, 420);
				ofDrawBitmapString("Deshabilite las opciones de memoria de la BIOS como caché o vigilancia.", 100, 490);
				ofDrawBitmapString("Si necesita usar el modo a prueba de fallos para eliminar o deshabilitar componentes, reinicie su equipo,", 100, 560);
				ofDrawBitmapString("presione la tecla F8 para seleccionar opciones de inicio avanzadas y seleccione el modo a prueba de errores.", 100, 630);
				ofDrawBitmapString("Información técnica:", 100, 700);
				ofDrawBitmapString("*** STOP: 0x0000008E (0x0000005, 0x8052BA34, 0xA89EAFEA, 0x00000000)", 100, 770);
				ofDrawBitmapString("Empezando el volcado de memoria física", 100, 840);
				ofScale(1.2f, 1.2f, 1);
				ofDrawBitmapString("Pulse TAB para iniciar", 100, 840);
				ofPopMatrix();
			}
			else if (comienza == 1) {
				if (s % 5 == 0) {
					opac -= 10;
					evaluar();
					ofSetColor(0, 0, 150);
					//stroke(0, 0, 150);
					ofSetLineWidth(2);
					//ofPoint(pixT, piyT);
					ofEllipse(pixT, piyT, 1, 1);
					ofSetColor(255, 10);
					ofFill();
					ofRect(pixT, piyT, pfxT, pfyT);
					for (int i = 0; i < 30; i++) {
						ofRect(pixT + i, piyT + i, pfxT - i, pfyT - i);
					}
					ofSetLineWidth(2);
					ofSetColor(120, 100);
					ofNoFill();
					ofRect(pixT, piyT, pfxT, pfyT);
					ofSetColor(255);
					ofFill();
					ofDrawBitmapString("error", pixT + 50, piyT + 20);
					// TACHE
					ofSetColor(0);
					ofNoFill();
					ofSetLineWidth(1.2f);
					ofLine(pixT + 7, piyT + 7, pixT + 22, piyT + 22);
					ofLine(pixT + 7, piyT + 22, pixT + 22, piyT + 7);
					ofSetColor(100);
					ofFill();
					ofRect(pixT + 5, piyT + 5, 20, 20);
				}
				s = s + ofGetElapsedTimeMillis() / 1000;
			}
		}
		else if (escena == 16) {
			//CURVAS 
			for (int i = 0; i < qlc; i++) {
				ofSetColor(lccol[i], lccol[i]);
				ofFill();
				ofPushMatrix();
				ofTranslate(lcpix[i], lcpiy[i]);
				ofEllipse(cos(ang17[i])*radio17[i], sin(ang17[i])*radio17[i], lcgros[i], lcgros[i]);
				ofPopMatrix();
			}
			// HORIZONTAL
			for (int i = 0; i < qlh; i++) {
				ofSetColor(lhcol[i], lhcol[i]);
				ofFill();
				ofEllipse(lhpix[i] + lhincx[i], lhpiy[i], lhgros[i], lhgros[i]);
			}
			// VERTICAL
			for (int i = 0; i < qlv; i++) {
				ofSetColor(lvcol[i], lvcol[i]);
				ofFill();
				ofEllipse(lvpix[i], lvpiy[i] + lvincy[i], lvgros[i], lvgros[i]);
			}
		}
		else if (escena == 17) {
			ofPushMatrix();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			//pointLight(1, 1, 1, 0, 0, 0);
			//pointLight(1, 1, 1, -width / 4, -height / 4, 0);
			int millis = ofGetElapsedTimeMillis();
			ofRotateX(ofRadToDeg(ofGetMouseX() / 200 + 5 * millis*0.0001));
			ofRotateY(ofRadToDeg(ofGetMouseY() / 100 + 3.5*millis*0.0001));
			ofSetLineWidth(ofRandom(1, 2));
			ofSetColor(100 + sin(col18), col18, col18, 8);
			ofNoFill();
			for (int x = -ofGetHeight() / 2; x < ofGetHeight() / 2; x += di * 2) {
				for (int y = -ofGetHeight() / 8; y < ofGetHeight() / 8; y += di * 4) {
					ofRotateZ(ofRadToDeg(di * 8 * PI));
					ofBox(x - di, x - di, x - di);
				}
			}
			ofPopMatrix();
		}
		else if (escena == 18) {
			ofPushStyle();
			ofPushMatrix();
			ofRotateX(-70);
			ofTranslate(0, rx19*.5, 0);

			ofSetColor((1 + sin(vcol19)) * 100, (1 + cos(vcol19*0.7)) * 100, (1.3 + sin(vcol19)) * 100, 50);
			//strokeWeight(1);
			ofPushMatrix();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			for (int i = 0; i < part19; i++) {
				ofEllipse(px19[i], py19[i], pz19[i], 1, 1);
			}
			ofPopMatrix();
			ofPopMatrix();
			ofPopStyle();
		}
		else if (escena == 19) {
			if(inicia19){
				ofPushMatrix();
				ofPushStyle();
				//ofSetLineWidth(5);
				ofSetColor(0, 25);
				ofFill();
				for (int x = 0; x <= ofGetWidth(); x += 5) {
					for (int y = 0; y <= ofGetHeight(); y += 5) {
						ofEllipse(px20 + ofNoise(x)*ofRandom(ofGetWidth() * 2), py20 + ofNoise(y)*ofRandom(ofGetHeight() * 2),5,5);
					}
				}
				ofScale(0.5f, 0.5f, 1);
				ofSetColor(255);
				ofFill();			
				ofDrawBitmapString("la verdad se revelara tarde o temprano", ofGetWidth() - ofGetWidth()*0.9, ofGetHeight()- ofGetHeight()*0.9);
				ofScale(2,2,1);
				ofSetColor(255, opa20);
				ofFill();
				ofDrawBitmapString("VERDAD?", ofGetWidth() - ofGetWidth() / 8, ofGetHeight() - ofGetHeight() / 8);
				ofDrawBitmapString("VERDAD?", -1+ofGetWidth() - ofGetWidth() / 8, ofGetHeight() - ofGetHeight() / 8);
				ofDrawBitmapString("VERDAD?", 1+ofGetWidth() - ofGetWidth() / 8, ofGetHeight() - ofGetHeight() / 8);
				ofDrawBitmapString("VERDAD?", ofGetWidth() - ofGetWidth() / 8, -1+ofGetHeight() - ofGetHeight() / 8);
				ofPopStyle();
				ofPopMatrix();
			}
		}
		else if (escena == 20) {
			ofPushStyle();
			ofSetLineWidth(5);
			ofScale(0.5f, 0.5f,1);
			ofSetColor(255);
			ofFill();
			ofDrawBitmapString(letras.at(escoge21), px21, py21);
			ofPopStyle();
		}
		else if (escena == 21) {
			// Twitter
			ofDrawBitmapString("Twitter pendiente", ofGetWidth()/2, ofGetHeight()/2);

		}
		else if (escena == 22) {
			ofSetColor(0, 5);
			ofFill();
			ofRect(0, 0, ofGetWidth(), ofGetHeight());
			ofSetColor(255);
			for (int i = 0; i < part23; i++) {
				ofEllipse(px23[i], py23[i], 2.5f, 2.5f);
			}
		}
		else if (escena == 23) {
			ofPushStyle();
			//noStroke();
			ofSetColor(0, 5);
			ofFill();
			ofRect(0, 0, ofGetWidth(), ofGetHeight());
			ofTranslate(0, ofGetHeight() / 2);
			ofSetColor(255, ofRandom(0, 255));
			ofNoFill();
			ofSetLineWidth(ofRandom(1, 7));
			for (int i = 0; i<pun24; i++) {
				px24[i] = i+i;
				ofEllipse(px24[i], py24[i], pz24[i],2,2);
			}
			ofPopStyle();
		}
		else if (escena == 24) {
			// PEND
			ofDrawBitmapString("OSC de SuperCollider pendiente", ofGetWidth() / 2, ofGetHeight() / 2);
		}
		else if (escena == 25) {
			ofPushMatrix();
			rec.begin();
			//ofBackground(0);
			ofSetColor(255, 50);
			ofSetLineWidth(0.5);
			ofNoFill();
			int mil = ofGetElapsedTimeMillis();
			for (int i = 0; i<10; i++) {
				ofRotateX(30 * i + mil*0.001);
				ofRotateY(45 * i + mil*0.001);
				ofRotateZ(30 * i + mil*ofRandom(0.001, 0.0035));
				ofRect(ofGetWidth()/ 8, ofGetHeight()/ 8, 100, 400);
			}
			rec.end();
			ofPopMatrix();
			/*
			rec.begin();
			ofBackground(100);
			ofNoFill();
			ofSetColor(255);
			ofLine(20, 20, mouseX, mouseY);
			rec.end();

			ofFill();
			ofSetColor(255);

			rec.draw(9, 30);
			rec.draw(51, 30);
			*/

			ofPushMatrix();
			ofTranslate(200, 200, -200);
			
			
			ofPushMatrix();
			rec.draw(0, 0);
			ofRotateY(ofDegToRad(PI / 2));
			rec.draw(0, 0);
			ofPopMatrix();

			ofPushMatrix();
			ofTranslate(0, 0, -400);
			rec.draw(0, 0);
			ofPopMatrix();

			ofPushMatrix();
			ofTranslate(400, 0, 0);
			ofRotateY(ofDegToRad(PI / 2));
			rec.draw(0, 0);
			ofPopMatrix();

			ofPushMatrix();
			ofTranslate(0, 400, 0);
			ofRotateX(ofDegToRad(-PI / 2));
			rec.draw(0, 0);
			ofPopMatrix();

			ofPushMatrix();
			ofRotateX(ofDegToRad(-PI / 2));
			rec.draw(0, 0);
			ofPopMatrix();

			ofPopMatrix();
		}

		/////////////// TERMINAN ESCENAS (cuando el estado es falso)
	}

	if (fondo) {
		estado = true;
		ofSetBackgroundAuto(estado);
		fondo = false;
	}
	else if (estado == true) {
		if (escena == 6 || escena == 9 || escena == 18 || escena == 19) {
			ofBackground(255);
		}
		else {
			ofBackground(0);
		}
		ofSetBackgroundAuto(!estado);
		estado = false;
	}
}

void ofApp::evaluar() {
	// frameRate(5);
	pixT = ofRandom(ofGetWidth());
	piyT = ofRandom(ofGetHeight());
	pfxT = ofRandom(ofGetWidth() - pixT);
	pfyT = ofRandom(ofGetHeight() - piyT);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's')
		iniciaTodo = true;
	if (escena == 12) {
		if (key == OF_KEY_RIGHT) {
			pacMan.caso = 1;
		}
		else if (key == OF_KEY_DOWN) {
			pacMan.caso = 2;
		}
		else if (key == OF_KEY_LEFT) {
			pacMan.caso = 3;
		}
		else if (key == OF_KEY_UP) {
			pacMan.caso = 4;
		}
	}
	else if (escena == 15) {
		if (key == OF_KEY_TAB) {
			comienza = 1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if(escena==0)
		fondo = true;
	if (escena == 14) {
		radio = 1;
		radio2 = 1;
		radio3 = 1;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofBackground(0);
	fondo = true;
	escena++;
	if (escena == 18)
		inicia19 = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	estado = false;
	if (escena == 14) {
		radio = 1;
		radio2 = 1;
		radio3 = 1;
	}
	else if (escena == 15) {
		comienza = 0;
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

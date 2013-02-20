#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
	
  public:
	void setup();
	void update();
	void draw();
	
	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
	static bool sortOnBrightness(const ofColor &a, const ofColor &b);
	static bool sortOnHue(const ofColor &a, const ofColor &b);
	static bool sortOnSaturation(const ofColor &a, const ofColor &b);
	
	ofVideoGrabber grabber;
	
	vector<ofColor> colors;
	
	int sortState;
	
	string msg;
	
};
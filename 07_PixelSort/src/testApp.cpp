#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	grabber.initGrabber(320, 240);
	sortState = 0;
    
	
	for (int i = 0; i < grabber.getHeight() * grabber.getWidth(); i++) {
		ofColor black = ofColor::black;
		colors.push_back(black);
	}
	
	ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofPixelsRef pix = grabber.getPixelsRef();
    
    for(int y = 0; y < grabber.getHeight(); y++) {
        for(int x = 0; x < grabber.getWidth(); x++) {
            ofColor thisColor = pix.getColor(x, y);
            colors[x+(y*grabber.getWidth())] = thisColor;
        }
    }
	
    switch (sortState) {
        case 0:
			msg = "Press 2, 3, 4 to sort";
            break;
            
        case 1:
            ofSort(colors, testApp::sortOnBrightness);
			msg = "Sorting by Brightness";
            break;
            
        case 2:
            ofSort(colors, testApp::sortOnHue);
			msg = "Sotring by Hue";
            break;
            
        case 3:
            ofSort(colors, testApp::sortOnSaturation);
			msg = "Sorting by Saturation";
            break;
            
    }
    
    //draw little rects
    for(int y=0; y<grabber.getHeight(); y++)
    {
        for(int x=0; x<grabber.getWidth(); x++)
        {
            ofSetColor(colors[x+(y*grabber.getWidth())]);
            ofRect(x, y, 1, 1);
        }
    }
    
    ofSetColor(255);
    grabber.draw( grabber.getWidth(), 0);
	ofDrawBitmapString("camera", grabber.getWidth() + 10, grabber.getHeight() + 10);
	ofDrawBitmapString(msg, 10, grabber.getHeight() + 10);
}

//--------------------------------------------------------------
bool testApp::sortOnBrightness(const ofColor &a, const ofColor &b) {
    return a.getBrightness() < b.getBrightness();
}

//--------------------------------------------------------------
bool testApp::sortOnHue(const ofColor &a, const ofColor &b) {
    return a.getHue() < b.getHue();
}

//--------------------------------------------------------------
bool testApp::sortOnSaturation(const ofColor &a, const ofColor &b) {
    return a.getSaturation() < b.getSaturation();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
    if (key == '1') sortState = 0;
    if (key == '2') sortState = 1;
    if (key == '3') sortState = 2;
    if (key == '4') sortState = 3;
    if (key == '5') sortState = 4;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}
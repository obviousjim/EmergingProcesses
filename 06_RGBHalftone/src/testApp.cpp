#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    player.loadMovie("AndyTDK.mp4");
    player.play();
    ofBackground(0);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    
    

    //make stp size through the image dependent on the mouse X
    //make the scale of the circles depende on the mouse y
    float step  = ofMap(mouseX, 0, ofGetWidth(),  1, 20, true);
    float scale = ofMap(mouseY, 0, ofGetHeight(), 2, 50, true);

    ofPushStyle();
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);

    
    for(float y = 0; y < player.getHeight(); y+=step){
        for(float x = 0; x < player.getWidth(); x+=step){
            ofColor c = player.getPixelsRef().getColor(x, y);
            //draw rgb circles in 3 opposing directions
            ofVec2f redDir = ofVec2f(0,-1); //straight up
            ofVec2f greenDir = redDir.rotated(120.0);
            ofVec2f blueDir = greenDir.rotated(120.0);
            ofVec2f pixelPosition;
            pixelPosition.x = ofMap(x, 0, player.getWidth(), 0, ofGetWidth());
            pixelPosition.y = ofMap(y, 0, player.getHeight(), 0, ofGetHeight());
            
            //move in
            ofSetColor(c.r, 0, 0);
            ofCircle(pixelPosition + redDir * c.r * scale*.01, scale * c.r/255.);
            
            ofSetColor(0, c.g, 0);
            ofCircle(pixelPosition + greenDir * c.b * scale*.01, scale * c.g/255.0);
            
            ofSetColor(0, 0, c.b);
            ofCircle(pixelPosition + blueDir * c.g * scale*.01, scale * c.r/255.0);
            
        }
    }
    
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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
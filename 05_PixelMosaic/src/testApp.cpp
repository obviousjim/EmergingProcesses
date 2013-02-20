#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    player.loadMovie("fireworks.mp4");
    player.play();
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    float mosaicStep = ofMap(mouseX, 0, ofGetWidth(), 1, 20, true);
    float scale = ofMap(mouseY, 0, ofGetHeight(), 1, 5, true);

    ofPushStyle();
    for (float y = 0; y < player.getHeight(); y += mosaicStep){
        for (float x = 0; x < player.getWidth(); x += mosaicStep){
            ofColor myColor = player.getPixelsRef().getColor(x, y);
            ofSetColor(myColor);
            ofRect(x*scale, y*scale, mosaicStep*scale, mosaicStep*scale);
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
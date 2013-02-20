#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    grabber.initGrabber(640, 480);
    oldestFrameIndex = 0;
    delayBuffer.resize(50);
    
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();
    if(grabber.isFrameNew()){
        delayBuffer[oldestFrameIndex].setFromPixels(grabber.getPixelsRef());
        oldestFrameIndex++;
        if(oldestFrameIndex >= delayBuffer.size()){
            oldestFrameIndex = 0;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    grabber.draw(0,0);
    if(delayBuffer[oldestFrameIndex].isAllocated()){
        delayBuffer[oldestFrameIndex].draw(grabber.getWidth(), 0);
    }
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
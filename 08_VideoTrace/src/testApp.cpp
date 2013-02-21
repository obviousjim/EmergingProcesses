#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);
    ofEnableSmoothing();
    
    grabber.initGrabber(640,480);
    
    //setting the mesh draw mode to LINE_STRIP means
    //each subsequent vertex will be connected by one continuous line
    trace.setMode(OF_PRIMITIVE_LINE_STRIP);
    
    //make the line thick
    ofSetLineWidth(4);
    
    //change this to make the trace shorter or longer
    maxVertices = 1000;
}

//--------------------------------------------------------------
void testApp::update(){
    grabber.update();

    //you can use this if you want to animate the lines in a whacky way
    for(int i = 0; i < trace.getVertices().size(); i++){
        trace.getVertices()[i] += ofVec2f(cos(i/10.0 + ofGetElapsedTimef()/4.),
                                          sin(i/10.0 + ofGetElapsedTimef()/4.));
    }
    
    //remove the beginning when the line gets too big
    while (trace.getVertices().size() > maxVertices) {
        trace.removeVertex(0);
        trace.removeColor(0);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    trace.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    //everytime the mouse is moved add a point
    if(x < grabber.getWidth() && y < grabber.getHeight()){
        trace.addColor(grabber.getPixelsRef().getColor(x, y));
        trace.addVertex( ofVec3f(x,y,0) );
    }
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
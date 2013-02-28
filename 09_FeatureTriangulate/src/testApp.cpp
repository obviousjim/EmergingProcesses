#include "testApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void testApp::setup(){

	panel.setup(250, 800);
	
	panel.addPanel("Optical Flow");
    
    panel.addSlider("maxFeatures", 200, 1, 1000);
	panel.addSlider("qualityLevel", 0.01, 0.001, .02);
	panel.addSlider("minDistance", 4, 1, 16);


    grabber.initGrabber(640, 480);
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    grabber.update();
    if(grabber.isFrameNew()){
        vector<cv::Point2f> features;
        current.setFromPixels(grabber.getPixelsRef());
        current.setImageType(OF_IMAGE_GRAYSCALE);
        
        goodFeaturesToTrack(toCv(current),
                            features,
                            panel.getValueI("maxFeatures"),
                            panel.getValueF("qualityLevel"),
                            panel.getValueF("minDistance"));
        triangulation.reset();
        
        triangulation.addPoints(toOf(features).getVertices());
        triangulation.triangulate();
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    grabber.draw(0,0);
    ofNoFill();
    triangulation.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
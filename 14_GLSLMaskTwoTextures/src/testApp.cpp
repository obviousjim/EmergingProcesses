#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
	//this is important for the alpha comontent to come through
	ofEnableAlphaBlending();
	ofSetWindowShape(640, 480);
	
	//if the vertex and fragment shader have the same name you can just pass one string
	shader.load("maskTexture");
	//otherwise you could use this constructor:
	//shader.setup("maskTexture.vert", "maskTexture.frag");
	
	//set up a video grabber, this is what we will use to mask
	grabber.initGrabber(640, 480);
	
	//now load the black and white image to become the mask
	//this must match the size of grabber, 640x480 in this case
	mask.loadImage("stripes.png");
}

//--------------------------------------------------------------
void testApp::update(){
	grabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	//color cycle the background so we can see what's changing behind the mask easier
	ofColor color = ofColor::fromHsb(ofGetFrameNum()%255, 255, 255);
	ofBackground( color );
	
	ofPopStyle();
	//draw a circle so we can see something else underneath
	ofSetColor(color.invert());
	ofCircle(mouseX, mouseY, 15);
	ofPushStyle();
	
	//start the shader. now everything that is drawn is piped 'through' this shader
	shader.begin();
	//these names match the names in the shader
	shader.setUniformTexture("image", grabber, 0);
	shader.setUniformTexture("mask", mask, 1);
	//draw the shad
	grabber.draw(0, 0);
	
	shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	//hitting SHIFT+R let's us reload the shader live wihth recompiling!
	if(key == 'R'){
		shader.load("maskTexture");
	}
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
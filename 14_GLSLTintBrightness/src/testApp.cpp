#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//loads the shader
	shader.load("tintAndBrightness");

	//http://www.hh-h.com/assets/Parasol.jpg
	image.loadImage("Riley-Parasol.jpg");

	ofSetWindowShape(image.getWidth(), image.getHeight());
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	//begining a shader is like beginning an FBO. All drawing that takes place goes through the shader until end()
	shader.begin();

	float brightness = 2.0 * ofGetMouseX() / ofGetWidth() ;
	shader.setUniform1f("brightness", brightness);
	//hue cycling
	ofFloatColor tint = ofFloatColor::fromHsb( fmod(ofGetElapsedTimef() / 2.0, 1.0), 1.0, 1.0);
	shader.setUniform4f("tint", tint.r, tint.b, tint.g, tint.a);
	
	image.draw(0,0);
	
	//and put things back to normal
	shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	//convenient shortcut to reload the shader in real time by hitting SHIFT+R
	//this lets you edit the vertex and fragment files without having to recompiile
	if(key == 'R'){
		shader.load("tintAndBrightness");
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
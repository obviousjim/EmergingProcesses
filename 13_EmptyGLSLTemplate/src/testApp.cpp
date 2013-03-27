#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//loads the shader
	shader.load("emptyShader");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	//begining a shader is like begining an FBO. All drawing that takes place goes through the shader until end()
	shader.begin();
	
	//you could set some uniforms once the shader has begun
	ofImage someImage; //load this and then pass to the shader like so
	shader.setUniformTexture("image", someImage, 0);

	//you can pass just normal variables
	float someValueForTheShader = 3.0;
	shader.setUniform1f("singleValue", someValueForTheShader);
	
	//or 2 or 3 dimenionsal positions in space
	ofVec2f somePositionOnTheScreen = ofVec2f(mouseX, mouseY);
	shader.setUniform2f("singleValue", somePositionOnTheScreen.x,somePositionOnTheScreen.y);
	
	//or even colors, which are just like vectors
	//shaders always want colors to be floats between 0 to 1.0
	ofFloatColor color = ofColor(1.0, 0.0, 0.0);
	shader.setUniform3f("someColor", color.r, color.b, color.g);
	
	//now draw something!
	// ....
	
	//and put things back to normal
	shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	//convenient shortcut to reload the shader in real time by hitting SHIFT+R
	//this lets you edit the vertex and fragment files without having to recompiile
	if(key == 'R'){
		shader.load("emptyShader");
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
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//loads the shader
	shader.load("mouseHalo");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	//begining a shader is like beginning an FBO. All drawing that takes place goes through the shader until end()
	shader.begin();
	
	//modulate a circle radius between 20 and 200
	shader.setUniform1f("radius", ofMap( sin(ofGetElapsedTimef()*2),-1,1, 20, 200 ));
	//centered at the mouse
	shader.setUniform2f("mousePosition", mouseX, mouseY);
					
	//draw a full screen mesh
	ofMesh m;
	m.addVertex(ofVec2f(0,0));
	m.addVertex(ofVec2f(0,ofGetHeight()));
	m.addVertex(ofVec2f(ofGetWidth(),0));
	m.addVertex(ofVec2f(ofGetWidth(),ofGetHeight()));
	m.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	m.draw();
		
	//and put things back to normal
	shader.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	//convenient shortcut to reload the shader in real time by hitting SHIFT+R
	//this lets you edit the vertex and fragment files without having to recompile
	if(key == 'R'){
		shader.load("mouseHalo");
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
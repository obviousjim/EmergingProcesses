#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	fbo.allocate(640,480, GL_RGBA);
	ofSetCircleResolution(200);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	fbo.begin();
	
	ofClear(0,0,0,255);
	float step = 30;
	ofNoFill();
	for(int y = 0; y < fbo.getHeight(); y+=step){
		for(int x = 0; x < fbo.getWidth(); x+=step){
			ofCircle(x, y, 20 + sin(ofGetElapsedTimef() + x) * 20);
		}
	}
	fbo.end();
	
	//you could just draw the mesh normally
	//or distort it using your texture coordinates
//	fbo.draw(0,0);

	//or here we create animated edges using texture coordinates!
	//get the enter of the screen
	ofVec3f center = ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0);
	ofRectangle fboRectangle = ofRectangle(0,0,fbo.getWidth(), fbo.getHeight());
	
	//create a mesh
	ofMesh mesh;
	
	//TOP LEFT
	//texture coordinates are in the image space
	mesh.addTexCoord(fboRectangle.getTopLeft());
	//vertices are in the screen space
	mesh.addVertex( center + ofVec3f(-fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0)
						   + ofVec3f(cos(ofGetElapsedTimef()*4) * 50, sin(ofGetElapsedTimef()*6) * 50) );
	//BOTTOM LEFT
	mesh.addTexCoord(fboRectangle.getBottomLeft());
	mesh.addVertex( center + ofVec3f(-fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0)
						   + ofVec3f(cos(ofGetElapsedTimef()*4) * 50, sin(ofGetElapsedTimef()*6) * 50) );
	
	//TOP RIGHT
	mesh.addTexCoord(fboRectangle.getTopRight());
	mesh.addVertex(center + ofVec3f(fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0)
						  + ofVec3f(cos(ofGetElapsedTimef()*4) * 50, sin(ofGetElapsedTimef()*4) * 50) );
	
	//BOTTOM RIGHT
	mesh.addTexCoord(fboRectangle.getBottomRight());
	mesh.addVertex(center + ofVec3f(fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0)
						  + ofVec3f(cos(ofGetElapsedTimef()*2) * 50, sin(ofGetElapsedTimef()*2) * 50) );
	
	mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	
	//when a texture is bound, only
	fbo.getTextureReference().bind();
	mesh.draw();
	fbo.getTextureReference().unbind();
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
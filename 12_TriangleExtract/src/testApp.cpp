#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
	cubes.loadImage("new_rubiks_cube_5.jpg");
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofNoFill();

	ofPushStyle();
	//ofSetColor(255, 30);
	cubes.draw(0,0);
	ofPopStyle();
	
	//triangulation.draw();
	cubes.getTextureReference().bind();
	ofPushMatrix();
	ofTranslate(cubes.getWidth(), 0);
	texturedMesh.draw();
	ofPopMatrix();
	cubes.getTextureReference().unbind();
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
	triangulation.addPoint(ofPoint(x,y));
	triangulation.triangulate();
	texturedMesh = triangulation.triangleMesh;
	for(int i = 0;
		i < texturedMesh.getNumVertices();
		i++)
	{
		texturedMesh.addTexCoord(ofVec2f(
			texturedMesh.getVertex(i).x,
			texturedMesh.getVertex(i).y));
	}
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
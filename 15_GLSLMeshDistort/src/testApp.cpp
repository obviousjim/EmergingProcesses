#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	glEnable(GL_DEPTH_TEST);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(66,66,66);
	
	//initialize the video grabber
	vidGrabber.initGrabber(640,480);
	
	//this determines how much we push the meshes out
	extrusionAmount = 500.0;

	//store the width and height for convenience
	int width = vidGrabber.getWidth();
	int height = vidGrabber.getHeight();
	
	//taken right from the MeshDistort example
	//except we add texture coords now
	for (int y = 0; y < height; y++){
		for (int x = 0; x<width; x++){
			mainMesh.addVertex(ofPoint(x,y,0));	// mesh index = x + y*width
			mainMesh.addTexCoord(ofVec2f(x,y)); // lock each vertex to the right texture coordinate
		}
	}
	
	for (int y = 0; y<height-1; y++){
		for (int x=0; x<width-1; x++){
			mainMesh.addIndex(x+y*width);				// 0
			mainMesh.addIndex((x+1)+y*width);			// 1
			mainMesh.addIndex(x+(y+1)*width);			// 10
			
			mainMesh.addIndex((x+1)+y*width);			// 1
			mainMesh.addIndex((x+1)+(y+1)*width);		// 11
			mainMesh.addIndex(x+(y+1)*width);			// 10
		}
	}
	
	extrudeShader.load("meshExtrude");

}

//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	//You can either draw the mesh or the wireframe

	extrudeShader.begin();
	extrudeShader.setUniformTexture("image", vidGrabber, 0);
	extrudeShader.setUniform1f("extrusionAmount", extrusionAmount);
	
	ofPushMatrix();
	ofTranslate(ofGetWidth()/2- vidGrabber.getWidth()/2,
				ofGetHeight()/2-vidGrabber.getHeight()/2);
	
	mainMesh.drawFaces();

	ofPopMatrix();
	
	extrudeShader.end();


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
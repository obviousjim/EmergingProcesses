#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //this let's us draw the movie with transparent tinting
    ofEnableAlphaBlending();
    
    //load the movie. always looks in bin/data/
    player.loadMovie("fingers.mov");
    
    //play the movie to start with
    player.play();
    
    //you can change the loop settings this way
    player.setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //have to call updated to get new frames from the video stream
    player.update();
    
    // this chunk of code samples pixels from the video
    int sampleX = ofClamp(mouseX,0,player.getWidth()-1);
    int sampleY = ofClamp(mouseY,0,player.getHeight()-1);
    ofColor sample = player.getPixelsRef().getColor(sampleX, sampleY);
    
    ofBackground(sample);
    
    //we can tint the video here, the different colors stand for red, green, blue, alpha (transparency)
    ofSetColor(255,255,255,128);
    
    //draw the video at the top left corner
    player.draw(0,0);
    
    //draw the video attached to the mouse
    //player.draw(mouseX,mouseY);
    
    //resize the video with the mouse position
    //player.draw(0,0,mouseX, mouseY);
    
    //draw the video full screen
    //player.draw(0, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    //key codes are always the single character with single quotes.
    //In this case we are looking for space bar
    if(key == ' '){
        //toggle the player. if it's playing, we stop it. if it's not playing we start it
        if(player.isPlaying()){
            player.stop();
        }
        else {
            player.play();
        }
    }
    
    //we can toggle the window to cover the whole screen. great for installations!
    if(key == 'f'){
        ofToggleFullscreen();
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
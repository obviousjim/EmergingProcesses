#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    totalFrames = 0;
    if(!player.loadMovie("fingers.mov")){
        ofLogError("Movie load failed!");
    }
    else {
        player.play();
        accumulation.allocate(
            player.getWidth(), //WIDTH
            player.getHeight(), //HEIGHT
            player.getPixelsRef().getImageType());//PIX TYPE
    }
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
    if(player.isFrameNew()){
        
        //for each pixel create the new average
        for(int y = 0; y < player.getHeight(); y++){
            for (int x = 0; x < player.getWidth(); x++){
                //for a description of this algorithim, check out
                //http://en.wikipedia.org/wiki/Moving_average

                //first grab the colors
                ofFloatColor currentAverage = accumulation.getColor(x, y);
                ofFloatColor newPixel = player.getPixelsRef().getColor(x, y);
                
                //store the total average in a vector, since float colors are clamped to [0 - 1] range
                ofVec3f currentAccumulation = totalFrames * ofVec3f(currentAverage.r,currentAverage.g,currentAverage.b);
                currentAverage.r = (newPixel.r + currentAccumulation.x) / (totalFrames + 1);
                currentAverage.g = (newPixel.g + currentAccumulation.y) / (totalFrames + 1);
                currentAverage.b = (newPixel.b + currentAccumulation.z) / (totalFrames + 1);
                
                //reset the modified current average into the array
                accumulation.setColor(x,y,currentAverage);
            }
        }
        totalFrames++;        
        accumulation.reloadTexture();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    player.draw(0, 0);
    accumulation.draw(player.getWidth(), 0);
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
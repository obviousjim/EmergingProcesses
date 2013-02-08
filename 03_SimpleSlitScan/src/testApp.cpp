#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    currentRow = 0;
    if(!player.loadMovie("fingers.mov")){
        ofLogError("Load movie failed");
    }
    else{
        accumulation.allocate(player.getWidth(), player.getHeight(), OF_IMAGE_COLOR);
        player.play();
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    player.update();
    if(player.isFrameNew()){

        //copy a row of pixels
        for(int x = 0; x < player.getWidth(); x++){
            accumulation.setColor(x, currentRow, player.getPixelsRef().getColor(x, currentRow));
        }

        //this way is slower but more explicit, and more flexible
        //pixels are stored like this
        //rgb rgb rgb
        //012 345 678
        //unsigned char* dest = accumulation.getPixels() + (currentRow*int(accumulation.getWidth()) * 3);
        //unsigned char* src = player.getPixels() + (currentRow*int(accumulation.getWidth()) * 3);
        //memcpy reads "copy into dest from source size"
        //memcpy(dest, src, int(accumulation.getWidth()) * 3);

        //increment the row, and rap if need be
        currentRow = (currentRow + 1) % int(player.getHeight());
        
        //you could also do it this way:
//        currentRow++;
//        if(currentRow == player.getHeight()){
//            currentRow = 0;
//        }
        
        //update the texture
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
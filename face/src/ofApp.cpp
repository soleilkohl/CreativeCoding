#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600, 700);
    face.load("/Users/soleilkohl/Desktop/imgres 12.17.09 PM.jpg");
    ofSetFrameRate(15);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofBackground(200, 145, 123);
    ofBackground(0);
    
    //face.draw(130, 0, 500, 700);
    
    /*ofSetColor(0, 0, 0, 175);
    for (int i = 100; i<=600; i+=100){  //lines at each 100
        ofDrawLine(i, 0, i, 700);
        ofDrawLine(0, i, 800, i);
    }

    ofSetColor(50, 50, 50, 100);
    for (int i = 150; i<=650; i+=100){  //lines at each 50
        ofDrawLine(i, 0, i, 700);
        ofDrawLine(0, i, 800, i);
    }*/
    
    ofSetColor(245, 238, 225, 200);
    
    int count = 0;
    for (int i = 420; i < 530; i += 15){ //neck
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(i-230+xOffset-(count*18), i+yOffset, 150+xOffset-(count*8), 5+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 370; i < 530; i += 15){ //neck
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(i-180+xOffset-(count*18), i+yOffset, 175+xOffset-(count*8), 7+yOffset);
        count++;
    }
    
    for (int i = 250; i < 330; i += 15){ //rectangles in diagonal down cheek
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(i+xOffset, i+yOffset, 60+xOffset, 5+yOffset);
    }
    
    for (int i = 330; i < 430; i += 15){ //rectangles in diagonal down cheek
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(i-50+xOffset, i+yOffset, 60+xOffset, 3+yOffset);
    }
    
    for (int i = 150; i < 330; i += 15){ //rectangles straight down the face
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(280+xOffset, i+yOffset, 150 + xOffset, 5+yOffset);
    }
    
    for (int i = 330; i < 400; i += 15){ //rectangles straight down the face
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(270+xOffset, i+yOffset, 150 + xOffset, 3+yOffset);
    }
    
    for (int i = 330; i < 400; i += 15){ //rectangles straight down the face
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(270+xOffset, i+yOffset, 150 + xOffset, 3+yOffset);
    }
    
    ofSetColor(245, 238, 225, 200);
    
    count = 0;
    for (int i = 130; i < 210; i += 10){ //top forehead
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(300+xOffset, i+yOffset, 120+(count*4)+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 130; i < 210; i += 10){ //top forehead
        float xOffset = ofRandom(-6, 6);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(200+xOffset, i+yOffset, 220+(count*4)+xOffset, 4+yOffset);
        count++;
    }

    count = 0;
    for (int i = 210; i < 240; i += 10){ //bottom forehead
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(285+xOffset, i+yOffset, 165-(count*4)+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 210; i < 240; i += 10){ //bottom forehead
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(185+xOffset, i+yOffset, 265-(count*4)+xOffset, 4+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 240; i < 320; i += 10){    //nosebridge
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(295+xOffset, i+yOffset, 145+(count*6)+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 240; i < 320; i += 10){    //nosebridge
        float xOffset = ofRandom(-6, 6);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(195+xOffset, i+yOffset, 245+(count*6)+xOffset, 4+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 320; i <= 340; i += 10){    //bottom bit of nose and cupids bow
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(285+xOffset, i+yOffset, 195-(count*10)+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 320; i <= 340; i += 10){    //bottom bit of nose and cupids bow
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(285+xOffset, i+yOffset, 195-(count*10)+xOffset, 4+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 340; i <= 390; i += 10){    //lip to mouth face lines
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(280+xOffset, i+yOffset, 180+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 340; i <= 390; i += 10){    //lip to mouth face lines
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(280+xOffset, i+yOffset, 180+xOffset, 4+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 400; i <= 440; i += 10){    //chin
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(290+(count*35)+xOffset, i+yOffset, 145-(count*30)+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 400; i <= 420; i += 10){    //chin
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(290+(count*35)+xOffset, i+yOffset, 155-(count*30)+xOffset, 4+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 250; i <= 340; i += 10){    //ear
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(210+xOffset+(count*3), i+yOffset, 60+xOffset, 4+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 250; i <= 340; i += 10){    //ear detail
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(215+xOffset+(count*3), i+yOffset, 45+xOffset, 2+yOffset);
        count++;
    }
    
    
    //ofSetColor(222, 167, 114, 200);
    count = 0;
    for (int i = 150; i < 300; i += 10){    //lines that transition down
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(350+xOffset, i+yOffset, 80-(count*10)+xOffset, 3+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 370; i < 440; i += 15){ //jawline steps
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(275+(count*30)+xOffset, i+yOffset, 17+xOffset, 5+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 250; i < 320; i += 15){ //nose steps
        float xOffset = ofRandom(-4, 4);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(430+(count*10)+xOffset, i+yOffset, 15+xOffset, 5+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 250; i < 320; i += 15){ //nose steps
        float xOffset = ofRandom(-3, 3);
        float yOffset = ofRandom(-3, 3);
        ofDrawRectangle(410+(count*10)+xOffset, i+yOffset, 40+xOffset, 5+yOffset);
        count++;
    }
    
    ofSetColor(245, 238, 225, 200);
    count = 0;
    for (int i = 240; i < 320; i += 10){
        float xOffset = ofRandom(-7, 7);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(330+xOffset, i+yOffset, 10+(count*6)+xOffset, 3+yOffset);
        count++;
    }
    
    ofSetColor(160,82,45);
    count = 0;
    for (int i = 370; i <= 385; i += 5){
        float xOffset = ofRandom(-3, 3);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(i+xOffset, 207+yOffset-(count*3), 10+xOffset, 5+yOffset);
        count++;
    }
    
    count = 0;
    for (int i = 390; i <= 420; i += 5){
        float xOffset = ofRandom(-3, 3);
        float yOffset = ofRandom(-2, 2);
        ofDrawRectangle(i+xOffset, 190+yOffset+(count*3), 10+xOffset, 5+yOffset);
        count++;
    }
    
    
    //ofDrawRectangle(330, 320, 50, 3);
    //ofDrawRectangle(330, 330, 40, 3);
    
   // ofSetColor(245, 238, 225, 200);
    //ofDrawTriangle(200, 150, 400, 110, 430, 150);
   // ofSetColor(123, 112, 126, 200);
    //ofDrawTriangle(280, 355, 290, 400, 430, 450);
    
    ofSetColor(ofColor::white);
    float xOffset = ofRandom(-5, 5);
    float yOffset = ofRandom(-5, 5);
    ofDrawTriangle(400+xOffset, 250+yOffset, 425+xOffset, 245+yOffset, 420+xOffset, 265+yOffset);
    
    int midX = 410;
    int midY = 250;
    int numRects = 5;
    for (int r=0; r<numRects; r++) {    //flashing eyes
        float randomColorR = ofRandom(0, 45);
        float randomColorG = ofRandom(50, 245);
        float randomColorB = ofRandom(0, 45);
        ofSetColor(randomColorR, randomColorG, randomColorB);
        float width = ofRandom(3, 15);
        float height = ofRandom(3, 15);
        float xOffset = ofRandom(-5, 5);
        float yOffset = ofRandom(-5, 5);
        ofDrawRectangle(midX + xOffset, midY + yOffset, width, height);
    }
    
    midX = 445;
    midY = 360;
    numRects = 5;
    for (int r=0; r<numRects; r++) {    //flashing lips
        float randomColorR = ofRandom(50, 245);
        float randomColorG = ofRandom(0, 45);
        float randomColorB = ofRandom(0, 45);
        ofSetColor(randomColorR, randomColorG, randomColorB);
        float width = ofRandom(10, 25);
        float height = ofRandom(5, 15);
        float xOffset = ofRandom(-5, 5);
        float yOffset = ofRandom(-5, 5);
        ofDrawRectangle(midX + xOffset, midY + yOffset, width, height);
        ofDrawRectangle(midX + xOffset, midY + 7 + yOffset, width, height);
        ofDrawRectangle(midX -7 + xOffset, midY + 5 + yOffset, width - 5, height - 3);
    }
    
    
    
    numRects = 35;
    for (int r=0; r<numRects; r++) {    //flashing hair
        midX = 250;
        midY = 150;
        float randomColorR = ofRandom(100, 250);
        float randomColorG = ofRandom(100, 250);
        float randomColorB = ofRandom(100, 250);
        /*float randomColorR = ofRandom(200, 250);
        float randomColorG = ofRandom(100, 250);
        float randomColorB = 0;*/
        float rad = 10;
        float radOffset = ofRandom(-20,20);
        ofSetColor(randomColorR, randomColorG, randomColorB, 100);
        
        float xOffset = ofRandom(-60, 50);
        float yOffset = ofRandom(-70, 40);
        float width = ofRandom(5, 40);
        float height = ofRandom(50, 175);
        
        ofDrawRectangle(midX + xOffset, midY + yOffset, width, height);
        ofDrawRectangle(midX + xOffset, midY -50 + yOffset, width, height);
        ofDrawRectangle(midX + 50 + xOffset, midY + yOffset, width, height);
        height = ofRandom(10, 100);
        ofDrawRectangle(midX + xOffset, midY - 40 + yOffset, width, height);
        ofDrawRectangle(midX  + xOffset, midY - 30 + yOffset, width, height);
        ofDrawRectangle(midX + xOffset, midY + yOffset, width + 5, height);
        ofDrawRectangle(midX-100 + xOffset, midY + yOffset, width, height);
        
        ofDrawRectangle(midX-100+ xOffset, midY + 40 + yOffset, width, height);
        ofDrawRectangle(midX-100+ xOffset, midY + 200 + yOffset, width, height);
        ofDrawRectangle(midX+100+ xOffset, midY + yOffset, width + 5, height);
        ofDrawRectangle(midX-50+ xOffset, midY + 100+yOffset, width + 5, height);
        ofDrawRectangle(midX-90+ xOffset, midY + 200+yOffset, width-5, height);
        
        ofDrawCircle(midX+xOffset, midY+yOffset, rad + radOffset);
        ofDrawCircle(midX+xOffset, midY-30+yOffset, rad + 10+radOffset);
        ofDrawCircle(midX-30+xOffset, midY+30+yOffset, rad + 10+radOffset);
        midX = 200;
        midY = 200;
        ofDrawCircle(midX+xOffset, midY+yOffset, rad + radOffset);
        midX = 350;
        midY = 150;
        ofDrawCircle(midX+xOffset, midY+yOffset, rad + 3 + radOffset);
        midX = 200;
        midY = 300;
        xOffset = ofRandom(-80, 40);
        yOffset = ofRandom(-60, 60);
        ofDrawCircle(midX+xOffset, midY+yOffset, rad + 15 + radOffset);
        ofDrawCircle(midX-20+xOffset, midY+80+yOffset, rad + 10 + radOffset);
        ofDrawCircle(midX+10+xOffset, midY+160+yOffset, rad + 5 + radOffset);
        ofDrawCircle(midX+5+xOffset, midY+240+yOffset, rad + radOffset);
        
        xOffset = ofRandom(-100, 100);
        yOffset = ofRandom(-100, 100);
        ofDrawCircle(midX+xOffset, midY+yOffset, rad + 5 + radOffset);
        ofDrawCircle(midX-20+xOffset, midY-60+yOffset, rad + radOffset);
        
        xOffset = ofRandom(-70, 40);
        yOffset = ofRandom(-50, 50);
        midX = 195;
        midY = 160;
        ofDrawCircle(midX+xOffset, midY+yOffset, rad + radOffset);
        ofDrawCircle(midX+200+xOffset, midY+yOffset, rad + radOffset);
        ofDrawCircle(midX+200+xOffset, midY-80+yOffset, rad + radOffset);
    }
    
    //ofDrawLine(415, 360, 455, 340);

    ofSetColor(200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

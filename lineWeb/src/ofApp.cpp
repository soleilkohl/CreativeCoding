#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255,255,255);
    lineWidth = 1;
    distLineFrag = 30;
    offsetA = ofRandom(3);
    offsetB = ofRandom(3);
}

//--------------------------------------------------------------
void ofApp::update(){
 

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0,0,0,30);
    
    for (auto line : lines) {       //use the Line class to obtain points a and b
        ofDrawLine(line.a + offsetA, line.b + offsetB); //draw line from point a to b
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'd' && lineWidth < 7)
        lineWidth++;
    if (key == 'a' && lineWidth > 0)
        lineWidth--;
    if (key == 'w' && distLineFrag <= 200)
        distLineFrag += 10;
    if (key == 's' && distLineFrag >= 20)
        distLineFrag -= 10;
    if (key == ' ') {
        ofSetColor(0);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    }
    if (key == OF_KEY_DOWN)
        offsetA -= 2;
    if (key == OF_KEY_UP)
        offsetA += 2;
    if (key == OF_KEY_RIGHT)
        offsetB += 2;
    if (key == OF_KEY_LEFT)
        offsetB -= 2;
    ofSetLineWidth(lineWidth);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    for (auto point : drawnPoints){
        ofPoint mouse;                      //takes current position of mouse
        mouse.set(x,y);
        float dist = (mouse - point).length();
        if (dist < distLineFrag){                     //looks at distance between lines, and if less than it
            Line lineTemp;                  //connects the position of the mouse with the points in drawnPoints
            lineTemp.a = mouse;
            lineTemp.b = point;
            lines.push_back(lineTemp);
        }
    }
    drawnPoints.push_back(ofPoint(x,y));    //every time we drag the mouse, we save points in drawnPoints vector
                                            //drawnPoints is like a history of all mouse movement
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

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(transparency.setup("transparency", 200, 0, 255));
    gui.add(blurFade.setup("blur fade", 5, 0, 20));
    gui.add(brightness.setup("brightness", 255, 0, 255));
    gui.add(slowDown.setup("slow down", 10, 0, 1000));
    gui.add(videoDraw.setup("ghost effect", false));
    gui.add(normalsDraw.setup("live fuzz", false));
    
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    
    width = 640;
    height = 480;
    ofSetWindowShape(width, height);
    video.initGrabber(width, height);
    
    grayscale.allocate(width, height);
    blur.allocate(width, height);
    blur.setPasses(10);
    normals.allocate(width, height);
    disp.allocate(width,height);
    
    //bDrawVideo = false;
    bDrawField = false;
    //bDrawNormals = false;
    
    bCapture = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    video.update();
   blur.setPasses(slowDown);
    
    blur.setFade(blurFade);
    disp.setUseTexture(true);
    
    if ( video.isFrameNew() ){
        grayscale.setTexture( video.getTexture() );
        grayscale.update();
        blur << grayscale;
        blur.update();
        normals << blur;
        normals.update();
    }
    
    if (bCapture){
        disp.getBackBuffer()->begin();
        ofSetColor(brightness);
        video.draw(0, 0);
        disp.getBackBuffer()->end();
        
        bCapture = false;
    }
    
    disp.setTexture(normals.getTexture());
    disp.update();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, intensity);
    
    
    ofBackground(0);
    
    ofSetColor(brightness);
    if ( videoDraw ){
        video.draw(0,0,ofGetWidth(),ofGetHeight());
        ofSetColor(255,transparency);
    }
    
    disp.draw(0,0,ofGetWidth(),ofGetHeight());
    
    if ( normalsDraw ){
        ofSetColor(brightness);
        normals.draw(0,0,ofGetWidth(),ofGetHeight());
    }
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'v'){
        videoDraw = !videoDraw;
    } else if (key == 'n'){
        normalsDraw = !normalsDraw;
    } else {
        bCapture = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
 //    blur.rasius = ofMap(x, 0 , ofGetWidth(), 0, 10, true);
    
    blur.setPasses(ofMap(y, 0, ofGetHeight(),0, 10, true));
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

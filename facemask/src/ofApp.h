#pragma once

#include "ofApp.h"
#include "ofxOsc.h"
#include "ofxSyphon.h"
#include "ofxGui.h"

#include "Face.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg);
    void serverUpdated(ofxSyphonServerDirectoryEventArgs &args);
    void serverRetired(ofxSyphonServerDirectoryEventArgs &arg);
    
    Face face;
    
    void drawFacePoints();
    void drawFacePolygons();
    
    ofxOscReceiver receiver;
    
    bool found = false;
    vector<ofVec2f> points;
    
    int highlighted = 0; // which point is selected
    
    ofMesh mesh;
    
    ofImage img;
    
    ofPixels pixels;
    ofFbo fbo;
    
    ofxSyphonClient client;
    ofxSyphonServerDirectory dir;
    int dirIdx;
    
    ofxIntSlider lineWidth;
    ofxIntSlider offsetXL;
    ofxIntSlider offsetXH;
    ofxIntSlider offsetYL;
    ofxIntSlider offsetYH;
    
    ofxToggle drawAll;
    ofxToggle faceOutline;
    ofxToggle colorTo;

    ofxPanel gui;
};


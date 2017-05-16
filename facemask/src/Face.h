//
//  Face.hpp
//  cocoon
//
//  Created by Soleil Kohl on 4/25/17.
//
//
#pragma once

#include "ofMain.h"

class ofxOscMessage;

// a single tracked face from FaceOSC
class Face {
    
public:
    
    int found;
    
    // pose
    float poseScale;
    ofVec2f posePosition;       // FaceOSC win size: 640x680
    ofVec3f poseOrientation;
    
    // gesture
    float mouthWidth, mouthHeight;
    float eyeLeft, eyeRight;
    float eyebrowLeft, eyebrowRight;
    float jaw;
    float nostrils;
    
    Face();
    
    // parse an OSC message from FaceOSC
    // returns true if a message was handled
    bool parseOSC(ofxOscMessage& m);
    
    // get the current face values as a string (includes end lines)
    string toString();
};

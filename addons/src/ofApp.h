#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFx.h"

#include "ofxGrayscale.h"
#include "ofxBlur.h"
#include "ofxNormals.h"
#include "ofxDisplacePixels.h"

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
		
    
    ofxIntSlider transparency;
    ofxIntSlider slowDown;
    ofxFloatSlider blurFade;
    ofxIntSlider brightness;
    ofxToggle videoDraw;
    ofxToggle normalsDraw;
    ofxToggle fieldDraw;
    ofxButton button;
    ofxPanel gui;
    
    ofVideoGrabber      video;
    
    ofxGrayscale        grayscale;
    ofxBlur             blur;
    ofxNormals          normals;
    ofxDisplacePixels   disp;
    
    int             width, height;
    
    //bool            bDrawVideo;
    //bool            bDrawNormals;
    bool            bDrawField;
    bool            bCapture;
};

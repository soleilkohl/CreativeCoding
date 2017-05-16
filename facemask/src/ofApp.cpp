#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetWindowShape(600, 480);
    ofSetFrameRate(30);
    
    gui.setup();
    gui.add(lineWidth.setup("lineWidth", 2, 1, 10));
    gui.add(offsetXL.setup("x offset low bound", 0, 0, 100));
    gui.add(offsetXH.setup("x offset high bound", 0, 0, 100));
    gui.add(offsetYL.setup("y offset low bound", 0, 0, 100));
    gui.add(offsetYH.setup("y offset high bound", 0, 0, 100));
    
    gui.add(drawAll.setup("draw all lines", false));
    gui.add(faceOutline.setup("show face outline", true));
    gui.add(colorTo.setup("color to", false));

    
    // FaceOSC sends to port 8338 by default
    receiver.setup(8338);
    
    // FaceOSC raw message is 66 xy pairs
    for(int i = 0; i < 66; ++i) {
        points.push_back(ofVec2f());
    }
    
    //ofBackground(255);
    
    //loop through vector and addVertex to mesh
    /*for(int i = 0; i < 132; i = i+2) {
     mesh.addVertex(points[0].x, points[0].y);
     p++;
     }*/
    
    
    //setup our directory
    dir.setup();
    //setup our client
    client.setup();
    
    //register for our directory's callbacks
    ofAddListener(dir.events.serverAnnounced, this, &ofApp::serverAnnounced);
    // not yet implemented
    //ofAddListener(dir.events.serverUpdated, this, &ofApp::serverUpdated);
    ofAddListener(dir.events.serverRetired, this, &ofApp::serverRetired);
    
     dirIdx = -1;
    
    fbo.allocate(680, 480);
    pixels.allocate(640, 480, OF_PIXELS_RGBA);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // check for waiting osc messages
    while(receiver.hasWaitingMessages())
    {
        // get the next message
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        // load face from any FaceOSC messages
        face.parseOSC(m);
        
        /* // found face?
         if(face.found > 0) {
         cout << "---------" << endl
         << face.toString();
         }*/
        
        // found face?
        if(m.getAddress() == "/found") {
            found = (bool) m.getArgAsInt32(0);
        }
        
        // raw mesh points: 132 floats for 66 xy pairs
        else if(m.getAddress() == "/raw" && m.getNumArgs() == 132) {
            int p = 0;
            for(int i = 0; i < 132; i = i+2) {
                points[p].x = m.getArgAsFloat(i);
                points[p].y = m.getArgAsFloat(i+1);
                //mesh.addVertex(points[i], points[i+1]);
                p++;
            }
        }
    }
    
    /* int k = 0;
     for(int i = 0; i < 66; i += 1)
     {
     k = i;
     while (k < 66) {
     //if (points[i].x == points[k].x || points[i].y == points[k].y)
     if (points[i] == points[k])
     ofSetBackgroundColor(60, 150, 37);
     k++;
     
     }
     
     }*/
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    // draw a face
     if(face.found > 0) {
     ofPushMatrix();
     ofTranslate(face.posePosition);
     ofScale(face.poseScale, face.poseScale);
     
     ofSetColor(0);
     ofNoFill();
     ofDrawEllipse(-20, face.eyeLeft * -9, 20, 7);
     ofDrawEllipse(20, face.eyeRight * -9, 20, 7);
     ofDrawEllipse(0, 20, face.mouthWidth * 3, face.mouthHeight * 3);
     ofDrawEllipse(-5, face.nostrils * -1, 7, 3);
     ofDrawEllipse(5, face.nostrils * -1, 7, 3);
     
     ofSetRectMode(OF_RECTMODE_CENTER);
     ofFill();
     ofDrawRectangle(-20, face.eyebrowLeft * -5, 25, 5);
     ofDrawRectangle(20, face.eyebrowRight * -5, 25, 5);
     ofSetRectMode(OF_RECTMODE_CORNER);
     ofPopMatrix();
     }
    
    ofSetColor(255);
    fbo.begin();
    if(dir.isValidIndex(dirIdx)){
        ofSetColor(255);
        client.draw(0, 0);
    }
    fbo.end();
    fbo.draw(0,0);
    
    if(dir.isValidIndex(dirIdx)){
        ofTextureData &texData = client.getTexture().getTextureData();
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, fbo.getId());
        glReadPixels(0, 0, texData.width, texData.height, texData.glInternalFormat, GL_UNSIGNED_BYTE, pixels.getData());
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);
        //ofLog() << pixels.getColor(0,0);
    }
    
    //img = client.getImage();
    
    client.bind();
    client.getTexture().readToPixels(pixels);
    client.unbind();
    
    //ofLog() << pixels.getColor(100, 100);
    
    
    ofFill();
    ofSetColor(0);
    //ofDrawBitmapString("Be certain FaceOSC is sending 'raw' data!", 12, 20);
    //ofDrawBitmapString("Use Left and Right arrow keys to cycle points", 12, 40);
    //ofDrawBitmapString("current index = [" + ofToString(highlighted) + "]", 12, 60);
   
    //draw lines between each point
    int j = 0;
    int color = 0;
    float xOffset;
    float yOffset;
    for(int i = 0; i < 27; i += 1)
    {
        if (drawAll)
            j = 0;
        else
            j = i;
        while (j < 66) {
            xOffset = ofRandom(-offsetXL, offsetXH);
            yOffset = ofRandom(-offsetYL, offsetYH);
            if(colorTo)
                ofSetColor(pixels.getColor(points[i].x, points[i].y));
            else
                ofSetColor(pixels.getColor(points[j].x, points[j].y));
            ofDrawLine(points[i].x, points[i].y, points[j].x+xOffset, points[j].y+yOffset);
            j++;
            //color += 2;
        }
        //color = 0;
    }
    
    
    for(int i = 36; i < 66; i += 1)
    {
        if (drawAll)
            j = 0;
        else
            j = i;
        while (j < 66) {
            xOffset = ofRandom(-offsetXL, offsetXH);
            yOffset = ofRandom(-offsetYL, offsetYH);
            if(colorTo)
                ofSetColor(pixels.getColor(points[i].x, points[i].y));
            else
                ofSetColor(pixels.getColor(points[j].x, points[j].y));
            ofDrawLine(points[i].x, points[i].y, points[j].x+xOffset, points[j].y+yOffset);
            j++;
            //color += 2;
        }
        //color = 0;
    }
    
    for(int i = 31; i < 36; i += 1)
    {
        if (drawAll)
            j = 0;
        else
            j = i;
        while (j < 66) {
            xOffset = ofRandom(-offsetXL, offsetXH);
            yOffset = ofRandom(-offsetYL, offsetYH);
            if(colorTo)
                ofSetColor(pixels.getColor(points[i].x, points[i].y));
            else
                ofSetColor(pixels.getColor(points[j].x, points[j].y));            ofDrawLine(points[i].x, points[i].y, points[j].x+xOffset, points[j].y+yOffset);
            j++;
            //color += 2;
        }
        //color = 0;
    }
    
    for(int i = 27; i < 31; i += 1)
    {
        if (drawAll)
            j = 0;
        else
            j = i;
        while (j < 66) {
            xOffset = ofRandom(-offsetXL, offsetXH);
            yOffset = ofRandom(-offsetYL, offsetYH);
            if(colorTo)
                ofSetColor(pixels.getColor(points[i].x, points[i].y));
            else
                ofSetColor(pixels.getColor(points[j].x, points[j].y));
            ofDrawLine(points[i].x, points[i].y, points[j].x+xOffset, points[j].y+yOffset);
            j++;
            //color += 2;
        }
        //color = 0;
    }
    
    if(found && faceOutline) {
        //drawFacePoints();
        drawFacePolygons();
    }
    
    //for(int i = 0; i < 66; i += 1)
    //{
    //ofSetColor(255);
    //for (int j = 0; j < 66; j += 1)
    //    ofDrawLine(points[highlighted].x, points[highlighted].y, points[j].x, points[j].y);
    //}
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_RIGHT) {
        highlighted++;
        if(highlighted >= points.size()) {
            highlighted = 0;
        }
    }
    else if(key == OF_KEY_LEFT) {
        highlighted--;
        if(highlighted < 0) {
            highlighted = points.size()-1;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::drawFacePoints() {
    ofFill();
    //ofSetLineWidth(1);
    for(int i = 0; i < points.size(); i++) {
        if(i == highlighted) {
            ofSetColor(255, 0, 0);
            ofDrawCircle(points[i], 4);
        } else {
            ofSetColor(100);
            ofDrawCircle(points[i], 3);
        }
    }
}

//--------------------------------------------------------------
void ofApp::drawFacePolygons() {
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(lineWidth);
    
    // Face outline
    ofBeginShape();
    for(int i = 0; i < 17; i++) {
        ofVertex(points[i].x, points[i].y);
    }
    for(int i = 26; i > 16; i--) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape(OF_CLOSE);
    
    // Eyes
    ofBeginShape();
    for(int i = 36; i < 42; i++) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape(OF_CLOSE);
    ofBeginShape();
    for(int i = 42; i < 48; i++) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape(OF_CLOSE);
    
    // Upper lip
    ofBeginShape();
    for(int i = 48; i < 55; i++) {
        ofVertex(points[i].x, points[i].y);
    }
    for(int i = 62; i > 59; i--) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape(OF_CLOSE);
    
    // Lower lip
    ofBeginShape();
    for(int i = 54; i < 60; i+=2) {
        ofVertex(points[i].x, points[i].y);
    }
    ofVertex(points[48].x, points[48].y);
    for(int i = 65; i > 62; i--) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape(OF_CLOSE);
    
    // Nose bridge
    ofBeginShape();
    for(int i = 27; i < 31; i++) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape();
    
    // Nose bottom
    ofBeginShape();
    for(int i = 31; i < 36; i++) {
        ofVertex(points[i].x, points[i].y);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //press any key to move through all available Syphon servers
    if (dir.size() > 0)
    {
        dirIdx++;
        if(dirIdx > dir.size() - 1)
            dirIdx = 0;
        
        client.set(dir.getDescription(dirIdx));
        string serverName = client.getServerName();
        string appName = client.getApplicationName();
        
        if(serverName == ""){
            serverName = "null";
        }
        if(appName == ""){
            appName = "null";
        }
        ofSetWindowTitle(serverName + ":" + appName);
    }
    else
    {
        ofSetWindowTitle("No Server");
    }
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
    //draw line from face to mouse
    
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

//--------------------------------------------------------------
void ofApp::serverAnnounced(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        ofLogNotice("ofxSyphonServerDirectory Server Announced")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}

//--------------------------------------------------------------
void ofApp::serverUpdated(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        ofLogNotice("ofxSyphonServerDirectory Server Updated")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}

//--------------------------------------------------------------
void ofApp::serverRetired(ofxSyphonServerDirectoryEventArgs &arg)
{
    for( auto& dir : arg.servers ){
        ofLogNotice("ofxSyphonServerDirectory Server Retired")<<" Server Name: "<<dir.serverName <<" | App Name: "<<dir.appName;
    }
    dirIdx = 0;
}

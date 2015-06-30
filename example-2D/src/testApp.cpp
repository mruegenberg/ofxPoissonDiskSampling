#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    float w = ofGetWidth();
    float h = ofGetHeight();
    m_density = min<float>(w,h) * 0.03;
    m_samples = ofxPoissonDiskSampling::sample2D(w, h, m_density, false);
    
    printf("%d samples\n", m_samples.size());
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofSetColor(220,0,50);
    ofFill();
    for(ofVec2f v : m_samples) {
        ofCircle(v.x,v.y, 5);
    }
    
    ofSetColor(0,90,180);
    ofNoFill();
    for(ofVec2f v : m_samples) {
        ofCircle(v.x,v.y, m_density * 0.5);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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

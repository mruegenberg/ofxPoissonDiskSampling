#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    float w = ofGetWidth();
    float h = ofGetHeight();
    m_density = min<float>(w,h) * 0.05;
    m_samples = ofxPoissonDiskSampling::sample2D(w, h, m_density, false);

    // Uncomment to create samples with pure randomness
    /*
    int c = m_samples.size();
    m_samples.clear();
    for(int i=0; i<c; ++i)
        m_samples.push_back(ofVec2f(ofRandom(0,w), ofRandom(0,h)));
    */
    
    printf("%lu samples\n", m_samples.size());

    m_triangulation = ofxDelaunay2D::triangulate(m_samples);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    ofSetColor(150,120,0);
    ofNoFill();
    m_triangulation.drawWireframe();

    
    ofSetColor(220,0,50);
    ofFill();
    for(ofVec2f v : m_samples) {
        ofCircle(v.x,v.y, 5);
    }
    
    ofSetColor(0,170,230);
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

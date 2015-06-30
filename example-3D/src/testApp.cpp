#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAntiAliasing();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableDepthTest();
    ofSetSmoothLighting(true);
    ofSetSphereResolution(32);
    
    m_w = ofGetWidth();
    m_h = ofGetHeight();
    m_density = min<float>(m_w,m_h) * 0.1;
    m_samples = ofxPoissonDiskSampling::sample3D(m_w, m_h, m_density * 10, m_density, false);

    m_pointLight.setDiffuseColor(ofColor(0,0,255.f));
    m_pointLight.setSpecularColor(ofColor(255.f,0,0));
    m_pointLight.setPointLight();
//     m_pointLight.setPosition(0.25*m_w,0.25*m_h,100);
	

    m_material1.setShininess(64);
    m_material1.setSpecularColor(ofColor(255,0,0));
    m_material1.setDiffuseColor(ofColor(0,0,255));
    
    printf("%lu samples\n", m_samples.size());
}

//--------------------------------------------------------------
void testApp::update(){
    float radius = 700;
    ofVec3f center(m_w/2.0,m_h/2.0,0);
        m_pointLight.setPosition(cos(ofGetElapsedTimef()*.6f) * radius * 2 + center.x, 
						   sin(ofGetElapsedTimef()*.8f) * radius * 2 + center.y, 
						   -cos(ofGetElapsedTimef()*.8f) * radius * 2 + center.z);
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);

    ofEnableLighting();
    m_material1.begin();
    m_pointLight.enable();

    ofSetColor(255, 0, 0, 255);
    m_cam.begin();
    ofPushMatrix();
    ofTranslate(-m_w / 2, -m_h / 2);
    
    for(ofVec3f v : m_samples) {
        ofDrawSphere(v, 5);
    }

    ofPopMatrix();
    m_cam.end();
    
    m_pointLight.disable();
    m_material1.end();
    ofDisableLighting();

    /*
    ofSetColor(0,90,180);
    ofNoFill();
    for(ofVec3f v : m_samples) {
        ofCircle(v, m_density * 0.5);
    }
    */

    ofSetColor(255,255,255);
    ofDrawBitmapString("Use the mouse buttons to move the camera.", 50,50);
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

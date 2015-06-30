#pragma once

#include "ofMain.h"
#include "ofxPoissonDiskSampling.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
		
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
                
private:
    vector<ofVec3f> m_samples;
    float m_density;

    ofEasyCam m_cam;
    ofLight m_pointLight;
    ofMaterial m_material1;

    float m_w; float m_h;
};

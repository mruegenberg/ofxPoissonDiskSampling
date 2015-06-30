#include "ofMain.h"
#include "testApp.h"
#include "ofGLProgrammableRenderer.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
    
    ofSetupOpenGL(1024,768,OF_WINDOW);
    ofSetCircleResolution(32);

    ofRunApp(new testApp());
}

#include "testApp.h"
#undef PI
#undef TWO_PI
#undef HALF_PI
#include "TutorialApplication.h"

class MyThread : public ofThread {
        // the thread function
        void MyThread::threadedFunction() {

            // start
            ogreMain();
            // done
    }

};

//--------------------------------------------------------------
void testApp::setup(){
    // create object
    MyThread *thread = new MyThread;
    //ogreMain();
    // start the thread
    thread->startThread(true, false);    // blocking, non verbose    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

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
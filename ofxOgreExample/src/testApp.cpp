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
    m_datapool = &CDataPool::getInstance();
    SEntity entity = {0};   
    m_datapool->createEntity("pm", entity);
    // create object
    MyThread *thread = new MyThread;
    //ogreMain();
    // start the thread
    thread->startThread(true, false);    // blocking, non verbose    

    ofSetLogLevel(OF_LOG_VERBOSE);
    openNIDevice.setup();//FromXML("openni/config/ofxopenni_config.xml");
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    openNIDevice.addUserGenerator();
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
    openNIDevice.getWidth();

    openNIDevice.setMaxNumUsers(2);
    openNIDevice.setUsePointCloudsAllUsers(true);
    openNIDevice.start();
}

//--------------------------------------------------------------
void testApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void testApp::draw(){

    string msg = "Num of Users Tracked: " + ofToString(openNIDevice.getNumTrackedUsers());
    static string pm;
    int numUsers = openNIDevice.getNumTrackedUsers();
    if (numUsers) {
        for (int i = 0; i < numUsers; i++) {
            ofxOpenNIUser & user = openNIDevice.getTrackedUser(i);
            if (user.isTracking()) {
                //Get Left and right hand posisitons
                ofPoint rhp = openNIDevice.getTrackedUser(i).getJoint(JOINT_RIGHT_HAND).getWorldPosition();                
                //cout<< "x:" << rhp.x << endl;
                if ( rhp.x < -100){                    
                    if ( pm == "Wireframe")
                    {
                        break;
                    }              
                    cout << "changing to Wireframe"<<endl;
                    pm = "Wireframe";
                    m_datapool->setValue("pm", pm);
                }else if ( rhp.x > 100){                    
                    if ( pm == "Points")
                    {
                        break;
                    }
                    cout << "changing to Points"<<endl;
                    pm = "Points";
                    m_datapool->setValue("pm", pm);
                }else{
                    //cout << "changing to Solid"<<endl;
                    if ( pm == "Solid")
                    {
                        break;
                    }
                    
                    pm = "Solid";
                    m_datapool->setValue("pm", pm);
                }                              
            }
        }

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
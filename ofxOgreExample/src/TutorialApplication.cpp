/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.cpp
-----------------------------------------------------------------------------

This source file is part of the
___                 __    __ _ _    _ 
/___\__ _ _ __ ___  / / /\ \ (_) | _(_)
//  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
|___/                              
Tutorial Framework
http://www.ogre3d.org/tikiwiki/
-----------------------------------------------------------------------------
*/
#include "TutorialApplication.h"

//-------------------------------------------------------------------------------------
TutorialApplication::TutorialApplication(void)
{
    m_datapool = &DataPool::CDataPool::getInstance();
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}
void TutorialApplication::eventLoop()
{
    ofSleepMillis(5000);
    Ogre::PolygonMode pm;
    void *temp = 0;
    
    while(1){
        m_datapool->getRefByName("pm", temp);
        if (temp != 0)
        {            
            string *str = (string *)temp;
            //cout<<"string"<<*str<<endl;
            if ( *str == "Wireframe" )
            {
                pm = Ogre::PM_WIREFRAME;
                //cout<<"changing to WireFrame"<<endl;
            }else if ( *str == "Points")
            {
                pm = Ogre::PM_POINTS;
                //cout<<"changing to Points"<<endl;
            }else{
                pm = Ogre::PM_SOLID;
                //cout<<"changing to Solid"<<endl;
            }
            mCamera->setPolygonMode(pm);
            mDetailsPanel->setParamValue(10, *str);
        }       
    }
}
//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
    Ogre::Entity* ogreHead = mSceneMgr->createEntity("Head", "ogrehead.mesh");
    Ogre::SceneNode* headNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("HeadNode");
    headNode->attachObject(ogreHead);
    Ogre::Light* light = mSceneMgr->createLight( "MainLight" );
    light->setPosition(20, 80, 50);
    // create your scene here :)    
    cout<<"start event loop"<<endl<<endl<<endl;
    startThread();
}



#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

int ogreMain()
{
    // Create application object
    TutorialApplication app;
    try {
        app.go();
    } catch( Ogre::Exception& e ) {
        std::cerr << "An exception has occured: " <<
            e.getFullDescription().c_str() << std::endl;
    }

    return 0;
}


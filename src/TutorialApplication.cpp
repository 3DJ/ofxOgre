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
    
}
//-------------------------------------------------------------------------------------
TutorialApplication::~TutorialApplication(void)
{
}

//-------------------------------------------------------------------------------------
void TutorialApplication::createScene(void)
{
    mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5f, 0.5f, 0.5f));
    Ogre::Entity* a1 = mSceneMgr->createEntity("a1", "cube.mesh");
    Ogre::SceneNode* aNode1 = mSceneMgr->getRootSceneNode()->createChildSceneNode("aNode1");
    aNode1->attachObject(a1);
    aNode1->scale(0.1, 0.1, 0.1);
    aNode1->setPosition(-30,20,0);
    aNode1->yaw( Ogre::Degree( 20 ) );

    Ogre::Entity* a2 = mSceneMgr->createEntity( "a2", "cube.mesh" );
    Ogre::SceneNode* aNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "aNode2" );
    aNode2->attachObject( a2 );
    aNode2->scale(0.11, 0.11, 0.11);
    aNode2->setPosition(-10,20,-10);
    aNode2->yaw( Ogre::Degree( 10 ) );

    Ogre::Entity* a3 = mSceneMgr->createEntity( "a3", "cube.mesh" );
    Ogre::SceneNode* aNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "aNode3");
    aNode3->attachObject( a3 );
    aNode3->scale(0.11, 0.11, 0.11);
    aNode3->setPosition(10,20,-10);
    aNode3->yaw( Ogre::Degree( -10 ) );

    Ogre::Entity* a4 = mSceneMgr->createEntity( "a4", "cube.mesh" );
    Ogre::SceneNode* aNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "aNode4");
    aNode4->attachObject( a4 );
    aNode4->scale(0.1, 0.1, 0.1);
    aNode4->setPosition(30,20,0);
    aNode4->yaw( Ogre::Degree( -20 ) );

    Ogre::Entity* b1 = mSceneMgr->createEntity( "b1", "cube.mesh" );
    Ogre::SceneNode* bNode1 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "bNode1");
    bNode1->attachObject( b1 );
    bNode1->scale(0.1, 0.1, 0.1);
    bNode1->setPosition(-30,0,0);
    bNode1->yaw( Ogre::Degree( 20 ) );

    Ogre::Entity* b2 = mSceneMgr->createEntity( "b2", "cube.mesh" );
    Ogre::SceneNode* bNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "bNode2" );
    bNode2->attachObject( b2 );
    bNode2->scale(0.11, 0.11, 0.11);
    bNode2->setPosition(-10, 0,-10);
    bNode2->yaw( Ogre::Degree( 10 ) );

    Ogre::Entity* b3 = mSceneMgr->createEntity( "b3", "cube.mesh" );
    Ogre::SceneNode* bNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "bNode3");
    bNode3->attachObject( b3 );
    bNode3->scale(0.11, 0.11, 0.11);
    bNode3->setPosition(10, 0,0);
    bNode3->yaw( Ogre::Degree( -10 ) );

    Ogre::Entity* b4 = mSceneMgr->createEntity( "b4", "cube.mesh" );
    Ogre::SceneNode* bNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "bNode4");
    bNode4->attachObject( b4 );
    bNode4->scale(0.1, 0.1, 0.1);
    bNode4->setPosition(30,0,0);
    bNode4->yaw( Ogre::Degree( -20 ) );

    Ogre::Entity* c1 = mSceneMgr->createEntity("c1", "cube.mesh");
    Ogre::SceneNode* cNode1 = mSceneMgr->getRootSceneNode()->createChildSceneNode("cNode1");
    cNode1->attachObject(c1);
    cNode1->scale(0.1, 0.1, 0.1);
    cNode1->setPosition(-30, -20,0);
    cNode1->yaw( Ogre::Degree( 20 ) );

    Ogre::Entity* c2 = mSceneMgr->createEntity( "c2", "cube.mesh" );
    Ogre::SceneNode* cNode2 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "cNode2" );
    cNode2->attachObject( c2 );
    cNode2->scale(0.11, 0.11, 0.11);
    cNode2->setPosition(-10, -20,-10);
    cNode2->yaw( Ogre::Degree( 10 ) );

    Ogre::Entity* c3 = mSceneMgr->createEntity( "c3", "cube.mesh" );
    Ogre::SceneNode* cNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "cNode3");
    cNode3->attachObject( c3 );
    cNode3->scale(0.11, 0.11, 0.11);
    cNode3->setPosition(10, -20,-10);
    cNode3->yaw( Ogre::Degree( -10 ) );

    Ogre::Entity* c4 = mSceneMgr->createEntity( "c4", "cube.mesh" );
    Ogre::SceneNode* cNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "cNode4");
    cNode4->attachObject( c4 );
    cNode4->scale(0.1, 0.1, 0.1);
    cNode4->setPosition(30, -20,0);
    cNode4->yaw( Ogre::Degree( -20 ) );
}
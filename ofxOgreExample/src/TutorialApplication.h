/*
-----------------------------------------------------------------------------
Filename:    TutorialApplication.h
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
#ifndef __TutorialApplication_h_
#define __TutorialApplication_h_

#include "BaseApplication.h"
#include "ofThread.h"
#include "ofMain.h"
#include "DataPool.h"

int ogreMain();

class TutorialApplication : public BaseApplication, public ofThread
{
public:
    TutorialApplication(void);
    virtual ~TutorialApplication(void);

    void threadedFunction(){
        eventLoop();
    }
protected:
    void eventLoop();
    virtual void createScene(void);
    DataPool::CDataPool *m_datapool;
};

#endif // #ifndef __TutorialApplication_h_

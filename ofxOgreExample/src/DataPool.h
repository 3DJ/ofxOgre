//
//  CBoxButton.cpp
//  Kinect_3DJ
//
//  Created by LJ on 10/1/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Kinect_3DJ_DataPool_h
#define Kinect_3DJ_DataPool_h

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

#include "ofThread.h"


struct SEntity{
    bool isSaved;
    string value;     
    void* pointer;
};
typedef map<string, SEntity> mapEntity;

namespace DataPool{
    // I didn't add the lock on the config file saving
    class CDataPool : public ofThread{

    public:
        static CDataPool& getInstance(){
            static CDataPool _instance;
            return _instance;
        }
        bool initSounds();

        bool getEntityByName( string key, SEntity& entity);
        // get a value which is created by "createEntity"
        bool getValueByName( string key, string& val );

        // get the the reference of the key which is created by "createRef"
        bool getRefByName( string key, void* &val );
        // this will be deprecated(using getRefByName instead of). it's the same as getRefByName. just for compatibility.
        bool getPointerByName( string key, void* &val);

        mapEntity getDataPool();

        // return value: false not mean U didn't create the entity. u need to check it by findValue
        bool createEntity( string key, SEntity entity );

        // create a Ref wont be saved to datapool.3dj file. It's only used to pass the data between controller and viewer
        // isSaved sign will be set as false.
        bool createRef( string key, void* val);

        // return value: false not mean U didn't set the value. u need to check it by findValue
        bool setEntity( string key, SEntity entity);

        // alter the value which is created by "creatEntity", if cover is false, the data wont be replaced
        bool setValue( string key, string val, bool cover = false );
        // recommend
        string* findValueRef( string key);

        // It will be removed later. don't use it.
        SEntity* findEntityRefInVector( string val );

        // deprecated. It will be removed later. don't use it.
        vector<mapEntity::iterator> getVector();
        // deprecated. It will be removed later. don't use it.
        int findIndexInVector( string val );

    private:
        CDataPool(){ initSounds();}
        CDataPool(const CDataPool&);
        CDataPool& operator=(const CDataPool&);

        vector<mapEntity::iterator> m_vectorRefEntity;
        mapEntity m_mapDataPool;
    };
};

#endif

//
//  GameScene.h
//  Oshigoto
//
//  Created by Furukawa on 2016/06/10.
//
//

#ifndef __Oshigoto__GameScene__
#define __Oshigoto__GameScene__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MultiResolution.h"
#include "FLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

class GameScene : public FLayer
{
public:
    static Scene *createScene();
    static GameScene *create();
    virtual bool init();
    void update(float delta);
    
};

#endif /* defined(__Oshigoto__GameScene__) */

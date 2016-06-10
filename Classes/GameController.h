//
//  GameController.h
//  Factorian
//
//  Created by Furukawa on 2016/06/01.
//
//

#ifndef __Factorian__GameController__
#define __Factorian__GameController__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MultiResolution.h"
#include "FLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

class GameController : public FLayer
{
public:
    static GameController *_instance;
    static GameController *getInctance();
    static GameController *create();
    virtual bool init();
    void update(float delta);
    
    static GameController *recreate();
    
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    
    Vec2 getTouchPos();
    Vec2 getTouchBeganPos();
    bool isTouch();
    bool isTouchBegan();
    bool isTouchEnded();
    
    void setAutoMode(bool isAutoMode);
    
private:
    
    Vec2 _touchBeganPos;
    Vec2 _touchPos;
    
    bool _isTouch;
    bool _isTouchBegan;
    bool _isTouchEnded;
    bool _isAutoMode;
};

#endif /* defined(__Factorian__GameController__) */

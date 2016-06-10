//
//  FScale9SpriteButton.h
//  Factorian
//
//  Created by Furukawa on 2016/06/05.
//
//

#ifndef __Factorian__FScale9SpriteButton__
#define __Factorian__FScale9SpriteButton__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MultiResolution.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;
using namespace extension;

class FScale9SpriteButton : public Scale9Sprite
{
public:
    static FScale9SpriteButton *create(Size size, string text);
    virtual bool init(Size size, string text);
    void update(float delta);
    
    
    void setFunction(function<void ()> func);
    
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
    void onTouchEnded(Touch *touch, Event *event);
    
    void setString(string str);
    
protected:
    
    Label *_textLabel;
    function<void ()> _func;
};

#endif /* defined(__Factorian__FScale9SpriteButton__) */

//
//  FScale9SpriteButton.cpp
//  Factorian
//
//  Created by Furukawa on 2016/06/05.
//
//

#include "FScale9SpriteButton.h"

FScale9SpriteButton *FScale9SpriteButton::create(Size size, string text)
{
    FScale9SpriteButton *pRet = new FScale9SpriteButton();
    if(pRet && pRet->init(size, text))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool FScale9SpriteButton::init(Size size, string text)
{
    if ( !Scale9Sprite::init() ) return false;
    
    initWithFile("image/ui/waku.png");
    
    setContentSize(size);
    
    _textLabel = Label::createWithTTF(text, "fonts/misaki_gothic.ttf", 8);
    _textLabel->getTexture()->setAliasTexParameters();
    _textLabel->setPosition(getBoundingBox().size/2);
    _textLabel->setColor(Color3B(55, 55, 55));
    addChild(_textLabel);
    
    
    // タッチ
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(FScale9SpriteButton::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(FScale9SpriteButton::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(FScale9SpriteButton::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    
    scheduleUpdate();
    return true;
}

void FScale9SpriteButton::update(float delta)
{
    
}

void FScale9SpriteButton::setFunction(function<void ()> func)
{
    _func = func;
}

bool FScale9SpriteButton::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    return true;
}

void FScale9SpriteButton::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    
}

void FScale9SpriteButton::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    if(_func && getBoundingBox().containsPoint(touch->getLocation()))
    {
        _func();
        
        stopAllActions();
        runAction(Sequence::create(EaseOut::create(ScaleTo::create(0.05, 0.7), 2),
                                   EaseIn::create(ScaleTo::create(0.05, 1), 2),
                                   NULL));
    }
}


void FScale9SpriteButton::setString(string str)
{
    _textLabel->setString(str);
}














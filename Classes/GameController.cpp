//
//  GameController.cpp
//  Factorian
//
//  Created by Furukawa on 2016/06/01.
//
//

#include "GameController.h"

GameController *GameController::_instance = NULL;

GameController *GameController::getInctance()
{
    if(!_instance)
    {
        _instance = GameController::create();
    }
    
    return _instance;
}

GameController *GameController::create()
{
    GameController *pRet = new GameController();
    if(pRet && pRet->init())
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

GameController* GameController::recreate()
{
    _instance = GameController::create();
    return _instance;
}

bool GameController::init()
{
    if ( !FLayer::init() ) return false;
    
    _touchPos = Vec2::ZERO;
    _touchBeganPos = Vec2::ZERO;
    
    _isTouch = false;
    _isTouchBegan = false;
    _isTouchEnded = false;
    
    return true;
}

void GameController::update(float delta)
{
    if(_isTouchBegan) _isTouchBegan = false;
    if(_isTouchEnded) _isTouchEnded = false;
    
    
}

bool GameController::onTouchBegan(Touch *touch, Event *event)
{
    _touchPos = touch->getLocation();
    _touchBeganPos = _touchPos;
    
    _isTouch = true;
    _isTouchBegan = true;
    
    return true;
}

void GameController::onTouchMoved(Touch *touch, Event *event)
{
    _touchPos = touch->getLocation();
}

void GameController::onTouchEnded(Touch *touch, Event *event)
{
    _touchPos = touch->getLocation();
    
    _isTouch = false;
    _isTouchEnded = true;
}

bool GameController::isTouch()
{
    return _isTouch;
}

bool GameController::isTouchBegan()
{
    return _isTouchBegan;
}

bool GameController::isTouchEnded()
{
    return _isTouchEnded;
}

void GameController::setAutoMode(bool isAutoMode)
{
    _isAutoMode = isAutoMode;
}

Vec2 GameController::getTouchPos()
{
    return _touchPos;
}

Vec2 GameController::getTouchBeganPos()
{
    return _touchBeganPos;
}
















//
//  GameScene.cpp
//  Oshigoto
//
//  Created by Furukawa on 2016/06/10.
//
//

#include "GameScene.h"
#include "GameController.h"

Scene *GameScene::createScene()
{
    auto scene = Scene::create();
    scene->addChild(GameScene::create());
    return scene;
}

GameScene *GameScene::create()
{
    GameScene *pRet = new GameScene();
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

bool GameScene::init()
{
    if ( !FLayer::init() ) return false;
    
    auto gameCtrl = GameController::recreate();
    addChild(gameCtrl);
    
    
    scheduleUpdate();
    gameCtrl->scheduleUpdate();
    
    return true;
}

void GameScene::update(float delta)
{
    
}
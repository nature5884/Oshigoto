//
//  TownScene.cpp
//  Oshigoto
//
//  Created by Kobayashi on 2016/06/10.
//
//

#include "TownScene.h"
#include "GameController.h"

Scene *TownScene::createScene()
{
	auto scene = Scene::create();
	scene->addChild(TownScene::create());
	return scene;
}

TownScene *TownScene::create()
{
	TownScene *pRet = new TownScene();
	if (pRet && pRet->init())
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

bool TownScene::init()
{
	if (!FLayer::init())
	{
		return false;
	}

	auto gameCtrl = GameController::recreate();
	addChild(gameCtrl);

	TMXTiledMap *testMap = TMXTiledMap::create("printTest.tmx");
	testMap->setPosition(0,0);
	this->addChild(testMap);

	auto test = Sprite::create("house.png");
	test->setPosition(100, 100);
	this->addChild(test);

	scheduleUpdate();
	gameCtrl->scheduleUpdate();

	return true;
}

void TownScene::update(float delta)
{
	
}
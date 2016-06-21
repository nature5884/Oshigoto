//
//  TownScene.h
//  Oshigoto
//
//  Created by Kobayashi on 2016/06/10.
//
//

#ifndef _TOWN_SCENE_H_
#define _TOWN_SCENE_H_

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "MultiResolution.h"
#include "FLayer.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace std;

class TownScene : public FLayer
{
public:
	static Scene *createScene();
	static TownScene *create();
	virtual bool init();
	void update(float delta);

};

#endif _TOWN_SCENE_H_
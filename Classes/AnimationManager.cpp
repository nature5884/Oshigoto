//
//  AnimationManager.cpp
//  TextScript1
//
//  Created by Furukawa on 2014/11/20.
//
//

#include "AnimationManager.h"

// アニメーションキャッシュ追加
void AnimationManager::addAnimationCache(string path, string cacheName, int startNum, int endNum, float delay)
{
    // アニメーションの準備
    auto *_animation = Animation::create();
    for (int i = startNum; i < endNum; i++) {
        auto str = __String::createWithFormat("%s%i.png", path.c_str(), i);
        _animation->addSpriteFrameWithFile(str->getCString());
    }
    
    _animation->setDelayPerUnit(delay);
    _animation->setRestoreOriginalFrame(true);
    
    // キャッシュに登録
    AnimationCache::getInstance()->addAnimation(_animation, cacheName);
}

void AnimationManager::addAnimationCacheWalk4(string path, string cacheName, int startNum, float delay)
{
    int frame[] = {0,1,0,2};
    // アニメーションの準備
    auto *_animation = Animation::create();
    for (int i = 0; i < 4; i++) {
        auto str = __String::createWithFormat("%s%i.png", path.c_str(), startNum + frame[i]);
        _animation->addSpriteFrameWithFile(str->getCString());
    }
    
    _animation->setDelayPerUnit(delay);
    _animation->setRestoreOriginalFrame(true);
    
    // キャッシュに登録
    AnimationCache::getInstance()->addAnimation(_animation, cacheName);
}

// 指定回リピートするアニメートアクションをキャッシュから生成
Repeat* AnimationManager::createRepeat(string cacheName, unsigned int time)
{
    return Repeat::create(Animate::create(AnimationCache::getInstance()->getAnimation(cacheName)), time);
}

// 永遠にリピートするアニメートアクションをキャッシュから生成
RepeatForever* AnimationManager::createRepeatForever(string cacheName)
{
    return RepeatForever::create(Animate::create(AnimationCache::getInstance()->getAnimation(cacheName)));
}
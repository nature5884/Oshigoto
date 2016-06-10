//
//  Label.cpp
//  TextScript1
//
//  Created by Furukawa on 2014/10/28.
//
//

#include "FLabel.h"
#include <locale.h>

const int FLabel::STRING_LINE_MAX = 10;

FLabel *FLabel::create(string str, string fontFile, int fontSize)
{
    FLabel *ret = new FLabel();
    
    if(ret && ret->init(str, fontFile, fontSize))
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        delete ret;
        ret = NULL;
        return NULL;
    }
}

bool FLabel::init(string str, string fontFile, int fontSize)
{
    if(!cocos2d::Label::init()) return false;
    
    setString("");
    
    TTFConfig ttfConfig(fontFile.c_str(), fontSize, GlyphCollection::DYNAMIC);
    setTTFConfig(ttfConfig);
    
    baseString = str;
    frameCnt = 0;
    
    lineCount = 0;
    
    running = false;
    cansel = false;
    
    scheduleUpdate();
    
    return true;
}

void FLabel::update(float delta)
{
    if(running)
    {
        runString();
    }
}

void FLabel::startRunString(string text, float dt)
{
    setString("");
    baseString = text;
    delayTime = dt;
    
    running = true;
    lineCount = 0;
    
    frameCnt = 0;
}

void FLabel::endRunString()
{
    tempDelayTime = delayTime;
    delayTime = 0;
    cansel = true;
}

void FLabel::runString()
{
    if(frameCnt >= delayTime * 60)
    {
        
        if(getString().length() < baseString.length())
        {
            int len = 1;
            
            if(baseString[getString().length()] == '\n'||
               baseString[getString().length()] == '\0')
            {
                len = 1;
            }
            else if(baseString[getString().length()] > 'z' ||
               baseString[getString().length()] < ' ' )
            {
                len = 3;
            }
            
            // 現在の文字を格納
            talkingChar = baseString.substr(getString().length(), len);
//            log("%s", talkingChar.c_str());
            
            // 改行なかったら文字数＋１
            if(baseString[getString().length()] != '\n') lineCount++;
            
            // 文字数が
//            if(lineCount >= STRING_LINE_MAX)
//            {
//                baseString.insert(getString().length() + len, "\n");
//                lineCount = 0;
//            }
            
            // ベース文字列から、必要な長さを部分的にコピーする。
            setString(baseString.substr(0, getString().length() + len));
            
            
//            printf("%s\n", baseString.substr(0, getString().length()).c_str());
        }
        
        else
        {
            running = false;
            if(cansel)
            {
                delayTime = tempDelayTime;
                cansel = false;
            }
        }
    }
    
    // カウントアップ
    if(frameCnt >= delayTime * 60) frameCnt = 0;
    else frameCnt++;
}
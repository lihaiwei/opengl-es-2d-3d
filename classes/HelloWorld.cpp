//
//  HelloWorld.cpp
//  HelloMonkey
//
//  Created by Neil on 4/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "HelloWorld.h"
#include "App.h"

#include "2d/scene/Scene2D.h"
#include "2d/entities/Image.h"
#include "core/texture/TextureAtlas.h"
#include "core/utils/Log.h"
#include "2d/ui/button/ButtonImage.h"
#include "2d/ui/Slider.h"
#include "2d/entities/MovieClip.h"

NS_MONKEY_BEGIN

HellWorld::HellWorld() : Scene2D(), _speed(30.0f), _lastTime(0.0f) {
    init();
}

HellWorld::~HellWorld() {
    
}

void HellWorld::init() {
    
    _speed = 240; // 速度240像素每秒
    
    App::getInstance()->setBackcolor(0xFF00FF);
    
    float screenWidth  = App::getInstance()->getWidth();
    float screenHeight = App::getInstance()->getHeight();
    // 载入资源
    TextureAtlas::getInstance()->addTextureAtlasWithJson("flappbird.json");
    // 添加背景
    Image *background = Image::create("background.png");
    background->setScale(2, 2, 2);
    addChild(background);
    // 初始化地板以及天空
    for (int i = 0; i < 10; i++) {
        Image *land = Image::createFrameTexture("land.png");
        land->setPosition(i * land->getWidth(), -screenHeight + land->getHeight(), -1.0f);
        addChild(land);
        _lands.push_back(land);
        
        Image *sky = Image::createFrameTexture("sky.png");
        sky->setPosition(i * sky->getWidth(), land->getY() + sky->getHeight() - 10, 0);
        addChild(sky);
        _skys.push_back(sky);
    }
    // 初始化水管
    MovieClip *bird = new MovieClip();
    // 初始化鸟
    for (int i = 1; i < 5; i++) {
        char str[50];
        sprintf(str, "bird-0%d.png", i);
        std::string frame(str);
        bird->addFrame(frame, MovieClip::Type::TEXTURE_FRAME);
    }
    bird->setPosition(screenWidth/2, -screenHeight/2, 0);
    bird->setFps(15);
    bird->play();
    
    addChild(bird);
    
    
    _lastTime = App::getInstance()->getRunningTime();
    addEventListener(Scene2D::RENDER_EVENT, this, EVENT_CALLBACK(HellWorld::onEnterFrame));
}

void HellWorld::onEnterFrame(monkey::Event *e) {
    float currentTime = App::getInstance()->getRunningTime();
    
    moveBackground(currentTime - _lastTime);
    
    _lastTime = currentTime;
}

void HellWorld::moveBackground(float advanceTime) {
    float speed = advanceTime * _speed;
    // 滚动背景
    for (auto iter = _skys.begin(); iter != _skys.end(); iter++) {
        (*iter)->getPosition(_temp);
        (*iter)->setPosition(_temp.x - (int)speed, _temp.y, _temp.z);
        if ((*iter)->getX() + (*iter)->getWidth() < 0) {
            (*iter)->setPosition(App::getInstance()->getWidth(), _temp.y, _temp.z);
        }
    }
    // 滚动陆地
    for (auto iter = _lands.begin(); iter != _lands.end(); iter++) {
        (*iter)->getPosition(_temp);
        (*iter)->setPosition(_temp.x - (int)speed, _temp.y, _temp.z);
        if ((*iter)->getX() + (*iter)->getWidth() < 0) {
            (*iter)->setPosition(App::getInstance()->getWidth(), _temp.y, _temp.z);
        }
    }
}

NS_MONKEY_END

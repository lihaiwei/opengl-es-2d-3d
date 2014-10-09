//
//  Application.cpp
//  HelloMonkey
//
//  Created by Neil on 7/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "MainDelegate.h"

#include <App.h>
#include <2d/scene/Scene2D.h>
#include <2d/entities/Image.h>
#include <2d/ui/font/Font.h>
#include <2d/ui/font/FontCache.h>
#include <2d/ui/font/FontFNT.h>
#include <2d/ui/font/FontFNTConfig.h>
#include <2d/ui/font/TextFormatter.h>
#include <2d/ui/label/Label.h>
#include <2d/ui/label/LabelFNT.h>
#include <core/utils/Log.h>
#include "2d/ui/button/Button.h"
#include "2d/ui/button/ButtonImage.h"

USING_NS_MONKEY

MainDelegate::MainDelegate() {
    
}

MainDelegate::~MainDelegate() {
    
}

void MainDelegate::onClick(monkey::Event &event) {
    LOGE("TOUCH_IN -> xiaofeiji.jpg");
}

void MainDelegate::didFinishLaunching() {
    Scene2D *scene = new Scene2D();
    scene->setViewport(0, 0, App::getInstance()->getWidth(), App::getInstance()->getHeight());
    
    Image *img = Image::create("xiaofeiji.jpg");
    img->setPosition(100.0f, -200.0f, 0.0f);
    scene->addChild(img);
    img->addEventListener(TouchEvent::TOUCH_HIT, this, EVENT_CALLBACK(MainDelegate::onClick));
    
    Label *label = Label::create("Ni hao A.", "", 24);
    scene->addChild(label);
    
    LabelFNT *fnt = LabelFNT::create("bitmapFontChinese.fnt", "亲自成立于HelloWORD!123");
    fnt->setPosition(200.0f, -300.0f, 0.0f);
//    scene->addChild(fnt);
    
    ButtonImage *btn = new ButtonImage();
    btn->initWithImage("animationbuttonnormal.png", "animationbuttonpressed.png");
//    scene->addChild(btn);
    btn->addChild(fnt);
    btn->setPosition(0, 0, 0.0f);
    
    img->addChild(btn);
    
    App::getInstance()->addScene2D(scene);
}

void MainDelegate::didEnterBackground() {
    
}

void MainDelegate::didEnterForeground() {
    
}

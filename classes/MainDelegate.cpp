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
#include <platform/TextureUtils.h>
#include "2d/ui/button/Button.h"
#include "2d/ui/button/ButtonImage.h"
#include <2d/entities/Quad.h>
#include <2d/ui/button/CheckBox.h>

USING_NS_MONKEY

MainDelegate::MainDelegate() {
    
}

MainDelegate::~MainDelegate() {
    
}

void MainDelegate::onClick(monkey::Event &event) {
    LOGE("TOUCH_IN -> xiaofeiji.jpg");
}

void MainDelegate::didFinishLaunching() {
    
    float screenWidth  = App::getInstance()->getWidth();
    float screenHeight = App::getInstance()->getHeight();
    
    Scene2D *scene = new Scene2D();
    scene->setViewport(0, 0, App::getInstance()->getWidth(), App::getInstance()->getHeight());
    
    Image *img = Image::create("xiaofeiji.jpg");
    img->setPosition(0.0f, -0.0f, 0.0f);
    scene->addChild(img);
    img->addEventListener(TouchEvent::TOUCH_HIT, this, EVENT_CALLBACK(MainDelegate::onClick));
    
    Label *sysFont = Label::create("Hello , This is 系统字体。", "", 24);
    sysFont->setPosition(100.0f, -300.0f, 0.0f);
    scene->addChild(sysFont);
    
    LabelFNT *fnt = LabelFNT::create("bitmapFontChinese.fnt", "亲自成立于HelloWORD!123");
    fnt->setPosition(0.0f, -300.0f, 0.0f);
    
    ButtonImage *btn = new ButtonImage();
    btn->initWithImage("animationbuttonnormal.png", "animationbuttonpressed.png");
    btn->setPosition(0, 0, 0.0f);
    
    btn->addChild(fnt);
    img->addChild(btn);
    
    CheckBox *checkbox = new CheckBox();
    checkbox->initwithImage("check_box_normal.png", "check_box_normal_press.png", "check_box_active.png", "check_box_active_press.png");
    checkbox->setPosition(screenWidth / 2, -screenHeight / 2, 0);
    
    scene->addChild(checkbox);
    
    App::getInstance()->addScene2D(scene);
}

void MainDelegate::didEnterBackground() {
    
}

void MainDelegate::didEnterForeground() {
    
}

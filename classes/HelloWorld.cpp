//
//  HelloWorld.cpp
//  HelloMonkey
//
//  Created by Neil on 4/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "HelloWorld.h"
#include "App.h"

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
#include <2d/ui/ProgressBar.h>
#include <2d/ui/Slider.h>

NS_MONKEY_BEGIN

HellWorld::HellWorld() : Scene2D() {
    init();
}

HellWorld::~HellWorld() {
    
}

void HellWorld::init() {
    float screenWidth  = App::getInstance()->getWidth();
    float screenHeight = App::getInstance()->getHeight();
    
    Image *img = Image::create("xiaofeiji.jpg");
    img->setPosition(0.0f, -0.0f, 0.0f);
    addChild(img);
    
    Label *sysFont = Label::create("Hello , This is 系统字体。", "", 24);
    sysFont->setPosition(100.0f, -300.0f, 0.0f);
    addChild(sysFont);
    
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
    
    addChild(checkbox);
    
    ProgressBar* progressBar = new ProgressBar();
    progressBar->initWithTexture("sliderProgress.png");
    progressBar->setPosition(0, -100, 0);
    progressBar->setPercent(0.5f);
    progressBar->setTotalLength(screenWidth);
    
    addChild(progressBar);
    
    Slider *slider = new Slider();
    slider->initWithTextures("sliderTrack.png", "sliderThumb.png", "sliderThumb.png", "sliderProgress2.png");
    slider->setPosition(50.0f, -200, 0);
    
    addChild(slider);
    
}

NS_MONKEY_END
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

USING_NS_MONKEY

MainDelegate::MainDelegate() {
    
}

MainDelegate::~MainDelegate() {
    
}

void MainDelegate::didFinishLaunching() {
    Scene2D *scene = new Scene2D();
    scene->setViewport(0, 0, App::getInstance()->getWidth(), App::getInstance()->getHeight());
    
    Image *img = Image::create("xiaofeiji.jpg");
    scene->addChild(img);
    
    Label *label = Label::create("Ni hao A.", "", 24);
    scene->addChild(label);
    
    App::getInstance()->addScene2D(scene);
}

void MainDelegate::didEnterBackground() {
    
}

void MainDelegate::didEnterForeground() {
    
}

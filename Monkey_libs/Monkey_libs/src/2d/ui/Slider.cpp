//
//  Slider.cpp
//  Monkey_libs
//
//  Created by Neil on 2/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "2d/ui/Slider.h"

NS_MONKEY_BEGIN

Slider::Slider() {
    
}

Slider::~Slider() {
    
}

void Slider::initWithTextures(const std::string &bar, const std::string &ballUp, const std::string &ballDown, const std::string &progress, Type type) {
    
}

void Slider::loadBarTexture(const std::string &fileName, Type type) {
    
}

void Slider::loadSliderBallTextures(const std::string &up, const std::string &down, Type type) {
    
}

void Slider::loadProgressBarTexture(const std::string &progress, Type type) {
    
}

void Slider::setPercent(float value) {
    
}

float Slider::getPercent() const {
    return _progress->getPercent();
}

void Slider::setLength(float value) {
    _progress->setTotalLength(value);
}

float Slider::getLength() const {
    return _progress->getTotalLength();
}

NS_MONKEY_END
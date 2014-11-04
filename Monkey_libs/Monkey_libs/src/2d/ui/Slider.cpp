//
//  Slider.cpp
//  Monkey_libs
//
//  Created by Neil on 2/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "2d/ui/Slider.h"

NS_MONKEY_BEGIN

Slider::Slider() :
Widget(),
_bar(nullptr),
_sliderBall(nullptr),
_progress(nullptr)
{
    
}

Slider::~Slider() {
    
}

void Slider::initWithTextures(const std::string &bar, const std::string &ballUp, const std::string &ballDown, const std::string &progress, Type type) {
    
    loadBarTexture(bar, type);
    loadProgressBarTexture(progress, type);
    loadSliderBallTextures(ballUp, ballDown, type);
    // 设置组件位置
    
    _bar->setAnchor(0.0f, 0.5f);        // bar摆到中间
    _bar->setPosition(0.0f, -_height/2, 0.0f);
    _progress->setAnchor(0.0f, 0.5f);   //
    _progress->setPosition(0.0f, -_height/2, 0.0f);
    _sliderBall->setPosition(0, 0, 0);
    
    setPercent(0.6);
}

void Slider::loadBarTexture(const std::string &fileName, Type type) {
    if (_bar) {
        removeWidget(_bar);
        delete _bar;
        _bar = nullptr;
    }
    switch (type) {
        case Widget::Type::TEXTURE:
            _bar = Image::create(fileName);
            break;
        case Widget::Type::TEXTURE_FRAME:
            _bar = Image::createFrameTexture(fileName);
            break;
        default:
            return;
            break;
    }
    addWidget(_bar);
    _width  = _bar->getWidth();
    _min.setTo(0, 0);
    _max.setTo(_width, _height);
}

void Slider::loadSliderBallTextures(const std::string &up, const std::string &down, Type type) {
    if (_sliderBall) {
        removeWidget(_sliderBall);
        delete _sliderBall;
        _sliderBall = nullptr;
    }
    _sliderBall = new ButtonImage();
    _sliderBall->initWithImage(up, down, type);
    addWidget(_sliderBall);
    
    _height = _sliderBall->getHeight();
    _max.setTo(_width, _height);
}

void Slider::loadProgressBarTexture(const std::string &progress, Type type) {
    if (_progress) {
        removeWidget(_progress);
        delete _progress;
        _progress = nullptr;
    }
    _progress = new ProgressBar();
    _progress->initWithTexture(progress, type);
    _progress->setTotalLength(_width);
    addWidget(_progress);
}

void Slider::setPercent(float value) {
    _progress->setPercent(value);
    _sliderBall->setPosition(_width * value - _sliderBall->getWidth() / 2, 0.0f, 0.0f);
}

float Slider::getPercent() const {
    return _progress->getPercent();
}

NS_MONKEY_END
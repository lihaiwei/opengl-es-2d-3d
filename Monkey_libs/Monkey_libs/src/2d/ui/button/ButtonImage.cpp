//
//  ButtonImage.cpp
//  Opengl2D
//
//  Created by Neil on 27/9/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "ButtonImage.h"

NS_MONKEY_BEGIN

ButtonImage::ButtonImage() :
Button(),
_upImage(nullptr),
_downImage(nullptr)
{
    initButtonRender();
    enableMouse(true);
}

ButtonImage::~ButtonImage() {
    delete _upImage;
    delete _downImage;
}

void ButtonImage::initButtonRender() {
    
    _upImage    = new Image();
    _downImage  = new Image();
    
    _upImage->enableMouse(false);
    _downImage->enableMouse(false);
    
    addChild(_upImage);
    addChild(_downImage);
}

void ButtonImage::initWithImage(const std::string &up, const std::string &down, ButtonImage::Type type) {
    initUpImage(up, type);
    initDownImage(down, type);
    setButtonStatus(Button::ButtonStats::UP);
}

void ButtonImage::initUpImage(const std::string &name, ButtonImage::Type type) {
    if (name.empty()) {
        return;
    }
    switch (type) {
        case ButtonImage::Type::TEXTURE:
            _upImage->initWithTexture(name);
            break;
        case ButtonImage::Type::TEXTURE_FRAME:
            _upImage->initWithFrameTexture(name);
            break;
        default:
            break;
    }
    _width  = _upImage->getWidth();
    _height = _upImage->getHeight();
    _min.setTo(0, 0);
    _max.setTo(_width, _height);
}

void ButtonImage::initDownImage(const std::string &name, ButtonImage::Type type) {
    if (name.empty()) {
        return;
    }
    
    switch (type) {
        case ButtonImage::Type::TEXTURE:
            _downImage->initWithTexture(name);
            break;
        case ButtonImage::Type::TEXTURE_FRAME:
            _downImage->initWithFrameTexture(name);
            break;
        default:
            break;
    }
}

void ButtonImage::setButtonStatus(Button::ButtonStats stats) {
    _buttonStats = stats;
    switch (_buttonStats) {
        case Button::ButtonStats::UP:
            _upImage->setVisiable(true);
            _downImage->setVisiable(false);
            break;
        case Button::ButtonStats::DOWN:
            _upImage->setVisiable(false);
            _downImage->setVisiable(true);
            break;
        default:
            break;
    }
}

NS_MONKEY_END
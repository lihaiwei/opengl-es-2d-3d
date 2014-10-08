//
//  Button.cpp
//  Opengl2D
//
//  Created by Neil on 26/9/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "2d/ui/button/Button.h"
#include "core/event/TouchEvent.h"

NS_MONKEY_BEGIN

Button::Button() : DisplayObject() {
    addEventListener(TouchEvent::TOUCH_BEGAN, this, EVENT_CALLBACK(Button::onTouchBegan));
    addEventListener(TouchEvent::TOUCH_END,   this, EVENT_CALLBACK(Button::onTouchEnd));
    addEventListener(TouchEvent::TOUCH_MOVE,  this, EVENT_CALLBACK(Button::onTouchMove));
    addEventListener(TouchEvent::TOUCH_OUT,   this, EVENT_CALLBACK(Button::onTouchOut));
}

Button::~Button() {
    
}

void Button::setButtonStatus(Button::ButtonStats stats) {
    _buttonStats = stats;
}

void Button::onTouchBegan(Event *e) {
    setButtonStatus(Button::ButtonStats::DOWN);
}

void Button::onTouchEnd(Event *e) {
    setButtonStatus(Button::ButtonStats::OVER);
}

void Button::onTouchMove(Event *e) {
    setButtonStatus(Button::ButtonStats::OVER);
}

void Button::onTouchOut(Event *e) {
    setButtonStatus(Button::ButtonStats::UP);
}

NS_MONKEY_END
//
//  CheckBox.cpp
//  Monkey_libs
//
//  Created by Neil on 24/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "2d/ui/button/CheckBox.h"
#include "core/event/TouchEvent.h"

NS_MONKEY_BEGIN


CheckBox::CheckBox() :
DisplayObject(),
_disableRenderer(nullptr),
_disableSelectedRenderer(nullptr),
_activeRenderer(nullptr),
_activeSeltectedRenderer(nullptr),
_activeEvent(Event::ACTIVE),
_disableEvent(Event::DISABLE),
_active(false)
{
    initRenderer();
}

CheckBox::~CheckBox() {
    delete _disableRenderer;
    delete _disableSelectedRenderer;
    delete _activeRenderer;
    delete _activeSeltectedRenderer;
}

void CheckBox::initRenderer() {
    
    _activeSeltectedRenderer    = new Image();
    _activeRenderer             = new Image();
    _disableRenderer            = new Image();
    _disableSelectedRenderer    = new Image();
    
    _activeRenderer->enableMouse(false);
    _activeSeltectedRenderer->enableMouse(false);
    _disableRenderer->enableMouse(false);
    _disableSelectedRenderer->enableMouse(false);
    
    enableMouse(true);
    
    addChild(_activeSeltectedRenderer);
    addChild(_activeRenderer);
    addChild(_disableSelectedRenderer);
    addChild(_disableRenderer);
    
    addEventListener(TouchEvent::TOUCH_BEGAN, this, EVENT_CALLBACK(CheckBox::onTouchBegin));
    addEventListener(TouchEvent::TOUCH_END,   this, EVENT_CALLBACK(CheckBox::onTouchEnd));
}

void CheckBox::initwithImage(const std::string &disable, const std::string &disableSelected, const std::string &active, const std::string &activeSeltected, CheckBox::Type type) {
    
    initDisableRenderer(disable, type);
    initDisableSeltectedRenderer(disableSelected, type);
    initActiveRenderer(active, type);
    initActiveSeltectedRenderer(activeSeltected, type);
    
    setValue(false);
}

void CheckBox::setValue(bool value) {
    _active = value;
    hideAll();
    if (_active) {
        onActive();
    } else {
        onDisable();
    }
}

void CheckBox::onTouchBegin(monkey::Event *e) {
    if (_active) {
        onPressActive();
    } else {
        onPressDisable();
    }
}

void CheckBox::onTouchEnd(monkey::Event *e) {
    if (_active) {
        onDisable();
    } else {
        onActive();
    }
    _active = !_active;
}

void CheckBox::hideAll() {
    _disableRenderer->setVisiable(false);
    _disableSelectedRenderer->setVisiable(false);
    _activeRenderer->setVisiable(false);
    _activeSeltectedRenderer->setVisiable(false);
}

void CheckBox::onActive() {
    hideAll();
    _activeRenderer->setVisiable(true);
    
    _activeEvent.reset();
    dispatchEvent(_activeEvent);
}

void CheckBox::onPressActive() {
    hideAll();
    _activeSeltectedRenderer->setVisiable(true);
}

void CheckBox::onDisable() {
    hideAll();
    _disableRenderer->setVisiable(true);
    
    _disableEvent.reset();
    dispatchEvent(_disableEvent);
}

void CheckBox::onPressDisable() {
    hideAll();
    _disableSelectedRenderer->setVisiable(true);
}

void CheckBox::initDisableRenderer(const std::string &fileName, CheckBox::Type type) {
    if (fileName.empty()) {
        return;
    }
    switch (type) {
        case CheckBox::Type::TEXTURE:
            _disableRenderer->initWithTexture(fileName);
            break;
        case CheckBox::Type::TEXTURE_FRAME:
            _disableRenderer->initWithFrameTexture(fileName);
            break;
        default:
            break;
    }
}

void CheckBox::initDisableSeltectedRenderer(const std::string &fileName, CheckBox::Type type) {
    if (fileName.empty()) {
        return;
    }
    switch (type) {
        case CheckBox::Type::TEXTURE:
            _disableSelectedRenderer->initWithTexture(fileName);
            break;
        case CheckBox::Type::TEXTURE_FRAME:
            _disableSelectedRenderer->initWithFrameTexture(fileName);
            break;
        default:
            break;
    }
}

void CheckBox::initActiveRenderer(const std::string &fileName, CheckBox::Type type) {
    if (fileName.empty()) {
        return;
    }
    switch (type) {
        case CheckBox::Type::TEXTURE:
            _activeRenderer->initWithTexture(fileName);
            break;
        case CheckBox::Type::TEXTURE_FRAME:
            _activeRenderer->initWithFrameTexture(fileName);
            break;
        default:
            break;
    }
    _width  = _activeRenderer->getWidth();
    _height = _activeRenderer->getHeight();
    _min.setTo(0, 0);
    _max.setTo(_width, _height);
}

void CheckBox::initActiveSeltectedRenderer(const std::string &fileName, CheckBox::Type type) {
    if (fileName.empty()) {
        return;
    }
    switch (type) {
        case CheckBox::Type::TEXTURE:
            _activeSeltectedRenderer->initWithTexture(fileName);
            break;
        case CheckBox::Type::TEXTURE_FRAME:
            _activeSeltectedRenderer->initWithFrameTexture(fileName);
            break;
        default:
            break;
    }
}

void CheckBox::draw(bool includeChildren, Material3D* shader) {
    
    _enterDrawEvent.reset();
    dispatchEvent(_enterDrawEvent);
    
    for (auto iter = _children.begin(); iter != _children.end(); iter++) {
        if ((*iter) == _activeRenderer || (*iter) == _activeSeltectedRenderer || (*iter) == _disableRenderer || (*iter) == _disableSelectedRenderer) {
            continue;
        }
        (*iter)->draw(includeChildren, shader);
    }
    
    _activeRenderer->draw(includeChildren, shader);
    _activeSeltectedRenderer->draw(includeChildren, shader);
    _disableSelectedRenderer->draw(includeChildren, shader);
    _disableRenderer->draw(includeChildren, shader);
    
    _exitDrawEvent.reset();
    dispatchEvent(_exitDrawEvent);
}

NS_MONKEY_END
//
//  Scene2D.cpp
//  Monkey_libs
//
//  Created by Neil on 7/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "Scene2D.h"
#include "core/camera/Camera3D.h"
#include "core/camera/lens/OrthographicLens2D.h"

NS_MONKEY_BEGIN

Scene2D::Scene2D() : Scene() {
    if (_defaultCamera) {
        delete _defaultCamera;
        _defaultCamera = nullptr;
    }
    _camera = new Camera3D(new OrthographicLens2D());
    _defaultCamera = _camera;
}

Scene2D::~Scene2D() {
    
}

void Scene2D::handleTouchesBegan(monkey::TouchEvent &event) {
    dispatchEvent(event);
}

void Scene2D::handleTouchesEnd(monkey::TouchEvent &event) {
    dispatchEvent(event);
}

void Scene2D::handleTouchMove(monkey::TouchEvent &event) {
    dispatchEvent(event);
}

void Scene2D::handleMouseWheel(monkey::TouchEvent &event) {
    dispatchEvent(event);
}

/**
 *  2d的渲染不再使用层级属性。根据子父级结构来渲染。
 *  @param camera
 *  @param clearDepth
 */
void Scene2D::render(Camera3D* camera, bool clearDepth) {
    _renderLength = (int)_children.size();
    if (_renderLength == 0 || !_visible) {
        return;
    }
    _renderIndex  = 0;
    bool doRender = false;
    if (!_paused) {
        doRender = true;
        _renderEvent.reset();
        dispatchEvent(_renderEvent);
    }
    
    if (clearDepth) {
#if CC_TARGET_PLATFORM == CC_TARGET_OS_IPHONE
        glClearDepthf(1.0);
#else
        glClearDepth(1.0);
#endif
    }
    
    if (doRender) {
        while (_renderIndex < _renderLength) {
            _children[_renderIndex]->draw(true);
            _renderIndex++;
        }
    }
}

NS_MONKEY_END
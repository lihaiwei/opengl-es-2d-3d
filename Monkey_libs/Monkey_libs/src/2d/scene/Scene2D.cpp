//
//  Scene2D.cpp
//  Monkey_libs
//
//  Created by Neil on 7/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "2d/scene/Scene2D.h"
#include "2d/entities/DisplayObject.h"

#include "core/camera/Camera3D.h"
#include "core/camera/lens/OrthographicLens2D.h"


NS_MONKEY_BEGIN

Scene2D::Scene2D() : Scene(), _interDisp(nullptr) {
    if (_defaultCamera) {
        delete _defaultCamera;
        _defaultCamera = nullptr;
    }
    _camera = new Camera3D(new OrthographicLens2D());
    _defaultCamera = _camera;
}

Scene2D::~Scene2D() {
    
}

bool Scene2D::eventVisitor(Pivot3D *disp, monkey::TouchEvent &event) {
    if (!event.points || event.size == 0) {
        return false;
    }
    if (disp->getChildren().size() > 0) {
        for (auto iter = _children.rbegin(); iter != _children.rend(); iter++) {
            bool ret = eventVisitor((*iter), event);
            if (ret) {
                return true;
            }
        }
        return false;
    } else {
        
        // 如果显示对象无此类型事件，并且显示对象不含TOUCH_IN TOUCH_OUT TOUCH_HIT RIGHT_MOUSE_CLICK MIDDLE_MOUSE_CLICK
        if (!disp->hasEventListener(event.type)) {
            
            if (
                disp->hasEventListener(TouchEvent::TOUCH_IN) ||
                disp->hasEventListener(TouchEvent::TOUCH_OUT) ||
                disp->hasEventListener(TouchEvent::TOUCH_HIT) ||
                disp->hasEventListener(TouchEvent::RIGHT_MOUSE_CLICK) ||
                disp->hasEventListener(TouchEvent::MIDDLE_MOUSE_CLICK)
                ) {
                
            }
            
            return false;
        }
        
        // 非2d显示对象
        DisplayObject *displayObject = dynamic_cast<DisplayObject*>(disp);
        if (!displayObject) {
            return false;
        }
        
        bool isIn = displayObject->hitTestPoint(event.points[0].x, event.points[0].y);
        
        // TOUCH_OUT事件:未选中显示对象 AND TOUCH_OUT事件 AND TOUCH_IN状态
        if (!isIn && disp->hasEventListener(TouchEvent::TOUCH_OUT) && _interDisp == disp) {
            // touch out 事件
            TouchEvent touchOutEvent(TouchEvent::TOUCH_OUT, true, event.points, event.size);
            disp->dispatchEvent(touchOutEvent);
            // null
            _interDisp = nullptr;
            return true;
        }
        // ...
        if (!isIn) {
            if (disp == _interDisp) {
                _interDisp = nullptr;
            }
            return false;
        }
        // TOUCH_IN事件
        if (isIn && disp->hasEventListener(TouchEvent::TOUCH_IN) && _interDisp != disp) {
            // touch in事件
            TouchEvent touchInEvent(TouchEvent::TOUCH_IN, true, event.points, event.size);
            disp->dispatchEvent(touchInEvent);
        }
        // ......
        disp->dispatchEvent(event);
        // click事件
        if (event.type == TouchEvent::TOUCH_END && disp->hasEventListener(TouchEvent::TOUCH_HIT)) {
            TouchEvent touchHit(TouchEvent::TOUCH_HIT, true, event.points, event.size);
            disp->dispatchEvent(touchHit);
        } else if (event.type == TouchEvent::RIGHT_MOUSE_UP && disp->hasEventListener(TouchEvent::RIGHT_MOUSE_CLICK)) {
            TouchEvent touchHit(TouchEvent::RIGHT_MOUSE_CLICK, true, event.points, event.size);
            disp->dispatchEvent(touchHit);
        } else if (event.type == TouchEvent::MIDDLE_MOUSE_UP && disp->hasEventListener(TouchEvent::MIDDLE_MOUSE_CLICK)) {
            TouchEvent touchHit(TouchEvent::MIDDLE_MOUSE_CLICK, true, event.points, event.size);
            disp->dispatchEvent(touchHit);
        }
        
        _interDisp = displayObject;
        
        return true;
    }
    
    return false;
}

void Scene2D::handleTouchesBegan(monkey::TouchEvent &event) {
    dispatchEvent(event);
    eventVisitor(this, event);
}

void Scene2D::handleTouchesEnd(monkey::TouchEvent &event) {
    dispatchEvent(event);
    eventVisitor(this, event);
}

void Scene2D::handleTouchMove(monkey::TouchEvent &event) {
    dispatchEvent(event);
    eventVisitor(this, event);
}

void Scene2D::handleMouseWheel(monkey::TouchEvent &event) {
    dispatchEvent(event);
    eventVisitor(this, event);
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
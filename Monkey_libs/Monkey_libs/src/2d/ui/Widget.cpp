//
//  Widget.cpp
//  Monkey_libs
//
//  Created by Neil on 2/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#include "2d/ui/Widget.h"

NS_MONKEY_BEGIN

Widget::Widget() {
    
}

Widget::~Widget() {
    for (auto iter = _widgets.begin(); iter != _widgets.end(); iter++) {
        delete (*iter);
    }
    _widgets.clear();
}

void Widget::addWidget(monkey::DisplayObject *widget) {
    _widgets.push_back(widget);
    widget->relativeParent(this);
}

void Widget::addWidgetAt(monkey::DisplayObject *widget, int idx) {
    _widgets.insert(_widgets.begin() + idx, widget);
    widget->relativeParent(this);
}

void Widget::removeWidget(monkey::DisplayObject *widget) {
    for (auto iter = _widgets.begin(); iter != _widgets.end(); iter++) {
        if (*iter == widget) {
            _widgets.erase(iter);
            widget->unRelativeParent();
            return;
        }
    }
}

void Widget::removeWidgetAt(int idx) {
    (*(_widgets.begin() + idx))->unRelativeParent();
    _widgets.erase(_widgets.begin() + idx);
}

void Widget::draw(bool includeChildren, Material3D* shader) {
    _enterDrawEvent.reset();
    dispatchEvent(_enterDrawEvent);
    
    for (auto iter = _children.begin(); iter != _children.end(); iter++) {
        (*iter)->draw(includeChildren, shader);
    }

    for (auto iter = _widgets.begin(); iter != _widgets.end(); iter++) {
        (*iter)->draw(includeChildren, shader);
    }
    
    _exitDrawEvent.reset();
    dispatchEvent(_exitDrawEvent);
}

NS_MONKEY_END
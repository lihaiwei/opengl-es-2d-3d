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
        delete iter->first;
    }
    _widgets.clear();
}

void Widget::addWidget(monkey::DisplayObject *widget) {
    _widgets.insert(std::make_pair(widget, true));
    _widgetList.push_back(widget);
    addChild(widget);
}

void Widget::addWidgetAt(monkey::DisplayObject *widget, int index) {
    _widgets.insert(std::make_pair(widget, true));
    _widgetList.insert(_widgetList.begin() + index, widget);
    addChild(widget);
}

void Widget::removeWidget(monkey::DisplayObject *widget) {
    removeChild(widget);
    _widgets.erase(widget);
    auto iter = std::find(_widgetList.begin(), _widgetList.end(), widget);
    if (iter != _widgetList.end()) {
        _widgetList.erase(iter);
    }
}

void Widget::removeWidgetAt(int index) {
    auto iter = _widgetList.begin() + index;
    _widgets.erase((*iter));
    removeChild((*iter));
    _widgetList.erase(iter);
}

void Widget::draw(bool includeChildren, Material3D* shader) {
    _enterDrawEvent.reset();
    dispatchEvent(_enterDrawEvent);
    
    for (auto iter = _children.begin(); iter != _children.end(); iter++) {
        auto widget = dynamic_cast<DisplayObject*>(*iter);
        if (widget && _widgets.find(widget) != _widgets.end()) {
            continue;
        }
        (*iter)->draw(includeChildren, shader);
    }
    
    for (auto iter = _widgetList.begin(); iter != _widgetList.end(); iter++) {
        (*iter)->draw(includeChildren, shader);
    }
    
    _exitDrawEvent.reset();
    dispatchEvent(_exitDrawEvent);
}

NS_MONKEY_END
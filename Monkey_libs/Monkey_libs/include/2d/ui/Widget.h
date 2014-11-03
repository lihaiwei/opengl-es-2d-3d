//
//  Widget.h
//  Monkey_libs
//
//  Created by Neil on 2/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef Monkey_libs_Widget_h
#define Monkey_libs_Widget_h

#include "2d/entities/DisplayObject.h"

NS_MONKEY_BEGIN

class Widget : public DisplayObject {
    
public:
    
    enum class Type {
        TEXTURE,
        TEXTURE_FRAME
    };
    
    Widget();
    
    virtual ~Widget();
    
protected:
    
    /**
     *  添加一个控件
     *  @param widget   控件
     */
    virtual void addWidget(DisplayObject *widget);
    /**
     *  添加控件
     *
     *  @param widget 控件
     *  @param idx    位置
     */
    virtual void addWidgetAt(DisplayObject *widget, int idx);
    /**
     *  移除一个控件
     *  @param widget 控件
     */
    virtual void removeWidget(DisplayObject *widget);
    /**
     *  移除控件
     *  @param idx  位置
     */
    virtual void removeWidgetAt(int idx);
    /**
     *  绘制阶段
     *  @param includeChildren
     */
    virtual void draw(bool includeChildren = false, Material3D* shader = nullptr) override;
    
    std::vector<DisplayObject*> _widgets;
    
};

NS_MONKEY_END

#endif

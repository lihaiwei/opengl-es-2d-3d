//
//  Scene2D.h
//  Monkey_libs
//
//  Created by Neil on 7/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef Monkey_libs_Scene2D_h
#define Monkey_libs_Scene2D_h

#include "core/scene/Scene.h"

NS_MONKEY_BEGIN

/**
 *  Scene2D,忽略Pivot3D.layer属性。改用容器层级来维护显示顺序。
 */
class Scene2D : public Scene {
    
public:
    
    Scene2D();
    virtual ~Scene2D();
    
    /**
     *  touches began事件
     *  @param event
     */
    virtual void handleTouchesBegan(TouchEvent &event) override;
    /**
     *  touch end事件
     *  @param event
     */
    virtual void handleTouchesEnd(TouchEvent &event) override;
    /**
     *  touch move事件
     *  @param event
     */
    virtual void handleTouchMove(TouchEvent &event) override;
    /**
     *  mouse wheel事件
     *  @param event
     */
    virtual void handleMouseWheel(TouchEvent &event) override;
    /**
     *  render
     *  @param camera
     *  @param clearDepth
     */
    virtual void render(Camera3D *camera = nullptr, bool clearDepth = false);
};



NS_MONKEY_END

#endif

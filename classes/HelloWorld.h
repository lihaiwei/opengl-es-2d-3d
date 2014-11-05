//
//  HelloWorld.h
//  HelloMonkey
//
//  Created by Neil on 4/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef __HelloMonkey__HelloWorld__
#define __HelloMonkey__HelloWorld__

#include "2d/scene/Scene2D.h"
#include "core/geom/Vector3D.h"

NS_MONKEY_BEGIN

class HellWorld : public Scene2D {
    
public:
    
    HellWorld();
    ~HellWorld();
    
    /**
     * 初始化
     */
    void init();
    /**
     *  进入帧循环
     *  @param e
     */
    void onEnterFrame(Event *e);
    
private:
    
    /**
     *  更新背景
     *  @param advanceTime
     */
    void moveBackground(float advanceTime);
    
    std::vector<DisplayObject*> _lands; // 地板
    std::vector<DisplayObject*> _skys;  // 天空
    std::vector<DisplayObject*> _pipeUps; // 上水管
    std::vector<DisplayObject*> _pipeDowns; // 下水管
    
    Vector3D _temp;
    float    _speed;
    float    _lastTime;
    
};

NS_MONKEY_END

#endif /* defined(__HelloMonkey__HelloWorld__) */

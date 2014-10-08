//
//  DisplayObject.h
//  Monkey
//
//  Created by Neil on 6/9/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef _DisplayObject_h
#define _DisplayObject_h

#include <string>

#include "platform/PlatformMacros.h"
#include "core/material/BlendMode.h"
#include "core/geom/Rectangle.h"
#include "core/base/Pivot3D.h"

NS_MONKEY_BEGIN

#define MAX_B  10000000
#define MIN_B -10000000

/**
 *  显示对象
 */
class DisplayObject : public Pivot3D {
    
public:
    
    DisplayObject();
    
    virtual ~DisplayObject();
    
    /**
     *  设置锚点
     *  @param x 宽度百分比
     *  @param y 高度百分比
     */
    virtual void setAnchor(float x, float y);
    /**
     *  获取锚点
     *  @return
     */
    virtual Vector2D getAnchor();
    
    /**
     *  设置透明度
     *  @param value
     */
    virtual void setAlpha(float value);
    /**
     *  获取透明度
     *  @return
     */
    virtual float getAlpha();
    /**
     *  设置混合模式
     *  @param mode
     */
    virtual void setBlendMode(BlendMode mode);
    /**
     *  获取混合模式
     *  @return
     */
    virtual BlendMode getBlendMode();
    /**
     *  宽度
     *  @return
     */
    virtual float getWidth();
    /**
     *  高度
     *  @return
     */
    virtual float getHeight();
    /**
     *  获取bounds.min
     *  @return
     */
    virtual Vector2D getMin();
    /**
     *  获取bounds.max
     *  @return
     */
    virtual Vector2D getMax();
    /**
     *  更新bounds
     */
    virtual void updateBounds(bool forece = false);
    /**
     *  碰撞测试
     *  @param x x坐标
     *  @param y y坐标
     *  @return
     */
    virtual bool hitTestPoint(float x, float y);
    /**
     *  碰撞测试
     *  @param point
     *  @return
     */
    virtual bool hitTestPoint(const Point2D &point);
    /**
     *  网格数据，2D对象只包含一个网格数据
     *  @return
     */
    virtual Geometry3D* getGeometry3d();
    /**
     *  inview
     *  @return
     */
    virtual bool inView() override;
    /**
     *  添加到场景
     *  @param scene
     */
    virtual void addedToScene(Scene *scene);
    /**
     *  从场景中移除
     */
    virtual void removedFromScene();
    
protected:
    
    /**
     *  设置GPU状态：混合模式、深度测试、stencil测试等。
     */
    virtual void setGPUStats();
    /**
     *  恢复GPU状态。全局采用一个默认混合模式、深度测试、stencil测试状态。只有当对象启用的时候，才会通知
     *  GPU修改状态，渲染完成之后，恢复至默认水平。
     */
    virtual void disableGPUStats();
    
    /**
     *  模型数据
     */
    Geometry3D*  _geometry;
    
    BlendMode   _blendMode;
    
    float       _alpha;
    float       _width;
    float       _height;
    
    bool        _boundsDirty;
    
    Vector2D    _min;
    Vector2D    _max;
    // 锚点
    Vector2D    _anchorPoint;
    
    GLenum              _srcFactor;
    GLenum              _dstFactor;
};

NS_MONKEY_END

#endif

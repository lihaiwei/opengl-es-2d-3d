//
//  ProgressBar.h
//  Monkey_libs
//
//  Created by Neil on 26/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef Monkey_libs_ProgressBar_h
#define Monkey_libs_ProgressBar_h

#include "2d/entities/DisplayObject.h"
#include "2d/entities/Image.h"

NS_MONKEY_BEGIN


class ProgressBar : public DisplayObject {
    
public:
    
    enum class Direction {
        LEFT,
        RIGHT
    };
    
    enum class Type {
        TEXTURE,
        TEXTURE_FRAME
    };
    
    ProgressBar();
    
    virtual ~ProgressBar();
    
    /**
     *  初始化
     *
     *  @param textureName      贴图名称
     *  @param type             贴图类型
     */
    virtual void initWithTexture(const std::string &textureName, ProgressBar::Type type = ProgressBar::Type::TEXTURE, ProgressBar::Direction direction = ProgressBar::Direction::RIGHT);
    
    /**
     *  设置progress bar总长度
     *  @param value 长度
     */
    void setTotalLength(float value);
    /**
     *  获取progress bar总长度
     *  @return
     */
    float getTotalLength() const;
    
    /**
     *  获取progress bar的方向
     *  @return 方向
     */
    ProgressBar::Direction getDirection() const;
    /**
     *  设置progress bar的方向
     *  @param direction
     */
    void setDirection(ProgressBar::Direction direction);
    /**
     *  设置进度
     *  @param percent 进度
     */
    void setPercent(float percent);
    /**
     *  获取进度
     */
    float getPercent() const;
    /**
     *  绘制
     *  @param includeChildren 是否绘制children
     *  @param shader          shader
     */
    virtual void draw(bool includeChildren = false, Material3D* shader = nullptr) override;
    
protected:
    
    ProgressBar::Direction _direction;
    float _percent;
    float _totalLength;
    float _baseWidth;
    Image* _renderer;
};



NS_MONKEY_END

#endif
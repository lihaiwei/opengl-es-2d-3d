//
//  Slider.h
//  Monkey_libs
//
//  Created by Neil on 2/11/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef Monkey_libs_Slider_h
#define Monkey_libs_Slider_h

#include "2d/entities/DisplayObject.h"

NS_MONKEY_BEGIN

class Slider : public DisplayObject {
    
public:
    
    enum class Type {
        TEXTURE,
        TEXTURE_FRAME
    };

    
    Slider();
    
    virtual ~Slider();
    
    /**
     *  加载bar资源
     *  @param fileName bar资源名称
     *  @param type     类型
     */
    void loadBarTexture(const std::string &fileName, Type type);
    
    
    
};

NS_MONKEY_END

#endif

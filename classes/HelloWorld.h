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

NS_MONKEY_BEGIN

class HellWorld : public Scene2D {
    
public:
    
    HellWorld();
    ~HellWorld();
    
    void init();
    
};

NS_MONKEY_END

#endif /* defined(__HelloMonkey__HelloWorld__) */

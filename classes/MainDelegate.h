//
//  Application.h
//  HelloMonkey
//
//  Created by Neil on 7/10/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef __HelloMonkey__Application__
#define __HelloMonkey__Application__

#include <stdio.h>

#include <core/base/Object.h>
#include <core/event/Event.h>

class MainDelegate : public monkey::Object {
    
public:
    
    MainDelegate();
    ~MainDelegate();
    
    void didFinishLaunching();
    void didEnterForeground();
    void didEnterBackground();
    
    // delete
    void onClick(monkey::Event &event);
};

#endif /* defined(__HelloMonkey__Application__) */
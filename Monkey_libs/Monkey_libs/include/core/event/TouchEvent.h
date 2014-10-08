//
//  TouchEvent.h
//  Monkey
//
//  Created by Neil on 15/9/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef _TouchEvent_h
#define _TouchEvent_h

#include "core/event/Event.h"
#include "core/geom/Vector2D.h"
#include "platform/PlatformMacros.h"

NS_MONKEY_BEGIN

class TouchEvent : public Event {
    
public:
    
    /**
     *  TouchBegan OR Mouse_Down
     */
    static const std::string TOUCH_BEGAN;
    /**
     *  TouchMove OR Mouse_Move
     */
    static const std::string TOUCH_MOVE;
    /**
     *  TouchEnd OR Mouse_Up
     */
    static const std::string TOUCH_END;
    /**
     *  TouchIn OR MouseIN
     */
    static const std::string TOUCH_IN;
    /**
     *  TouchOut OR MouseOut
     */
    static const std::string TOUCH_OUT;
    static const std::string RIGHT_MOUSE_DOWN;
    static const std::string RIGHT_MOUSE_UP;
    static const std::string RIGHT_MOUSE_CLICK;
    static const std::string MIDDLE_MOUSE_DOWN;
    static const std::string MIDDLE_MOUSE_UP;
    static const std::string MIDDLE_MOUSE_CLICK;
    
    TouchEvent(std::string type, bool bubbles, const Point2D *mpoints, const int ssize);
    virtual ~TouchEvent();
    
    const Point2D *points;
    const int size;
    
};

typedef TouchEvent MouseEvent;

NS_MONKEY_END

#endif

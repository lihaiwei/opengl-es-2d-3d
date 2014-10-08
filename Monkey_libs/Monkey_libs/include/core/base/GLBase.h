//
//  GLBase.h
//  Opengl2D
//
//  Created by Neil on 13/9/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef _GLBase_h
#define _GLBase_h

#include "platform/PlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC
#include "glfw3.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#endif


#endif
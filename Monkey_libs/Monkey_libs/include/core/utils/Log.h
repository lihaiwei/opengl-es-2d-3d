//
//  Log.h
//  Monkey
//
//  Created by Neil on 23/8/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef _LOGS_H
#define _LOGS_H

#include <stdlib.h>
#include <stdio.h>

#include "platform/PlatformMacros.h"

NS_MONKEY_BEGIN

#define LOGI(...) { fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); }
#define LOGE(...) { fprintf(stderr, __VA_ARGS__); fprintf(stderr, "\n"); }

NS_MONKEY_END

#endif

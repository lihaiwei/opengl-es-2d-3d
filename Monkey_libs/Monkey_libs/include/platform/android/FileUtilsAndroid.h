//
//  FileUtilsIOS.h
//  Monkey
//
//  Created by Neil on 24/8/14.
//  Copyright (c) 2014 neil. All rights reserved.
//

#ifndef __FileUtilsAndroid__
#define __FileUtilsAndroid__

#include "platform/PlatformConfig.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID

#include "platform/FileUtils.h"
#include "platform/PlatformMacros.h"

NS_MONKEY_BEGIN

class FileUtilsAndroid : public FileUtils {
    
public:
    virtual std::string getFullPath(const std::string &filename);
};

NS_MONKEY_END

#endif

#endif

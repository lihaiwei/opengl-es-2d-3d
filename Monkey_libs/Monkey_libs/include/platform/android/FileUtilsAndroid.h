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

#include <android/asset_manager.h>

NS_MONKEY_BEGIN

class FileUtilsAndroid : public FileUtils {
    
public:
	
	FileUtilsAndroid();
	virtual ~FileUtilsAndroid();
	
    /**
     * 获取文件全路径
     * @paran filename	文件名称
     */
	virtual std::string getFullPath(const std::string &filename);
	/**
	 * 设置AssetManager
	 * @manager 		资源管理器
	 */
	virtual void setAssetManager(AAssetManager *manager);
	/**
	 * 设置APK路径
	 */
	virtual void setAPKPath(const std::string &path);
    
private:
    
    std::string 	_apkPath;
    AAssetManager 	*assetmanager;
};

NS_MONKEY_END

#endif

#endif

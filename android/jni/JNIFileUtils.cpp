/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class monkey_helper_JNIFileUtils */
#include "JNIHelper.h"

#include "core/utils/Log.h"
#include "platform/android/FileUtilsAndroid.h"

#ifndef _Included_monkey_helper_JNIFileUtils
#define _Included_monkey_helper_JNIFileUtils
#ifdef __cplusplus
extern "C" {
#endif

USING_NS_MONKEY

/*
 * Class:     monkey_helper_JNIFileUtils
 * Method:    setApkPath
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_monkey_helper_JNIFileUtils_setApkPath(JNIEnv *env, jclass jc, jstring str) {
	std::string path = JNIHlper::jstring2string(str);
	LOGE("Java_monkey_helper_JNIFileUtils_setApkPath -> %s", path.c_str());
}

/*
 * Class:     monkey_helper_JNIFileUtils
 * Method:    setAssetsManager
 * Signature: (Ljava/lang/Object;Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_monkey_helper_JNIFileUtils_setAssetsManager(JNIEnv *env, jclass jc, jobject context, jobject assetManager) {
	
}

#ifdef __cplusplus
}
#endif
#endif
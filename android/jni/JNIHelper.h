#ifndef __ANDROID_JNI_HELPER_H__
#define __ANDROID_JNI_HELPER_H__

#include <jni.h>
#include <string>

#include "platform/PlatformMacros.h"

NS_MONKEY_BEGIN

class JNIHlper {
	
public:
	
	static void 	setJavaVM(JavaVM *vm);
	static JavaVM* 	getJavaVM();
	static JNIEnv*	getEnv();
	static std::string jstring2string(jstring str);
	
private:
	
	static JNIEnv* cacheEnv(JavaVM* jvm);
	
	static JavaVM* _vm;
};

NS_MONKEY_END

#endif

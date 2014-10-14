#include "JNIHelper.h"

#include "core/utils/Log.h"

static pthread_key_t _key;

NS_MONKEY_BEGIN

JavaVM* JNIHlper::_vm = NULL;


JavaVM* JNIHlper::getJavaVM() {
	return _vm;
}

void JNIHlper::setJavaVM(JavaVM *vm) {
	pthread_t thisthread = pthread_self();
	_vm = vm;
	pthread_key_create(&_key, NULL);
}

JNIEnv* JNIHlper::getEnv() {
	JNIEnv *_env = (JNIEnv *)pthread_getspecific(_key);
	if (_env == NULL) {
		_env = JNIHlper::cacheEnv(_vm);
	}
	return _env;
}

JNIEnv* JNIHlper::cacheEnv(JavaVM* jvm) {
	JNIEnv* _env = NULL;
	jint ret = jvm->GetEnv((void**)&_env, JNI_VERSION_1_4);
	switch (ret) {
		case JNI_OK:
			pthread_setspecific(_key, _env);
			return _env;
			break;
		case JNI_EDETACHED:
			if (jvm->AttachCurrentThread(&_env, NULL) < 0) {
				LOGE("Failed to get the environment using AttachCurrentThread()");
				return NULL;
			} else {
				pthread_setspecific(_key, _env);
				return _env;
			}
			break;
		case JNI_EVERSION:
			LOGE("JNI interface version 1.4 not supported");
			break;
		default:
			LOGE("Failed to get the environment using GetEnv()");
			return NULL;
			break;
	}
	return NULL;
}

std::string JNIHlper::jstring2string(jstring jstr) {
	if (jstr == NULL) {
		return "";
	}
	JNIEnv *env = JNIHlper::getEnv();
	if (!env) {
		return "";
	}
	const char* chars = env->GetStringUTFChars(jstr, NULL);
	std::string result(chars);
	env->ReleaseStringUTFChars(jstr, chars);
	return result;
}

NS_MONKEY_END

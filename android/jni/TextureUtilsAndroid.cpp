#include "TextureUtilsAndroid.h"
#include "JNIHelper.h"
#include <jni.h>

#include "core/utils/Log.h"

NS_MONKEY_BEGIN

#define ALIGN_TOP    1
#define ALIGN_CENTER 3
#define ALIGN_BOTTOM 2

typedef struct {
    unsigned int    height;
    unsigned int    width;
    bool            isPremultipliedAlpha;
    bool            hasShadow;
    float           offsetX;
    float           offsetY;
    float           shadowBlur;
    float           shadowOpacity;
    bool            hasStroke;
    float           strokeR;
    float           strokeG;
    float           strokeB;
    float           strokeSize;
    float           tintR;
    float           tintG;
    float           tintB;
    unsigned char*  data;
} TextureInfo;

static bool initWithString(const char* text, TextAlign align, const char *fontName, int size, TextureInfo *info) {
	
	jstring jstrText = JNIHelper::getEnv()->NewStringUTF(text);
	jstring jstrFont = JNIHelper::getEnv()->NewStringUTF(fontName);
	
	LOGE("static bool initWithString(const char* text, TextAlign align, const char *fontName, int size, TextureInfo *info) {");
	
//	JniMethodInfo methodInfo;
//	if (!JNIHelper::getStaticMethodInfo(methodInfo, "monkey/helper/TextureUtils", "test",
//		   "(Ljava/lang/String;)V")) {
//		   LOGE("%s %d: error to get methodInfo", __FILE__, __LINE__);
//		   return false;
//	}
	
	jclass jcls = JNIHelper::getEnv()->FindClass("monkey/helper/TextureUtils");
	if (jcls == NULL) {
		LOGE("Can't find class ->", "monkey/helper/TextureUtils");
	}
	
	jmethodID methodID = JNIHelper::getEnv()->GetStaticMethodID(jcls, "test", "()V");
	if (methodID == NULL) {
		LOGE("Can't find method ->", "test");
	}
	
	jobject jtk = JNIHelper::getEnv()->CallStaticObjectMethod(jcls, methodID);
	
	
	JNIHelper::getEnv()->DeleteLocalRef(jstrText);
	JNIHelper::getEnv()->DeleteLocalRef(jstrFont);
	
	return true;
}

ByteArray* TextureUtilsAndroid::getTextureDataWithText(const char* text, const TextFormatter &format, int &width, int &height, bool &hasAlpha) {
	
	TextureInfo info;
    info.width  = format.width;
    info.height = format.height;
    info.hasShadow = format.shadow.enabled;
    info.offsetX   = format.shadow.offsetX;
    info.offsetY   = format.shadow.offsetY;
    info.shadowBlur= format.shadow.shadowBlur;
    info.shadowOpacity = format.shadow.shadowOpacity;
    info.hasStroke = format.stroke.enabled;
    info.strokeR   = format.stroke.red;
    info.strokeG   = format.stroke.green;
    info.strokeB   = format.stroke.blue;
    info.strokeSize= format.stroke.size;
    info.tintR     = format.fontFillColorR;
    info.tintG     = format.fontFillColorG;
    info.tintB     = format.fontFillColorB;
    
    if (!initWithString(text, format.align, format.fontName.c_str(), format.fontSize, &info)) {
    	return NULL;
    }
	
    height	= info.height;
    width	= info.width;
    hasAlpha= info.isPremultipliedAlpha;
    
    ByteArray *bytes = new ByteArray(info.data, width * height * 4);
	return bytes;
}

TextureUtils* TextureUtils::getInstance() {
    if (_instance == nullptr) {
        _instance = new TextureUtilsAndroid();
    }
    return _instance;
}

NS_MONKEY_END

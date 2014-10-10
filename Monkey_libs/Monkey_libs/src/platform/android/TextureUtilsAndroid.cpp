#include "platform/android/TextureUtilsAndroid.h"

NS_MONKEY_BEGIN

ByteArray* TextureUtilsAndroid::getTextureDataWithText(const char* text, const TextFormatter &format, int &width, int &height, bool &hasAlpha) {
	return nullptr;
}

TextureUtils* TextureUtils::getInstance() {
    if (_instance == nullptr) {
        _instance = new TextureUtilsAndroid();
    }
    return _instance;
}

NS_MONKEY_END

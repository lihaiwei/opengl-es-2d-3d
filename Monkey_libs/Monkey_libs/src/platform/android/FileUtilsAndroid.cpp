#include "platform/android/FileUtilsAndroid.h"

NS_MONKEY_BEGIN

std::string FileUtilsAndroid::getFullPath(const std::string &filename) {
	return "";
}

FileUtils* FileUtils::getInstance() {
    if (!_instance) {
        _instance = new FileUtilsAndroid();
    }
    return _instance;
}

NS_MONKEY_END

#include "platform/android/FileUtilsAndroid.h"

NS_MONKEY_BEGIN

FileUtilsAndroid::FileUtilsAndroid() : FileUtils(), _apkPath(""), assetmanager(NULL) {
	
}

FileUtilsAndroid::~FileUtilsAndroid() {
	
}

void FileUtilsAndroid::setAPKPath(const std::string &path) {
	_apkPath = path;
}

void FileUtilsAndroid::setAssetManager(AAssetManager *manager) {
	assetmanager = manager;
}

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

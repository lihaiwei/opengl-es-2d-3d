#include "platform/android/FileUtilsAndroid.h"
#include "core/utils/Log.h"

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
	
	AAsset *asset = AAssetManager_open(assetmanager, filename.c_str(), AASSET_MODE_UNKNOWN);
	if (asset == NULL) {
		LOGE("资源%s为null", filename.c_str());
	} else {
		LOGE("资源大小%d", AAsset_getLength(asset));
	}
	return "";
}

FileUtils* FileUtils::getInstance() {
    if (!_instance) {
        _instance = new FileUtilsAndroid();
    }
    return _instance;
}

NS_MONKEY_END

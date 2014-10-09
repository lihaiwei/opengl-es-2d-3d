LOCAL_PATH := $(call my-dir)


# monkey模块
include $(CLEAR_VARS)

LOCAL_MODULE    := monkey

JNI_SOURCES := jnihelper.c

LOCAL_SRC_FILES += ${JNI_SOURCES}

LOCAL_LDLIBS := -lGLESv1_CM \
                -lGLESv2 \
                -lEGL \
                -llog \
                -lz \
                -landroid
                
include $(BUILD_SHARED_LIBRARY)








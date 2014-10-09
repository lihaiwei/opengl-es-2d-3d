LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := monkey

LOCAL_SRC_FILES := jnihelper.c
				   
LOCAL_LDLIBS := -lGLESv1_CM \
                -lGLESv2 \
                -lEGL \
                -llog \
                -lz \
                -landroid

include $(BUILD_SHARED_LIBRARY)

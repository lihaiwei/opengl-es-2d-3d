/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_example_hellomonkey_GLHelper */
#include "GLViewAndroid.h"

#ifndef _Included_com_example_hellomonkey_GLHelper
#define _Included_com_example_hellomonkey_GLHelper
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_example_hellomonkey_GLHelper
 * Method:    onSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_hellomonkey_GLHelper_onSurfaceCreated(JNIEnv *, jclass) {
	GLView::onCreate();
}

/*
 * Class:     com_example_hellomonkey_GLHelper
 * Method:    onSurfaceChanged
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_hellomonkey_GLHelper_onSurfaceChanged(JNIEnv *, jclass) {
	GLView::onChange();
}

/*
 * Class:     com_example_hellomonkey_GLHelper
 * Method:    onDrawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_hellomonkey_GLHelper_onDrawFrame(JNIEnv *, jclass) {
	GLView::onDraw();
}

#ifdef __cplusplus
}
#endif
#endif

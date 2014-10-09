#include <GLES2/gl2.h>
#include <jni.h>
#include <android/log.h>

/*
 * Class:     com_example_hellomonkey_GLWrapper
 * Method:    onSurfaceCreated
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_hellomonkey_GLHelper_onSurfaceCreated (JNIEnv *env, jclass jc) {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}

/*
 * Class:     com_example_hellomonkey_GLWrapper
 * Method:    onSurfaceChanged
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_hellomonkey_GLHelper_onSurfaceChanged (JNIEnv *env, jclass jc) {

}

/*
 * Class:     com_example_hellomonkey_GLWrapper
 * Method:    onDrawFrame
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_example_hellomonkey_GLHelper_onDrawFrame (JNIEnv *env, jclass jc) {
	glClear(GL_COLOR_BUFFER_BIT);
}

#include "GLViewAndroid.h"

#include <GLES2/gl2.h>

void onSurfaceCreated() {
	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
}

void onSurfaceChanged() {

}

void onDrawFrame() {
	glClear(GL_COLOR_BUFFER_BIT);
}


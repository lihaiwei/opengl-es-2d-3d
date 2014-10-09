#include "GLViewAndroid.h"

void GLView::onChange() {
	
}

void GLView::onCreate() {
	glClearColor(1.0f, 0.5f, 0.0f, 0.0f);
}

void GLView::onDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
}

#include "GLViewAndroid.h"
#include "core/geom/Vector3D.h"
#include "core/utils/Log.h"
#include "core/base/Pivot3D.h"

USING_NS_MONKEY

void GLView::onChange() {
	
}

void GLView::onCreate() {
	glClearColor(1.0f, 0.5f, 0.0f, 0.0f);
}

void GLView::onDraw() {
	glClear(GL_COLOR_BUFFER_BIT);
	LOGE("%s", "测试测试");
	
	Pivot3D *pivot = new Pivot3D();
//	pivot->setTranslation(1.0f, 2.0f, 3.0f, true);
//	
//	LOGE("Pivot.x = %s", pivot->getX());
}

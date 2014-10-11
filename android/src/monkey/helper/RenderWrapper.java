package monkey.helper;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class RenderWrapper implements Renderer {

	@Override
	public void onDrawFrame(GL10 gl) {
		GLJNI.onDrawFrame();
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		GLJNI.onSurfaceChanged(width, height);
	}
	
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		GLJNI.onSurfaceCreated();
	}
	
}

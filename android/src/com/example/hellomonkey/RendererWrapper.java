package com.example.hellomonkey;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class RendererWrapper implements Renderer {
	
	@Override
	public void onDrawFrame(GL10 gl) {
		GLHelper.onDrawFrame();
	}
	
	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		GLHelper.onSurfaceChanged();
	}
	
	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		GLHelper.onSurfaceCreated();
	}
	
}

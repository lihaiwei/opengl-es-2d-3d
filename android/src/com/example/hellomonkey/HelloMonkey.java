package com.example.hellomonkey;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.view.Menu;
import android.widget.Toast;

public class HelloMonkey extends Activity {

	private GLSurfaceView glsurfaceView;
	private boolean rendererSet;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		GLHelper.loadLibrary();
		
		ActivityManager manager = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
		ConfigurationInfo  info = manager.getDeviceConfigurationInfo();
		
		final boolean supportsES2 = info.reqGlEsVersion >= 0x20000 || isProbablyEmulator();
		
		if (supportsES2) {
			glsurfaceView = new GLSurfaceView(this);
			if (isProbablyEmulator()) {
				glsurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
			}
			
			glsurfaceView.setEGLContextClientVersion(2);
			glsurfaceView.setRenderer(new RendererWrapper());
			
			rendererSet = true;
			setContentView(glsurfaceView);
		} else {
			Toast.makeText(this, "This device does not support OpenGL ES 2.0.",
		                Toast.LENGTH_LONG).show();
		}
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		if (rendererSet) {
			glsurfaceView.onPause();
		}
	}

	@Override
	protected void onResume() {
		super.onResume();
		if (rendererSet) {
			glsurfaceView.onResume();
		}
	}
	
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.hello_monkey, menu);
		return true;
	}
	
	private boolean isProbablyEmulator() {
		 return Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1
		            && (Build.FINGERPRINT.startsWith("generic")
		                    || Build.FINGERPRINT.startsWith("unknown")
		                    || Build.MODEL.contains("google_sdk")
		                    || Build.MODEL.contains("Emulator")
		                    || Build.MODEL.contains("Android SDK built for x86"));
	}
	
}

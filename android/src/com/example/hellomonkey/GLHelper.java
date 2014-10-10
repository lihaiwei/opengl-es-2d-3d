package com.example.hellomonkey;

public class GLHelper {
	
	public static void loadLibrary() {
		System.loadLibrary("monkeyandroid");
	}
	
	public static native void onSurfaceCreated();
	
	public static native void onSurfaceChanged();
	
	public static native void onDrawFrame();
	
}

package monkey.helper;

/**
 * glview jni接口.
 * 通知c++渲染.
 * @author Neil
 *
 */
public class GLJNI {
	/**
	 * 加载渲染引擎
	 */
	public static void loadLibrary() {
		System.loadLibrary("monkeyandroid");
	}
	
	public static native void onDrawFrame();
	
	public static native void onSurfaceChanged(int width, int height);
	
	public static native void onSurfaceCreated();
	
}

package monkey.activity;

import monkey.helper.GLJNI;
import monkey.helper.JNIFileUtils;
import monkey.helper.RenderWrapper;
import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.widget.Toast;

public class MonkeyActivity extends Activity {

	private GLSurfaceView glSurfaceView;
	private boolean		  glInited;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		initGL();
		initFileUtils();
	}
	
	@Override
	protected void onPause() {
		super.onPause();
		if (glInited) {
			glSurfaceView.onPause();
		}
	}

	@Override
	protected void onResume() {
		super.onResume();
		if (glInited) {
			glSurfaceView.onResume();
		}
	}
	
	/**
	 * 初始化FileUtils
	 */
	private void initFileUtils() {
		JNIFileUtils.setApkPath(getApplicationInfo().sourceDir);
		JNIFileUtils.setAssetsManager((Context)this, getAssets());
	}
	
	/**
	 * 初始化OpenglES、加载引起库
	 */
	private void initGL() {
		// 加载库
		GLJNI.loadLibrary();
		// 初始化opengl es
		ActivityManager manager	  = (ActivityManager)getSystemService(Context.ACTIVITY_SERVICE);
		ConfigurationInfo config  = manager.getDeviceConfigurationInfo();
		final boolean supportsES2 = config.reqGlEsVersion >= 0x20000 || isProbablyEmulator();
		if (supportsES2) {
			glSurfaceView = new GLSurfaceView(this);
			if (isProbablyEmulator()) {
				glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
			}
			glSurfaceView.setEGLContextClientVersion(2);
			glSurfaceView.setRenderer(new RenderWrapper());
			setContentView(glSurfaceView);
			glInited = true;
		} else {
			glInited = false;
			Toast.makeText(this, "This device does not support OpenGL ES 2.0.",
		                Toast.LENGTH_LONG).show();
		}
		System.out.println(getApplicationInfo().sourceDir);
	}
	
	/**
	 * 检测是否为模拟器
	 * @return
	 */
	private boolean isProbablyEmulator() {
		return Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1
        && (Build.FINGERPRINT.startsWith("generic")
        		|| Build.FINGERPRINT.startsWith("unknown")
                || Build.MODEL.contains("google_sdk")
                || Build.MODEL.contains("Emulator")
                || Build.MODEL.contains("Android SDK built for x86"));
	}
	
}

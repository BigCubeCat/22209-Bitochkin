package me.bigcubecat.game;

import com.badlogic.gdx.Graphics;
import com.badlogic.gdx.backends.lwjgl3.Lwjgl3Application;
import com.badlogic.gdx.backends.lwjgl3.Lwjgl3ApplicationConfiguration;

// Please note that on macOS your application needs to be started with the -XstartOnFirstThread JVM argument
public class DesktopLauncher {
	public static void main (String[] arg) {
		Lwjgl3ApplicationConfiguration config = new Lwjgl3ApplicationConfiguration();
		Graphics.DisplayMode mode = Lwjgl3ApplicationConfiguration.getDisplayModes(Lwjgl3ApplicationConfiguration.getPrimaryMonitor())[0];
		config.setForegroundFPS(30);
		config.setFullscreenMode(mode);
		config.setTitle("Schizophrenia Attack!");
		new Lwjgl3Application(new MyGdxGame(), config);
	}
}

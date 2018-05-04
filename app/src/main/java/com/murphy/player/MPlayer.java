package com.murphy.player;

import android.os.Bundle;

import com.murphy.player.annotations.AccessedByNative;
import com.murphy.player.annotations.CalledByNative;

import java.io.IOException;
import java.lang.ref.WeakReference;

public class MPlayer {
    static {
//        System.loadLibrary("ijkffmpeg");
        System.loadLibrary("player-lib");
        native_init();
    }

    public MPlayer() {
        native_setup(new WeakReference<>(this));
    }

    @AccessedByNative
    private long mNativeMediaPlayer;
    @AccessedByNative
    private long mNativeMediaDataSource;
    @AccessedByNative
    private long mNativeAndroidIO;
    @AccessedByNative
    private int mListenerContext;

    private String mDataSource;

    @CalledByNative
    private static void postEventFromNative(Object weakThiz, int what, int arg1, int arg2, Object ob) {
        if (weakThiz == null) {
            return;
        }
    }

    @CalledByNative
    private static String onSelectCodec(Object weakThiz, String mimeType, int profile, int level) {
        return "";
    }

    @CalledByNative
    private static boolean onNativeInvoke(Object weakThiz, int what, Bundle args) {
        return false;
    }

    public void start() {
        _start();
    }

    public void stop() {
        _stop();
    }

    public void prepare() throws IOException {
        _prepare();
    }

    public void prepareAsync() throws IOException {
        _prepareAsync();
    }

    public void setDataSource(String path)
            throws IOException, IllegalArgumentException, SecurityException, IllegalStateException {
        mDataSource = path;
        _setDataSource(path, null, null);
    }

    public String getDataSource() {
        return mDataSource;
    }

    private static native void native_init();
    private native void native_setup(Object mediaplayer_this);
    public native final void native_finalize();
    public native void native_message_loop(Object mediaplayer_this);

    public static native void native_profileBegin(String libName);
    public static native void native_profileEnd();
    public static native void native_setLogLevel(int level);

    public native void setLooping(boolean looping);
    public native boolean isLooping();
    private native void _setVolume(float leftVolume, float rightVolume);

    private native void _setAudioStreamType(int streamtype);
    private native void _reset();
    private native void _release();
    public native long getDuration();
    public native long getCurrentPosition();
    public native void seekTo(long msec) throws IllegalStateException;
    public native boolean isPlaying();
    //
    private native void _pause() throws IllegalStateException;
    private native void _stop() throws IllegalStateException;
    private native void _start() throws IllegalStateException;
    private native void _prepareAsync() throws IllegalStateException;
    private native void _prepare() throws IOException, IllegalStateException;

    private native int _getAudioStreamType() throws IllegalStateException;
    //
    private native void _setDataSource(String path, String[] keys, String[] values)
            throws IOException, IllegalArgumentException, SecurityException, IllegalStateException;

}

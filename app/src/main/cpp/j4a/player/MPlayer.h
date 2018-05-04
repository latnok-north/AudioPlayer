//
// Created by murphy on 2018/4/22.
//

#ifndef PLAYER_MPLAYER_H
#define PLAYER_MPLAYER_H

#include "j4a_base.h"

namespace murphy {
    class MPlayer_Java {
    private:
        MPlayer_Java();
        ~MPlayer_Java();
        MPlayer_Java(const MPlayer_Java&);
        MPlayer_Java& operator=(const MPlayer_Java&);

        static MPlayer_Java* m_pInstance;

        jclass id;

        jfieldID field_mNativeMediaPlayer;
        jfieldID field_mNativeMediaDataSource;
        jfieldID field_mNativeAndroidIO;
        jmethodID method_postEventFromNative;
        jmethodID method_onSelectCodec;
        jmethodID method_onNativeInvoke;
    public:
        static MPlayer_Java* getInstance();

        jlong J4AC_MPlayer__mNativeMediaPlayer__get(JNIEnv *env, jobject thiz);
        jlong J4AC_MPlayer__mNativeMediaPlayer__get__catchAll(JNIEnv *env, jobject thiz);
        void J4AC_MPlayer__mNativeMediaPlayer__set(JNIEnv *env, jobject thiz, jlong value);
        void J4AC_MPlayer__mNativeMediaPlayer__set__catchAll(JNIEnv *env, jobject thiz, jlong value);
        jlong J4AC_MPlayer__mNativeMediaDataSource__get(JNIEnv *env, jobject thiz);
        jlong J4AC_MPlayer__mNativeMediaDataSource__get__catchAll(JNIEnv *env, jobject thiz);
        void J4AC_MPlayer__mNativeMediaDataSource__set(JNIEnv *env, jobject thiz, jlong value);
        void J4AC_MPlayer__mNativeMediaDataSource__set__catchAll(JNIEnv *env, jobject thiz, jlong value);
        jlong J4AC_MPlayer__mNativeAndroidIO__get(JNIEnv *env, jobject thiz);
        jlong J4AC_MPlayer__mNativeAndroidIO__get__catchAll(JNIEnv *env, jobject thiz);
        void J4AC_MPlayer__mNativeAndroidIO__set(JNIEnv *env, jobject thiz, jlong value);
        void J4AC_MPlayer__mNativeAndroidIO__set__catchAll(JNIEnv *env, jobject thiz, jlong value);
        void J4AC_MPlayer__postEventFromNative(JNIEnv *env, jobject weakThiz, jint what, jint arg1, jint arg2, jobject obj);
        void J4AC_MPlayer__postEventFromNative__catchAll(JNIEnv *env, jobject weakThiz, jint what, jint arg1, jint arg2, jobject obj);
        jstring J4AC_MPlayer__onSelectCodec(JNIEnv *env, jobject weakThiz, jstring mimeType, jint profile, jint level);
        jstring J4AC_MPlayer__onSelectCodec__catchAll(JNIEnv *env, jobject weakThiz, jstring mimeType, jint profile, jint level);
        jstring J4AC_MPlayer__onSelectCodec__asGlobalRef__catchAll(JNIEnv *env, jobject weakThiz, jstring mimeType, jint profile, jint level);
        const char *J4AC_MPlayer__onSelectCodec__asCBuffer(JNIEnv *env, jobject weakThiz, jstring mimeType, jint profile, jint level, char *out_buf, int out_len);
        const char *J4AC_MPlayer__onSelectCodec__asCBuffer__catchAll(JNIEnv *env, jobject weakThiz, jstring mimeType, jint profile, jint level, char *out_buf, int out_len);
        jstring J4AC_MPlayer__onSelectCodec__withCString(JNIEnv *env, jobject weakThiz, const char *mimeType_cstr__, jint profile, jint level);
        jstring J4AC_MPlayer__onSelectCodec__withCString__catchAll(JNIEnv *env, jobject weakThiz, const char *mimeType_cstr__, jint profile, jint level);
        jstring J4AC_MPlayer__onSelectCodec__withCString__asGlobalRef__catchAll(JNIEnv *env, jobject weakThiz, const char *mimeType_cstr__, jint profile, jint level);
        const char *J4AC_MPlayer__onSelectCodec__withCString__asCBuffer(JNIEnv *env, jobject weakThiz, const char *mimeType_cstr__, jint profile, jint level, char *out_buf, int out_len);
        const char *J4AC_MPlayer__onSelectCodec__withCString__asCBuffer__catchAll(JNIEnv *env, jobject weakThiz, const char *mimeType_cstr__, jint profile, jint level, char *out_buf, int out_len);
        jboolean J4AC_MPlayer__onNativeInvoke(JNIEnv *env, jobject weakThiz, jint what, jobject args);
        jboolean J4AC_MPlayer__onNativeInvoke__catchAll(JNIEnv *env, jobject weakThiz, jint what, jobject args);
        int J4A_loadClass__J4AC_MPlayer(JNIEnv *env);
    };


}





#endif //PLAYER_MPLAYER_H

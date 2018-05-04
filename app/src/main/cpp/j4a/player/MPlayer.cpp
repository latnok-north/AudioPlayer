//
// Created by murphy on 2018/4/22.
//

#include <string.h>
#include "MPlayer.h"


using namespace murphy;


MPlayer_Java::MPlayer_Java() {
    ALOGI("%s\n", __func__);
}

MPlayer_Java::~MPlayer_Java() {
    ALOGI("%s\n", __func__);
}

jlong MPlayer_Java::J4AC_MPlayer__mNativeMediaPlayer__get(JNIEnv *env, jobject thiz) {
    return env->GetLongField(thiz, field_mNativeMediaPlayer);
}

jlong MPlayer_Java::J4AC_MPlayer__mNativeMediaPlayer__get__catchAll(JNIEnv *env, jobject thiz) {
    jlong ret_value = J4AC_MPlayer__mNativeMediaPlayer__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }
    return ret_value;
}

void MPlayer_Java::J4AC_MPlayer__mNativeMediaPlayer__set(JNIEnv *env, jobject thiz, jlong value) {
    env->SetLongField(thiz, field_mNativeMediaPlayer, value);
}

void MPlayer_Java::J4AC_MPlayer__mNativeMediaPlayer__set__catchAll(JNIEnv *env, jobject thiz,
                                                                   jlong value) {
    J4AC_MPlayer__mNativeMediaPlayer__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

jlong MPlayer_Java::J4AC_MPlayer__mNativeMediaDataSource__get(JNIEnv *env, jobject thiz) {
    return env->GetLongField(thiz, field_mNativeMediaDataSource);
}

jlong MPlayer_Java::J4AC_MPlayer__mNativeMediaDataSource__get__catchAll(JNIEnv *env, jobject thiz) {
    jlong ret_value = J4AC_MPlayer__mNativeMediaDataSource__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }
    return ret_value;
}

void
MPlayer_Java::J4AC_MPlayer__mNativeMediaDataSource__set(JNIEnv *env, jobject thiz, jlong value) {
    env->SetLongField(thiz, field_mNativeMediaDataSource, value);
}

void MPlayer_Java::J4AC_MPlayer__mNativeMediaDataSource__set__catchAll(JNIEnv *env, jobject thiz,
                                                                       jlong value) {
    J4AC_MPlayer__mNativeMediaDataSource__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

jlong MPlayer_Java::J4AC_MPlayer__mNativeAndroidIO__get(JNIEnv *env, jobject thiz) {
    return env->GetLongField(thiz, field_mNativeAndroidIO);
}

jlong MPlayer_Java::J4AC_MPlayer__mNativeAndroidIO__get__catchAll(JNIEnv *env, jobject thiz) {
    jlong ret_value = J4AC_MPlayer__mNativeAndroidIO__get(env, thiz);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return 0;
    }

    return ret_value;
}

void MPlayer_Java::J4AC_MPlayer__mNativeAndroidIO__set(JNIEnv *env, jobject thiz, jlong value) {
    env->SetLongField(thiz, field_mNativeAndroidIO, value);
}

void MPlayer_Java::J4AC_MPlayer__mNativeAndroidIO__set__catchAll(JNIEnv *env, jobject thiz,
                                                                 jlong value) {
    J4AC_MPlayer__mNativeAndroidIO__set(env, thiz, value);
    J4A_ExceptionCheck__catchAll(env);
}

void
MPlayer_Java::J4AC_MPlayer__postEventFromNative(JNIEnv *env, jobject weakThiz, jint what, jint arg1,
                                                jint arg2, jobject obj) {
    env->CallStaticVoidMethod(id, method_postEventFromNative, weakThiz, what, arg1, arg2, obj);
}

void
MPlayer_Java::J4AC_MPlayer__postEventFromNative__catchAll(JNIEnv *env, jobject weakThiz, jint what,
                                                          jint arg1, jint arg2, jobject obj) {
    J4AC_MPlayer__postEventFromNative(env, weakThiz, what, arg1, arg2, obj);
    J4A_ExceptionCheck__catchAll(env);
}

jstring MPlayer_Java::J4AC_MPlayer__onSelectCodec(JNIEnv *env, jobject weakThiz, jstring mimeType,
                                                  jint profile, jint level) {
    return static_cast<jstring>(env->CallStaticObjectMethod(id, method_onSelectCodec, weakThiz,
                                                            mimeType, profile, level));
}

jstring
MPlayer_Java::J4AC_MPlayer__onSelectCodec__catchAll(JNIEnv *env, jobject weakThiz, jstring mimeType,
                                                    jint profile, jint level) {
    jstring ret_object = J4AC_MPlayer__onSelectCodec(env, weakThiz, mimeType, profile, level);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        return NULL;
    }

    return ret_object;
}

jstring
MPlayer_Java::J4AC_MPlayer__onSelectCodec__asGlobalRef__catchAll(JNIEnv *env, jobject weakThiz,
                                                                 jstring mimeType, jint profile,
                                                                 jint level) {
    jstring ret_object = NULL;
    jstring local_object = J4AC_MPlayer__onSelectCodec__catchAll(env, weakThiz, mimeType, profile,
                                                                 level);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = reinterpret_cast<jstring>(J4A_NewGlobalRef__catchAll(env, local_object));
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local_object));
    return ret_object;
}

const char *MPlayer_Java::J4AC_MPlayer__onSelectCodec__asCBuffer(JNIEnv *env, jobject weakThiz,
                                                                 jstring mimeType, jint profile,
                                                                 jint level, char *out_buf,
                                                                 int out_len) {
    const char *ret_value = NULL;
    const char *c_str = NULL;
    jstring local_string = J4AC_MPlayer__onSelectCodec(env, weakThiz, mimeType, profile, level);
    if (J4A_ExceptionCheck__throwAny(env) || !local_string) {
        goto fail;
    }

    c_str = env->GetStringUTFChars(local_string, NULL);
    if (J4A_ExceptionCheck__throwAny(env) || !c_str) {
        goto fail;
    }

    strlcpy(out_buf, c_str, out_len);
    ret_value = out_buf;

    fail:
    J4A_ReleaseStringUTFChars__p(env, local_string, &c_str);
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local_string));
    return ret_value;
}

const char *
MPlayer_Java::J4AC_MPlayer__onSelectCodec__asCBuffer__catchAll(JNIEnv *env, jobject weakThiz,
                                                               jstring mimeType, jint profile,
                                                               jint level, char *out_buf,
                                                               int out_len) {
    const char *ret_value = NULL;
    const char *c_str = NULL;
    jstring local_string = J4AC_MPlayer__onSelectCodec__catchAll(env, weakThiz, mimeType, profile,
                                                                 level);
    if (J4A_ExceptionCheck__catchAll(env) || !local_string) {
        goto fail;
    }

    c_str = env->GetStringUTFChars(local_string, NULL);
    if (J4A_ExceptionCheck__catchAll(env) || !c_str) {
        goto fail;
    }

    strlcpy(out_buf, c_str, out_len);
    ret_value = out_buf;

    fail:
    J4A_ReleaseStringUTFChars__p(env, local_string, &c_str);
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local_string));
    return ret_value;
}

jstring MPlayer_Java::J4AC_MPlayer__onSelectCodec__withCString(JNIEnv *env, jobject weakThiz,
                                                               const char *mimeType_cstr__,
                                                               jint profile, jint level) {
    jstring ret_object = NULL;
    jstring mimeType = NULL;

    mimeType = env->NewStringUTF(mimeType_cstr__);
    if (J4A_ExceptionCheck__throwAny(env) || !mimeType)
        goto fail;

    ret_object = J4AC_MPlayer__onSelectCodec(env, weakThiz, mimeType, profile, level);
    if (J4A_ExceptionCheck__throwAny(env) || !ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&mimeType));
    return ret_object;
}

jstring
MPlayer_Java::J4AC_MPlayer__onSelectCodec__withCString__catchAll(JNIEnv *env, jobject weakThiz,
                                                                 const char *mimeType_cstr__,
                                                                 jint profile, jint level) {
    jstring ret_object = NULL;
    jstring mimeType = NULL;

    mimeType = env->NewStringUTF(mimeType_cstr__);
    if (J4A_ExceptionCheck__catchAll(env) || !mimeType)
        goto fail;

    ret_object = J4AC_MPlayer__onSelectCodec__catchAll(env, weakThiz, mimeType, profile, level);
    if (J4A_ExceptionCheck__catchAll(env) || !ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&mimeType));
    return ret_object;
}

jstring MPlayer_Java::J4AC_MPlayer__onSelectCodec__withCString__asGlobalRef__catchAll(JNIEnv *env,
                                                                                      jobject weakThiz,
                                                                                      const char *mimeType_cstr__,
                                                                                      jint profile,
                                                                                      jint level) {
    jstring ret_object = NULL;
    jstring local_object = J4AC_MPlayer__onSelectCodec__withCString__catchAll(env, weakThiz,
                                                                              mimeType_cstr__,
                                                                              profile, level);
    if (J4A_ExceptionCheck__catchAll(env) || !local_object) {
        ret_object = NULL;
        goto fail;
    }

    ret_object = reinterpret_cast<jstring>(J4A_NewGlobalRef__catchAll(env, local_object));
    if (!ret_object) {
        ret_object = NULL;
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local_object));
    return ret_object;
}

const char *
MPlayer_Java::J4AC_MPlayer__onSelectCodec__withCString__asCBuffer(JNIEnv *env, jobject weakThiz,
                                                                  const char *mimeType_cstr__,
                                                                  jint profile, jint level,
                                                                  char *out_buf, int out_len) {
    const char *ret_value = NULL;
    const char *c_str = NULL;
    jstring local_string = J4AC_MPlayer__onSelectCodec__withCString(env, weakThiz, mimeType_cstr__,
                                                                    profile, level);
    if (J4A_ExceptionCheck__throwAny(env) || !local_string) {
        goto fail;
    }

    c_str = env->GetStringUTFChars(local_string, NULL);
    if (J4A_ExceptionCheck__throwAny(env) || !c_str) {
        goto fail;
    }

    strlcpy(out_buf, c_str, out_len);
    ret_value = out_buf;

    fail:
    J4A_ReleaseStringUTFChars__p(env, local_string, &c_str);
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local_string));
    return ret_value;
}

const char *MPlayer_Java::J4AC_MPlayer__onSelectCodec__withCString__asCBuffer__catchAll(JNIEnv *env,
                                                                                        jobject weakThiz,
                                                                                        const char *mimeType_cstr__,
                                                                                        jint profile,
                                                                                        jint level,
                                                                                        char *out_buf,
                                                                                        int out_len) {
    const char *ret_value = NULL;
    const char *c_str = NULL;
    jstring local_string = J4AC_MPlayer__onSelectCodec__withCString__catchAll(env, weakThiz,
                                                                              mimeType_cstr__,
                                                                              profile, level);
    if (J4A_ExceptionCheck__catchAll(env) || !local_string) {
        goto fail;
    }

    c_str = env->GetStringUTFChars(local_string, NULL);
    if (J4A_ExceptionCheck__catchAll(env) || !c_str) {
        goto fail;
    }

    strlcpy(out_buf, c_str, out_len);
    ret_value = out_buf;

    fail:
    J4A_ReleaseStringUTFChars__p(env, local_string, &c_str);
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local_string));
    return ret_value;
}

jboolean
MPlayer_Java::J4AC_MPlayer__onNativeInvoke(JNIEnv *env, jobject weakThiz, jint what, jobject args) {
    return env->CallStaticBooleanMethod(id, method_onNativeInvoke, weakThiz, what, args);
}

jboolean
MPlayer_Java::J4AC_MPlayer__onNativeInvoke__catchAll(JNIEnv *env, jobject weakThiz, jint what,
                                                     jobject args) {
    jboolean ret_value = J4AC_MPlayer__onNativeInvoke(env, weakThiz, what, args);
    if (J4A_ExceptionCheck__catchAll(env)) {
        return false;
    }

    return ret_value;
}

int MPlayer_Java::J4A_loadClass__J4AC_MPlayer(JNIEnv *env) {
    int ret = -1;
    const char *J4A_UNUSED(name) = NULL;
    const char *J4A_UNUSED(sign) = NULL;
    jclass J4A_UNUSED(class_id) = NULL;
    int J4A_UNUSED(api_level) = 0;
//
//    if (id != NULL)
//        return 0;

    sign = "com/murphy/player/MPlayer";
    id = J4A_FindClass__asGlobalRef__catchAll(env, sign);
    if (id == NULL) {
        goto fail;
    }

    class_id = id;
    name = "mNativeMediaPlayer";
    sign = "J";
    field_mNativeMediaPlayer = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (field_mNativeMediaPlayer == NULL)
        goto fail;
    class_id = id;
    name = "mNativeMediaDataSource";
    sign = "J";
    field_mNativeMediaDataSource = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (field_mNativeMediaDataSource == NULL)
        goto fail;

    class_id = id;
    name = "mNativeAndroidIO";
    sign = "J";
    field_mNativeAndroidIO = J4A_GetFieldID__catchAll(env, class_id, name, sign);
    if (field_mNativeAndroidIO == NULL)
        goto fail;

    name = "postEventFromNative";
    sign = "(Ljava/lang/Object;IIILjava/lang/Object;)V";
    method_postEventFromNative = J4A_GetStaticMethodID__catchAll(env, class_id, name, sign);
    if (method_postEventFromNative == NULL)
        goto fail;

    name = "onSelectCodec";
    sign = "(Ljava/lang/Object;Ljava/lang/String;II)Ljava/lang/String;";
    method_onSelectCodec = J4A_GetStaticMethodID__catchAll(env, class_id, name, sign);
    if (method_onSelectCodec == NULL)
        goto fail;

    class_id = id;
    name = "onNativeInvoke";
    sign = "(Ljava/lang/Object;ILandroid/os/Bundle;)Z";
    method_onNativeInvoke = J4A_GetStaticMethodID__catchAll(env, class_id, name, sign);
    if (method_onNativeInvoke == NULL)
        goto fail;

    ALOGD("J4ALoader: OK: '%s' loaded\n", "com.murphy.player.MPlayer");
    ret = 0;

    fail:
    return ret;
}

MPlayer_Java *MPlayer_Java::m_pInstance = NULL;

MPlayer_Java *MPlayer_Java::getInstance() {
    if (m_pInstance == NULL) {
        m_pInstance = new MPlayer_Java();
    }
    return m_pInstance;
}

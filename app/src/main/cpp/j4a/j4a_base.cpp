//
// Created by murphy on 2018/4/18.
//

#include "j4a_base.h"
#include "MPlayer.h"

bool J4A_ExceptionCheck__throwAny(JNIEnv *env) {
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        return true;
    }
    return false;
}

bool J4A_ExceptionCheck__catchAll(JNIEnv *env) {
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
        return true;
    }
    return false;
}

int J4A_ThrowExceptionOfClass(JNIEnv *env, jclass clazz, const char *msg) {
    if (env->ThrowNew(clazz, msg) != JNI_OK) {
        ALOGE("%s: Failed: msg: '%s'\n", __func__, msg);
    }
    return 0;
}

int J4A_ThrowException(JNIEnv *env, const char *class_sign, const char *msg) {
    int ret = -1;

    if (J4A_ExceptionCheck__catchAll(env)) {
        ALOGE("pending exception throwed.\n");
    }

    jclass exceptionClass = J4A_FindClass__catchAll(env, class_sign);
    if (exceptionClass == NULL) {
        J4A_FUNC_FAIL_TRACE();
        ret = -1;
        goto fail;
    }

    ret = J4A_ThrowExceptionOfClass(env, exceptionClass, msg);
    if (ret) {
        J4A_FUNC_FAIL_TRACE();
        goto fail;
    }

    ret = 0;
    fail:
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(exceptionClass));
    return ret;
}

int J4A_ThrowIllegalStateException(JNIEnv *env, const char *msg) {
    return J4A_ThrowException(env, "java/lang/IllegalStateException", msg);
}

jclass J4A_NewGlobalRef__catchAll(JNIEnv *env, jobject obj) {
    jclass obj_global = static_cast<jclass>(env->NewGlobalRef(obj));
    if (J4A_ExceptionCheck__catchAll(env) || !(obj_global)) {
        J4A_FUNC_FAIL_TRACE();
        goto fail;
    }

    fail:
    return obj_global;
}

void J4A_DeleteLocalRef(JNIEnv *env, jobject obj) {
    if (!obj)
        return;
    env->DeleteLocalRef(obj);
}

void J4A_DeleteLocalRef__p(JNIEnv *env, jobject *obj) {
    if (!obj)
        return;
    J4A_DeleteLocalRef(env, *obj);
    *obj = NULL;
}

void J4A_DeleteGlobalRef(JNIEnv *env, jobject obj) {
    if (!obj)
        return;
    env->DeleteGlobalRef(obj);
}

void J4A_DeleteGlobalRef__p(JNIEnv *env, jobject *obj) {
    if (!obj)
        return;
    J4A_DeleteGlobalRef(env, *obj);
    *obj = NULL;
}

void J4A_ReleaseStringUTFChars(JNIEnv *env, jstring str, const char *c_str) {
    if (!str || !c_str)
        return;
    env->ReleaseStringUTFChars(str, c_str);
}

void J4A_ReleaseStringUTFChars__p(JNIEnv *env, jstring str, const char **c_str) {
    if (!str || !c_str)
        return;
    J4A_ReleaseStringUTFChars(env, str, *c_str);
    *c_str = NULL;
}

jclass J4A_FindClass__catchAll(JNIEnv *env, const char *class_sign) {
    jclass clazz = env->FindClass(class_sign);
    if (J4A_ExceptionCheck__catchAll(env) || !(clazz)) {
        J4A_FUNC_FAIL_TRACE();
        clazz = NULL;
        goto fail;
    }
    fail:
    return clazz;
}

jclass J4A_FindClass__asGlobalRef__catchAll(JNIEnv *env, const char *class_sign) {
    jclass clazz_global = NULL;
    jclass clazz = J4A_FindClass__catchAll(env, class_sign);
    if (!clazz) {
        J4A_FUNC_FAIL_TRACE1(class_sign);
        goto fail;
    }

    clazz_global = J4A_NewGlobalRef__catchAll(env, clazz);
    if (!clazz_global) {
        J4A_FUNC_FAIL_TRACE1(class_sign);
        goto fail;
    }

    fail:
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&clazz));
    return clazz_global;
}

jmethodID J4A_GetMethodID__catchAll(JNIEnv *env, jclass clazz, const char *method_name,
                                    const char *method_sign) {
    jmethodID method_id = env->GetMethodID(clazz, method_name, method_sign);
    if (J4A_ExceptionCheck__catchAll(env) || !method_id) {
        J4A_FUNC_FAIL_TRACE2(method_name, method_sign);
        method_id = NULL;
        goto fail;
    }

    fail:
    return method_id;
}

jmethodID J4A_GetStaticMethodID__catchAll(JNIEnv *env, jclass clazz, const char *method_name,
                                          const char *method_sign) {
    jmethodID method_id = env->GetStaticMethodID(clazz, method_name, method_sign);
    if (J4A_ExceptionCheck__catchAll(env) || !method_id) {
        J4A_FUNC_FAIL_TRACE2(method_name, method_sign);
        method_id = NULL;
        goto fail;
    }

    fail:
    return method_id;
}

jfieldID J4A_GetFieldID__catchAll(JNIEnv *env, jclass clazz, const char *field_name,
                                  const char *field_sign) {
    jfieldID field_id = env->GetFieldID(clazz, field_name, field_sign);
    if (J4A_ExceptionCheck__catchAll(env) || !field_id) {
        J4A_FUNC_FAIL_TRACE2(field_name, field_sign);
        field_id = NULL;
        goto fail;
    }

    fail:
    return field_id;
}

jfieldID J4A_GetStaticFieldID__catchAll(JNIEnv *env, jclass clazz, const char *field_name,
                                        const char *field_sign) {
    jfieldID field_id = env->GetStaticFieldID(clazz, field_name, field_sign);
    if (J4A_ExceptionCheck__catchAll(env) || !field_id) {
        J4A_FUNC_FAIL_TRACE2(field_name, field_sign);
        field_id = NULL;
        goto fail;
    }

    fail:
    return field_id;
}

jbyteArray J4A_NewByteArray__catchAll(JNIEnv *env, jsize capacity) {
    jbyteArray local = env->NewByteArray(capacity);
    if (J4A_ExceptionCheck__catchAll(env) || !local)
        return NULL;

    return local;
}

jbyteArray J4A_NewByteArray__asGlobalRef__catchAll(JNIEnv *env, jsize capacity) {
    jbyteArray local = env->NewByteArray(capacity);
    if (J4A_ExceptionCheck__catchAll(env) || !local)
        return NULL;

    jbyteArray global = static_cast<jbyteArray>(env->NewGlobalRef(local));
    J4A_DeleteLocalRef__p(env, reinterpret_cast<jobject *>(&local));
    return global;
}

using namespace murphy;

int J4A_LoadAll__catchAll(JNIEnv *env){
    MPlayer_Java::getInstance()->J4A_loadClass__J4AC_MPlayer(env);
    return 0;
}
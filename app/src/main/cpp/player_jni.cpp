#include <jni.h>
#include <assert.h>
#include <string>
#include "m_log.h"
#include "j4a_base.h"
#include "m_player.h"
using namespace std;
using namespace murphy;
const char *p_jni_class_player = "com/murphy/player/MPlayer";

static void message_loop_n(JNIEnv *env) {

}

static int message_loop(void *arg){
    return 0;
}

static void
MPlayer_native_init(JNIEnv *env) {
    ALOGI("%s\n", __func__);
//    M_Mutex *mutex;
}



static void MPlayer_native_setup(JNIEnv *env, jobject thiz, jobject weak_this) {
    ALOGI("%s\n", __func__);
    M_Player *player = new M_Player(message_loop);
    player->SetPlayer(env, thiz, player);
}

static JNINativeMethod g_methods[] = {
        {"native_init",    "()V",                                                         (void *) MPlayer_native_init},
        {"native_setup",   "(Ljava/lang/Object;)V",                                       (void *) MPlayer_native_setup},
//        {"native_finalize",     "()V",                                                         (void *) MPlayer_native_finalize},
//        {"native_message_loop", "(Ljava/lang/Object;)V",                                       (void *) MPlayer_native_message_loop},
//        {"native_profileBegin", "(Ljava/lang/String;)V",                                       (void *) MPlayer_native_profileBegin},
//        {"native_profileEnd",   "()V",                                                         (void *) MPlayer_native_profileEnd},
//        {"native_setLogLevel",  "(I)V",                                                        (void *) MPlayer_native_setLogLevel},
//        {"setLooping",          "(Z)V",                                                        (void *) MPlayer_setLooping},
//        {"isLooping",           "()Z",                                                         (void *) MPlayer_isLooping},
//        {"_setVolume",          "(FF)V",                                                       (void *) MPlayer_setVolume},
//        {"_setAudioStreamType", "(I)V",                                                        (void *) MPlayer_setAudioStreamType},
//        {"_reset",              "()V",                                                         (void *) MPlayer_reset},
//        {"_release",            "()V",                                                         (void *) MPlayer_release},
//        {"getDuration",         "()J",                                                         (void *) MPlayer_getDuration},
//        {"getCurrentPosition",  "()J",                                                         (void *) MPlayer_getCurrentPosition},
//        {"seekTo",              "(J)V",                                                        (void *) MPlayer_seekTo},
//        {"isPlaying",           "()Z",                                                         (void *) MPlayer_isPlaying},
//        {"_pause",              "()V",                                                         (void *) MPlayer_pause},
//        {"_stop",               "()V",                                                         (void *) MPlayer_stop},
//        {"_start",              "()V",                                                         (void *) MPlayer_start},
//        {"_prepareAsync",  "()V",                                                         (void *) MPlayer_prepareAsync},
//        {"_prepare",            "()V",                                                         (void *) MPlayer_prepare},
//        {"_getAudioStreamType", "()I",                                                         (void *) MPlayer_getAudioStreamType},
//        {"_setDataSource", "(Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/String;)V", (void *) MPlayer_setDataSourceAndHeaders}
};

JavaVM *g_vm;
jclass player_class;

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv *p_Env;
    g_vm = vm;
    if (vm->GetEnv((void **)&p_Env, JNI_VERSION_1_4) != JNI_OK) {
        return -1;
    }
    assert(p_Env != NULL);

    player_class = J4A_FindClass__asGlobalRef__catchAll(p_Env, p_jni_class_player);
    assert(player_class);
    p_Env->RegisterNatives(player_class, g_methods, NELEM(g_methods));

    J4A_LoadAll__catchAll(p_Env);

    return JNI_VERSION_1_4;
}

JNIEXPORT void JNI_OnUnload(JavaVM* vm, void* reserved){

}
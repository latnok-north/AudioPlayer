//
// Created by murphy on 2018/4/15.
//

#include <j4a/player/MPlayer.h>
#include "m_player.h"
using namespace murphy;

M_Player::M_Player(int (*msg_loop)(void *)) {
    this->msg_loop = msg_loop;
    this->mutex = new M_Mutex();
}

M_Player::~M_Player() {
    if (this->mutex != NULL) {
        delete this->mutex;
    }

    if (this->msg_thread != NULL) {
        delete this->msg_thread;
    }
}

void M_Player::SetPlayer(JNIEnv *env, jobject thiz, M_Player *mp) {
    this->mutex->M_LockMutex();
    M_Player *old = reinterpret_cast<M_Player *>(MPlayer_Java::getInstance()->J4AC_MPlayer__mNativeMediaPlayer__get__catchAll(env, thiz));
//    if (mp) {
////        ijkmp_inc_ref(mp);
//    }
    MPlayer_Java::getInstance()->J4AC_MPlayer__mNativeMediaPlayer__set__catchAll(env, thiz, reinterpret_cast<jlong>(mp));
    this->mutex->M_UnlockMutex();

    ALOGI("%s\n", __func__);
}

//
// Created by murphy on 2018/4/15.
//

#ifndef PLAYER_M_PLAYER_H
#define PLAYER_M_PLAYER_H

#include <tools/m_mutex.h>
#include <tools/m_thread.h>
#include <jni.h>
namespace murphy {

    class M_Player {
    public:
        M_Player(int(*msg_loop)(void*));
        ~M_Player();

        void SetPlayer(JNIEnv *env, jobject thiz, M_Player *mp);

    private:
        int (*msg_loop)(void *);


        volatile int ref_count;
        int restart;
        int restart_from_beginning;
        int seek_req;
        long seek_msec;
        int mp_state;

        char *data_source;
        void *weak_thiz;

        M_Mutex *mutex;
        M_Thread *msg_thread;
    };

}
#endif //PLAYER_M_PLAYER_H

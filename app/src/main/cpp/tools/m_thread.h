//
// Created by murphy on 2018/4/13.
//

#ifndef MPLAYER_M_THREAD_H
#define MPLAYER_M_THREAD_H

#include <pthread.h>

namespace murphy {

    typedef enum {
        SDL_THREAD_PRIORITY_LOW,
        SDL_THREAD_PRIORITY_NORMAL,
        SDL_THREAD_PRIORITY_HIGH
    } SDL_ThreadPriority;

    class M_Thread {
    public:
        M_Thread(int (*fn)(void *), void *data, const char *name);

        ~M_Thread();

        void M_WaitThread(int *status);

        int M_SetThreadPriority(SDL_ThreadPriority priority);

        void M_DetachThread();

        pthread_t id;

        int (*func)(void *);

        void *data;
        char name[32];
        int retval;

    private:
//        pthread_t id;
//
//        int (*func)(void *);
//
//        void *data;
//        char name[32];
//        int retval;
    };
}


#endif //MPLAYER_M_THREAD_H

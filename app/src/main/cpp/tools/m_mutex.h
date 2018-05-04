//
// Created by murphy on 2018/4/13.
//

#ifndef MPLAYER_M_MUTEX_H
#define MPLAYER_M_MUTEX_H

#include <sys/types.h>

namespace murphy {
    class M_Mutex {
    public:
        M_Mutex();

        ~M_Mutex();

        int M_LockMutex();

        int M_UnlockMutex();

    private:
        pthread_mutex_t id;
    };
}

#endif //MPLAYER_M_MUTEX_H

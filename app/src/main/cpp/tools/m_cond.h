//
// Created by murphy on 2018/4/14.
//

#ifndef MPLAYER_M_COND_H
#define MPLAYER_M_COND_H

#include "m_mutex.h"

namespace murphy {
        class M_Cond {
        public:
            M_Cond();

            ~M_Cond();

            int SDL_CondSignal();

            int SDL_CondBroadcast();

            int SDL_CondWaitTimeout(M_Mutex *mutex, uint32_t ms);

            int SDL_CondWait(M_Mutex *mutex);

        private:
            pthread_cond_t id;
        };
}


#endif //MPLAYER_M_COND_H

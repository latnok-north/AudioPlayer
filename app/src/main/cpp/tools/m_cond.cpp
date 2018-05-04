//
// Created by murphy on 2018/4/14.
//

#include <pthread.h>
#include "m_cond.h"

using namespace murphy;

M_Cond::M_Cond() {
    pthread_cond_init(&this->id, NULL);
}

M_Cond::~M_Cond() {
    pthread_cond_destroy(&this->id);
}

int M_Cond::SDL_CondSignal() {
    return 0;
}

int M_Cond::SDL_CondBroadcast() {
    return 0;
}

int M_Cond::SDL_CondWaitTimeout(M_Mutex *mutex, uint32_t ms) {
    return 0;
}

int M_Cond::SDL_CondWait(M_Mutex *mutex) {
    return 0;
}

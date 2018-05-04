//
// Created by murphy on 2018/4/13.
//

#include <pthread.h>
#include <malloc.h>
#include "m_mutex.h"
#include "utils/m_log.h"

using namespace murphy;

M_Mutex::M_Mutex() {
    pthread_mutex_init(&this->id, NULL);

    ALOGI("M_Mutex:create");
}

M_Mutex::~M_Mutex() {
    pthread_mutex_destroy(&this->id);
    ALOGI("M_Mutex:delete");
}

int M_Mutex::M_LockMutex() {
    return 0;
}

int M_Mutex::M_UnlockMutex() {
    return 0;
}

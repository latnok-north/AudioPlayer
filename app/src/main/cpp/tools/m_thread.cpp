//
// Created by murphy on 2018/4/13.
//

#include <assert.h>
#include <string.h>
#include "m_thread.h"
#include "utils/m_log.h"

using namespace murphy;

static void *M_RunThread(void *data) {
    M_Thread *thread = static_cast<M_Thread *>(data);
    ALOGI("SDL_RunThread: [%d] %s\n", (int) thread->id, thread->name);
    pthread_setname_np(pthread_self(), thread->name);
    thread->retval = thread->func(thread->data);
#ifdef __ANDROID__
//    SDL_JNI_DetachThreadEnv();
#endif
    return NULL;
}

M_Thread::M_Thread(int (*fn)(void *), void *data, const char *name) {
    this->func = fn;
    this->data = data;
    strlcpy(this->name, name, sizeof(this->name) - 1);

    pthread_create(&this->id, NULL, M_RunThread, this);
//    int retval = pthread_create(&this->id, NULL, M_RunThread, this);
//    if (retval) {
//
//    }

    ALOGI("M_Thread:create");
}

M_Thread::~M_Thread() {
    ALOGI("M_Thread:delete");
}

void M_Thread::M_WaitThread(int *status) {
    assert(this);
    pthread_join(this->id, NULL);

    if (status)
        *status = this->retval;
}

void M_Thread::M_DetachThread() {
    pthread_detach(this->id);
}

int M_Thread::M_SetThreadPriority(murphy::SDL_ThreadPriority priority) {
    struct sched_param sched;
    int policy;
    pthread_t thread = pthread_self();
    if (pthread_getschedparam(thread, &policy, &sched) < 0) {
        ALOGE("pthread_getschedparam() failed");
        return -1;
    }

    if (priority == SDL_THREAD_PRIORITY_LOW) {
        sched.sched_priority = sched_get_priority_min(policy);
    } else if (priority == SDL_THREAD_PRIORITY_HIGH) {
        sched.sched_priority = sched_get_priority_max(policy);
    } else {
        int min_priority = sched_get_priority_min(policy);
        int max_priority = sched_get_priority_max(policy);
        sched.sched_priority = (min_priority + (max_priority - min_priority) / 2);
    }
    if (pthread_setschedparam(thread, policy, &sched) < 0) {
        ALOGE("pthread_setschedparam() failed");
        return -1;
    }
    return 0;
}

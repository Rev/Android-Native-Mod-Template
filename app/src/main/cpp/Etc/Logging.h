#ifndef LOGGING_H
#define LOGGING_H

#include <android/log.h>

enum LogType
{
    DEBUG = 3,
    INFO  = 4,
    WARN  = 5,
    ERROR = 6
};

#define TAG "Polar"

#define LOGDEBUG(...) ((void)__android_log_print(DEBUG, TAG, __VA_ARGS__))
#define LOGINFO(...) ((void)__android_log_print(INFO,  TAG, __VA_ARGS__))
#define LOGWARN(...) ((void)__android_log_print(WARN,  TAG, __VA_ARGS__))
#define LOGERROR(...) ((void)__android_log_print(ERROR, TAG, __VA_ARGS__))

#endif
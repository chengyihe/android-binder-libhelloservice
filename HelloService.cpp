#define LOG_TAG "HelloService"

#include <sys/wait.h>
#include <unistd.h>

#include <cutils/log.h>
#include <binder/BinderService.h>

#include "HelloService.h"

namespace android {

HelloService::HelloService()
{
}

HelloService::~HelloService()
{
}

int HelloService::add(int a, int b)
{
    return a + b;
}

int HelloService::sub(int a, int b)
{
    return a - b;
}

}; // namespace android

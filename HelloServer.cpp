#define LOG_TAG "HelloServer"

#include <utils/Log.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "HelloService.h"

using namespace android;

int main()
{
    LOGD("HelloServer is starting");

    sp<ProcessState> proc(ProcessState::self());
    ProcessState::self()->startThreadPool();

    defaultServiceManager()->addService(String16("hello"), new HelloService);

    LOGD("Successfully register service: hello");
    LOGD("Ready to joinThreadPool");

    IPCThreadState::self()->joinThreadPool();

    return 0;
}

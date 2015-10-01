#define LOG_TAG "HelloClient"

#include <utils/Log.h>

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include "IHelloService.h"

using namespace android;

int main()
{
    sp<IHelloService> service = interface_cast<IHelloService>(defaultServiceManager()->getService(String16("hello")));

    LOGD("service->add(4, 3) = %d", service->add(4, 3));
    LOGD("service->sub(4, 3) = %d", service->sub(4, 3));

    return 0;
}

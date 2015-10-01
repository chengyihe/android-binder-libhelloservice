#define LOG_TAG "HelloService"

#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include "IHelloService.h"

namespace android {

class BpHelloService: public BpInterface<IHelloService>
{
public:
    BpHelloService(const sp<IBinder>& impl)
        : BpInterface<IHelloService>(impl)
    {
    }

    virtual int add(int a, int b)
    {
        uint32_t n;
        Parcel data, reply;
        data.writeInterfaceToken(IHelloService::getInterfaceDescriptor());
        data.writeInt32(a);
        data.writeInt32(b);
        remote()->transact(BnHelloService::TRANSACTION_ADD, data, &reply);

        return reply.readInt32();
    }

    virtual int sub(int a, int b)
    {
        uint32_t n;
        Parcel data, reply;
        data.writeInterfaceToken(IHelloService::getInterfaceDescriptor());
        data.writeInt32(a);
        data.writeInt32(b);
        remote()->transact(BnHelloService::TRANSACTION_SUB, data, &reply);

        return reply.readInt32();
    }
};

IMPLEMENT_META_INTERFACE(HelloService, "chengyihe.test.IHelloService");

status_t BnHelloService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
        case TRANSACTION_ADD: {
            CHECK_INTERFACE(IHelloService, data, reply);
            int a = data.readInt32();
            int b = data.readInt32();
            int c = add(a, b);
            reply->writeInt32(c);
            return NO_ERROR;
        }
        case TRANSACTION_SUB: {
            CHECK_INTERFACE(IHelloService, data, reply);
            int a = data.readInt32();
            int b = data.readInt32();
            int c = sub(a, b);
            reply->writeInt32(c);
            return NO_ERROR;
        }
        default: {
            return BBinder::onTransact(code, data, reply, flags);
        }
    }
    // should be unreachable
    return NO_ERROR;
}

}; // namespace android

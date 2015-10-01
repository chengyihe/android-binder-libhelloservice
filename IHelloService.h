#ifndef IHELLOSERVICE_H
#define IHELLOSERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>

namespace android {

class IHelloService: public IInterface {
public:
    DECLARE_META_INTERFACE(HelloService);

    virtual int add(int , int) = 0;
    virtual int sub(int , int) = 0;
};

class BnHelloService: public BnInterface<IHelloService> {
public:
    enum {
        TRANSACTION_ADD = IBinder::FIRST_CALL_TRANSACTION,
        TRANSACTION_SUB,
    };

    virtual status_t onTransact(uint32_t code, const Parcel& data,
            Parcel* reply, uint32_t flag = 0);
};

}; // namespace android

#endif // IHELLOSERVICE_H

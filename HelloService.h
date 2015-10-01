#ifndef HELLOSERVICE_H
#define HELLOSERVICE_H

#include <stdint.h>
#include <sys/types.h>

#include <utils/RefBase.h>
#include <utils/Errors.h>

#include <binder/IInterface.h>

#include "IHelloService.h"

namespace android {

class HelloService: public BnHelloService
{
public:
    HelloService();
    ~HelloService();
    virtual int add(int, int);
    virtual int sub(int, int);
};

}; // namespace android

#endif // HELLOSERVICE_H

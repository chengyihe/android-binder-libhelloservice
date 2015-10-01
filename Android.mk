LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES += \
	IHelloService.cpp \
	HelloService.cpp

LOCAL_SHARED_LIBRARIES += \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := libhelloservice
LOCAL_MODULE_TAGS := optional

include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := HelloServer.cpp
LOCAL_STATIC_LIBRARIES += \
	libhelloservice \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE:= helloserver
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := HelloClient.cpp
LOCAL_STATIC_LIBRARIES += \
	libhelloservice \
	libbinder \
	libcutils \
	libutils \
	liblog

LOCAL_MODULE := helloclient
LOCAL_MODULE_TAGS := optional

include $(BUILD_EXECUTABLE)

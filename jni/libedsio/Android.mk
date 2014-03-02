LOCAL_PATH := $(call my-dir)



include $(CLEAR_VARS)

LOCAL_MODULE := edsio

LOCAL_C_INCLUDES := $(LOCAL_PATH)
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../glib
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../glib/glib
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../glib/gmodule
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../glib/android

SRCDIR := $(shell readlink $(LOCAL_PATH))

LOCAL_SRC_FILES := \
$(SRCDIR)/base64.c \
$(SRCDIR)/default.c \
$(SRCDIR)/edsio.c \
$(SRCDIR)/edsio_edsio.c \
$(SRCDIR)/fh.c \
$(SRCDIR)/generic.c \
$(SRCDIR)/library.c \
$(SRCDIR)/maketime.c \
$(SRCDIR)/md5c.c \
$(SRCDIR)/partime.c \
$(SRCDIR)/sha.c \
$(SRCDIR)/simple.c

LOCAL_CFLAGS := -O3
LOCAL_SHARED_LIBRARIES := libglib-2.0 libgmodule-2.0
LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)  
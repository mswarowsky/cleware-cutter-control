set(LIB_SOURCES USBaccessBasic.c USBaccess.cpp)
set(HEADERS ${HEADERS} USBaccess.h USBaccessBasic.h USBaccessDevTypes.h)



add_library(USBaccess STATIC ${LIB_SOURCES} ${HEADERS})
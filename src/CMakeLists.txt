
cmake_minimum_required(VERSION 3.2)

set(SOURCE_FILES main.cpp)


######################################################
# Building the executable
######################################################
add_executable(cleware-cutter-control ${SOURCE_FILES})
target_link_libraries(cleware-cutter-control USBaccess)
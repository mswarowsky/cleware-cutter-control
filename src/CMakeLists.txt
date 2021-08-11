
cmake_minimum_required(VERSION 3.2)

set(SOURCE_FILES main.cpp)



######################################################
# Building the executable
######################################################
add_executable(cleware-cutter-control ${SOURCE_FILES})

target_include_directories(cleware-cutter-control PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(cleware-cutter-control CutterCommand ${Boost_LIBRARIES})
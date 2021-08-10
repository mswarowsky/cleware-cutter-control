
cmake_minimum_required(VERSION 3.2)

project(cleware-cutter-control)

######################################################
# Set all language sstandars
######################################################
enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

######################################################
# Add all includes and subdirs
######################################################
include_directories(${PROJECT_SOURCE_DIR}/include)
# For simple use just add the whol dir as unclude directory and not split it 
# into src and include dir 
include_directories(${PROJECT_SOURCE_DIR}/libs/USBaccess)


add_subdirectory(libs)
add_subdirectory(src)





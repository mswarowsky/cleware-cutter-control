
cmake_minimum_required(VERSION 3.2)

project(cleware-cutter-control)

######################################################
# Set all language sstandars
######################################################
enable_language(C)
enable_language(CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion")



#######################################################
# Find external libaries
#######################################################
find_package(Boost REQUIRED COMPONENTS program_options)

######################################################
# Add all includes and subdirs
######################################################
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_SOURCE_DIR}/libs/USBaccess)
include_directories(${PROJECT_SOURCE_DIR}/libs/CutterCommand)


add_subdirectory(libs)
add_subdirectory(src)



######################################################
# Installation and packaging
######################################################
install(TARGETS cleware-cutter-control
        RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}/bin")
install(FILES "util/99-cleware.rules" DESTINATION "/lib/udev/rules.d")
install(FILES "util/cleware-cutter-control" DESTINATION "${CMAKE_INSTALL_PREFIX}/man")





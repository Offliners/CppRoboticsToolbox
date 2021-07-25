cmake_minimum_required(VERSION 2.8)

project(CppRoboticsToolbox)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(Link src/Link.cpp)
add_library(Manipulator src/Manipulator.cpp)
add_executable(DH2TF src/DH2TF.cpp)

include_directories("/usr/include/eigen3")
include_directories("./include/")

target_link_libraries(DH2TF Link)
target_link_libraries(Manipulator Link)
target_link_libraries(DH2TF Manipulator)
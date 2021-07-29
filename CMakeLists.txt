cmake_minimum_required(VERSION 2.8)

project(CppRoboticsToolbox)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")

add_library(Link SHARED src/Link.cpp)
add_library(Manipulator SHARED src/Manipulator.cpp)
add_library(Angle SHARED src/Angle.cpp)
add_library(ArgParser SHARED src/ArgParser.cpp)

add_executable(DH2TF DH2TF.cpp)
add_executable(AngleConverter AngleConverter.cpp)
add_executable(DH DH.cpp)

include_directories("/usr/include/eigen3")
include_directories("./include/")

target_link_libraries(DH2TF Link)
target_link_libraries(Manipulator Link)
target_link_libraries(DH2TF Manipulator)
target_link_libraries(AngleConverter Angle)
target_link_libraries(DH ArgParser)
target_link_libraries(DH Manipulator)

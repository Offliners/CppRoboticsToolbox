cmake_minimum_required(VERSION 2.8)

project(CppRoboticsToolbox)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

execute_process(COMMAND cp -a ${PROJECT_SOURCE_DIR}/data ${PROJECT_BINARY_DIR}/data)

###### Dependencies #######
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(include)

add_library(Link SHARED src/Link.cpp)
add_library(Manipulator SHARED src/Manipulator.cpp)
add_library(Angle SHARED src/Angle.cpp)
add_library(ArgParser SHARED src/ArgParser.cpp)

target_link_libraries(Manipulator Link)

###### DH2DF #######
add_executable(DH2TF src/DH2TF.cpp)
target_link_libraries(DH2TF Link)
target_link_libraries(DH2TF Manipulator)

###### DH #######
add_executable(DH src/DH.cpp)
target_link_libraries(DH ArgParser)
target_link_libraries(DH Manipulator)

###### AngleConverter #######
add_executable(AngleConverter src/AngleConverter.cpp)
target_link_libraries(AngleConverter Angle)


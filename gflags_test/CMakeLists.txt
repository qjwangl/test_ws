cmake_minimum_required(VERSION 2.8)
project(gft)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_CXX_FLAGS "-std=c++11")
#set(CMAKE_C_COMPILER "arm-poky-linux-gnueabi-gcc")
#set(CMAKE_CXX_COMPILER "arm-poky-linux-gnueabi-g++")
#set(ARM arm)
set(ARM x86)
message("c = ${CMAKE_C_COMPILER}")
#where to find header files
include_directories(.)
include_directories(${gft_SOURCE_DIR}/third_party/${ARM}/gflags/include)
include_directories(${gft_SOURCE_DIR}/third_party/${ARM}/glog/include)
#include_directories(${gft_SOURCE_DIR}/third_party/${ARM}/glog/include/glog)

#where to find library
link_directories(${gft_SOURCE_DIR}/third_party/${ARM}/gflags/lib)
link_directories(${gft_SOURCE_DIR}/third_party/${ARM}/glog/lib)
message("libpath = ${gft_SOURCE_DIR}/third_party/${ARM}/gflags/lib")

aux_source_directory(. DIR_SRCS)
add_executable(gft ${DIR_SRCS})
target_link_libraries(gft gflags glog pthread)

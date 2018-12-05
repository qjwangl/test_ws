cmake_minimum_required(VERSION 2.8)

project(test_sqrt)

include_directories(.)
include_directories(include)

aux_source_directory(src DIR_SRCS)

add_executable(test_sqrt ${DIR_SRCS})

target_link_libraries(test_sqrt)
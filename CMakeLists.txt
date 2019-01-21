cmake_minimum_required(VERSION 3.6)
project(Ganzhiji)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Agrothm.cpp Agrothm.h)
add_executable(Ganzhiji ${SOURCE_FILES})
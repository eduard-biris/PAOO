cmake_minimum_required(VERSION 3.0)

project(myApp VERSION 1.0)

add_library(SmartArray STATIC SmartArray.cpp)
add_library(ArrayInterface STATIC ArrayInterface.cpp)
add_library(utils STATIC utils.cpp)
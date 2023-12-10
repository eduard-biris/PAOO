cmake_minimum_required(VERSION 3.0)

project(myApp VERSION 1.0)

add_subdirectory(classes)

add_executable(myApp main.cpp)

target_link_libraries(myApp PUBLIC StudentService)

target_include_directories(myApp PUBLIC classes)

cmake_minimum_required(VERSION 3.0)

project(myApp VERSION 1.0)

add_subdirectory(classes)

add_executable(myApp main.cpp)

target_link_libraries(myApp PUBLIC SmartArray)
target_link_libraries(myApp PUBLIC ArrayInterface)
target_link_libraries(myApp PUBLIC utils)
target_link_libraries(myApp PUBLIC ReallySmartArray)

target_include_directories(myApp PUBLIC classes)

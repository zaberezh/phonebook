cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(Phonebook CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(input STATIC input.cpp)

add_executable(phonebook main.cpp)

target_link_libraries(phonebook PRIVATE input)


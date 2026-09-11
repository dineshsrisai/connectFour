cmake_minimum_required(VERSION 3.16)
project(connectFour CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.11 REQUIRED COMPONENTS Widgets)

add_executable(connectFour
    src/main.cpp
    src/board.cpp
    src/ai.cpp
    src/mainwindow.cpp
    include/mainwindow.h
)

target_include_directories(connectFour PRIVATE include)
target_link_libraries(connectFour PRIVATE Qt6::Widgets)

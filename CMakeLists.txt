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

if(WIN32)
    add_custom_command(TARGET connectFour POST_BUILD
        COMMAND "C:/Qt/6.11.2/mingw_64/bin/windeployqt.exe"
        --release
        "$<TARGET_FILE:connectFour>"
    )
endif()

add_executable(benchmark
    src/benchmark.cpp
    src/board.cpp
    src/ai.cpp
)

target_include_directories(benchmark PRIVATE include)

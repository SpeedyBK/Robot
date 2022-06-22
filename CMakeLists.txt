cmake_minimum_required(VERSION 3.19)
project(Robot)

set(CMAKE_CXX_STANDARD 14)

add_executable(Robot main.cpp
               src/World.cpp
               src/World.h
        src/Display.cpp
        src/Display.h
               src/Factory.cpp
               src/Factory.h src/Robot.cpp src/Robot.h)
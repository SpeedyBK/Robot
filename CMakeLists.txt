cmake_minimum_required(VERSION 3.19)
project(Robot)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR C:\\Users\\Benja\\CLionProjects\\SFML_Install\\lib\\cmake\\SFML)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Robot main.cpp
               src/World.cpp
               src/World.h
               src/Display.cpp
               src/Display.h
               src/Factory.cpp
               src/Factory.h
               src/Robot.cpp
               src/Robot.h)

target_link_libraries(Robot sfml-graphics sfml-audio)
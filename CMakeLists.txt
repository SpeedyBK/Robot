cmake_minimum_required(VERSION 3.19)
project(Robot)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/benjamin/Dependencies/sfml/include")
set(SFML_LIBRARY_DIR "/home/benjamin/Dependencies/sfml/lib")
set(SFML_DIR "/home/benjamin/Dependencies/sfml/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(Robot main.cpp
               src/World.cpp
               src/World.h
               src/Display.cpp
               src/Display.h
               src/Factory.cpp
               src/Factory.h
               src/Robot.cpp
               src/Robot.h
               src/graph/Graph.cpp
               src/graph/Graph.h
               src/graph/Vertex.cpp
               src/graph/Vertex.h
               src/graph/Edge.cpp
               src/graph/Edge.h
               src/Exception.cpp
               src/Exception.h
               src/Algorithms/AStar.cpp
               src/Algorithms/AStar.h
               src/Algorithms/Node.cpp
               src/Algorithms/Node.h)

target_link_libraries(Robot sfml-graphics sfml-audio)

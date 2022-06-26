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
        src/Robot.h
        src/graph/Graph.cpp
        src/graph/Graph.h
        src/graph/Vertex.cpp
        src/graph/Vertex.h
        src/graph/Edge.cpp
        src/graph/Edge.h
        src/Exception.cpp
        src/Exception.h src/Algorithms/AStar.cpp src/Algorithms/AStar.h)

target_link_libraries(Robot sfml-graphics sfml-audio)

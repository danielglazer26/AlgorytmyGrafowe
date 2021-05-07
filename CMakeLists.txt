cmake_minimum_required(VERSION 3.19)
project(AlgorytmyGrafowe)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorytmyGrafowe main.cpp Source/LoadFromFile.cpp Header/LoadFromFile.h Source/GraphRepresentation.cpp Header/GraphRepresentation.h Source/EdgesSortedList.cpp Header/EdgesSortedList.h Source/Matrix.cpp Header/Matrix.h)
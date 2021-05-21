cmake_minimum_required(VERSION 3.19)
project(AlgorytmyGrafowe)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorytmyGrafowe main.cpp Source/LoadFromFile.cpp Header/LoadFromFile.h Source/GraphRepresentation.cpp Header/GraphRepresentation.h Source/CombinedList.cpp Header/CombinedList.h Source/Matrix.cpp Header/Matrix.h Source/MinimalSpanningTree/KruskalAlgorithm.cpp Header/MinimalSpanningTree/KruskalAlgorithm.h Source/MinimalSpanningTree/PrimAlgorithm.cpp Header/MinimalSpanningTree/PrimAlgorithm.h Source/MinimalSpanningTree/AlgorithmsMST.cpp Header/MinimalSpanningTree/AlgorithmsMST.h Source/TheShortestPath/DijkstraAlgorithm.cpp Header/TheShortestPath/DijkstraAlgorithm.h Source/TheShortestPath/BellmanFordAlgorithm.cpp Header/TheShortestPath/BellmanFordAlgorithm.h Source/TheShortestPath/AlgorithmsTheShortestPath.cpp Header/TheShortestPath/AlgorithmsTheShortestPath.h Source/Queue.cpp Header/Queue.h)
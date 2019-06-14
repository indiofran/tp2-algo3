cmake_minimum_required(VERSION 3.10.3)
project(tp3algo3)

set(CMAKE_CXX_STANDARD 14)


include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_SOURCES tests/*.cpp)

add_executable(correrTests tests/conjunto-tests.cpp algoritmosP2/floydWarshall.h algoritmosP2/floydWarshall.cpp algoritmosP2/Dijkstra.h algoritmosP2/Dijkstra.cpp algoritmosP2/DijkstraPQ.h algoritmosP2/DijkstraPQ.cpp
        algoritmosP2/bellmanFord.h algoritmosP2/bellmanFord.cpp
        graph/graph.h graph/graph.cpp digraph/digraph.h digraph/digraph.cpp)

add_executable(experimentacion2 tests/experimentacion2.cpp algoritmosP2/floydWarshall.h algoritmosP2/floydWarshall.cpp algoritmosP2/Dijkstra.h algoritmosP2/Dijkstra.cpp algoritmosP2/DijkstraPQ.h algoritmosP2/DijkstraPQ.cpp
        algoritmosP2/bellmanFord.h algoritmosP2/bellmanFord.cpp
        graph/graph.h graph/graph.cpp digraph/digraph.h digraph/digraph.cpp)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)

# Test suites a ejecutar
add_test(correrTests conjunto_test)

# Target para correr Valgrind
add_custom_target(correrValgrind
        valgrind --leak-check=full -v ./correrTests 2>&1
        DEPENDS correrTests)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(experimentacion2 gtest gtest_main)

# Test suites a ejecutar
add_test(experimentacion2 conjunto_test)



add_executable(segmentationIsMyFault main.cpp disjoint_set/disjoint_set_array.cpp disjoint_set/disjoint_set_array.hpp disjoint_set/disjoint_set_tree.cpp
        disjoint_set/disjoint_set_tree.hpp disjoint_set/disjoint_set_tree_pc.cpp disjoint_set/disjoint_set_tree_pc.hpp
        graph/graph.h graph/graph.cpp digraph/digraph.h digraph/digraph.cpp segmentation/segmentation.cpp segmentation/segmentation.h
        agm/kruskal.cpp agm/kruskal.h segmentation/in_out_functions.cpp segmentation/in_out_functions.h
        algoritmosP2/Dijkstra.h algoritmosP2/Dijkstra.cpp algoritmosP2/DijkstraPQ.h algoritmosP2/DijkstraPQ.cpp
        algoritmosP2/bellmanFord.h algoritmosP2/bellmanFord.cpp algoritmosP2/floydWarshall.h algoritmosP2/floydWarshall.cpp)

add_executable(llenaloDeSuper llenaloDeSuper.cpp digraph/digraph.h digraph/digraph.cpp
        algoritmosP2/Dijkstra.h algoritmosP2/Dijkstra.cpp algoritmosP2/DijkstraPQ.h algoritmosP2/DijkstraPQ.cpp
        algoritmosP2/bellmanFord.h algoritmosP2/bellmanFord.cpp algoritmosP2/floydWarshall.h algoritmosP2/floydWarshall.cpp)
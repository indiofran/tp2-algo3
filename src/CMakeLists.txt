cmake_minimum_required(VERSION 3.10.3)
project(tp2algo3)

set(CMAKE_CXX_STANDARD 14)


include_directories(src/ tests/google-test)
add_subdirectory(tests/google-test)

# Leemos todos los archivos de test en ./tests
file(GLOB TEST_SOURCES tests/*.cpp)

add_executable( correrTests
                tests/conjunto-tests.cpp
                min_path/bellman_ford/bellmanFord.cpp
                min_path/dijkstra/Dijkstra.cpp
                min_path/dijskstra_pq/DijkstraPQ.cpp
                min_path/floyd_warshall/floydWarshall.cpp
                digraph/digraph.cpp )

add_executable( experimentacion2
                tests/experimentacion2.cpp
                min_path/bellman_ford/bellmanFord.cpp
                min_path/dijkstra/Dijkstra.cpp
                min_path/dijskstra_pq/DijkstraPQ.cpp
                min_path/floyd_warshall/floydWarshall.cpp
                segmentation/disjoint_set/disjoint_set_tree_pc.cpp
                digraph/digraph.cpp
                graph/graph.cpp)

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(correrTests gtest gtest_main)

# Test suites a ejecutar
add_test(correrTests conjunto_test)

# Target para correr Valgrind
add_custom_target(  correrValgrind
                    valgrind --leak-check=full -v ./correrTests 2>&1
                    DEPENDS correrTests   )

# Necesitamos asociar los archivos del framework de testing
target_link_libraries(experimentacion2 gtest gtest_main)

# Test suites a ejecutar
add_test(experimentacion2 conjunto_test)



add_executable( segmentationIsMyFault
                segmentationIsMyFault.cpp
                segmentation/algorithms/algorithms.cpp
                segmentation/cli/cli.cpp
                segmentation/disjoint_set/disjoint_set_array.cpp
                segmentation/disjoint_set/disjoint_set_tree.cpp
                segmentation/disjoint_set/disjoint_set_tree_pc.cpp
                segmentation/io/io.cpp
                graph/graph.cpp)

add_executable( llenaloDeSuper
                llenaloDeSuper.cpp
                min_path/bellman_ford/bellmanFord.cpp
                min_path/dijkstra/Dijkstra.cpp
                min_path/dijskstra_pq/DijkstraPQ.cpp
                min_path/floyd_warshall/floydWarshall.cpp
                digraph/digraph.cpp )

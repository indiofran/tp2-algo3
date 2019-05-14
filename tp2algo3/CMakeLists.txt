cmake_minimum_required(VERSION 3.12)
project(tp3algo3)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp3algo3 main.cpp disjoint_set/disjoint_set_array.cpp disjoint_set/disjoint_set_array.hpp disjoint_set/disjoint_set_tree.cpp disjoint_set/disjoint_set_tree.hpp graph/graph.h graph/graph.cpp digraph/digraph.h digraph/digraph.cpp segmentation/segmentation.cpp segmentation/segmentation.h agm/kruskal.cpp agm/kruskal.h)
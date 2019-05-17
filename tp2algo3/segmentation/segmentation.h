//
// Created by enzo on 13/05/19.
//

#ifndef TP3ALGO3_SEGMENTATION_H
#define TP3ALGO3_SEGMENTATION_H


#include <algorithm>
#include "../disjoint_set/disjoint_set_array.hpp"
#include "../agm/kruskal.h"

vector<graph> segments_by_min_distance(graph& g);
vector<graph> segments_by_quantiles(graph& g);

disjoint_set_array do_initial_segmentation(graph& g); // poner cada nodo en una componente disinta
float internal_diff(disjoint_set_array& ds, int e);


#endif //TP3ALGO3_SEGMENTATION_H

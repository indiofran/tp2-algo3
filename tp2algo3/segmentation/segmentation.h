//
// Created by enzo on 13/05/19.
//

#ifndef TP3ALGO3_SEGMENTATION_H
#define TP3ALGO3_SEGMENTATION_H


#include <algorithm>
#include "../disjoint_set/disjoint_set_array.hpp"
#include "../disjoint_set/disjoint_set_tree.hpp"
#include "../disjoint_set/disjoint_set_tree_pc.hpp"
#include "../agm/kruskal.h"

vector<int> segments_by_min_distance_array(graph& g,int n,int k);
vector<int> segments_by_min_distance_tree(graph& g,int n,int k);
vector<int> segments_by_min_distance_tree_pv(graph& g,int n,int k);






#endif //TP3ALGO3_SEGMENTATION_H

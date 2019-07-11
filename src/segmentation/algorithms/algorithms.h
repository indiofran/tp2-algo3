#ifndef SEGMENTATION_ALGORITHMS
#define SEGMENTATION_ALGORITHMS


#include "../disjoint_set/disjoint_set_array.hpp"
#include "../disjoint_set/disjoint_set_tree.hpp"
#include "../disjoint_set/disjoint_set_tree_pc.hpp"
#include "../io/io.h"
#include <algorithm>

struct rgb {
    int cero;
    int uno;
    int dos;
    rgb(){
        cero=0,uno=0,dos=0;
    }
};


vector<int> segments_by_min_distance_array(graph& g, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count);
vector<int> segments_by_min_distance_tree(graph& g, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count);
vector<int> segments_by_min_distance_tree_pc(graph& g, int n, int k, long long unsigned int& find_count, long long unsigned int& unite_count);
map<int,rgb> get_clusters(vector<int>& segments);

#endif

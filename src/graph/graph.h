//
// Created by enzo on 13/05/19.
//

#ifndef TP3ALGO3_GRAPH_H
#define TP3ALGO3_GRAPH_H

#endif //TP3ALGO3_GRAPH_H

#include <vector>

using namespace std;

typedef int node;

struct edge {
    node from;
    node to;
    int weight;

    bool operator<(const edge& a)const;
    bool operator==(const edge& a)const;
};

typedef vector<edge> graph;
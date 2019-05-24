//
// Created by enzo on 13/05/19.
//

#ifndef TP3ALGO3_DIGRAPH_H
#define TP3ALGO3_DIGRAPH_H

#endif //TP3ALGO3_DIGRAPH_H

#include <vector>

using namespace std;

typedef int node;

struct directed_edge
{
    node from;
    //int subindiceFrom;
    node to;
    //int subindiceTo;
    float weight;

    bool operator<(const directed_edge& a);
    bool operator==(const directed_edge& a);
};

typedef vector<directed_edge> digraph;
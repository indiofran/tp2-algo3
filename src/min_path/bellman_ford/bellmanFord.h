//
// Created by DELL on 5/19/2019.
//

#ifndef TP2_ALGO3_BELLMANFORD_H
#define TP2_ALGO3_BELLMANFORD_H


#include "../../digraph/digraph.h"
#include <iostream>
#include <vector>
#include <limits>

class BellmanFord {
public:
    static void bellmanFord(digraph H, int raiz, int n);
    static vector<int> bellmanFord_forTesting(digraph H, int raiz, int n);
    static void bellmanFordForTime(digraph H, int raiz, int n);
};



#endif //TP2_ALGO3_BELLMANFORD_H

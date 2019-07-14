//
// Created by DELL on 5/19/2019.
//

#ifndef TP2_ALGO3_DIJKSTRA_H
#define TP2_ALGO3_DIJKSTRA_H
#include "../../digraph/digraph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>


class Dijkstra {

public:
    static void dijkstra(digraph H, int raiz, int n);
    static vector<int> dijkstra_forTesting(digraph H, int raiz, int n);
    static void dijkstraForTime(digraph H, int raiz, int n);

};


#endif //TP2_ALGO3_DIJKSTRA_H

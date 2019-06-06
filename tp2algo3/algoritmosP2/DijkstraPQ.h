//
// Created by DELL on 5/19/2019.
//

#ifndef TP2_ALGO3_DIJKSTRAPQ_H
#define TP2_ALGO3_DIJKSTRAPQ_H
#include "Dijkstra.h"

class DijkstraPQ {

public:

    static void dijkstraPQ(digraph H, int raiz, int n);
    static vector<int> dijkstraPQ_forTesting(digraph H, int raiz, int n);
};


#endif //TP2_ALGO3_DIJKSTRAPQ_H

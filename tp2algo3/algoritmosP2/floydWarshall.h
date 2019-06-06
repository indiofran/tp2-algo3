//
// Created by DELL on 5/19/2019.
//

#ifndef TP2_ALGO3_FLOYDWARSHALL_H
#define TP2_ALGO3_FLOYDWARSHALL_H
#include "DijkstraPQ.h"

class FloydWarshall {
public:
    static void floydWarshall(digraph H,int n);
    static vector<int> floydWarshall_forTesting(digraph H,int n);
};



#endif //TP2_ALGO3_FLOYDWARSHALL_H

//
// Created by enzo on 14/05/19.
//

#include "kruskal.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "../disjoint_set/disjoint_set_array.hpp"


using namespace std;

//Toma una lista de aristas
graph kruskal(graph g,int n) { //Por referencia??

    //Arbol generador minimo
    graph T;

    //Sort inicial
    sort(g.begin(), g.end());

    //Creo disjoint set;
    disjoint_set_array ds(n);

    for(int i = 0,j=0;i < n-1; ++i) {

        while(ds.find(g[j].to) == ds.find(g[j].from)){
            ++j;
        }
        T.push_back(g[j]);
        ds.unite(g[j].to,g[j].from);
    }

    return T;
}

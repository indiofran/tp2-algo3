//
// Created by enzo on 14/05/19.
//

#include "kruskal.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include "../disjoint_set/disjoint_set_array.hpp"


using namespace std;


graph kruskal(graph &g,int n) {
    //Toma una lista de aristas

    graph T;

    //Sort inicial                                        REVISAR LA FUNCION DE COMPARACION
    sort(g.begin(), g.end());

    //Algoritmo de Kruskal;
    disjoint_set_array ds(n);

    for(int i = 0, j = 0; i < n-1; ++i) {

        while(ds.find(g[j].to) == ds.find(g[j].from)){
            T.push_back(g[j]);                              //DUDA INDICE
            ds.unite(g[j].to,g[j].from);
            ++j;
        }
    }

    return T;
}

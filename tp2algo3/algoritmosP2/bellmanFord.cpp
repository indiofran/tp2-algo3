//
// Created by DELL on 5/19/2019.
//

#include "bellmanFord.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using neigh = pair<int, int>;         ////vecino, costo
using graph = vector<vector<neigh>>;

const int infty = numeric_limits<int>::max() / 2 - 1;
const int none = -1;

int cost(neigh x) {return x.second;}
int to(neigh x) {return x.first;}

int BellmanFord::bellmanFord(digraph H, int raiz, int n) {

    int vertice = n*61;
    //transformacion de aristas a adyacencias
    graph G(n);
    for(int i = 0; i < H.size(); ++i) {
        if (H[i].from == raiz){
            G[raiz].push_back({H[i].to,H[i].weight});
        }
    }

    //algoritmo de Bellman-Ford
    vector<int> D(vertice, infty), T(vertice, none), M(vertice, false);
    D[raiz] = 0; bool changed = M[raiz] = true;
    for(int i = 0; i <= n and changed; ++i) {
        changed = false;
        for(int v = 0; v < n; ++v) if(M[v]) {
                M[v] = false;
                for(auto e: G[v]) if(D[v] + cost(e) < D[to(e)])
                    {
                        M[to(e)] = changed = true;
                        D[to(e)] = D[v] + cost(e);
                        T[to(e)] = v;
                    }
            }
    }

    //output del algoritmo
   for(int i = 0; i<n; i++){
        if (i*61 != raiz) {
            cout << raiz/61 << "," << i << "," << D[i*61] << endl;
        }
    }
    return 0;
}

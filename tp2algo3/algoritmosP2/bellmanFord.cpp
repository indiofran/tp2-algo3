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

int bellmaFord() {
    //transformacion de aristas a adyacencias
    int n, m, r; cin >> n >> m >> r;
    graph G(n);
    for(int i = 0; i < m; ++i) {
        int v, w, c; cin >> v >> w >> c;
        G[v].push_back({w,c});
    }

    //algoritmo de Bellman-Ford
    vector<int> D(n, infty), T(n, none), M(n, false);
    D[r] = 0; bool changed = M[r] = true;
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
    if(changed) cout << "Ciclo negativo detectado" << endl;
    else {
        for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << " "; cout << endl;
        for(int i = 0; i < n; ++i) cout << "D[" << i << "] = " << D[i] << " "; cout << endl;
    }
    return 0;
}

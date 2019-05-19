//
// Created by DELL on 5/19/2019.
//

#include "DijkstraPQ.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//vecino, costo
using neigh = pair<int, int>;
using graph = vector<vector<neigh>>;
//costo, v, w
using bridge = tuple<int,int,int>;

const int none = -1;

int costo(neigh x) {return x.second;}
int vecino(neigh x) {return x.first;}

int main() {
    //transformacion de aristas a adyacencias
    int n, m, r; cin >> n >> m >> r;
    graph G(n);
    for(int i = 0; i < m; ++i) {
        int v, w, c; cin >> v >> w >> c;
        G[v].push_back({w,c});
    }

    //algoritmo de dijkstra
    vector<int> T(n, none), D(n); T[r] = r; D[r] = 0;
    priority_queue<bridge> S;
    for(auto x : G[r]) S.push({-costo(x), r, vecino(x)});
    while(not S.empty()) {
        int c, v, w;
        tie(c,v,w) = S.top();
        S.pop();
        if(T[w] == none) {
            T[w] = v; D[w] = -c;
            for(auto x : G[w]) if(T[vecino(x)] == none)
                    S.push({c-costo(x), w, vecino(x)});
        }
    }

    //output del algoritmo
    for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << " "; cout << endl;
    for(int i = 0; i < n; ++i) cout << "D[" << i << "] = " << D[i] << " "; cout << endl;
    return 0;
}
//
// Created by DELL on 5/19/2019.
//

#include "bellmanFord.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

//using neigh = pair<int, int>;         ////vecino, costo
//using  adjacency_list = vector<vector<neigh>>;

const int infty = numeric_limits<int>::max() / 2 - 1;
const int none = -1;

//int cost(neigh x) {return x.second;}
//int to(neigh x) {return x.first;}

int BellmanFord::bellmanFord(digraph H, int raiz, int n) {

    //Lista de sucesores
    //adjacency_list G(n*61);

   // for(int i = 0; i < H.size(); ++i) {
       // G[H[i].from].push_back({H[i].to,H[i].weight});
   // }

    vector<int> D(n*61, infty),  M(n*61, false);

    D[raiz] = 0;

    bool changed = M[raiz] = true;

    for(int i = 0; i <= n*61 and changed; ++i) {
        changed = false;

            for(int j=0 ; j<H.size();j++){

                M[H[j].from] = false;

                if (D[H[j].from] + H[j].weight < D[H[j].to]) {
                    M[H[j].to] = changed = true;
                    D[H[j].to] = D[H[j].from] + H[j].weight;
                }
            }
    }


    //output del algoritmo
    if(changed) cout << "Ciclo negativo detectado" << endl;
    else {
        for(int i = 0; i<n; i++){
            if (i*61 != raiz) {
                cout << raiz/61 << "," << i << "," << D[i*61] << endl;
            }
        }
    }
    return 0;
}

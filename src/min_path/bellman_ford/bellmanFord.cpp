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

void BellmanFord::bellmanFord(digraph H, int raiz, int n) {

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

            M[j] = false;
            for(int k=0; k<H[j].size(); k++) {

                if (D[j] + H[j][k].weight < D[H[j][k].to]) {
                    M[H[j][k].to] = changed = true;
                    D[H[j][k].to] = D[j] + H[j][k].weight;
                }
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
}



//Para testing


vector<int> BellmanFord::bellmanFord_forTesting(digraph H, int raiz, int n) {

    vector<int> D(n*61, infty),  M(n*61, false);

    D[raiz] = 0;

    bool changed = M[raiz] = true;

    for(int i = 0; i <= n*61 and changed; ++i) {
        changed = false;

        for(int j=0 ; j<H.size();j++){

            M[j] = false;
            for(int k=0; k<H[j].size(); k++) {

                if (D[j] + H[j][k].weight < D[H[j][k].to]) {
                    M[H[j][k].to] = changed = true;
                    D[H[j][k].to] = D[j] + H[j][k].weight;
                }
            }
        }
    }

    vector<int> v;
    for(int i = 0; i<n; i++){
        if (i*61 != raiz) {
            v.push_back(D[i*61]);
        }
    }
    return v;
}

void BellmanFord::bellmanFordForTime(digraph H, int raiz, int n) {

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

            M[j] = false;
            for(int k=0; k<H[j].size(); k++) {

                if (D[j] + H[j][k].weight < D[H[j][k].to]) {
                    M[H[j][k].to] = changed = true;
                    D[H[j][k].to] = D[j] + H[j][k].weight;
                }
            }
        }
    }
}
//
// Created by DELL on 5/19/2019.
//

#include "DijkstraPQ.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int DijkstraPQ::dijkstraPQ (digraph H, int raiz, int n) { //el fin es el nodo donde quiero terminar dijkstra, pero capaz es mejor dar todos y depsues ver
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> T(vertices,none), D(vertices);
    T[raiz] = raiz;
    D[raiz] = 0;
    priority_queue<bridge> S;
    for(int i = 0; i<H.size(); i++){
        if (H[i].from == raiz){
            S.push({-H[i].weight, raiz, H[i].to});
        }
    }
    while(not S.empty()){
        int weight, from, to;
        tie(weight, from, to) = S.top();
        //cout << weight << "," << from << "," << to << endl;
        S.pop();
        if(T[to] == none){
            T[to] = from;
            D[to] = -weight;
            //cout << "T[" << to << "] = " << T[to] << " " << "D[" << to << "] = " << D[to] << endl;
            for(int j = 0; j<H.size(); j++){
                if (H[j].from == to){
                    if(T[H[j].to] == none){
                        S.push({weight-H[j].weight, to, H[j].to});
                    }
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        if (i*61 != raiz) {
            cout << raiz/61 << "," << i << "," << D[i*61] << endl;
        }
    }


    //for(int i = 0; i < n*61; ++i) cout << "T[" << i << "] = " << T[i] << " " << "D[" << i << "] = " << D[i] << endl;
    return 0;
}
//
// Created by DELL on 5/19/2019.
//

#include "DijkstraPQ.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;



int DijkstraPQ::dijkstraPQ2 (digraph H, int raiz, int n) { //el fin es el nodo donde quiero terminar dijkstra, pero capaz es mejor dar todos y depsues ver
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
        cout << weight << "," << from << "," << to << endl;
        S.pop();
        if(T[to] == -1){
            T[to] = from;
            D[to] = -weight;
            cout << D[to] << endl;
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
        int min = 10000;
        int minJ = 0;
        for(int j = (i*61); j<(i*61)+60; j++){
            if(D[j]<min){
                minJ = j;
            }
        }
        cout << "T[" << minJ << "] = " << T[i] << "," << "D[" << minJ << "] = " << D[i] << endl;
    }


    //for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << " "; cout << endl;
    //for(int i = 0; i < n; ++i) cout << "D[" << i << "] = " << D[i] << " "; cout << endl;
    return 0;
}
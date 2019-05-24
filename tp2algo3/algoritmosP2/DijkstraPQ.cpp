//
// Created by DELL on 5/19/2019.
//

#include "DijkstraPQ.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int DijkstraPQ::dijkstraPQ (digraph H, int raiz, int n){ //el fin es el nodo donde quiero terminar dijkstra, pero capaz es mejor dar todos y depsues ver
    const int none = -1;
    using bridge = tuple<int,int,int>;

    vector<int> T(n,none), D(n);
    T[raiz] = raiz;
    D[raiz] = 0;
    priority_queue<bridge> S;
    for(auto x : H[raiz]) S.push({-H[x].weight, raiz, H[x].to});
    while(not S.empty()){
        int weight, from, to;
        tie(weight, from, to) = S.top();
        S.pop();
        if(T[to] == none){
            T[to] = from;
            D[to] = -weight;
            for(auto x : H[to]) if(T[H[x].to] == none){
                    S.push(weight-H[x].weight, to, H[x].to);
                }
        }
    }

    for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << " "; cout << endl;
    for(int i = 0; i < n; ++i) cout << "D[" << i << "] = " << D[i] << " "; cout << endl;
    return 0;
}
//
// Created by DELL on 5/19/2019.
//

#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int Dijkstra::dijkstra(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> T(vertices,none), D(vertices);
    T[raiz] = raiz;
    D[raiz] = 0;
    vector<bridge> S;
    for(int i = 0; i<H.size(); i++){
        if (H[i].from == raiz){
            S.push_back({-H[i].weight, raiz, H[i].to});
        }
    }
    while(not S.empty()){
        int weight, from, to;
        int min = 10000;
        int minJ = 0;
        for(int j=0;j<S.size();j++) {
            if(get<2>(S[j]) < min){
                minJ = j;
                min = get<2>(S[j]);
                //cout << minJ << endl;
            }
        }
        tie(weight, from, to) = S[minJ];
        //cout << weight << "," << from << "," << to << endl;
        S.erase(S.begin()+minJ-1);
        if(T[to] == none){
            T[to] = from;
            D[to] = -weight;
            //cout << "T[" << to << "] = " << T[to] << " " << "D[" << to << "] = " << D[to] << endl;
            for(int j = 0; j<H.size(); j++){
                if (H[j].from == to){
                    if(T[H[j].to] == none){
                        S.push_back({weight-H[j].weight, to, H[j].to});
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
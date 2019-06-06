//
// Created by DELL on 5/19/2019.
//

#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

void Dijkstra::dijkstra(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> D(vertices, none);
    D[raiz] = 0;
    vector<bridge> S;
    for(int i = 0; i<H.size(); i++){
        if (H[i].from == raiz){
            S.push_back({H[i].weight, raiz, H[i].to});
        }
    }
    while(not S.empty()){
        int weight, from, to;
        int min = 10000;
        int minJ = 0;
        for(int j=0;j<S.size();j++) {
            if(get<0>(S[j]) < min){
                minJ = j;
                min = get<0>(S[j]);
            }
        }
        tie(weight, from, to) = S[minJ];
        S.erase(S.begin()+minJ);

        if(D[to] == none){
            D[to] = weight;

            for(int j = 0; j<H.size(); j++){
                if (H[j].from == to){
                    if(D[H[j].to] == none){
                        S.push_back({weight+H[j].weight, to, H[j].to});
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

    return;
}

vector<int> Dijkstra::dijkstra_forTesting(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> D(vertices, none);
    D[raiz] = 0;
    vector<bridge> S;
    for(int i = 0; i<H.size(); i++){
        if (H[i].from == raiz){
            S.push_back({H[i].weight, raiz, H[i].to});
        }
    }
    while(not S.empty()){
        int weight, from, to;
        int min = 10000;
        int minJ = 0;
        for(int j=0;j<S.size();j++) {
            if(get<0>(S[j]) < min){
                minJ = j;
                min = get<0>(S[j]);
            }
        }
        tie(weight, from, to) = S[minJ];
        S.erase(S.begin()+minJ);

        if(D[to] == none){
            D[to] = weight;

            for(int j = 0; j<H.size(); j++){
                if (H[j].from == to){
                    if(D[H[j].to] == none){
                        S.push_back({weight+H[j].weight, to, H[j].to});
                    }
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


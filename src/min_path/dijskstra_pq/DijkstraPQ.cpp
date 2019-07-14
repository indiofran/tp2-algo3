//
// Created by DELL on 5/19/2019.
//

#include "DijkstraPQ.h"


using namespace std;

void DijkstraPQ::dijkstraPQ (digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> D(vertices, none);
    D[raiz] = 0;
    priority_queue<bridge> S;
    for(int i = 0; i<H[raiz].size(); i++){
        S.push({-H[raiz][i].weight, raiz, H[raiz][i].to});
    }
    while(not S.empty()){
        int weight, from, to;
        tie(weight, from, to) = S.top();
        S.pop();

        if(D[to] == none){
            D[to] = -weight;
            for(int j = 0; j<H[to].size(); j++){
                if(D[H[to][j].to] == none){
                    S.push({weight-H[to][j].weight, to, H[to][j].to});
                }
            }
        }
    }

    for(int i = 0; i<n; i++){
        if (i*61 != raiz) {
            cout << raiz/61 << "," << i << "," << D[i*61] << endl;
        }
    }
}

vector<int> DijkstraPQ::dijkstraPQ_forTesting(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> D(vertices, none);
    D[raiz] = 0;
    priority_queue<bridge> S;
    for(int i = 0; i<H[raiz].size(); i++){
        S.push({-H[raiz][i].weight, raiz, H[raiz][i].to});
    }
    while(not S.empty()){
        int weight, from, to;
        tie(weight, from, to) = S.top();
        S.pop();

        if(D[to] == none){
            D[to] = -weight;
            for(int j = 0; j<H[to].size(); j++){
                if(D[H[to][j].to] == none){
                    S.push({weight-H[to][j].weight, to, H[to][j].to});
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

void DijkstraPQ::dijkstraPQForTime (digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;

    vector<int> D(vertices, none);
    D[raiz] = 0;
    priority_queue<bridge> S;
    for(int i = 0; i<H[raiz].size(); i++){
        S.push({-H[raiz][i].weight, raiz, H[raiz][i].to});
    }
    while(not S.empty()){
        int weight, from, to;
        tie(weight, from, to) = S.top();
        S.pop();

        if(D[to] == none){
            D[to] = -weight;
            for(int j = 0; j<H[to].size(); j++){
                if(D[H[to][j].to] == none){
                    S.push({weight-H[to][j].weight, to, H[to][j].to});
                }
            }
        }
    }
}
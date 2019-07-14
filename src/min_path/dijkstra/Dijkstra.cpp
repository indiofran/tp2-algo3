//
// Created by DELL on 5/19/2019.
//

#include "Dijkstra.h"

using namespace std;

void Dijkstra::dijkstra(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;
    int numeroVisitados = n * 61;

    vector<int> D(vertices, none);
    vector<int> visitados(vertices, none);
    visitados[raiz] = 1;
    D[raiz] = 0;
    vector<bridge> S;
    for(int i = 0; i<H[raiz].size(); i++){
        S.push_back({H[raiz][i].weight, raiz, H[raiz][i].to});
    }
    while(numeroVisitados != 0){
        int weight, from, to;
        int min = 1000000000;
        int minJ = 0;
        for(int j=0;j<S.size();j++) {
            if (visitados[get<2>(S[j])] == none){
                if(get<0>(S[j]) < min) {
                    minJ = j;
                    min = get<0>(S[j]);
                }
            }
        }
        tie(weight, from, to) = S[minJ];
        visitados[to] = 1;
        numeroVisitados --;

        if(D[to] == none){
            D[to] = weight;

            for(int j = 0; j<H[to].size(); j++){
                if(D[H[to][j].to] == none){
                    S.push_back({weight + H[to][j].weight, to, H[to][j].to});
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

vector<int> Dijkstra::dijkstra_forTesting(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;
    int numeroVisitados = n * 61;

    vector<int> D(vertices, none);
    vector<int> visitados(vertices, none);
    visitados[raiz] = 1;
    D[raiz] = 0;
    vector<bridge> S;
    for(int i = 0; i<H[raiz].size(); i++){
        S.push_back({H[raiz][i].weight, raiz, H[raiz][i].to});
    }
    while(numeroVisitados != 0){
        int weight, from, to;
        int min = 1000000000;
        int minJ = 0;
        for(int j=0;j<S.size();j++) {
            if (visitados[get<2>(S[j])] == none){
                if(get<0>(S[j]) < min) {
                    minJ = j;
                    min = get<0>(S[j]);
                }
            }
        }
        tie(weight, from, to) = S[minJ];
        visitados[to] = 1;
        numeroVisitados --;

        if(D[to] == none){
            D[to] = weight;

            for(int j = 0; j<H[to].size(); j++){
                if(D[H[to][j].to] == none){
                    S.push_back({weight + H[to][j].weight, to, H[to][j].to});
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

void Dijkstra::dijkstraForTime(digraph H, int raiz, int n) {
    const int none = -1;
    using bridge = tuple<int, int, int>;
    int vertices = n * 61;
    int numeroVisitados = n * 61;

    vector<int> D(vertices, none);
    vector<int> visitados(vertices, none);
    visitados[raiz] = 1;
    D[raiz] = 0;
    vector<bridge> S;
    for(int i = 0; i<H[raiz].size(); i++){
        S.push_back({H[raiz][i].weight, raiz, H[raiz][i].to});
    }
    while(numeroVisitados != 0){
        int weight, from, to;
        int min = 1000000000;
        int minJ = 0;
        for(int j=0;j<S.size();j++) {
            if (visitados[get<2>(S[j])] == none){
                if(get<0>(S[j]) < min) {
                    minJ = j;
                    min = get<0>(S[j]);
                }
            }
        }
        tie(weight, from, to) = S[minJ];
        visitados[to] = 1;
        numeroVisitados --;

        if(D[to] == none){
            D[to] = weight;

            for(int j = 0; j<H[to].size(); j++){
                if(D[H[to][j].to] == none){
                    S.push_back({weight + H[to][j].weight, to, H[to][j].to});
                }
            }
        }
    }
}


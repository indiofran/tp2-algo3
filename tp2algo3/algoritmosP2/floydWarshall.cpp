//
// Created by DELL on 5/19/2019.
//

#include "floydWarshall.h"
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

using matrix = vector<vector<int>>;
const int infty = numeric_limits<int>::max() / 2 - 1; //valor apropiado

const int none = -1;


int floydWarshall() {
    //transformacion de aristas a adyacencias
    int n, m; cin >> n >> m;
    matrix D(n, vector<int>(n, infty));  //Matriz de pesos
    matrix P(n, vector<int>(n, none));   //Matriz de caminos
    for(int i = 0; i < m; ++i) {
        int v, w, c; cin >> v >> w >> c;
        D[v][w] = c;
        P[v][w] = v;
    }
    for(int v = 0; v < n; ++v) {D[v][v] = 0; P[v][v] = v;}

    //Algoritmo de Floyd-Warshall
    bool c = false;                      //Existe ciclo negativo
    for(int k = 0; k < n and not c; ++k) for(int i = 0; i < n and not c; ++i) {
            for(int j = 0; j < n; ++j) if(D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = P[k][j];
                }
            c = D[i][i] < 0;
        }

    if(c) cout << "Ciclo negativo detectado" << endl;
    else {
        cout << "D = " << endl;
        for(int i = 0; i < n; ++i) {for(int j = 0; j < n; ++j) cout << setw(3) << D[i][j] << " "; cout << endl;}
        cout << "P = " << endl;
        for(int i = 0; i < n; ++i) {for(int j = 0; j < n; ++j) cout << setw(3) << P[i][j] << " "; cout << endl;}
    }
    return 0;
}
//
// Created by DELL on 5/19/2019.
//

#include "floydWarshall.h"
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

int FloydWarshall::floydWarshall(digraph H, int raiz, int n) {
    const int none = -1;
    using matrix = vector<vector<int>>;
    const int infty = numeric_limits<int>::max() / 2 - 1; 
    //transformacion de aristas a adyacencias
    int vertices = n*61;
    matrix D(vertices, vector<int>(vertices, infty));  //Matriz de pesos
    matrix P(vertices, vector<int>(vertices, none));   //Matriz de caminos
    for(int i = 0; i < H.size(); ++i) {
        if (H[i].from == raiz){
            D[raiz][H[i].weight] = H[i].to;
            P[raiz][H[i].weight] = raiz;
        }
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

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (i*61 != raiz){
                cout << raiz/61 << "," << P[i*61][j]<< ","<< D[i*61][j] ; 
                cout << endl;
            }
        }
    }
    }
    return 0;
}

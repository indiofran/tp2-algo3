//
// Created by DELL on 5/19/2019.
//

#include "floydWarshall.h"
#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;
const int none = -1;
using matrix = vector<vector<int> >;
const int infty = numeric_limits<int>::max() / 2 - 1;

int FloydWarshall::floydWarshall(digraph H, int n) {

    matrix D(n*61, vector<int>(n*61, infty));  //Matriz de pesos
    for(int i = 0; i<H.size(); i++) {
        D[H[i].from][H[i].to] = H[i].weight;
    }
    for(int v = 0; v < n*61; ++v) {
        D[v][v] = 0;
    }

    bool c = false;                      //Existe ciclo negativo
    for(int k = 0; k < n*61 and not c; ++k) {
        for (int i = 0; i < n*61 and not c; ++i) {
            for (int j = 0; j < n*61; ++j) {
                if (D[i][j] > D[i][k] + D[k][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
                c = D[i][i] < 0;
            }
        }
    }

    if(c) cout << "Ciclo negativo detectado" << endl;
    for(int i=0; i < n*61 ; i+=61) {
        for(int j = 0; j < n*61 ; j+=61){
            if (i != j){
                cout << i/61 << "," << j/61 << "," << D[i][j] << endl;
            }
        }
    }

    return 0;
}



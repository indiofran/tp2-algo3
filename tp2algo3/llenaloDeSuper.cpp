//
// Created by DELL on 5/29/2019.
//

#include <iostream>
#include "segmentation/segmentation.h"
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <cstring>
#include <random>
#include "algoritmosP2/DijkstraPQ.h"

//Ejercicio 2

//ARREGLAR
int llenaloDeSuper(int argc, char* argv[]){

    //Cantidad de ciudades y rutas
    int n,m; cin >> n >> m;

    //Lista de Aristas
    digraph H;
    vector<int> prices;

//Costos
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        prices.push_back(c);
    }

//Grafo
    for(int i = 0; i < m; ++i){
        int weight,from,to;
        cin >> to >> from >> weight;
        //cin >> from >> to >> weight; cual va?
        for (int j = 0; j<60; j++) {  //falta el caso j=60
            directed_edge e1;
            e1.from = (from*61)+j;
            int subindiceTo = j - weight;
            if (subindiceTo<0){
                subindiceTo = 0;
            }
            int localPrice1 = prices[from];
            int edgeValue = j - weight;
            if (edgeValue<0){
                edgeValue = -edgeValue;
            } else {
                edgeValue = 0;
            }
            while(j+edgeValue <= 60) {
                e1.to = (to*61)+subindiceTo;
                e1.weight = edgeValue * localPrice1;
                H.push_back(e1);
                subindiceTo++;
                edgeValue++;
            }
            directed_edge e2; //tengo que hacer lo mismo pero del vertice to al vertice from con el valor de la nafta de to
            e2.from = (to*61)+j;
            subindiceTo = j - weight;
            if (subindiceTo<0){
                subindiceTo = 0;
            }
            int localPrice2 = prices[to];
            edgeValue = j - weight;
            if (edgeValue<0){
                edgeValue = -edgeValue;
            } else {
                edgeValue = 0;
            }
            while(j+edgeValue <= 60) {
                e2.to = (from*61)+subindiceTo;
                e2.weight = edgeValue * localPrice2;
                H.push_back(e2);
                subindiceTo++;
                edgeValue++;
            }
        }
//j=60
        directed_edge e3;
        e3.from = (from*61)+60;
        e3.to = (to*61)+(60-weight);
        e3.weight = 0;
        H.push_back(e3);
        directed_edge e4;
        e4.from = (to*61)+60;
        e4.to = (from*61)+(60-weight);
        e4.weight = 0;
        H.push_back(e4);
    }

    int d = DijkstraPQ::dijkstraPQ2(H,(0*61),n);
/*
    for(int j = 0; j<n; j++){
        for(int i = 0; i<H.size(); i++) {
            if (H[i].from >= (j*61) && H[i].from <= (j*61)+60) {
                cout << H[i].from << "," << H[i].weight << "," << H[i].to << endl;
            }
        }
    }*/

return 0;


}
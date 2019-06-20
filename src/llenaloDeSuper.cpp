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
//#include "algoritmosP2/DijkstraPQ.h"
//#include "algoritmosP2/Dijkstra.h"
//#include "algoritmosP2/bellmanFord.h"
#include "algoritmosP2/floydWarshall.h"

//Ejercicio 2


int main(){

    //Cantidad de ciudades y rutas
    int n,m; cin >> n >> m;

    //Lista de Aristas
    digraph H(n*61);
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
        //cin >> to >> from >> weight;
        cin >> from >> to >> weight; //cual va?
        for (int j = 0; j<60; j++) {  //falta el caso j=60
            directed_edge e1;
            int nodeFrom1 = (from*61)+j;
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
                H[nodeFrom1].push_back(e1);
                subindiceTo++;
                edgeValue++;
            }
            directed_edge e2; //tengo que hacer lo mismo pero del vertice to al vertice from con el valor de la nafta de to
            int nodeFrom2 = (to*61)+j;
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
                H[nodeFrom2].push_back(e2);
                subindiceTo++;
                edgeValue++;
            }
        }
//j=60
        directed_edge e3;
        int nodeFrom3 = (from*61)+60;
        e3.to = (to*61)+(60-weight);
        e3.weight = 0;
        H[nodeFrom3].push_back(e3);
        directed_edge e4;
        int nodeFrom4 = (to*61)+60;
        e4.to = (from*61)+(60-weight);
        e4.weight = 0;
        H[nodeFrom4].push_back(e4);
    }

    //for (int i=0; i < n; i++) {
    //    DijkstraPQ::dijkstraPQ(H, (i * 61), n);
    //}
    for (int i=0; i < n; i++) {
        Dijkstra::dijkstra(H, (i * 61), n);
    }
    //for (int i=0; i < n; i++) {
    //    BellmanFord::bellmanFord(H, (i * 61), n);
    //}
    FloydWarshall::floydWarshall(H, n);


return 0;


}
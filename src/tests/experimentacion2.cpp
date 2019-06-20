//
// Created by hghianni on 07/06/19.
//

#include <gtest/gtest.h>
#include <random>
#include <chrono>

#include "../algoritmosP2/floydWarshall.h"

//Caso completo

TEST(text_all,random){

        for (int n = 2; n < 11; n++) {

            double tiempoDijkstraPQ = 0.0;
            double tiempoDijkstra = 0.0;
            double tiempoBellmanFord = 0.0;
            double tiempoFloydWarshall = 0.0;

            for(int k=0; k<100; k++) {

                std::random_device generator;

                //Intervalo de precios y distancias
                std::uniform_int_distribution<int> distribution(1, 10);


                vector<pair<int, int> > aristas;

                for (int l = 0; l < n - 1; ++l) {
                    for (int i = l + 1; i < n; ++i) {
                        aristas.push_back({l, i});

                    }
                }

                int m = aristas.size();

                //Lista de Aristas
                digraph H(n*61);
                vector<int> prices;

                //Costos
                for (int i = 0; i < n; ++i) {
                    int c = distribution(generator);
                    prices.push_back(c);
                }

                //Grafo
                for(int i = 0; i < m; ++i){
                    //cin >> to >> from >> weight;
                    int from = aristas[i].first;
                    int to = aristas[i].second;
                    int weight = distribution(generator);
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

                auto tiempo_inicio = chrono::steady_clock::now();
                for (int i = 0; i < n; i++) {
                    Dijkstra::dijkstraForTime(H, (i * 61), n);
                }
                auto tiempo_fin = chrono::steady_clock::now();
                tiempoDijkstra += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();
                tiempo_inicio = chrono::steady_clock::now();
                for (int i = 0; i < n; i++) {
                    DijkstraPQ::dijkstraPQForTime(H, (i * 61), n);
                }
                tiempo_fin = chrono::steady_clock::now();
                tiempoDijkstraPQ += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();
                tiempo_inicio = chrono::steady_clock::now();
                for (int i = 0; i < n; i++) {
                    BellmanFord::bellmanFordForTime(H, (i * 61), n);
                }
                tiempo_fin = chrono::steady_clock::now();
                tiempoBellmanFord += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();

                tiempo_inicio = chrono::steady_clock::now();
                FloydWarshall::floydWarshallForTime(H, n);
                tiempo_fin = chrono::steady_clock::now();
                tiempoFloydWarshall += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();
            }

            tiempoDijkstra = tiempoDijkstra / 100;
            tiempoDijkstraPQ = tiempoDijkstraPQ / 100;
            tiempoBellmanFord = tiempoBellmanFord / 100;
            tiempoFloydWarshall = tiempoFloydWarshall / 100;


            cout << n << "," << tiempoDijkstra << endl;
            cout << n << "," << tiempoDijkstraPQ << endl;
            cout << n << "," << tiempoBellmanFord << endl;
            cout << n << "," << tiempoFloydWarshall << endl;

        }
}

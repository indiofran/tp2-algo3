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

            for(int k=0; k<50; k++) {

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
                digraph H;
                vector<int> prices;

                //Costos
                for (int i = 0; i < n; ++i) {
                    int c = distribution(generator);
                    prices.push_back(c);
                }

                //Grafo
                for (int i = 0; i < m; ++i) {
                    int weight = distribution(generator);
                    int from = aristas[i].first;
                    int to = aristas[i].second;

                    for (int j = 0; j < 60; j++) {  //falta el caso j=60
                        directed_edge e1;
                        e1.from = (from * 61) + j;
                        int subindiceTo = j - weight;
                        if (subindiceTo < 0) {
                            subindiceTo = 0;
                        }
                        int localPrice1 = prices[from];
                        int edgeValue = j - weight;
                        if (edgeValue < 0) {
                            edgeValue = -edgeValue;
                        } else {
                            edgeValue = 0;
                        }
                        while (j + edgeValue <= 60) {
                            e1.to = (to * 61) + subindiceTo;
                            e1.weight = edgeValue * localPrice1;
                            H.push_back(e1);
                            subindiceTo++;
                            edgeValue++;
                        }
                        directed_edge e2;
                        e2.from = (to * 61) + j;
                        subindiceTo = j - weight;
                        if (subindiceTo < 0) {
                            subindiceTo = 0;
                        }
                        int localPrice2 = prices[to];
                        edgeValue = j - weight;
                        if (edgeValue < 0) {
                            edgeValue = -edgeValue;
                        } else {
                            edgeValue = 0;
                        }
                        while (j + edgeValue <= 60) {
                            e2.to = (from * 61) + subindiceTo;
                            e2.weight = edgeValue * localPrice2;
                            H.push_back(e2);
                            subindiceTo++;
                            edgeValue++;
                        }
                    }
//j=60
                    directed_edge e3;
                    e3.from = (from * 61) + 60;
                    e3.to = (to * 61) + (60 - weight);
                    e3.weight = 0;
                    H.push_back(e3);
                    directed_edge e4;
                    e4.from = (to * 61) + 60;
                    e4.to = (from * 61) + (60 - weight);
                    e4.weight = 0;
                    H.push_back(e4);
                }

                auto tiempo_inicio = chrono::steady_clock::now();
                for (int i = 0; i < n; i++) {
                    DijkstraPQ::dijkstraPQ(H, (i * 61), n);
                }
                auto tiempo_fin = chrono::steady_clock::now();
                tiempoDijkstraPQ += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();

                tiempo_inicio = chrono::steady_clock::now();
                for (int i = 0; i < n; i++) {
                    Dijkstra::dijkstra(H, (i * 61), n);
                }
                tiempo_fin = chrono::steady_clock::now();
                tiempoDijkstra += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();

                tiempo_inicio = chrono::steady_clock::now();
                for (int i = 0; i < n; i++) {
                    BellmanFord::bellmanFord(H, (i * 61), n);
                }
                tiempo_fin = chrono::steady_clock::now();
                tiempoBellmanFord += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();

                tiempo_inicio = chrono::steady_clock::now();
                FloydWarshall::floydWarshall(H, n);
                tiempo_fin = chrono::steady_clock::now();
                tiempoFloydWarshall += chrono::duration<double, milli>(tiempo_fin - tiempo_inicio).count();
            }

            tiempoDijkstraPQ = tiempoDijkstraPQ / 50;
            tiempoDijkstra = tiempoDijkstra / 50;
            tiempoBellmanFord = tiempoBellmanFord / 50;
            tiempoFloydWarshall = tiempoFloydWarshall / 50;

            cout << n << "," << tiempoDijkstraPQ << endl;
            cout << n << "," << tiempoDijkstra << endl;
            cout << n << "," << tiempoBellmanFord << endl;
            cout << n << "," << tiempoFloydWarshall << endl;

        }
}

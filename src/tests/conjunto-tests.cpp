#include <gtest/gtest.h>
#include <random>
#include "../min_path/floyd_warshall/floydWarshall.h"
#include "../min_path/dijkstra/Dijkstra.h"
#include "../min_path/dijskstra_pq/DijkstraPQ.h"
#include "../min_path/bellman_ford/bellmanFord.h"


TEST(text_all,random){

    for (int k = 0; k < 1000; ++k) {


        std::random_device generator;

        //Intervalo de precios y distancias
        std::uniform_int_distribution<int> distribution(1, 10);

        //Intervalo de la cantidad de ciudades
        std::uniform_int_distribution<int> distribution_for_n(2, 5);

        //Ciudades y rutas
        int n = distribution_for_n(generator);

        int aristasKn = (n*(n-1))/2;
        std::uniform_int_distribution<int> distribution_for_m(n-1, aristasKn);
        int m = distribution_for_m(generator);

        vector<pair<int,int> > aristas;
        vector<pair<int,int> > todas_las_aristas;

        //Me aseguro un grafo conexo
        for (int l = 0; l < n-1; ++l) {
            aristas.push_back({l,l+1});
        }

        //Calculo todas las aristas salvo las que ya use para que sea conexo
        for (int l = 0; l < n-1; ++l) {
            for (int i = l+1; i < n; ++i) {
                if(l+1 != i){
                    todas_las_aristas.push_back({l,i});
                }
            }
        }

        //Uso random shuffle para mezclar y agarro las cantidad que necesita para llegar a m aristas
        std::random_shuffle(todas_las_aristas.begin(),todas_las_aristas.end());

        for (int l = 0; l< (m-(n-1)); ++l) {
            aristas.push_back(todas_las_aristas[l]);
        }

        //Uso random shuffle para mezclar y agarro las cantidad que necesita para llegar a m aristas
        std::random_shuffle(todas_las_aristas.begin(),todas_las_aristas.end());

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

        vector<int> res1;
        vector<int> res2;
        vector<int> res3;
        vector<int> res4;


        for (int i = 0; i < n; i++) {
            vector<int> parcial;

            parcial = DijkstraPQ::dijkstraPQ_forTesting(H, (i * 61), n);
            for (int j = 0; j < parcial.size(); ++j) {
                res1.push_back(parcial[j]);
            }

            parcial = Dijkstra::dijkstra_forTesting(H, (i * 61), n);
            for (int j = 0; j < parcial.size() ; ++j) {
                res2.push_back(parcial[j]);
            }

            parcial = BellmanFord::bellmanFord_forTesting(H, (i * 61), n);
            for (int j = 0; j < parcial.size(); ++j) {
                res3.push_back(parcial[j]);
            }
        }

        res4 = FloydWarshall::floydWarshall_forTesting(H, n);


        EXPECT_EQ(res1,res2);
        EXPECT_EQ(res1, res3);
        EXPECT_EQ(res1, res4);
    }
}

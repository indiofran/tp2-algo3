#include <iostream>
#include "digraph/digraph.h"
#include "segmentation/segmentation.h"
#include <string>
#include <fstream>
#include <sstream>


int main() {
/*
    //Ejercicio 1

    //Ancho y alto de la imagen a procesar

    int w,h;
    ifstream infile;
    infile.open("testfile.in",std::ifstream::in);

    if (!infile) {  cout << "Can't open file "<< endl;  exit(1); }

    string inputLine ;

    cin>>w;

    cout << w << endl;

    return 0;
*/
   /*

    //int w, h;
    //cin >> w >> h;

    //Lista de Aristas
    graph G;

    //Cantidad de nodos
    int n=h*w;


    //Imagen
    vector<vector<int> > imagen;

    //Numeracion de los vertices
    vector<vector<int> > vertex ;
    int v=0;

    //Armo las matrices de pixeles y numero de vertices
    for(int i = 0; i < h; ++i){

        vector<int> vacio;
        vertex.push_back(vacio);
        imagen.push_back(vacio);

        for(int j = 0; i < w; ++j){
            int pixel;
            cin >> pixel;
            imagen[i].push_back(pixel);
            vertex[i].push_back(v);
            v++;
        }
    }

    //Gaussian Filter?

    //Imagen a Grafo
    G = image_to_graph(imagen,vertex,h,w);

   
    int k;
    vector<int> segments = segments_by_min_distance_array(G,n,k);

    //Convierto los segmentos en formato imagen
    imagen = segments_to_image(segments,h,w);

    //Cout de la segmentacion
    for(int i = 0; i < h; ++i){

        for(int j = 0; i < w; ++j){
            int pixel=imagen[i][j];
            cout << pixel;
        }
        cout<<endl;
    }



*/

    //Ejercicio 2

    //ARREGLAR

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
            directed_edge e;
            e.from = from;
            e.subindiceFrom = j;
            int subindiceTo = j - weight;
            if (subindiceTo<0){
                subindiceTo = 0;
            }
            int localPrice = prices[from];
            int edgeValue = j - weight;
            if (edgeValue<0){
                edgeValue = -edgeValue;
            } else {
                edgeValue = 0;
            }
            while(j+edgeValue <= 60) {
                e.to = to;
                e.subindiceTo = subindiceTo;
                e.weight = edgeValue * localPrice;
                H.push_back(e);
                subindiceTo++;
                edgeValue++;
            }
        }
        //j=60
        directed_edge e;
        e.from = from;
        e.subindiceFrom = 60;
        e.to = to;
        e.subindiceTo = 60 - weight;
        e.weight = 0;
        H.push_back(e);
    }

    return 0;


}
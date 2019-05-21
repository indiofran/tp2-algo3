#include <iostream>
#include "digraph/digraph.h"
#include "segmentation/in_out_functions.h"
#include "segmentation/segmentation.h"

int main() {

    //Ejercicio 1

    //Ancho y alto de la imagen a procesar

    int w, h; cin >> w >> h;

    //Lista de Aristas
    graph G;

    //Cantidad de nodos
    int n=h*w;


    //Imagen
    vector<vector<int> > imagen;

    //Numeracion de los vertices
    vector<vector<int> > vertex ;
    int v=0;

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

    //Imagen a Grafo     CORREGIR ARISTAS REPETIDAS
    G = image_to_graph(imagen,vertex,h,w);

    //Segmentacion del Grafo CORREGIR PARA ARBOLES Y REVISAR SI HACE FALTA KRUSKAL
    int k;
    vector<int> segments = segments_by_min_distance(G,n,k);

    //Convierto los segmentos en formato imagen   REVISAR
    imagen = segments_to_image(segments,h,w);

    //Cout de la segmentacion
    for(int i = 0; i < h; ++i){

        for(int j = 0; i < w; ++j){
            int pixel=imagen[i][j];
            cout << pixel;
        }
        cout<<endl;
    }





    //Ejercicio 2

    //ARREGLAR
/*
    //Cantidad de ciudades y rutas
    int n, m; cin >> n >> m;

    //Lista de Aristas
    digraph H;
    vector<int> costos;

    //Costos
    for(int i = 0; i < n; ++i){
        int c;
        cin >> c;
        costos.push_back(c);
    }

    //Grafo
    for(int i = 0; i < m; ++i){
        directed_edge e;
        cin >> e.to >> e.from >> e.weight;
        H.push_back(e);
    }

    return 0;

*/
}
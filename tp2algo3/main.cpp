#include <iostream>
#include "graph/graph.h"
#include "digraph/digraph.h"

int main() {

    //Ejercicio 1

    //Ancho y alto de la imagen a procesar

    int w, h; cin >> w >> h;

    //Lista de Aristas
    graph G;

    //Imagen
    vector<vector<int> > imagen;
    for(int i = 0; i < h; ++i){

        for(int j = 0; i < w; ++j){
            int pixel;                 //INT???
            cin >> pixel;

            imagen[i].push_back(pixel);
        }
    }

    //Imagen a Grafo?

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w ; ++j) {

            //Esquina izq arriba
            if(i==0==j){
                edge a,b,c;
                a.to=0;
                b.to=0;
                c.to=0;
                a.from=1;
                b.from=w;
                c.from=w+1;
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Esquina der abajo
            if(i==h-1 and j==w-1){
                edge a,b,c;
                a.to=0;
                b.to=0;
                c.to=0;
                a.from=1;
                b.from=h;
                c.from=h+1;
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Esquina der arriba
            if(i==0 and j==w-1){
                edge a,b,c;
                a.to=w-1;
                b.to=w-1;
                c.to=w-1;
                a.from=w-2;
                b.from=2*w -1;
                c.from=2*w -2;
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }
            //Esquina izq abajo
            if(i==h-1 and j==0){
                edge a,b,c;
                a.to=0;
                b.to=0;
                c.to=0;
                a.from=1;
                b.from=h;
                c.from=h+1;
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Fila arriba

            //Fila abajo

            //Resto de los casos?

        }
    }



    //Ejercicio 2



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
}

//
// Created by enzo on 13/05/19.
//

#include "segmentation.h"

//PROBLEMA ARISTAS REPETIDAS EN LA ENTRADA(BORRAR REPETIDOS?)
//REVISAR COMO VIENE DADO EL K O SE LO DOY
//REVISAR COMO AGARRAR LOS SEGMENTOS Y PASARLOS A MATRIZ

vector<int> segments_by_min_distance(graph& g,int n,int k) {

    //Cantidad de aristas
    unsigned int m = g.size();

    vector<int> Int;

    //Ordeno de manera creciente las aristas por peso(no decreciente)
    sort(g.begin(), g.end());

    //Segmentacion inicial S0
    disjoint_set_array segments = disjoint_set_array(n);

    // Para cada arista de g
    for (unsigned int q = 0; q < m; q++)
    {
        edge current = g[q];
        node vi = current.from;
        node vj = current.to;
        float weight = current.weight;

        int c1=segments.find(vi);
        int c2=segments.find(vj);

        // Si estan en componentes distintas
        if (c1 != c2)
        {

            // Calculo las diferencias internas
            float internal_diff_c1 = segments.internal_diff(c1);
            float internal_diff_c2 = segments.internal_diff(c2);

            // Cantidad de nodos que tienen las componentes
            int size_c1 = segments._size(c1);
            int size_c2 = segments._size(c2);

            int rc1=k/size_c1;
            int rc2=k/size_c2;

            // Calculo la minima diferencia interna
            int Mint = min(internal_diff_c1+rc1,internal_diff_c2+rc2);

            if (weight <= Mint)
            {
                //Uno las componentes
                segments.unite(vi, vj);

                //nose cual gano.actualizo los dos?

                //Actualizo la arista maxima del AGM de la componente que se formo
                segments.actualizarInt(weight,c1);
                segments.actualizarInt(weight,c2);
            }
        }
    }
    return segments.segmentation();
}

/*
vector<graph> segments_by_min_distance(graph& g,int n)
{
    graph a = kruskal(g);
    unsigned int m = a.size();
    sort(a.begin(), a.end());
    disjoint_set_array segments = do_initial_segmentation(a);


    for (unsigned int i = 1; i < m; i++)
    {
        edge current = a[i];
        node v = current.from;
        node w = current.to;
        float diff = current.weight;

        if (segments.find(v) != segments.find(w))
        {
            float internal_diff_v = internal_diff(segments, v);
            float internal_diff_w = internal_diff(segments, w);

            if (diff < internal_diff_v && diff < internal_diff_w)
            {
                segments.unite(v, w);
            }
        }
    }
}

*/
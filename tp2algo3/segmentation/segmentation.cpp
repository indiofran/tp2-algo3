//
// Created by enzo on 13/05/19.
//

#include "segmentation.h"
#include <algorithm>

//REVISAR COMO VIENE DADO EL K O SE LO DOY
//REVISAR COMO AGARRAR LOS SEGMENTOS Y PASARLOS A MATRIZ

vector<int> segments_by_min_distance_array(graph& g,int n,int k) {

    //Cantidad de aristas
    unsigned int m = g.size();

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
        int weight = current.weight;

        int c1=segments.find(vi);
        int c2=segments.find(vj);

        // Si estan en componentes distintas
        if (c1 != c2)
        {

            // Calculo las diferencias internas
            float internal_diff_c1 = segments.internal_difference(c1);
            float internal_diff_c2 = segments.internal_difference(c2);

            // Cantidad de nodos que tienen las componentes
            int size_c1 = segments.size(c1);
            int size_c2 = segments.size(c2);

            int rc1=k/size_c1;
            int rc2=k/size_c2;

            // Calculo la minima diferencia interna
            int Mint = min(internal_diff_c1+rc1,internal_diff_c2+rc2);

            if (weight <= Mint)
            {
                //Uno las componentes
                segments.unite(vi, vj);

                //Actualizo la arista maxima del AGM de la componente que se formo
                segments.update_internal_difference(weight,c1);
                segments.update_internal_difference(weight,c2);
            }
        }
    }
    return segments.segmentation();
}

vector<int> segments_by_min_distance_tree(graph& g,int n,int k) {

    //Cantidad de aristas
    unsigned int m = g.size();

    //Ordeno de manera creciente las aristas por peso(no decreciente)
    sort(g.begin(), g.end());

    //Segmentacion inicial S0
    disjoint_set_tree segments = disjoint_set_tree(n);

    // Para cada arista de g
    for (unsigned int q = 0; q < m; q++)
    {
        edge current = g[q];
        node vi = current.from;
        node vj = current.to;
        int weight = current.weight;

        int c1=segments.find(vi);
        int c2=segments.find(vj);

        // Si estan en componentes distintas
        if (c1 != c2)
        {

            // Calculo las diferencias internas
            float internal_diff_c1 = segments.internal_difference(c1);
            float internal_diff_c2 = segments.internal_difference(c2);

            // Cantidad de nodos que tienen las componentes
            int size_c1 = segments.size(c1);
            int size_c2 = segments.size(c2);

            int rc1=k/size_c1;
            int rc2=k/size_c2;

            // Calculo la minima diferencia interna
            int Mint = min(internal_diff_c1+rc1,internal_diff_c2+rc2);

            if (weight <= Mint)
            {
                //Uno las componentes
                segments.unite(vi, vj);

                //Actualizo la arista maxima del AGM de la componente que se formo
                segments.update_internal_difference(weight,c1);
                segments.update_internal_difference(weight,c2);
            }
        }
    }
    return segments.segmentation();
}

vector<int> segments_by_min_distance_tree_pc(graph& g,int n,int k) {

    //Cantidad de aristas
    unsigned int m = g.size();

    //Ordeno de manera creciente las aristas por peso(no decreciente)
    sort(g.begin(), g.end());

    //Segmentacion inicial S0
    disjoint_set_tree_pc segments = disjoint_set_tree_pc(n);

    // Para cada arista de g
    for (unsigned int q = 0; q < m; q++)
    {
        edge current = g[q];
        node vi = current.from;
        node vj = current.to;
        int weight = current.weight;

        int c1=segments.find(vi);
        int c2=segments.find(vj);

        // Si estan en componentes distintas
        if (c1 != c2)
        {

            // Calculo las diferencias internas
            float internal_diff_c1 = segments.internal_difference(c1);
            float internal_diff_c2 = segments.internal_difference(c2);

            // Cantidad de nodos que tienen las componentes
            int size_c1 = segments.size(c1);
            int size_c2 = segments.size(c2);

            int rc1=k/size_c1;
            int rc2=k/size_c2;

            // Calculo la minima diferencia interna
            int Mint = min(internal_diff_c1+rc1,internal_diff_c2+rc2);

            if (weight <= Mint)
            {
                //Uno las componentes
                segments.unite(vi, vj);

                //Actualizo la arista maxima del AGM de la componente que se formo
                segments.update_internal_difference(weight,c1);
                segments.update_internal_difference(weight,c2);
            }
        }
    }
    return segments.segmentation();
}



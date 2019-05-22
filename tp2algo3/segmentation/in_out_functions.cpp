//
// Created by Hernan Ghianni on 19/5/19.
//

#include "in_out_functions.h"
#include <algorithm>


graph image_to_graph (vector<vector<int> > image,vector<vector<int> > vertex,int h,int w){

    graph G;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w ; ++j) {
            bool centro=true;
            //Esquina izq arriba
            if(i==0 and 0==j){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }


            //Esquina der arriba
            if(i==0 and j==w-1){
                centro=false;
                edge a,b;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                a.to = vertex[i+1][j];
                b.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i+1][j]);
                b.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
            }

            //Esquina der abajo
            if(i==h-1 and j==w-1){
                centro=false;
            }


            //Esquina izq abajo
            if(i==h-1 and j==0){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                a.to = vertex[i][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                G.push_back(a);
            }

            //Fila arriba
            if(i==0 and j!=0 and j!=w-1){
                centro=false;
                edge a,b,c,d;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                d.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                d.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
            }

            //Fila abajo
            if(i==h-1 and j!=0 and j!=w-1){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                a.to = vertex[i][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                G.push_back(a);
            }
            //Columna izquierda
            if(j==0 and i!=0 and i!=h-1){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Columna derecha
            if(j==w-1 and i!=0 and i!=h-1){
                centro=false;
                edge a,b;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                a.to = vertex[i+1][j];
                b.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i+1][j]);
                b.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
            }

            //Resto de los casos
            if(centro){
                edge a,b,c,d;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i+1][j];
                c.to = vertex[i+1][j+1];
                d.to = vertex[i+1][j-1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i+1][j]);
                c.weight=abs(image[i][j]-image[i+1][j+1]);
                d.weight=abs(image[i][j]-image[i+1][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
            }
        }
    }

    return G;
}

vector<vector<int> > segments_to_image (vector<int> segments,int h,int w){
    vector<vector<int> > image;
    int k=0;

    for (int i = 0; i < h ; ++i) {
        vector<int> vacio;
        image.push_back(vacio);

        for (int j = 0; j < w; ++j) {
            image[i].push_back(segments[k]);
            k++;
        }
    }

    return image;
}
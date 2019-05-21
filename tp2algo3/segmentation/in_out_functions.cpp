//
// Created by Hernan Ghianni on 19/5/19.
//

#include "in_out_functions.h"


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
                a.to = 1;
                b.to = w;
                c.to = w+1;
                a.weight=abs(image[0][0]-image[0][1]);
                b.weight=abs(image[0][0]-image[1][0]);
                c.weight=abs(image[0][0]-image[1][1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }


            //Esquina der arriba
            if(i==0 and j==w-1){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[0][w-2];
                b.to = vertex[1][w-1];
                c.to = vertex[1][w-2];
                a.weight=abs(image[0][w-1]-image[0][w-2]);
                b.weight=abs(image[0][w-1]-image[1][w-1]);
                c.weight=abs(image[0][w-1]-image[1][w-2]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Esquina der abajo
            if(i==h-1 and j==w-1){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[i][j-1];
                b.to = vertex[i-1][j];
                c.to = vertex[i-1][j-1];
                a.weight=abs(image[h-1][w-1]-image[h-1][w-2]);
                b.weight=abs(image[h-1][w-1]-image[h-2][w-1]);
                c.weight=abs(image[h-1][w-1]-image[h-2][w-2]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }


            //Esquina izq abajo
            if(i==h-1 and j==0){
                centro=false;
                edge a,b,c;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i-1][j];
                c.to = vertex[i-1][j+1];
                a.weight=abs(image[h-1][0]-image[h-1][1]);
                b.weight=abs(image[h-1][0]-image[h-2][0]);
                c.weight=abs(image[h-1][0]-image[h-2][1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
            }

            //Fila arriba
            if(i==0 and j!=0 and j!=w-1){
                centro=false;
                edge a,b,c,d,e;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                e.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i][j-1];
                c.to = vertex[i+1][j];
                d.to = vertex[i+1][j+1];
                e.to = vertex[i+1][j-1];
                a.weight=abs(image[0][j]-image[0][j+1]);
                b.weight=abs(image[0][j]-image[0][j-1]);
                c.weight=abs(image[0][j]-image[1][j]);
                d.weight=abs(image[0][j]-image[1][j+1]);
                e.weight=abs(image[0][j]-image[1][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
                G.push_back(e);
            }

            //Fila abajo
            if(i==h-1 and j!=0 and j!=w-1){
                centro=false;
                edge a,b,c,d,e;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                e.from = vertex[i][j];
                a.to = vertex[i][j];
                b.to = vertex[i][j];
                c.to = vertex[i-1][j];
                d.to = vertex[i-1][j+1];
                e.to = vertex[i-1][j-1];
                a.weight=abs(image[h-1][j]-image[h-1][j+1]);
                b.weight=abs(image[h-1][j]-image[h-1][j-1]);
                c.weight=abs(image[h-1][j]-image[h-2][j]);
                d.weight=abs(image[h-1][j]-image[h-2][j+1]);
                e.weight=abs(image[h-1][j]-image[h-2][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
                G.push_back(e);
            }
            //Columna izquierda
            if(j==0 and i!=0 and i!=h-1){
                centro=false;
                edge a,b,c,d,e;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                e.from = vertex[i][j];
                a.to = vertex[i+1][j];
                b.to = vertex[i-1][j];
                c.to = vertex[i+1][j-1];
                d.to = vertex[i][j-1];
                e.to = vertex[i-1][j-1];
                a.weight=abs(image[i][0]-image[i-1][j]);
                b.weight=abs(image[i][0]-image[i-1][j+1]);
                c.weight=abs(image[i][0]-image[i][j+1]);
                d.weight=abs(image[i][0]-image[i+1][j]);
                e.weight=abs(image[i][0]-image[i+1][j+1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
                G.push_back(e);
            }

            //Columna derecha
            if(j==w-1 and i!=0 and i!=h-1){
                centro=false;
                edge a,b,c,d,e;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                e.from = vertex[i][j];
                a.to = vertex[i+1][j];
                b.to = vertex[i-1][j];
                c.to = vertex[i+1][j-1];
                d.to = vertex[i][j-1];
                e.to = vertex[i-1][j-1];
                a.weight=abs(image[i][w-1]-image[i+1][j]);
                b.weight=abs(image[i][w-1]-image[i-1][j]);
                c.weight=abs(image[i][w-1]-image[i+1][j-1]);
                d.weight=abs(image[i][w-1]-image[i][j-1]);
                e.weight=abs(image[i][w-1]-image[i-1][j-1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
                G.push_back(e);
            }

            //Resto de los casos
            if(centro){
                edge a,b,c,d,e,f,g,z;
                a.from = vertex[i][j];
                b.from = vertex[i][j];
                c.from = vertex[i][j];
                d.from = vertex[i][j];
                e.from = vertex[i][j];
                f.from = vertex[i][j];
                g.from = vertex[i][j];
                z.from = vertex[i][j];
                a.to = vertex[i][j+1];
                b.to = vertex[i][j-1];
                c.to = vertex[i+1][j-1];
                d.to = vertex[i+1][j];
                e.to = vertex[i+1][j+1];
                f.to = vertex[i-1][j-1];
                g.to = vertex[i-1][j];
                z.to = vertex[i-1][j+1];
                a.weight=abs(image[i][j]-image[i][j+1]);
                b.weight=abs(image[i][j]-image[i][j-1]);
                c.weight=abs(image[i][j]-image[i+1][j-1]);
                d.weight=abs(image[i][j]-image[i+1][j]);
                e.weight=abs(image[i][j]-image[i+1][j+1]);
                f.weight=abs(image[i][j]-image[i-1][j-1]);
                g.weight=abs(image[i][j]-image[i-1][j]);
                z.weight=abs(image[i][j]-image[i-1][j+1]);
                G.push_back(a);
                G.push_back(b);
                G.push_back(c);
                G.push_back(d);
                G.push_back(e);
                G.push_back(f);
                G.push_back(g);
                G.push_back(z);
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
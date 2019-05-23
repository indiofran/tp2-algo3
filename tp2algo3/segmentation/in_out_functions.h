//
// Created by Hernan Ghianni on 19/5/19.
//

#ifndef TP3ALGO3_IN_OUT_FUNCTIONS_H
#define TP3ALGO3_IN_OUT_FUNCTIONS_H


#include "../graph/graph.h"


graph image_to_graph (vector<vector<int> > image,vector<vector<int> > vertex,int h,int w);

vector<vector<int> > segments_to_image (vector<int> segments,int h,int w);


struct rgb {
    int cero;
    int uno;
    int dos;
    rgb(){
        cero=0,uno=0,dos=0;
    }
};

rgb change_base_to_256(int number);
#endif //TP3ALGO3_IN_OUT_FUNCTIONS_H

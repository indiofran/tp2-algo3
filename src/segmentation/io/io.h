#ifndef __IO_H__
#define __IO_H__

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "../../graph/graph.h"
#include "../algorithms/algorithms.h"

using namespace std;

/*
    Formato PGM:
        NÚMERO MÁGICO
        ANCHO ALTO
        MAXVAL
        DATOS_DE_PIXELES
*/

vector<vector<int>> read_path(string& path);
vector<vector<int>> read_stdio();
void write_path(vector<vector<int>>& image, vector<int>& segments, int k);
void write_stdio(vector<vector<int>> segmented_image);

graph image_to_graph (vector<vector<int> > &image,vector<vector<int> > &vertex,int h,int w);

vector<vector<int> > segments_to_image (vector<int> &segments,int h,int w);

#endif
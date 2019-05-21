//
// Created by hghianni on 13/05/19.
//

#include "disjoint_set_array.hpp"



int disjoint_set_array::find(int i)  const {
    return p[i];
}

void disjoint_set_array::unite(int i, int j) {
    i = find(i), j = find(j);
    int sizej=0;

    for (int k = 0; k < p.size() ; ++k) {
        if (p[k]==j){
            p[k]=i;
            sizej++;
        }
    }
    size[i]+=sizej;
}

void disjoint_set_array::actualizarInt(int i,int nuevoInt){
   Int[i]=nuevoInt;
}

int disjoint_set_array::internal_diff(int c){
    return Int[c];
}

int disjoint_set_array::_size(int c){
    return size[c];
}

vector<int> disjoint_set_array::segmentation(){
    return p;
}
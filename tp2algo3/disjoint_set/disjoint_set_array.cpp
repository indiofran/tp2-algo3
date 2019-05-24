//
// Created by hghianni on 13/05/19.
//

#include "disjoint_set_array.hpp"



int disjoint_set_array::find(int i) {
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
    _size[i]+=sizej;
}

//Le paso el padre sino no funciona
void disjoint_set_array::update_internal_difference(int i, int nuevoInt){
    _internal_difference[i]=nuevoInt;
}

//Le paso el padre sino no funciona
int disjoint_set_array::internal_difference(int c){
    return _internal_difference[c];
}

//Le paso el padre sino no funciona
int disjoint_set_array::size(int c){
    return _size[c];
}

vector<int> disjoint_set_array::segmentation(){
    return p;
}
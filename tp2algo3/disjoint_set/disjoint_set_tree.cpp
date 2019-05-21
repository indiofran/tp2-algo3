//
// Created by hghianni on 13/05/19.
//

#include "disjoint_set_tree.hpp"

int disjoint_set_tree::find(int i)  const {
    return p[i] == none ? i : find(p[i]);
}

void disjoint_set_tree::unite(int i, int j) {

    //Union by rank

    i = find(i), j = find(j);

    if(i != j) {

        if (r[i] < r[j]){
            p[i] = j;
            size[j]+=size[i];

        }else{
            if (r[i] > r[j]){
                p[j] = i;
                size[i]+=size[j];
            }else{
                p[j] = i;
                r[i]+=1;
                size[i]+=size[j];
            }
        }
    }
}

void disjoint_set_tree::actualizarInt(int i,int nuevoInt){
    Int[i]=nuevoInt;
}

int disjoint_set_array::internal_diff(int c){
    return Int[c];
}

int disjoint_set_array::_size(int c){
    return size[c];
}
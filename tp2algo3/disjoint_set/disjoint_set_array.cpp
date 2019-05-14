//
// Created by hghianni on 13/05/19.
//

#include "disjoint_set_array.hpp"



int disjoint_set_array::find(int i)  const {
    return p[i];
}

void disjoint_set_array::unite(int i, int j) {
    i = find(i), j = find(j);

    for (int k = 0; k < p.size() ; ++k) {
        if (p[k]==j){
            p[k]=i;
        }
    }
}
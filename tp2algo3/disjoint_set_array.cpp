//
// Created by hghianni on 13/05/19.
//

#include "disjoint_set_array.hpp"

//union by rank and path compression

int disjoint_set_array::find(int i)  const {
    return p[i] == none ? i : (p[i] = find(p[i]));
}

void disjoint_set_array::unite(int i, int j) {
    i = find(i), j = find(j);

    if(i != j) {

        if (r[i] < r[j]){
            p[i] = j;

        }else{
            if (r[i] > r[j]){
                p[j] = i;
            }else{
                p[j] = i;
                r[i]+=1;
            }
        }
    }
}
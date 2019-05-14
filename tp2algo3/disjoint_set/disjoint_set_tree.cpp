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
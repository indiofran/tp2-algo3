//
// Created by Hernan Ghianni on 14/5/19.
//

#include "disjoint_set_tree_pc.hpp"


int disjoint_set_tree_pc::find(int i)  const {

    //Path compression

    return p[i] == none ? i : (p[i] = find(p[i]));
}

void disjoint_set_tree_pc::unite(int i, int j) {

    //Union by rank

    //Raices de ambos conjuntos.

    i = find(i), j = find(j);

    if(i != j) {

        //Cuelgo el de menor rank de la raiz del otro.

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
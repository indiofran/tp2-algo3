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

void disjoint_set_tree_pc::actualizarInt(int i,int nuevoInt){
    Int[i]=nuevoInt;
}

int disjoint_set_array::internal_diff(int c){
    return Int[c];
}

int disjoint_set_array::_size(int c){
    return size[c];
}
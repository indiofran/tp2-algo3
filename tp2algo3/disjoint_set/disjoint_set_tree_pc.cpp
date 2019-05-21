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
            _size[j]+=_size[i];

        }else{
            if (r[i] > r[j]){
                p[j] = i;
                _size[i]+=_size[j];
            }else{
                p[j] = i;
                r[i]+=1;
                _size[i]+=_size[j];
            }
        }
    }
}

//Le paso el padre sino no funciona
void disjoint_set_tree_pc::update_internal_difference(int i, int nuevoInt) {
    _internal_difference[i]=nuevoInt;
}

//Le paso el padre sino no funciona
int disjoint_set_tree_pc::internal_difference(int c){
    return _internal_difference[c];
}

//Le paso el padre sino no funciona
int disjoint_set_tree_pc::size(int c){
    return _size[c];
}

vector<int> disjoint_set_tree_pc::segmentation(){
    vector<int> segments;
    for (int i = 0; i < p.size(); ++i) {
        segments.push_back(find(i));
    }
    return segments;
}
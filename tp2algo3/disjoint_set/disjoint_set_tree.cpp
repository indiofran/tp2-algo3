//
// Created by hghianni on 13/05/19.
//

#include "disjoint_set_tree.hpp"

int disjoint_set_tree::find(int i)   {
    return p[i] == none ? i : find(p[i]);
}

void disjoint_set_tree::unite(int i, int j) {

    //Union by rank

    i = find(i), j = find(j);

    if(i != j) {

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
void disjoint_set_tree::update_internal_difference(int i, int nuevoInt) {
    _internal_difference[i]=nuevoInt;
}

//Le paso el padre sino no funciona
int disjoint_set_tree::internal_difference(int c){
    return _internal_difference[c];
}

//Le paso el padre sino no funciona
int disjoint_set_tree::size(int c){
    return _size[c];
}


vector<int> disjoint_set_tree::segmentation(){
    vector<int> segments;
    for (int i = 0; i < p.size(); ++i) {
        segments.push_back(find(i));
    }
    return segments;
}
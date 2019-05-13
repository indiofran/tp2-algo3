//
// Created by hghianni on 13/05/19.
//

#ifndef TP3ALGO3_DISJOINT_SET_TREE_HPP
#define TP3ALGO3_DISJOINT_SET_TREE_HPP


class disjoint_set_tree {

public:

disjoint_set_array(int n) {
    p.assign(n, none);
    r.assign(n, 0);

}
int find(int i);

void unite(int i, int j);
};

#endif //TP3ALGO3_DISJOINT_SET_TREE_HPP

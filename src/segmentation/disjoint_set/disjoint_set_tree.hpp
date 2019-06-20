//
// Created by hghianni on 13/05/19.
//

#ifndef TP3ALGO3_DISJOINT_SET_TREE_HPP
#define TP3ALGO3_DISJOINT_SET_TREE_HPP



#include <vector>

using namespace std;

class disjoint_set_tree{
    const int none = -1;
    //p = parent, r = rank
    mutable vector<int> p, r;
    vector<int> _size;
    vector<int> _internal_difference;

public:
    disjoint_set_tree(int n) {
        p.assign(n, none); r.assign(n, 0);_size.assign(n,1);_internal_difference.assign(n,0);
    };

    int find(int i) ;

    void unite(int i, int j);

    void update_internal_difference(int i,int nuevoInt);

    int internal_difference(int c);

    int size(int c);

    vector<int> segmentation();
};

#endif //TP3ALGO3_DISJOINT_SET_TREE_HPP

//
// Created by hghianni on 13/05/19.
//

#ifndef TP3ALGO3_DISJOINT_SET_ARRAY_HPP
#define TP3ALGO3_DISJOINT_SET_ARRAY_HPP

#include <vector>

using namespace std;

class disjoint_set_array {
    const int none = -1;
    //p = parent, r = rank
    mutable vector<int> p, r;

public:
    disjoint_set_array(int n) {
        p.assign(n, none); r.assign(n, 0);
    };

    int find(int i) const;

    void unite(int i, int j);
};





#endif //TP3ALGO3_DISJOINT_SET_ARRAY_HPP

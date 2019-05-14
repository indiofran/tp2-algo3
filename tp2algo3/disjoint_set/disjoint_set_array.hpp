//
// Created by hghianni on 13/05/19.
//

#ifndef TP3ALGO3_DISJOINT_SET_ARRAY_HPP
#define TP3ALGO3_DISJOINT_SET_ARRAY_HPP

#include <vector>

using namespace std;

class disjoint_set_array {
    //p = parent
    mutable vector<int> p;


public:
    disjoint_set_array(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
        }

    };

    int find(int i) const;

    void unite(int i, int j);
};





#endif //TP3ALGO3_DISJOINT_SET_ARRAY_HPP

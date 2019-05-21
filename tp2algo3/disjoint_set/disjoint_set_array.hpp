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
    vector<int> size;
    vector<int> Int;

public:
    disjoint_set_array(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            size.push_back(1);
            Int.push_back(0);
        }

    };

    int find(int i) const;

    void unite(int i, int j);

    void actualizarInt(int i,int nuevoInt);

    int internal_diff(int c);

    int _size(int c);

    vector<int> segmentation();
};





#endif //TP3ALGO3_DISJOINT_SET_ARRAY_HPP

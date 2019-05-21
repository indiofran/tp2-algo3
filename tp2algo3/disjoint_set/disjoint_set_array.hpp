//
// Created by hghianni on 13/05/19.
//

#ifndef TP3ALGO3_DISJOINT_SET_ARRAY_HPP
#define TP3ALGO3_DISJOINT_SET_ARRAY_HPP

#include <vector>

using namespace std;

class disjoint_set_array {
    //p = parent
    vector<int> p;
    vector<int> _size;
    vector<int> _internal_difference;


public:
    disjoint_set_array(int n) {
        for (int i = 0; i < n; ++i) {
            p.push_back(i);
            _size.push_back(1);
            _internal_difference.push_back(0);
        }

    };

    int find(int i);

    void unite(int i, int j);

    void update_internal_difference(int i,int nuevoInt);

    int internal_difference(int c);

    int size(int c);

    vector<int> segmentation();
};





#endif //TP3ALGO3_DISJOINT_SET_ARRAY_HPP

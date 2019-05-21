//
// Created by Hernan Ghianni on 14/5/19.
//

#ifndef TP3ALGO3_DISJOINT_SET_TREE_PC_H
#define TP3ALGO3_DISJOINT_SET_TREE_PC_H


#include <vector>

using namespace std;

class disjoint_set_tree_pc {
    const int none = -1;

    //p = parent, r = rank.
    mutable vector<int> p, r;
    vector<int> size;
    vector<int> Int;

public:
    disjoint_set_tree_pc(int n) {

        //Cada elemento en un conjunto distinto.
        //Rank empieza en cero.

        p.assign(n, none); r.assign(n, 0);
    };

    int find(int i) const;

    void unite(int i, int j);

    void actualizarInt(int i,int nuevoInt);

    int internal_diff(int c);

    int _size(int c);
};



#endif //TP3ALGO3_DISJOINT_SET_TREE_PC_H

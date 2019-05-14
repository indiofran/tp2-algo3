//
// Created by enzo on 13/05/19.
//

#include "graph.h"

bool edge::operator<(const edge& a)
{
    return this->weight < a.weight;
}

bool edge::operator==(const edge& a)
{
    bool same_nodes = (this->to == a.to && this->from == a.from) || (this->to == a.from && this->from == a.to);
    bool same_weight = this->weight == a.weight;
    return same_nodes && same_weight;
}

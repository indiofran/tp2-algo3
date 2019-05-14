//
// Created by enzo on 13/05/19.
//

#include "digraph.h"

bool directed_edge::operator<(const directed_edge& a)
{
    return this->weight < a.weight;
}

bool directed_edge::operator==(const directed_edge& a)
{
    bool same_nodes_and_direction = this->to == a.to && this->from == a.from;
    bool same_weight = this->weight == a.weight;
    return same_nodes_and_direction && same_weight;
}

//
// Created by enzo on 13/05/19.
//

#include "segmentation.h"

vector<graph> segments_by_min_distance(graph& g)
{
    graph a = kruskal(g);
    unsigned int m = a.size();
    sort(a.begin(), a.end());
    disjoint_set_array segments = do_initial_segmentation(a);
    for (unsigned int i = 1; i < m; i++)
    {
        edge current = a[i];
        node v = current.from;
        node w = current.to;
        float diff = current.weight;

        if (segments.find(v) != segments.find(w))
        {
            float internal_diff_v = internal_diff(segments, v);
            float internal_diff_w = internal_diff(segments, w);
            if (diff < internal_diff_v && diff < internal_diff_w)
            {
                segments.unite(v, w);
            }
        }
    }
}
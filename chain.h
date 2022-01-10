//
// Created by loona on 2022-01-09.
//

#ifndef FIELD_FORCES_CHAIN_H
#define FIELD_FORCES_CHAIN_H
#include "segment.h"

class chain {
public:
    vector<node> nodes;
    vector<segment> segments;
    int highlighted_node_index;
    //float hihglighted_segment_index;

    chain(node start);
    ~chain();

    segment draw_segment(node start, node end);
    void delete_segment(int index);
    void redraw();

    void delete_node(int index);
    void insert_node(vector<float> pos, float mass, int index=1);

    bool mouse_is_colliding_with_node();
    bool mouse_is_colliding_with_segment();
    float select_node(int index);
    //float select_segment();
    void change_magnitude();
    void draw();

};


#endif //FIELD_FORCES_CHAIN_H

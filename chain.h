//
// Created by loona on 2022-01-09.
//

#ifndef FIELD_FORCES_CHAIN_H
#define FIELD_FORCES_CHAIN_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "node.h"
#include "segment.h"
#include "globvars.h"

class chain {
public:
    vector<node> nodes;
    vector<segment> segments;
    float highlighted_node_index;
    float hihglighted_segment_index;

    chain(node start, node end);
    ~chain();

    void draw_segment();
    void delete_sedment();
    void redraw();

    void delete_node();
    void insert_node();

    bool mouse_is_colliding_with_node();
    bool mouse_is_colliding_with_segment();
    float select_node();
    float select_segment();
    void change_magnitude();

};


#endif //FIELD_FORCES_CHAIN_H

//
// Created by loona on 2022-01-09.
//

#ifndef FIELD_FORCES_SEGMENT_H
#define FIELD_FORCES_SEGMENT_H
#include "node.h"
using namespace std;

class segment {
public:
    sf::Vertex vertices[4];
    segment(node start, node end, bool selected=false);
    ~segment();
    void recolour(bool selected=false);
};


#endif //FIELD_FORCES_SEGMENT_H

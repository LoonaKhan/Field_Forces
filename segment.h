//
// Created by loona on 2022-01-09.
//

#ifndef FIELD_FORCES_SEGMENT_H
#define FIELD_FORCES_SEGMENT_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "globvars.h"
using namespace std;

class segment {
public:
    sf::RectangleShape shape;
    segment(vector<float> start, vector<float> end, bool selected);
    ~segment();
    void recolour();
};


#endif //FIELD_FORCES_SEGMENT_H

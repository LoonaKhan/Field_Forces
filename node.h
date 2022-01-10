//
// Created by loona on 2022-01-09.
//

#ifndef FIELD_FORCES_NODE_H
#define FIELD_FORCES_NODE_H
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "globvars.h"
using namespace std;

class node {
public:
    sf::CircleShape shape;
    vector<float> pos;
    vector<float> a;
    vector<float> v;
    float force;
    float mass;
    float left, right, top, bottom;

    node(vector<float> pos, float mas);
    ~node();

    void accelerate();
    void move();
    void recolour(bool selected=false);

private:

};


#endif //FIELD_FORCES_NODE_H

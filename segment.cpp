//
// Created by loona on 2022-01-09.
//

#include "segment.h"

segment::segment(node start, node end, bool selected) {

    this->vertices[0] = sf::Vertex(sf::Vector2f(start.pos[0]-1,start.pos[1]-1), start.colour, sf::Vector2f(0,0));
    this->vertices[1] = sf::Vertex(sf::Vector2f(start.pos[0]+1,start.pos[1]+1), start.colour, sf::Vector2f(0,10));
    this->vertices[2] = sf::Vertex(sf::Vector2f(end.pos[0]-1, end.pos[1]-1), end.colour, sf::Vector2f(10,10));
    this->vertices[3] = sf::Vertex(sf::Vector2f(end.pos[0]-1,end.pos[1]+1), end.colour, sf::Vector2f(10,0));

    if (selected) segment::recolour();
}

void segment::recolour(bool selected) {

}

segment::~segment() = default;
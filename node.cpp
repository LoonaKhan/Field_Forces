//
// Created by loona on 2022-01-09.
//
#include "node.h"
#include <iostream>

node::node(vector<float> pos, float mass) {
    this->pos = pos;
    this->v = {0.0f, 0.0f};
    this->a = {0.0f, 0.0f};
    this->mass = mass;
    this->force = 0.0f;
    this->colour = sf::Color::White;

    this->shape.setPosition(pos[0], pos[1]);
    this->shape.setRadius(std::max(mass, 2.0f));
    this->shape.setOrigin(mass/2.0f, mass/2.0f);
    this->shape.setFillColor(sf::Color::White);
    this->shape.setOutlineColor(sf::Color::Black);

    this->left = this->shape.getOrigin().x - mass;
    this->right = this->shape.getOrigin().x+ mass;
    this->top = this->shape.getPosition().y - mass;
    this->bottom = this->shape.getPosition().y + mass;
}

node::~node() = default;

void node::accelerate() {
    for (int i=0; i<this->v.size(); i++){
        this->v[i] = this->v[i]+this->a[i];
    }
}

void node::move(float dx, float dy) {
    if (dx ==0.0f and dy ==0.0f){
        for (int i = 0; i < pos.size(); i++) {
            this->pos[i] = this->pos[i] + this->v[i];
            //move the shape
        }
        this->shape.move(this->v[0], this->v[1]);
    }

    else{
        this->pos[0] += dx; this->pos[1] +=dy;
        this->shape.move(dx, dy);
    }

    if ((this->left <= 0) or (this->right >= (float)screenres[0])) this->v[0] = -this->v[0];
    if ((this->top <= 0) or (this->bottom >= (float)screenres[1])) this->v[1] = -this->v[1];
}

void node::recolour(bool selected) {
    /*
     * Nodes are coloured white if the magnitude of their force is 0, blue if positive, red if negative
     * All nodes will have a black outline by default but the radius will be enabled only if it is selected.
     */
    if (this->force>0){
        this->shape.setFillColor(sf::Color{3, 161, 252});
        this->colour = sf::Color{3, 161, 252};
    }
    else if (this->force<0){
        this->shape.setFillColor(sf::Color{214, 82, 49});
        this->colour = sf::Color{214, 82, 49};
    }
    else{
        this->shape.setFillColor(sf::Color::White);
        this->colour = sf::Color::White;
    }

    if (selected) this->shape.setOutlineThickness(0.0f);
    else this->shape.setOutlineThickness(5.0f);
}
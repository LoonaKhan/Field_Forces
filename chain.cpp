//
// Created by loona on 2022-01-09.
//

#include "chain.h"
#include "vector"
using namespace std;

chain::chain(node start) {
    this->nodes = {start};
    this->segments = {};
    //this->segments = {draw_segment(start, end)};
    this->highlighted_node_index = this->nodes.size()-1;
}
chain::~chain() =default;

segment chain::draw_segment(node start, node end) {
    segment line(start, end);
    return line;
}
void chain::delete_segment(int index) {}
void chain::redraw() {
    this->segments.clear();
    for (int i=0; i<this->nodes.size()-1; i++){
        this->segments.push_back(draw_segment(nodes[i], nodes[i+1]));
    }
}

void chain::delete_node(int index) {}
void chain::insert_node(vector<float> pos, float mass, int index) {
        node point(pos, mass);
        if (this->segments.size()<=1){
            this->nodes.push_back(point);
            //this->segments = {draw_segment(this->nodes[0], this->nodes[1])};
        }
        else nodes[index] = point;
        this->highlighted_node_index = index;
}


bool chain::mouse_is_colliding_with_node() {
    sf::Vector2i mouse_pos = sf::Mouse::getPosition();
    for (int i=0;i<this->nodes.size(); i++) {
        if ((float)mouse_pos.x<=this->nodes[i].right and (float)mouse_pos.x>=this->nodes[i].left and (float)mouse_pos.y>=this->nodes[i].top and (float)mouse_pos.y<=this->nodes[i].bottom){
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (this->highlighted_node_index != i) this->highlighted_node_index = i;
                nodes[i].pos[0] = (float)mouse_pos.x;
                nodes[i].pos[1] = (float)mouse_pos.y;
            }

            return true;
        }
    }
    //this->highlighted_node_index = -1;
    return false;
}
bool chain::mouse_is_colliding_with_segment() {}
float chain::select_node(int index) {
    this->highlighted_node_index = index;
}
void chain::change_magnitude() {}
#include <iostream>
#include <SFML/Graphics.hpp>
#include "globvars.h"
#include "chain.h"
using namespace std;

int main() {
    sf::RenderWindow window(sf::VideoMode(screenres[0],screenres[1]), "Field Forces", sf::Style::Close | sf::Style::Resize); // creates the window
    sf::Clock clock;
    float lastTime =0;
    //vector<chain> chains;
    node newnode({500.0f, 500.0f}, 5);
    newnode.colour = sf::Color{3, 161, 252};
    //node endnode({600.0f, 800.0f}, 5);
    //endnode.colour = sf::Color{214, 82, 49};
    chain c(newnode);
    c.insert_node({600.0f, 800.0f}, 5);
    c.nodes[1].colour = sf::Color{214, 82, 49};

    while (window.isOpen()){
        sf::Event evnt{};

        while(window.pollEvent(evnt)) {
            if (evnt.type == evnt.Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){
                window.close();
            }
        }

        float currentTime = clock.restart().asSeconds();
        float fps = 1.0f/(currentTime - lastTime);
        lastTime = currentTime;

        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Right)){ // if we right click
            vector<float> mouse_pos = {(float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y};
            for (auto i : chains){
                if (!i.mouse_is_colliding_with_node()){ // and we are not colliding with any nodes
                    if (chains.empty()){
                        node point(mouse_pos, 5);
                        chain c(point);
                        chains.push_back(c);
                    }
                    if (i.mouse_is_colliding_with_segment()){
                        //get segment index and add 1 for the node index
                    }
                    i.insert_node(mouse_pos, 5, i.nodes.size()); // create a new node
                }
            }
        }*/



        window.clear();
        /*for (auto i : chains){
            for (auto j : i.nodes){
                window.draw(j.shape);
            }
            i.redraw();
            for (auto k : i.segments){
                window.draw(k.vertices , 4, sf::Quads);
            }
        }*/
        for (auto i : c.nodes){
            window.draw(i.shape);
        }
        c.redraw();
        for (auto j : c.segments){
            window.draw(j.vertices, 4, sf::Quads);
        }
        window.display(); //move the back buffer to the front buffer

    }
    return 0;
}

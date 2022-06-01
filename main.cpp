#include <iostream>
#include <SFML/Graphics.hpp> // add in SFML to the repo. not just in the include dir
#include "globvars.h"
#include "chain.h"
#include <cstdlib>
#include <ctime>
using namespace std;

vector<float> get_rand(float maxx=0.0f, float minn = 0.0f){
    srand(time(0));
    float x = max(((float)rand()/((float)RAND_MAX/screenres[0]))-5.0f, 0.0f);
    float y = max(((float)rand()/((float)RAND_MAX/screenres[1]))-5.0f, 0.0f);
    if (maxx !=0.0f or minn !=0.0f){
        x = min(max(minn, x), maxx);
        y = min(max(minn, y), maxx);
    }
    return {x,y};
}

int main() {
    sf::RenderWindow window(sf::VideoMode(screenres[0],screenres[1]),
                            "Field Forces",
                            sf::Style::Close | sf::Style::Resize); // creates the window
    sf::Clock clock;
    float lastTime =0;
    //vector<chain> chains;
    node newnode({500.0f, 500.0f}, 5);
    newnode.colour = sf::Color{3, 161, 252};

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
        window.setFramerateLimit(60);
        cout << (int) (1.0/clock.restart().asSeconds()) <<endl;


        vector<float> movement = {0.0f, 0.0f};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) movement[1] -= 1.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) movement[1] += 1.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) movement[0] -= 1.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) movement[0] += 1.0f;

        c.nodes[c.highlighted_node_index].move(movement[0], movement[1]);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            c.insert_node(get_rand(), 1.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)){
            c.cycle_selected();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)){
            for (int i =0; i<c.nodes.size(); i++){
                c.nodes[i].a = get_rand(0.1f, -0.1f);
            }
            //c.nodes[c.highlighted_node_index].a = {5.0f, 5.0f};
        }




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

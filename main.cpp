#include <SFML/Graphics.hpp>
#include <optional>
#include "constants.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SMFL");
    sf::CircleShape shape(50.f);
        shape.setFillColor(sf::Color(100, 250, 50));
    
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();
        window.draw(shape); 
        window.display();
    }
}

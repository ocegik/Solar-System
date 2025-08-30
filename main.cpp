#include <SFML/Graphics.hpp>
#include <optional>
#include "constants.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({1600, 1000}), "SMFL");
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/8k_stars.jpg")) {
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);
    sf::CircleShape sun(Constants::SunRadius * Constants::SCALE_RADIUS);
    sun.setFillColor(Constants::SunColor);
    sun.setOrigin({sun.getRadius(), sun.getRadius()});
    sun.setPosition({600, 400}); // center of screen

    sf::CircleShape earth(Constants::EarthRadius * Constants::SCALE_RADIUS);
    earth.setFillColor(Constants::EarthColor);
    earth.setOrigin({earth.getRadius(), earth.getRadius()});
    earth.setPosition({600 + Constants::EarthOrbit * Constants::SCALE_DISTANCE, 400});

    
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();
        window.draw(backgroundSprite);
        window.draw(sun);
        window.draw(earth);
        window.display();
    }
}

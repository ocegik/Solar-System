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

    // Sun
    sf::CircleShape sun(Constants::SunRadius * Constants::SUN_RADIUS_SCALE);
    sun.setFillColor(Constants::SunColor);
    sun.setOrigin({sun.getRadius(), sun.getRadius()});
    sun.setPosition({600, 400}); // center of screen

    // Mercury
    sf::CircleShape mercury(Constants::MercuryRadius * Constants::SCALE_RADIUS);
    mercury.setFillColor(Constants::MercuryColor);
    mercury.setOrigin({mercury.getRadius(), mercury.getRadius()});
    mercury.setPosition({600 + Constants::MercuryOrbit * Constants::SCALE_DISTANCE, 400});

    // Venus
    sf::CircleShape venus(Constants::VenusRadius * Constants::SCALE_RADIUS);
    venus.setFillColor(Constants::VenusColor);
    venus.setOrigin({venus.getRadius(), venus.getRadius()});
    venus.setPosition({600 + Constants::VenusOrbit * Constants::SCALE_DISTANCE, 400});

    // Earth
    sf::CircleShape earth(Constants::EarthRadius * Constants::SCALE_RADIUS);
    earth.setFillColor(Constants::EarthColor);
    earth.setOrigin({earth.getRadius(), earth.getRadius()});
    earth.setPosition({600 + Constants::EarthOrbit * Constants::SCALE_DISTANCE, 400});

    // Mars
    sf::CircleShape mars(Constants::MarsRadius * Constants::SCALE_RADIUS);
    mars.setFillColor(Constants::MarsColor);
    mars.setOrigin({mars.getRadius(), mars.getRadius()});
    mars.setPosition({600 + Constants::MarsOrbit * Constants::SCALE_DISTANCE, 400});

    // Jupiter
    sf::CircleShape jupiter(Constants::JupiterRadius * Constants::SCALE_RADIUS);
    jupiter.setFillColor(Constants::JupiterColor);
    jupiter.setOrigin({jupiter.getRadius(), jupiter.getRadius()});
    jupiter.setPosition({600 + Constants::JupiterOrbit * Constants::SCALE_DISTANCE, 400});

    // Saturn
    sf::CircleShape saturn(Constants::SaturnRadius * Constants::SCALE_RADIUS);
    saturn.setFillColor(Constants::SaturnColor);
    saturn.setOrigin({saturn.getRadius(), saturn.getRadius()});
    saturn.setPosition({600 + Constants::SaturnOrbit * Constants::SCALE_DISTANCE, 400});

    // Uranus
    sf::CircleShape uranus(Constants::UranusRadius * Constants::SCALE_RADIUS);
    uranus.setFillColor(Constants::UranusColor);
    uranus.setOrigin({uranus.getRadius(), uranus.getRadius()});
    uranus.setPosition({600 + Constants::UranusOrbit * Constants::SCALE_DISTANCE, 400});

    // Neptune
    sf::CircleShape neptune(Constants::NeptuneRadius * Constants::SCALE_RADIUS);
    neptune.setFillColor(Constants::NeptuneColor);
    neptune.setOrigin({neptune.getRadius(), neptune.getRadius()});
    neptune.setPosition({600 + Constants::NeptuneOrbit * Constants::SCALE_DISTANCE, 400});
        
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        
        window.clear();
        window.draw(backgroundSprite);
        window.draw(sun);
        window.draw(mercury);
        window.draw(venus);
        window.draw(earth);
        window.draw(mars);
        window.draw(jupiter);
        window.draw(saturn);
        window.draw(uranus);
        window.draw(neptune);
        window.display();
    }
}

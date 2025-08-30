#include <SFML/Graphics.hpp>
#include <optional>
#include "constants.hpp"
#include "CelestialBody.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({1600, 1000}), "Solar System");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/8k_stars.jpg")) {
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture)
    ;
    sf::Vector2f sunPos = {600, 400};

    // Create all planets using CelestialBody
    CelestialBody sun(Constants::SunRadius, Constants::SunColor, 0, 0, Constants::SUN_RADIUS_SCALE);

    CelestialBody mercury(Constants::MercuryRadius, Constants::MercuryColor, Constants::MercuryOrbit, 4.0f, Constants::SCALE_RADIUS);

    CelestialBody venus(Constants::VenusRadius, Constants::VenusColor, Constants::VenusOrbit, 1.6f, Constants::SCALE_RADIUS);

    CelestialBody earth(Constants::EarthRadius, Constants::EarthColor, Constants::EarthOrbit, 1.0f, Constants::SCALE_RADIUS);

    CelestialBody mars(Constants::MarsRadius, Constants::MarsColor, Constants::MarsOrbit, 0.5f, Constants::SCALE_RADIUS);

    CelestialBody jupiter(Constants::JupiterRadius, Constants::JupiterColor, Constants::JupiterOrbit, 0.08f, Constants::SCALE_RADIUS);

    CelestialBody saturn(Constants::SaturnRadius, Constants::SaturnColor, Constants::SaturnOrbit, 0.03f, Constants::SCALE_RADIUS);

    CelestialBody uranus(Constants::UranusRadius, Constants::UranusColor, Constants::UranusOrbit, 0.01f, Constants::SCALE_RADIUS);

    CelestialBody neptune(Constants::NeptuneRadius, Constants::NeptuneColor, Constants::NeptuneOrbit, 0.006f, Constants::SCALE_RADIUS);

    // Set initial positions
    sun.updatePosition(sunPos);
    mercury.updatePosition(sunPos);
    venus.updatePosition(sunPos);
    earth.updatePosition(sunPos);
    mars.updatePosition(sunPos);
    jupiter.updatePosition(sunPos);
    saturn.updatePosition(sunPos);
    uranus.updatePosition(sunPos);
    neptune.updatePosition(sunPos);

    sf::Clock clock;
        
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Update orbits (sun doesn't orbit, so skip it)
        mercury.updateOrbit(deltaTime);
        venus.updateOrbit(deltaTime);
        earth.updateOrbit(deltaTime);
        mars.updateOrbit(deltaTime);
        jupiter.updateOrbit(deltaTime);
        saturn.updateOrbit(deltaTime);
        uranus.updateOrbit(deltaTime);
        neptune.updateOrbit(deltaTime);

        // Update positions
        mercury.updatePosition(sunPos);
        venus.updatePosition(sunPos);
        earth.updatePosition(sunPos);
        mars.updatePosition(sunPos);
        jupiter.updatePosition(sunPos);
        saturn.updatePosition(sunPos);
        uranus.updatePosition(sunPos);
        neptune.updatePosition(sunPos);
        
        window.clear();
        window.draw(backgroundSprite);

        // Use draw() method for CelestialBody objects
        sun.draw(window);
        mercury.draw(window);
        venus.draw(window);
        earth.draw(window);
        mars.draw(window);
        jupiter.draw(window);
        saturn.draw(window);
        uranus.draw(window);
        neptune.draw(window);
        
        window.display();
    }
}

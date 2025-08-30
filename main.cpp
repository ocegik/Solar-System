#include <SFML/Graphics.hpp>
#include <optional>
#include "constants.hpp"
#include "CelestialBody.hpp"
#include "Camera.hpp"
#include "TextureManager.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({1600, 1000}), "Solar System");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Textures/8k_stars.jpg")) {
        return -1;
    }
    sf::Sprite backgroundSprite(backgroundTexture)
    ;
    Camera camera(window.getSize(), sf::Vector2f(0, 0), 0.1f);
    sf::Vector2f sunPos = {0, 0};

    TextureManager textureManager;
    textureManager.loadAllPlanetTextures();

    // Create all planets using CelestialBody

    CelestialBody sun(Constants::SunRadius, Constants::SunColor, 0, 0, Constants::SUN_RADIUS_SCALE, "sun");

    CelestialBody mercury(Constants::MercuryRadius, Constants::MercuryColor, Constants::MercuryOrbit, 4.0f, Constants::SCALE_RADIUS, "mercury");

    CelestialBody venus(Constants::VenusRadius, Constants::VenusColor, Constants::VenusOrbit, 1.6f, Constants::SCALE_RADIUS, "venus");

    CelestialBody earth(Constants::EarthRadius, Constants::EarthColor, Constants::EarthOrbit, 1.0f, Constants::SCALE_RADIUS, "earth");

    CelestialBody mars(Constants::MarsRadius, Constants::MarsColor, Constants::MarsOrbit, 0.5f, Constants::SCALE_RADIUS, "mars");

    CelestialBody jupiter(Constants::JupiterRadius, Constants::JupiterColor, Constants::JupiterOrbit, 0.08f, Constants::SCALE_RADIUS, "jupiter");

    CelestialBody saturn(Constants::SaturnRadius, Constants::SaturnColor, Constants::SaturnOrbit, 0.03f, Constants::SCALE_RADIUS, "saturn");

    CelestialBody uranus(Constants::UranusRadius, Constants::UranusColor, Constants::UranusOrbit, 0.01f, Constants::SCALE_RADIUS, "uranus");

    CelestialBody neptune(Constants::NeptuneRadius, Constants::NeptuneColor, Constants::NeptuneOrbit, 0.006f, Constants::SCALE_RADIUS, "neptune");

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
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (auto* key = event->getIf<sf::Event::KeyPressed>()) {
                float moveSpeed = 20.0f / camera.getZoom();
                
                if (key->code == sf::Keyboard::Key::Left || key->code == sf::Keyboard::Key::A) {
                    camera.move(sf::Vector2f(-moveSpeed, 0));
                }
                else if (key->code == sf::Keyboard::Key::Right || key->code == sf::Keyboard::Key::D) {
                    camera.move(sf::Vector2f(moveSpeed, 0));
                }
                else if (key->code == sf::Keyboard::Key::Up || key->code == sf::Keyboard::Key::W) {
                    camera.move(sf::Vector2f(0, -moveSpeed));
                }
                else if (key->code == sf::Keyboard::Key::Down || key->code == sf::Keyboard::Key::S) {
                    camera.move(sf::Vector2f(0, moveSpeed));
                }

                // Zoom
                else if (key->code == sf::Keyboard::Key::Q) {
                    camera.setZoom(camera.getZoom() * 1.3f);  // Zoom in
                }
                else if (key->code == sf::Keyboard::Key::E) {
                    camera.setZoom(camera.getZoom() * 0.7f);  // Zoom out
                }

                // Quick presets
                else if (key->code == sf::Keyboard::Key::Num1) {
                    camera.setZoom(0.01f);  // Full solar system view
                }
                else if (key->code == sf::Keyboard::Key::Num2) {
                    camera.setZoom(0.1f);   // Inner planets view
                }
                else if (key->code == sf::Keyboard::Key::Num3) {
                    camera.setZoom(1.0f);   // Close-up view
                }
                
                // Center on sun
                else if (key->code == sf::Keyboard::Key::Space) {
                    camera.setPosition(sf::Vector2f(0, 0));
                }

                else if (key->code == sf::Keyboard::Key::T) {
                    sun.setUseTexture(!sun.isUsingTexture());
                    mercury.setUseTexture(!mercury.isUsingTexture());
                    venus.setUseTexture(!venus.isUsingTexture());
                    earth.setUseTexture(!earth.isUsingTexture());
                    mars.setUseTexture(!mars.isUsingTexture());
                    jupiter.setUseTexture(!jupiter.isUsingTexture());
                    saturn.setUseTexture(!saturn.isUsingTexture());
                    uranus.setUseTexture(!uranus.isUsingTexture());
                    neptune.setUseTexture(!neptune.isUsingTexture());
                }
            }
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
    sun.drawWithCamera(window, camera, textureManager);
    mercury.drawWithCamera(window, camera, textureManager);
    venus.drawWithCamera(window, camera, textureManager);
    earth.drawWithCamera(window, camera, textureManager);
    mars.drawWithCamera(window, camera, textureManager);
    jupiter.drawWithCamera(window, camera, textureManager);
    saturn.drawWithCamera(window, camera, textureManager);
    uranus.drawWithCamera(window, camera, textureManager);
    neptune.drawWithCamera(window, camera, textureManager);
    
    window.display();
    }
}

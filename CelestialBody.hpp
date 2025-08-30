#pragma once
#include <SFML/Graphics.hpp>

class CelestialBody {
private:
    sf::CircleShape shape;
    float orbitDistance;
    float orbitAngle;
    float orbitSpeed;
    
public:
    CelestialBody(float radius, sf::Color color, float orbit, float speed, float radiusScale);
    
    void updatePosition(sf::Vector2f centerPos);
    void updateOrbit(float deltaTime);
    void draw(sf::RenderWindow& window);
    
    // Getters if you need them
    sf::Vector2f getPosition() const;
    float getRadius() const;
};
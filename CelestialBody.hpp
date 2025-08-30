#pragma once
#include <SFML/Graphics.hpp>

class Camera;

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
    void drawWithCamera(sf::RenderWindow& window, const Camera& camera);
    
    // Getters if you need them
    sf::Vector2f getPosition() const;
    float getRadius() const;
};
#pragma once
#include <SFML/Graphics.hpp>

class Camera;
class TextureManager;

class CelestialBody {
private:
    sf::CircleShape shape;
    float orbitDistance;
    float orbitAngle;
    float orbitSpeed;

    sf::Color fallbackColor;
    std::string textureName;
    bool useTexture;
    
public:
    CelestialBody(float radius, sf::Color color, float orbit, float speed, float radiusScale, const std::string& texture = "");
    
    void updatePosition(sf::Vector2f centerPos);
    void updateOrbit(float deltaTime);
    void draw(sf::RenderWindow& window);
    void drawWithCamera(sf::RenderWindow& window, const Camera& camera);
    void drawWithCamera(sf::RenderWindow& window, const Camera& camera, const TextureManager& textureManager);
    
    void setUseTexture(bool use);
    bool isUsingTexture() const;
    
    // Getters if you need them
    sf::Vector2f getPosition() const;
    float getRadius() const;
};
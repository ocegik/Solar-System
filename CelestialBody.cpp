#include "CelestialBody.hpp"
#include "constants.hpp" // your constants file
#include <cmath>
#include "Camera.hpp"
#include "TextureManager.hpp"


CelestialBody::CelestialBody(float radius, sf::Color color, float orbit, float speed, float radiusScale, const std::string& texture) 
    : orbitDistance(orbit * Constants::SCALE_DISTANCE), 
      orbitSpeed(speed), 
      orbitAngle(0),
      fallbackColor(color), 
      textureName(texture), 
      useTexture(!texture.empty()) 
      {
    
    shape.setRadius(radius * radiusScale);
    shape.setFillColor(fallbackColor);
    shape.setOrigin({shape.getRadius(), shape.getRadius()});
}

void CelestialBody::updatePosition(sf::Vector2f centerPos) {
    float x = centerPos.x + orbitDistance * std::cos(orbitAngle);
    float y = centerPos.y + orbitDistance * std::sin(orbitAngle);
    shape.setPosition({x, y});
}

void CelestialBody::updateOrbit(float deltaTime) {
    orbitAngle += orbitSpeed * deltaTime;
    
    // Keep angle in 0-2π range (optional, prevents overflow)
    if (orbitAngle > 2 * M_PI) {
        orbitAngle -= 2 * M_PI;
    }
}

void CelestialBody::draw(sf::RenderWindow& window) {
    shape.setTexture(nullptr);
    shape.setFillColor(fallbackColor);
    window.draw(shape);
}

sf::Vector2f CelestialBody::getPosition() const {
    return shape.getPosition();
}

float CelestialBody::getRadius() const {
    return shape.getRadius();
}
void CelestialBody::drawWithCamera(sf::RenderWindow& window, const Camera& camera) {
    sf::Vector2f screenPos = camera.worldToScreen(shape.getPosition());
    
    // Create a temporary shape for drawing at screen position
    sf::CircleShape tempShape = shape;
    tempShape.setPosition(screenPos);
    
    // Scale radius by zoom level
    float screenRadius = shape.getRadius() * camera.getZoom();
    tempShape.setRadius(screenRadius);
    tempShape.setOrigin(sf::Vector2f(screenRadius, screenRadius));

    tempShape.setTexture(nullptr);
    tempShape.setFillColor(fallbackColor);
    
    window.draw(tempShape);
}

void CelestialBody::drawWithCamera(sf::RenderWindow& window, const Camera& camera, const TextureManager& textureManager) {
    sf::Vector2f screenPos = camera.worldToScreen(shape.getPosition());
    
    // Create a temporary shape for drawing at screen position
    sf::CircleShape tempShape = shape;
    tempShape.setPosition(screenPos);
    
    // Scale radius by zoom level
    float screenRadius = shape.getRadius() * camera.getZoom();
    tempShape.setRadius(screenRadius);
    tempShape.setOrigin(sf::Vector2f(screenRadius, screenRadius));
    
    // Try to use texture if available and enabled
    if (useTexture && !textureName.empty()) {
        const sf::Texture* texture = textureManager.getTexture(textureName);
        if (texture) {
            tempShape.setTexture(texture);
            tempShape.setFillColor(sf::Color::White); // Don't tint the texture
        } else {
            // Fallback to solid color if texture failed to load
            tempShape.setTexture(nullptr);
            tempShape.setFillColor(fallbackColor);
        }
    } else {
        // Use solid color
        tempShape.setTexture(nullptr);
        tempShape.setFillColor(fallbackColor);
    }
    
    window.draw(tempShape);
}

void CelestialBody::setUseTexture(bool use) {
    useTexture = use;
}

bool CelestialBody::isUsingTexture() const {
    return useTexture;
}
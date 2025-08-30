#include "CelestialBody.hpp"
#include "constants.hpp" // your constants file
#include <cmath>
#include "Camera.hpp"


CelestialBody::CelestialBody(float radius, sf::Color color, float orbit, float speed, float radiusScale) 
    : orbitDistance(orbit * Constants::SCALE_DISTANCE), 
      orbitSpeed(speed), 
      orbitAngle(0) {
    
    shape.setRadius(radius * radiusScale);
    shape.setFillColor(color);
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
    
    window.draw(tempShape);
}
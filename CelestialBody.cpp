#include "CelestialBody.hpp"
#include "constants.hpp" // your constants file
#include <cmath>

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
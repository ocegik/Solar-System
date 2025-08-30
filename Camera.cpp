#include "Camera.hpp"
#include <algorithm>

Camera::Camera(sf::Vector2u windowSize, sf::Vector2f startPos, float startZoom) 
    : screenSize(windowSize), position(startPos), zoom(startZoom) {
}

sf::Vector2f Camera::worldToScreen(sf::Vector2f worldPos) const {
    // Translate relative to camera, then scale by zoom, then center on screen
    sf::Vector2f relative = worldPos - position;
    sf::Vector2f scaled = relative * zoom;
    sf::Vector2f screenCenter = sf::Vector2f(screenSize.x / 2.0f, screenSize.y / 2.0f);
    return screenCenter + scaled;
}

sf::Vector2f Camera::screenToWorld(sf::Vector2f screenPos) const {
    // Reverse of worldToScreen
    sf::Vector2f screenCenter = sf::Vector2f(screenSize.x / 2.0f, screenSize.y / 2.0f);
    sf::Vector2f relative = screenPos - screenCenter;
    sf::Vector2f scaled = relative / zoom;
    return position + scaled;
}

void Camera::move(sf::Vector2f offset) {
    position += offset;
}

void Camera::setPosition(sf::Vector2f newPos) {
    position = newPos;
}

void Camera::setZoom(float newZoom) {
    // Clamp zoom to reasonable values
    zoom = std::max(0.001f, std::min(1000.0f, newZoom));
}

void Camera::zoomAt(sf::Vector2f screenPos, float zoomDelta) {
    // Get world position under mouse before zoom
    sf::Vector2f worldPos = screenToWorld(screenPos);
    
    // Apply zoom
    setZoom(zoom * zoomDelta);
    
    // Adjust camera position so the world point stays under the mouse
    sf::Vector2f newScreenPos = worldToScreen(worldPos);
    sf::Vector2f offset = screenPos - newScreenPos;
    position -= offset / zoom;
}
#pragma once
#include <SFML/Graphics.hpp>

class Camera {
private:
    sf::Vector2f position;      // Camera position in world coordinates
    float zoom;                 // Zoom level (1.0 = normal, 2.0 = zoomed in 2x)
    sf::Vector2u screenSize;    // Window dimensions
    
public:
    Camera(sf::Vector2u windowSize, sf::Vector2f startPos = {0, 0}, float startZoom = 1.0f);
    
    // Transform world coordinates to screen coordinates
    sf::Vector2f worldToScreen(sf::Vector2f worldPos) const;
    
    // Transform screen coordinates to world coordinates (useful for mouse)
    sf::Vector2f screenToWorld(sf::Vector2f screenPos) const;
    
    // Camera controls
    void move(sf::Vector2f offset);
    void setPosition(sf::Vector2f newPos);
    void setZoom(float newZoom);
    void zoomAt(sf::Vector2f screenPos, float zoomDelta);
    
    // Getters
    sf::Vector2f getPosition() const { return position; }
    float getZoom() const { return zoom; }
    
    // Update screen size if window is resized
    void setScreenSize(sf::Vector2u newSize) { screenSize = newSize; }
};
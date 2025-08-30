// TextureManager.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <iostream>

class TextureManager {
private:
    std::unordered_map<std::string, sf::Texture> textures;
    
public:
    // Load a texture from file
    bool loadTexture(const std::string& name, const std::string& filepath) {
        sf::Texture texture;
        if (!texture.loadFromFile(filepath)) {
            std::cerr << "Failed to load texture: " << filepath << std::endl;
            return false;
        }
        textures[name] = std::move(texture);
        return true;
    }
    
    // Get texture by name
    const sf::Texture* getTexture(const std::string& name) const {
        auto it = textures.find(name);
        if (it != textures.end()) {
            return &it->second;
        }
        return nullptr;
    }
    
    // Load all planet textures
    void loadAllPlanetTextures() {
        loadTexture("sun", Constants::Textures::SUN_TEXTURE);
        loadTexture("mercury", Constants::Textures::MERCURY_TEXTURE);
        loadTexture("venus", Constants::Textures::VENUS_TEXTURE);
        loadTexture("earth", Constants::Textures::EARTH_TEXTURE);
        loadTexture("mars", Constants::Textures::MARS_TEXTURE);
        loadTexture("jupiter", Constants::Textures::JUPITER_TEXTURE);
        loadTexture("saturn", Constants::Textures::SATURN_TEXTURE);
        loadTexture("uranus", Constants::Textures::URANUS_TEXTURE);
        loadTexture("neptune", Constants::Textures::NEPTUNE_TEXTURE);
    }
    
    // Check if texture exists
    bool hasTexture(const std::string& name) const {
        return textures.find(name) != textures.end();
    }
};
/**************************************************************************
//
// File Name : AssetManager.cpp
// Description : Implementation file for the AssetManager class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#include "Asset_Manager.h"
#include <iostream>
#include <string>
#include <stdexcept>

// Internal function to load a texture for a specific tag
void Asset_Manager::loadTexture(ETextureTag tag)
{
    std::string filepath;

    switch (tag)
    {
    case ETextureTag::WALL:
        filepath = "resources/textures/tiles/Wall.png";
        break;
    case ETextureTag::FLOOR:
        filepath = "resources/textures/tiles/Floor.png";
        break;
    case ETextureTag::PLAYER:
        filepath = "resources/textures/player/Player1.png";
        break;
    case ETextureTag::COLLECTIBLE:
        filepath = "resources/textures/Collectible/Cat.png";
        break;
    default:
        throw std::runtime_error("Unknown texture tag.");
    }

    sf::Texture texture;
    if (!texture.loadFromFile(filepath))
    {
        std::cerr << "Failed to load texture: " << filepath << std::endl;
        throw std::runtime_error("Failed to load texture: " + filepath);
    }

    // Emplace into the map by moving the loaded texture
    m_TexturesDatabase.try_emplace(tag, std::move(texture));
}

// Return reference to requested texture
const sf::Texture& Asset_Manager::getTexture(ETextureTag tag)
{
    auto it = m_TexturesDatabase.find(tag);
    if (it == m_TexturesDatabase.end())
    {
        loadTexture(tag);
        it = m_TexturesDatabase.find(tag);
    }

    return it->second;
}

// Return reference to font (load on first request)
const sf::Font& Asset_Manager::getFont()
{
    if (!m_fontLoaded)
    {
        if (!m_font.loadFromFile("resources/fonts/arial.ttf"))
        {
            std::cerr << "Failed to load font: resources/fonts/arial.ttf" << std::endl;
            throw std::runtime_error("Font loading failed.");
        }
        m_fontLoaded = true;
    }

    return m_font;
}
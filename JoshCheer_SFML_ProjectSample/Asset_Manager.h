/**************************************************************************
//
// File Name : Asset_Manager.h
// Description : Header file for the Asset Manager Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/


#pragma once

// Includes
#include "SFML/Graphics.hpp"
#include <unordered_map>


// Enum class to store all of the texture tags
enum class ETextureTag
{
	WALL,
	FLOOR,
	PLAYER,
	COLLECTIBLE
};


class Asset_Manager
{

public:
	//public Class functions


	Asset_Manager() {};
	~Asset_Manager() = default;

	// Loads and returns a texture by tag	
	[[nodiscard]] const sf::Texture& getTexture(ETextureTag tag);

	// Function to load the font and return the font	
	[[nodiscard]] const sf::Font& getFont();
protected:



private:
	// private variables
	std::unordered_map<ETextureTag, sf::Texture> m_TexturesDatabase;
	sf::Font m_font;
	bool m_fontLoaded = false;

	// private functions
	void loadTexture(ETextureTag tag);

};


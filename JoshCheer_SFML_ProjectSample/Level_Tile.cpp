/**************************************************************************
//
// File Name : Level_Tile.cpp
// Description : Implementation file for  Level_Tile Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "Level_Tile.h"
#include "Utilities.h"
#include "Asset_Manager.h"


// Class Constructor
Level_Tile::Level_Tile() : Level_Object(EObjectType::TILE)
{
	// Set up shape and position
	m_pShape = std::make_unique <sf::RectangleShape>(sf::Vector2f(Utils::m_fWorldUnit, Utils::m_fWorldUnit));
	m_pShape->setOrigin(m_pShape->getGlobalBounds().width * 0.5f, m_pShape->getGlobalBounds().height * 0.5f);
	setPosition(sf::Vector2f(0.0f, 0.0f));
}


// Class Destructor
Level_Tile::~Level_Tile()
{
	///////////////////////////////
	// Release memory allocated. //
	///////////////////////////////	
}


// Function that sets the tile type with the correct asset and collision logic
void Level_Tile::setTileType(ETileType _eTileType, Asset_Manager* _pAssetManager)
{
	m_eTileType = _eTileType;
	bool bNeedsBoundingVolume = false;

	switch (m_eTileType)
	{
		case(ETileType::WALL):
		{
			m_pShape->setTexture(&_pAssetManager->getTexture(ETextureTag::WALL));
			bNeedsBoundingVolume = true;
			break;
		}
		case(ETileType::FLOOR):
		{
			m_pShape->setTexture(&_pAssetManager->getTexture(ETextureTag::FLOOR));
			break;
		}

	}
	if (bNeedsBoundingVolume)
	{
		makeBoundingVolume();
	}
}

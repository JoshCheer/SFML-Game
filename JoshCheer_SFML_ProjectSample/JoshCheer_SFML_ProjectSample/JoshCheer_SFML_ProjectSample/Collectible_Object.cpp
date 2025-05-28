/**************************************************************************
//
// File Name : Collectible_Object.cpp
// Description : Implementation file for the Collectible Object Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "Collectible_Object.h"
#include "Utilities.h"
#include "Scene_Manager.h"
#include "Asset_Manager.h"
#include "Collisions.h"
#include "Level.h"
#include "Player.h"


// Constructor to set up the shape and texture of the collectible
Collectible_Object::Collectible_Object(Scene_Manager& _pSceneManager) : Level_Object(EObjectType::COLLECTIBLE), m_pSceneManager(_pSceneManager)
{
	// Set up shape and position
	m_pShape = std::make_unique <sf::RectangleShape>(sf::Vector2f(Utils::m_fWorldUnit / 2.0f, Utils::m_fWorldUnit / 2.0f));
	m_pShape->setOrigin(m_pShape->getGlobalBounds().width * 0.5f, m_pShape->getGlobalBounds().height * 0.5f);
	setPosition(sf::Vector2f(1800.0f, 1000.0f));

	m_pShape->setTexture(&m_pSceneManager.getAssetManager().getTexture(ETextureTag::COLLECTIBLE));

	// Bounding volume
	makeBoundingVolume();
}







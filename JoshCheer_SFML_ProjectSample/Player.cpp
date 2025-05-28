/**************************************************************************
//
// File Name : Player.cpp
// Description : Implementation file for Player Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "Player.h"
#include "Collisions.h"
#include "Level.h"
#include "Scene_Manager.h"
#include "Asset_Manager.h"

// Player constructor
Player::Player(Scene_Manager& _pSceneManager) : Level_Object(EObjectType::PLAYER) , m_pSceneManager(_pSceneManager)
{
			
	// Set up shape and position
	m_pShape = std::make_unique <sf::RectangleShape>(sf::Vector2f(Utils::m_fWorldUnit, Utils::m_fWorldUnit));
	m_pShape->setOrigin(m_pShape->getGlobalBounds().width * 0.5f, m_pShape->getGlobalBounds().height * 0.5f);
	setPosition(sf::Vector2f(100.0f, 100.0f));
	m_pShape->setTexture(&_pSceneManager.getAssetManager().getTexture(ETextureTag::PLAYER));
	m_pShape->setRotation(-180.0f);
	// Bounding volume
	makeBoundingVolume();	
}



void Player::update(Level* _pLevel, float _fDeltaTime)
{
	// Move player based on inputs
	processInputs(_fDeltaTime);

	// Resolve any collisions with other objects.
	resolveCollisions(_pLevel);
}


// Function to process the player movement inputs
void Player::processInputs(float _fDeltaTime)
{
	// Left movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_pShape->setRotation(m_pShape->getRotation() - _fDeltaTime * (Utils::m_fWorldUnit * 4.0f) * (1.0f));
	}

	// Right movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_pShape->setRotation(m_pShape->getRotation() + _fDeltaTime * (Utils::m_fWorldUnit * 4.0f) * (1.0f));
	}

	// Determine forward vector
	// Vector that we compare against is (0, -1) - upward pointing vector in SFML. This is the starting position of the object.
	sf::Vector2f forwardVector;
	float fRadians = m_pShape->getRotation() * (Utils::m_fDegreesToRadians); // Converting angle to radians.
	forwardVector.x = std::sinf(fRadians);
	forwardVector.y = -std::cosf(fRadians);

	// Reset move direction
	m_MoveDirection = sf::Vector2f(0.0f, 0.0f);

	// Upwards movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_MoveDirection += (forwardVector * _fDeltaTime * (Utils::m_fWorldUnit * 4.0f) * (1.0f));
	}

	// Downwards movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_MoveDirection -= (forwardVector * _fDeltaTime * (Utils::m_fWorldUnit * 4.0f) * (1.0f));
	}
}

// Function to handle the players collisions
void Player::resolveCollisions(Level* _pLevel)
{

	// We move the bounding volume along one axis at a time, resolving conflicts as we find them. First the Y-axis.
	m_pAABB->top += m_MoveDirection.y;

	// Look for Y collisions first - dynamic objects
	for (auto& rIter : _pLevel->getDynamicObjects())
	{
		if (this == rIter.get())
		{
			// Do not check collisions with self.
			continue;
		}
		if (rIter->getBoundingVolume() == nullptr)
		{
			// Object does not have a bounding volume to collide with.
			continue;
		}

		if (m_pAABB->intersects(*rIter->getBoundingVolume()))
		{
			// Found a collison.
			if (rIter->getObjectType() == EObjectType::TILE)
			{
				// Collided with Tile. Push away from it.
				Collisions::resolveYCollisions(m_pAABB.get(), rIter->getBoundingVolume());
			}
			
		}
	}
	// Look for Y collisions first - static objects
	for (auto& rIter : _pLevel->getStaticObjects())
	{
		if (this == rIter.get())
		{
			// Do not check collisions with self.
			continue;
		}
		if (rIter->getBoundingVolume() == nullptr)
		{
			// Object does not have a bounding volume to collide with.
			continue;
		}

		if (m_pAABB->intersects(*rIter->getBoundingVolume()))
		{
			// Found a collison.
			if (rIter->getObjectType() == EObjectType::TILE)
			{
				// Collided with Tile. Push away from it.
				Collisions::resolveYCollisions(m_pAABB.get(), rIter->getBoundingVolume());
			}
			if (rIter->getObjectType() == EObjectType::COLLECTIBLE)
			{				
				m_pSceneManager.getAudioManager().PlaySound(ESoundTag::GAME_COMPLETE);
				_pLevel->setLevelComplete(true);
			}
		}
	}

	// As noted, we move the bounding volume along one axis at a time, resolving conflicts as we find them. Now we're moving along the X-axis.
	m_pAABB->left += m_MoveDirection.x;

	// Then look for X collisions - dynamic objects
	for (auto& rIter : _pLevel->getDynamicObjects())
	{
		if (this == rIter.get())
		{
			// Do not check collisions with self.
			continue;
		}
		if (rIter->getBoundingVolume() == nullptr)
		{
			// Object does not have a bounding volume to collide with.
			continue;
		}

		if (m_pAABB->intersects(*rIter->getBoundingVolume()))
		{
			// Found a collison.
			if (rIter->getObjectType() == EObjectType::TILE)
			{
				// Collided with Tile. Push away from it.
				Collisions::resolveXCollisions(m_pAABB.get(), rIter->getBoundingVolume());
			}			
		}
	}
	// Then look for X collisions - static objects
	for (auto& rIter : _pLevel->getStaticObjects())
	{
		if (this == rIter.get())
		{
			// Do not check collisions with self.
			continue;
		}
		if (rIter->getBoundingVolume() == nullptr)
		{
			// Object does not have a bounding volume to collide with.
			continue;
		}

		if (m_pAABB->intersects(*rIter->getBoundingVolume()))
		{
			// Found a collison.
			if (rIter->getObjectType() == EObjectType::TILE)
			{
				// Collided with Tile. Push away from it.
				Collisions::resolveXCollisions(m_pAABB.get(), rIter->getBoundingVolume());
			}
		}
	}
	
	// Bounding volume has now been adjusted for collisions. Need to align the position of shape.
	setPosition(sf::Vector2f(m_pAABB->left + 0.5f * m_pAABB->width, m_pAABB->top + 0.5f * m_pAABB->height));
}

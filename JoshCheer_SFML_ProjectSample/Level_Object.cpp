/**************************************************************************
//
// File Name : Level_Object.cpp
// Description : Implementation file for the level Object Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/


// Includes
#include "Level_Object.h"


// Constructor to set the object type to be used for collision later
Level_Object::Level_Object(EObjectType _eObjectType)
{
	m_eObjectType = _eObjectType;
}


// Class Destructor
Level_Object::~Level_Object()
{
	///////////////////////////////
	// Release memory allocated. //
	///////////////////////////////

}

// Render function to be used by all classes that inherit off this class
void Level_Object::render(sf::RenderWindow* _pWindow)
{
	if (m_pShape.get() != nullptr)
	{
		_pWindow->draw(*m_pShape);
	}
}

// Function to make a bounding volume for an level object to allow for collision logic
void Level_Object::makeBoundingVolume()
{
	// Need a shape to base bounding volume on.
	if (m_pShape.get() != nullptr)
	{
		
		// Make bounding volume.
		m_pAABB = std::make_unique<sf::FloatRect>();

		// Assign values:
		m_pAABB->top = m_pShape->getGlobalBounds().top;
		m_pAABB->left = m_pShape->getGlobalBounds().left;
		m_pAABB->height = m_pShape->getGlobalBounds().height;
		m_pAABB->width = m_pShape->getGlobalBounds().width;
	}
}


// Function to set thje potion of an level object if it has a shape
void Level_Object::setPosition(sf::Vector2f _Position)
{
	if (m_pShape.get() != nullptr)
	{
		m_pShape->setPosition(_Position);
	}
	if (m_pAABB.get() != nullptr)
	{
		m_pAABB->left = _Position.x - 0.5f * m_pAABB->width;
		m_pAABB->top = _Position.y - 0.5f * m_pAABB->height;
	}
}

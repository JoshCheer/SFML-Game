/**************************************************************************
//
// File Name : Level_Object.h
// Description : Header file for the level Object Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

// Includes
#include "SFML/Graphics.hpp"


// enum to store the different object types
enum class EObjectType
{
	PLAYER,
	TILE,
	COLLECTIBLE
};

class Level_Object
{

public:
	// public class functions

	Level_Object(EObjectType _eObjectType);
	virtual ~Level_Object();


	// Update object, such as changing its position.
	virtual void update(class Level* _pParentLevel, float _fDeltaTime) = 0;

	// Renders object - virtual in case a different definition is required for a sub-object.
	virtual void render(sf::RenderWindow* _pWindow);

	// Methods for accessing and making bounding volume.
	sf::FloatRect* getBoundingVolume() const { return m_pAABB.get(); };
	void makeBoundingVolume();


	sf::Vector2f getPosition() const { return m_pShape->getPosition(); };
	void setPosition(sf::Vector2f _Position);

	EObjectType getObjectType() const { return m_eObjectType; };
	bool destroyRequested() const { return m_bShouldDestroy; };

protected:
	// Protected class variables

	EObjectType m_eObjectType;
	std::unique_ptr<sf::Shape> m_pShape;
	bool m_bShouldDestroy = false;
	std::unique_ptr <sf::FloatRect> m_pAABB ;
private:

	
};



/**************************************************************************
//
// File Name : Collectible_Object.h
// Description : Header file for the Collectible Object Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

// Includes
#include "Level_Object.h"


class Scene_Manager;

// Collectible Object inherits all core functionality from the Level Object base class
class Collectible_Object : public Level_Object
{
public:
	// Public class functions
	Collectible_Object(Scene_Manager& _pSceneManager);
	~Collectible_Object() = default;

	// Update function not needed
	virtual void update(Level* _pParentLevel, float _fDeltaTime) {};

protected:

private:
	// private variables
	Scene_Manager& m_pSceneManager;
	
};


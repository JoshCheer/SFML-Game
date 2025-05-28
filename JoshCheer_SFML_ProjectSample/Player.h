/**************************************************************************
//
// File Name : Player.h
// Description : Header file for Player Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/


#pragma once

// Includes
#include "Level_Object.h"
#include "Utilities.h"

// Forward Declarations
class Scene_Manager;


class Player : public Level_Object
{

public:
	// Public Functions
	explicit Player(Scene_Manager& _pSceneManager);
	~Player() = default;	

	virtual void update(class Level* _pLevel, float _fDeltaTime);	

protected:

private:
	// Private variables 	
	sf::Vector2f m_MoveDirection;
	Scene_Manager& m_pSceneManager;


	// Private functions
	void resolveCollisions(Level* _pLevel);
	void processInputs(float _fDeltaTime);
};


/**************************************************************************
//
// File Name : Level.h
// Description : Header file for the level Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/


#pragma once


// Includes
#include "SFML/Graphics.hpp"
#include<list>

// Forward Declaration
class Level_Object;
class Collectible_Object;
class Player;
class Scene_Manager;


class Level
{
public:
	// Public class functions
	explicit Level(Scene_Manager& _sceneManager, int _levelNumber);
	~Level() = default;

	// Calls the update and render on all level objects
	void update();
	void render();

	// Sets up the level
	void loadLevel();

	void restartClock() { m_SceneClock.restart(); };
	bool isLevelComplete() const { return m_bLevelComplete; };
	void setLevelComplete(bool _bComplete) { m_bLevelComplete = _bComplete; };


	// Sets and gets for the set up the board 
	int getBoardWidth() const { return m_iBoardWidth; };
	int getBoardHeight() const { return m_iBoardHeight; };
	void setBoardWidth(int _iSize) { m_iBoardWidth = _iSize; };
	void setBoardHeight(int _iSize) { m_iBoardHeight = _iSize; };


	// Functions for getting and adding level objects
	const std::list<std::shared_ptr<Level_Object>>& getStaticObjects() const { return m_StaticObjects; }
	const std::list<std::shared_ptr<Level_Object>>& getDynamicObjects() const { return m_DynamicObjects; }
	void addStaticObject(std::shared_ptr<Level_Object> _pObject) { m_StaticObjects.push_front(_pObject); }
	void addDynamicObject(std::shared_ptr<Level_Object> _pObject) { m_DynamicObjects.push_front(_pObject); }


	
protected:


private:
	// Private class variables
	int m_iBoardWidth = 0;
	int m_iBoardHeight = 0;

	// List to store both static and dynamic level objects
	std::list<std::shared_ptr<Level_Object>> m_StaticObjects;
	std::list<std::shared_ptr<Level_Object>> m_DynamicObjects;

	int m_iLevelNumber = 0;
	bool m_bLevelComplete = false;
	sf::Clock m_SceneClock;

	// Class variables to be set at runtime
	Scene_Manager& m_pSceneManager;
	std::shared_ptr<Player> m_pPlayer;
	std::shared_ptr<Collectible_Object> m_pCollectible;
};


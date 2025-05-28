/**************************************************************************
//
// File Name : Level.cpp
// Description : Implementation file for the level Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "Level.h"
#include "Scene_Manager.h"
#include "Level_Object.h"
#include "Level_Loader.h"
#include "Asset_Manager.h"
#include "Player.h"
#include "Collectible_Object.h"


// Class Constructor taking in a reference to the scene manager and the level number to be used to decide which map will be loaded
Level::Level(Scene_Manager& _sceneManager, int _levelNumber) : m_pSceneManager(_sceneManager)
{
	// Sets class member variables to function parameters	
	m_iLevelNumber = _levelNumber;

	// Creates player and collectible to be used as a finish line
	m_pPlayer = std::make_shared<Player>(_sceneManager);
	m_pCollectible = std::make_shared<Collectible_Object>(_sceneManager);
	addStaticObject(m_pCollectible);
	
	// Calls function to start the level loading process
	loadLevel();


	// Start clock. Needed for calculating delta time.
	m_SceneClock.restart();
	
}




// Class update function to call update function for all level objects
void Level::update()
{

	// Calculate delta time.
	float fDeltaTime = m_SceneClock.getElapsedTime().asSeconds();
	m_SceneClock.restart();


	// Updates static Objects
	for (auto& rIter : m_StaticObjects)
	{
		rIter->update(this, fDeltaTime);
	}

	// Updates dynamic Objects
	for (auto& rIter : m_DynamicObjects)
	{
		rIter->update(this, fDeltaTime);
	}

	//Updates player last
	if (m_pPlayer)
	{
		m_pPlayer->update(this, fDeltaTime);
	}


}


// Class render function to call render function for all level objects
void Level::render()
{
	// Render static objects
	for (auto& rIter : m_StaticObjects)
	{
		rIter->render(&m_pSceneManager.getGameWindow());
		
	}

	// Render dynamic objects
	for (auto& rIter : m_DynamicObjects)
	{
		rIter->render(&m_pSceneManager.getGameWindow());
	}

	// Render player last
	if (m_pPlayer)
	{
		m_pPlayer->render(&m_pSceneManager.getGameWindow());
	}
	
}

// Function to load the level
void Level::loadLevel()
{
	if (m_iLevelNumber == 1)
	{
		// Loads the level based on the text file
		std::string sLevelTxtData = Level_Loader::loadLevelData("LevelOne.txt", this);
		Level_Loader::processLevelData(sLevelTxtData, this, &m_pSceneManager.getAssetManager());
	}
}

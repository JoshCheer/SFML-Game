/**************************************************************************
//
// File Name : Scene_manager.cpp
// Description : Implementation file for Scene_manager Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "Scene_Manager.h"


// Class constructor
Scene_Manager::Scene_Manager(sf::RenderWindow& _window)
	: m_window(_window),
	m_assetManager(std::make_unique<Asset_Manager>()),
	m_mouseInput(std::make_unique<Mouse_Input>()),
	m_mainMenu(std::make_unique<MainMenu>(*this)),
	m_audioManager(std::make_unique<Audio_Manager>()){}


// Update function to update everything inside of current scene
void Scene_Manager::update()
{
	m_mouseInput->checkLeftMouseInput();

	switch (m_sceneState)
	{
	case EGameSceneState::MAIN_MENU:
	{
		m_mainMenu->update();

		if (m_mainMenu->playGamePressed())
		{
			setGameScene(EGameSceneState::PLAYING_LEVEL);
			createLevel();
			m_mainMenu.reset();
		}
		break;
	}

	case EGameSceneState::PLAYING_LEVEL:
	{
		if (!m_level)
			throw std::runtime_error("Level is null during update.");

		if (m_level->isLevelComplete())
		{
			setGameScene(EGameSceneState::MAIN_MENU);
			m_mainMenu = std::make_unique<MainMenu>(*this);
			m_level.reset();
		}
		else
		{
			m_level->update();
		}
		break;
	}

	default:
		break;
	}
}

// Function to render everything in current scenes
void Scene_Manager::render()
{
	switch (m_sceneState)
	{
	case EGameSceneState::MAIN_MENU:
	{
		if (m_mainMenu)
			m_mainMenu->render();
		break;
	}

	case EGameSceneState::PLAYING_LEVEL:
	{
		if (!m_level)
			throw std::runtime_error("Level is null during render.");
		m_level->render();
		break;
	}

	default:
		break;
	}
}


// Function to create gameplay level
void Scene_Manager::createLevel()
{
	m_level = std::make_unique<Level>(*this, 1);
}

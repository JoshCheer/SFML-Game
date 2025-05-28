/**************************************************************************
//
// File Name : Scene_manager.h
// Description : Header file for Scene_manager Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

// Includes
#include <list>
#include <memory>
#include "SFML/Graphics.hpp"
#include "Level.h"
#include "MainMenu.h"
#include "Asset_Manager.h"
#include "Mouse_Input.h"
#include "Audio_Manager.h"

// enum for different game states
enum class EGameSceneState
{
    MAIN_MENU,
    PLAYING_LEVEL,
};

class Scene_Manager
{
public:
    // public functions
    explicit Scene_Manager(sf::RenderWindow& window);
    ~Scene_Manager() = default;

    void update();
    void render();

    void setGameScene(EGameSceneState state) { m_sceneState = state; }

    void createLevel();

    [[nodiscard]] sf::RenderWindow& getGameWindow() const { return m_window; }
    [[nodiscard]] Mouse_Input& getMouseInput() const { return *m_mouseInput; }
    [[nodiscard]] Asset_Manager& getAssetManager() const { return *m_assetManager; }
    [[nodiscard]] Audio_Manager& getAudioManager() const { return *m_audioManager; }
private:
    // private variables
    // Scene state
    EGameSceneState m_sceneState = EGameSceneState::MAIN_MENU;

    
    sf::RenderWindow& m_window;

    // Owned resources
    std::unique_ptr<Asset_Manager> m_assetManager;
    std::unique_ptr<Mouse_Input> m_mouseInput;
    std::unique_ptr<MainMenu> m_mainMenu;
    std::unique_ptr<Level> m_level;
    std::unique_ptr<Audio_Manager> m_audioManager;

};


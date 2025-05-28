/**************************************************************************
//
// File Name : MainMenu .h
// Description : Header file for Main Menu Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once


// Includes
#include "SFML/Graphics.hpp"
#include <vector>
#include <memory>
#include <array>


// Forward Declaration
class Scene_Manager;

class MainMenu
{
public:
	// public class functions
	explicit MainMenu(Scene_Manager& sceneManager);
	~MainMenu() = default;

	// Updates and renders the menu UI
	void update();
	void render();
	void processMouseInputs();



	// Functions to check for the play button being pressed
	[[nodiscard]] bool playGamePressed() const noexcept { return m_bPlayButtonPressed; }

protected:
private:
	// private class variables
	Scene_Manager& m_pSceneManager;
	static constexpr size_t BUTTON_COUNT = 2;
	bool m_bPlayButtonPressed = false;
	// UI Elements
	std::vector<std::unique_ptr<sf::RectangleShape>> allShapes_;
	std::array<sf::Text, BUTTON_COUNT> buttonTexts_;





	// private functions
	void initializeButtons();
	void initializeText();

};


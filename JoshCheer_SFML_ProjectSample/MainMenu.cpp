/**************************************************************************
//
// File Name : MainMenu.cpp
// Description : Implementation file for Main Menu Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "MainMenu.h"
#include "Scene_Manager.h"
#include "Mouse_Input.h"
#include "Utilities.h"
#include "Asset_Manager.h"

#include <iostream>

namespace {
	// Anonymous namespace for internal constants
	const sf::Vector2f BUTTON_SIZE{ 200.0f, 50.0f };
	constexpr float BUTTON_VERTICAL_OFFSET = 200.0f;
	constexpr unsigned int FONT_SIZE = 16u;
	const sf::Color TEXT_COLOR = sf::Color::Black;
}

MainMenu::MainMenu(Scene_Manager& sceneManager)
	: m_pSceneManager{ sceneManager } {


	initializeButtons();
	initializeText();
}

void MainMenu::initializeButtons() {
	const auto centerX = static_cast<float>(Utils::m_iWindowWidth) / 2.0f;
	const auto centerY = static_cast<float>(Utils::m_iWindowHeight) / 2.0f;

	// Create play button
	auto playButton = std::make_unique<sf::RectangleShape>(BUTTON_SIZE);
	playButton->setOrigin(BUTTON_SIZE.x * 0.5f, BUTTON_SIZE.y * 0.5f);
	playButton->setPosition(centerX, centerY - BUTTON_VERTICAL_OFFSET);
	Utils::formatButton(playButton.get());
	allShapes_.push_back(std::move(playButton));

	auto quitButton = std::make_unique<sf::RectangleShape>(BUTTON_SIZE);
	quitButton->setOrigin(BUTTON_SIZE.x * 0.5f, BUTTON_SIZE.y * 0.5f);
	quitButton->setPosition(centerX, centerY + BUTTON_VERTICAL_OFFSET);
	Utils::formatButton(quitButton.get());
	allShapes_.push_back(std::move(quitButton));
}


void MainMenu::initializeText() {
	const auto& font = m_pSceneManager.getAssetManager().getFont();

	// Setup play button text
	Utils::formatText(buttonTexts_[0], font, "PLAY", FONT_SIZE, TEXT_COLOR);
	buttonTexts_[0].setPosition(allShapes_[0].get()->getPosition());

	// Setup quit button text
	Utils::formatText(buttonTexts_[1], font, "QUIT", FONT_SIZE, TEXT_COLOR);
	buttonTexts_[1].setPosition(allShapes_[1].get()->getPosition());
}


// Update to check for mouse input
void MainMenu::update()
{
	// Check for left mouse button press
	const auto mouseState = m_pSceneManager.getMouseInput().getLeftMouseState();
	if (mouseState == ELeftMouseButtonState::PRESSED) {
		processMouseInputs();
	}
}

// Renders the button and text
void MainMenu::render()
{
	auto& gameWindow = m_pSceneManager.getGameWindow();

	// Render all shapes
	for (const auto& shape : allShapes_) {
		gameWindow.draw(*shape);
	}

	// Render all button text
	for (const auto& text : buttonTexts_) {
		gameWindow.draw(text);
	}
}


// Function to process the mouse input
void MainMenu::processMouseInputs() {
	auto& gameWindow = m_pSceneManager.getGameWindow();


	const sf::Vector2f mousePosition = gameWindow.mapPixelToCoords(
		sf::Mouse::getPosition(gameWindow)
	);

	if (allShapes_[0].get()->getGlobalBounds().contains(mousePosition)) {
		m_pSceneManager.getAudioManager().PlaySound(ESoundTag::BUTTON_CLICK);
		m_bPlayButtonPressed = true;
	}
	else if (allShapes_[1].get()->getGlobalBounds().contains(mousePosition)) {
		m_pSceneManager.getAudioManager().PlaySound(ESoundTag::BUTTON_CLICK);
		sf::Clock clock;
		while (clock.getElapsedTime().asSeconds() < 0.25) {} // Simple delay		
		gameWindow.close();
	}
}
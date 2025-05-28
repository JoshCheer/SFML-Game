/**************************************************************************
//
// File Name : Utilities.h
// Description : Header file for the Utilities NameSpace.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

#include "SFML/Graphics.hpp"

namespace Utils
{
	// Defines the size of the Open GL window.
	inline constexpr  int m_iWindowWidth = 1920;
	inline constexpr int m_iWindowHeight = 1080;


	// Defines the parameters for the visual styling of the buttons
	inline const sf::Color m_ButtonFillColor{ 255, 225, 175, 255 };
	inline const sf::Color m_ButtonOutlineColor = sf::Color(185, 125, 90, 255);
	inline constexpr float m_fButtonOutlineThickness = 2.0f;

	// how many pixels one world unit is
	inline constexpr float m_fWorldUnit = 64.0f;


	// Radian Degree conversion calculations
	inline constexpr float m_fDegreesToRadians = 3.14159f / 180.0f;
	inline constexpr float m_fRadiansToDegrees = 180.0f / 3.14159f;


	// Function to handle the cosmetic changes to the buttons
	static void formatButton(sf::Shape* _pButton)
	{
		_pButton->setFillColor(m_ButtonFillColor);
		_pButton->setOutlineColor(m_ButtonOutlineColor);
		_pButton->setOutlineThickness(m_fButtonOutlineThickness);
	}


	// Function to handle the formatting of text to reduce repeated code in UI
	inline void formatText(sf::Text& _rText, const sf::Font& _pFont, std::string _sTextString, int _iCharacterSize, sf::Color _Color)
	{
		_rText.setFont(_pFont);
		_rText.setString(_sTextString);
		_rText.setCharacterSize(_iCharacterSize);
		_rText.setFillColor(_Color);
		_rText.setStyle(sf::Text::Style::Bold);
		_rText.setLetterSpacing(0.2f);
		_rText.setOrigin(_rText.getGlobalBounds().left + _rText.getGlobalBounds().width * 0.5f, _rText.getGlobalBounds().top + _rText.getGlobalBounds().height * 0.5f);
	}

}

/**************************************************************************
//
// File Name : MouseInput.h
// Description : Header file for MouseInput Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

// Includes
#include "SFML/Graphics.hpp"

// Enum for mouse button state
enum class ELeftMouseButtonState
{
	IDLE,
	PRESSED,
	HOLDING,
	RELEASED
};

class Mouse_Input
{
public:
	// public functions
	// Constuctor and destructor not needed
	Mouse_Input() {};
	~Mouse_Input() {};

	void checkLeftMouseInput();


	ELeftMouseButtonState getLeftMouseState() const { return m_eLeftMouseButtonState; };
protected:

private:
	// private variables
	ELeftMouseButtonState m_eLeftMouseButtonState = ELeftMouseButtonState::IDLE;
};


/**************************************************************************
//
// File Name : MouseInput.cpp
// Description : Implementation file for MouseInput Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include "Mouse_Input.h"
#include <iostream>


void Mouse_Input::checkLeftMouseInput()
{
	// Update state of left button
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (m_eLeftMouseButtonState == ELeftMouseButtonState::RELEASED || m_eLeftMouseButtonState == ELeftMouseButtonState::IDLE)
		{
			// Button has been pressed, change state to PRESSED.
			m_eLeftMouseButtonState = ELeftMouseButtonState::PRESSED;
			;
		}
		else if (m_eLeftMouseButtonState == ELeftMouseButtonState::PRESSED)
		{
			// Button is still pressed, change state to HOLDING.
			m_eLeftMouseButtonState = ELeftMouseButtonState::HOLDING;
		}
		else if (m_eLeftMouseButtonState == ELeftMouseButtonState::HOLDING)
		{
			// Button is being held down, keep state the same.
		}
	}
	else
	{
		if (m_eLeftMouseButtonState == ELeftMouseButtonState::PRESSED || m_eLeftMouseButtonState == ELeftMouseButtonState::HOLDING)
		{
			// Button has been released, change state to RELEASED.
			m_eLeftMouseButtonState = ELeftMouseButtonState::RELEASED;
		}
		else if (m_eLeftMouseButtonState == ELeftMouseButtonState::RELEASED)
		{
			// Button is not doing anything, set state to IDLE.
			m_eLeftMouseButtonState = ELeftMouseButtonState::IDLE;
		}
		else if (m_eLeftMouseButtonState == ELeftMouseButtonState::IDLE)
		{
			// Button is not doing anything, keep state the same (IDLE).
			
		}
	}
	
}

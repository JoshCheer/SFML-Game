/**************************************************************************
//
// File Name : Collisions.h
// Description : Header file for the Collision NameSpace.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/


#pragma once


// Includes
#include "SFML/Graphics.hpp"

namespace Collisions
{
	// Shifts ObjA left or right until no longer colliding with ObjB.
	static void resolveXCollisions(sf::FloatRect* _pObjA, sf::FloatRect* _pObjB)
	{
		sf::Vector2f entityACenter{ (_pObjA->left + _pObjA->width / 2.0f),
									 (_pObjA->top + _pObjA->height / 2.0f) };

		sf::Vector2f entityBCenter{ (_pObjB->left + _pObjB->width / 2.0f),
									 (_pObjB->top + _pObjB->height / 2.0f) };

		if (entityACenter.x <= entityBCenter.x)
		{
			float fOffset = -(_pObjA->left + _pObjA->width - _pObjB->left);
			_pObjA->left += fOffset;
		}

		if (entityACenter.x >= entityBCenter.x)
		{
			float fOffset = (_pObjB->left + _pObjB->width - _pObjA->left);
			_pObjA->left += fOffset;
		}
	}

	// Shifts ObjA up or down until no longer colliding with ObjB.
	static void resolveYCollisions(sf::FloatRect* _pObjA, sf::FloatRect* _pObjB)
	{
		sf::Vector2f entityACenter{ (_pObjA->left + _pObjA->width / 2.0f),
									 (_pObjA->top + _pObjA->height / 2.0f) };

		sf::Vector2f entityBCenter{ (_pObjB->left + _pObjB->width / 2.0f),
									 (_pObjB->top + _pObjB->height / 2.0f) };

		if (entityACenter.y <= entityBCenter.y)
		{
			float fOffset = -(_pObjA->top + _pObjA->height - _pObjB->top);
			_pObjA->top += fOffset;
		}

		if (entityACenter.y >= entityBCenter.y)
		{
			float fOffset = (_pObjB->top + _pObjB->height - _pObjA->top);
			_pObjA->top += fOffset;
		}
	}
}


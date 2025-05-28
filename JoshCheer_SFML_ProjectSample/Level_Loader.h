/**************************************************************************
//
// File Name : Level_Loader.h
// Description : Header file for the level Loader Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

// Includes
#include "SFML/Graphics.hpp"

class Level_Loader
{
public:
	// Public class functions

	// Constructor Destructor not needed
	Level_Loader(void) {}; 
	~Level_Loader(void) {};

	// Loads the level data from the file
	static std::string loadLevelData(std::string _sLevelName, class Level* _pLevel);


	// Processes the data and creates the tiles
	static void processLevelData(std::string _sLevelData, Level* _pLevel, class Asset_Manager* _pAssetManager);
protected:

private:
	
};


/**************************************************************************
//
// File Name : Level_Tile.h
// Description : Header file for  Level_Tile Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

#pragma once

// Includes
#include "Level_Object.h"


// enum for different tile types
enum class ETileType
{
	WALL,
	FLOOR
};

class Level_Tile : public Level_Object
{

public:
	// public class functions
	Level_Tile();
	virtual ~Level_Tile();

	virtual void update(Level* _pParentLevel, float _fDeltaTime) {};

	void setTileType(ETileType _eTileType, class Asset_Manager* _pAssetManager);
protected:

private:
	//private class variables
	ETileType m_eTileType = ETileType::WALL;
};


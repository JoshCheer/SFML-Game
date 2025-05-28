/**************************************************************************
//
// File Name : Level_Loader.cpp
// Description : Implementation file for the level Loader Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/


// Includes
#include "Level_Loader.h"
#include "Level.h"
#include "Level_Tile.h"
#include "Utilities.h"
#include<fstream>
#include "Asset_Manager.h"


// Function to load the file and return the string of the level data
std::string Level_Loader::loadLevelData(std::string _sLevelName, Level* _pLevel)
{
    std::string sLevelData;
    std::fstream loadFileStream;
    loadFileStream.open("resources\\gamedata\\leveldata\\" + _sLevelName, std::ios::in);

    if (loadFileStream)
    {       
        std::string sLoadFileString;
        while (std::getline(loadFileStream, sLoadFileString))
        {
            if (_pLevel->getBoardWidth() == 0)
            {
                _pLevel->setBoardWidth(sLoadFileString.size());
            }         

            sLevelData = sLevelData + sLoadFileString;
            _pLevel->setBoardHeight(_pLevel->getBoardHeight() + 1);
        }
        loadFileStream.close();
    }
    else
    {
        printf("couldn't open");
    }
    return sLevelData;
}

void Level_Loader::processLevelData(std::string _sLevelData, Level* _pLevel, Asset_Manager* _pAssetManager)
{
    
    for (unsigned int i = 0; i < _sLevelData.size(); ++i)
    {
        // Create tile
        //Level_Tile* pNewTile = new Level_Tile();       
        std::shared_ptr<Level_Tile> pNewTile = std::make_shared<Level_Tile>();
        // Checks for X or 0 to know if it should add a wall or floor to the grid
        if (_sLevelData[i] == 'X')
        {
            pNewTile->setTileType(ETileType::WALL, _pAssetManager);
        }
        else if (_sLevelData[i] == '0')
        {
            pNewTile->setTileType(ETileType::FLOOR, _pAssetManager);
        }

        // Assign position to tile - done after setting tile type so that the Bounding Volume is in the right position.
        int iRow = i / _pLevel->getBoardWidth();
        int iColumn = i % _pLevel->getBoardWidth();

        // Add tile to level.
        pNewTile->setPosition(sf::Vector2f(iColumn * Utils::m_fWorldUnit + 0.5f * Utils::m_fWorldUnit, iRow * Utils::m_fWorldUnit + 0.5f * Utils::m_fWorldUnit));
        _pLevel->addStaticObject(pNewTile);
      
    }


    
    
}


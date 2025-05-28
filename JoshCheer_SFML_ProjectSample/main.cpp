/**************************************************************************
//
// File Name : main.cpp
// Description : main source file.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/

// Includes
#include <SFML/Graphics.hpp>
#include <memory>
#include "Scene_Manager.h"
#include "Utilities.h"

int main()
{
    sf::RenderWindow gameWindow(
        sf::VideoMode(Utils::m_iWindowWidth, Utils::m_iWindowHeight),
        "Game Window",
        sf::Style::Fullscreen
    );

    auto sceneManager = std::make_unique<Scene_Manager>(gameWindow);

    while (gameWindow.isOpen())
    {
        sf::Event event;
        while (gameWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameWindow.close();
            }

            // Check for key presses
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    // ESC will close program.
                    gameWindow.close();
                }
            }

        }
        // Updates everything in the current scene
        sceneManager->update();

        // render loop 
        gameWindow.clear();
        sceneManager->render();
        gameWindow.display();
    }

    return 0;
}
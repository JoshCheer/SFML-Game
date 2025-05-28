/**************************************************************************
//
// File Name : Audio_Manager.cpp
// Description : Implementation file for Audio Manager Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/
#include "Audio_Manager.h"
#include <iostream>
#include <stdexcept>

Audio_Manager::Audio_Manager()
{	
    // Loads the required sounds
	LoadSound("resources/sounds/ButtonClick.wav", ESoundTag::BUTTON_CLICK);
	LoadSound("resources/sounds/GameComplete.wav", ESoundTag::GAME_COMPLETE);
}


// Function to handle the playing of the sounds
void Audio_Manager::PlaySound(ESoundTag _eSoundTag)
{
    auto it = m_sounds.find(_eSoundTag);
    if (it != m_sounds.end())
    {
        it->second->play();
    }
    else
    {
        std::cerr << "Sound not found for tag: " << static_cast<int>(_eSoundTag) << '\n';
    }
}
// Function to handle the stopping of the sounds in required
void Audio_Manager::StopSound(ESoundTag _eSoundTag)
{
    auto it = m_sounds.find(_eSoundTag);
    if (it != m_sounds.end())
    {
        it->second->stop();
    }
    else
    {
        std::cerr << "Sound not found for tag: " << static_cast<int>(_eSoundTag) << '\n';
    }
}

// Function to handle the loading of the sounds
void Audio_Manager::LoadSound(std::string _sFilepath, ESoundTag _eSoundTag)
{
    if (m_soundBuffers.contains(_eSoundTag))
    {
        throw std::runtime_error("Sound already loaded for this tag.");
    }

    auto buffer = std::make_unique<sf::SoundBuffer>();
    if (!buffer->loadFromFile(_sFilepath))
    {
        throw std::runtime_error("Failed to load sound from file: " + _sFilepath);
    }

    auto sound = std::make_unique<sf::Sound>();
    sound->setBuffer(*buffer);

	
	m_soundBuffers[_eSoundTag] = std::move(buffer);
	m_sounds[_eSoundTag] = std::move(sound);
}
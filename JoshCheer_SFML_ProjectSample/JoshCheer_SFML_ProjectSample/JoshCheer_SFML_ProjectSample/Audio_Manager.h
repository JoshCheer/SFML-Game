/**************************************************************************
//
// File Name : Audio_Manager.h
// Description : Header file for the Audio Manager Class.
// Author : Josh Cheer
// Mail : jcheer1391@gmail.com
//
**************************************************************************/
#pragma once
// Includes
#include "SFML/Audio.hpp"
#include <map>

// Enumerator for sound tags
enum class ESoundTag
{	
	BUTTON_CLICK,
	GAME_COMPLETE,	
};


class Audio_Manager
{
public:
	Audio_Manager();
	~Audio_Manager() = default;

	void PlaySound(ESoundTag _eSoundTag);
	void StopSound(ESoundTag _eSoundTag);	

protected:


private:
	std::map<ESoundTag, std::unique_ptr<sf::SoundBuffer>> m_soundBuffers;
	std::map<ESoundTag, std::unique_ptr<sf::Sound>>  m_sounds;

	// Stores a given sound in this classes sound databases to be used by the rest of the program.
	void LoadSound(std::string _sFilepath, ESoundTag _eSoundTag);

	
	

};
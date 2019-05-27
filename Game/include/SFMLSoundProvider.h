#pragma once

#include "stdafx.h"
#include "IAudioProvider.h"
#include "SoundFileCache.h"

class SFMLSoundProvider : public IAudioProvider
{
public:

	SFMLSoundProvider();
	virtual ~SFMLSoundProvider();

	void PlaySound(std::string filename) override;
	void PlaySong(std::string filename, bool looping = false) override;
	void StopAllSounds() override;

	bool IsSoundPlaying() override;
	bool IsSongPlaying() override;

private:
	static const int MAX_SOUND_CHANNELS = 5;

	SoundFileCache _soundFileCache;
	sf::Sound   _currentSounds[MAX_SOUND_CHANNELS];
	std::string _currentSongName;
};
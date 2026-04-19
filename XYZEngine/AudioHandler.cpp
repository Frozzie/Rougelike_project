
#include "pch.h"
#include "AudioHandler.h"

namespace XYZEngine
{
	AudioComponent::AudioComponent(GameObject* gameObject) : Component(gameObject)
	{
		soundBuffer = new sf::SoundBuffer;
		sound = new sf::Sound; 
	}

	AudioComponent::~AudioComponent()
	{
		delete soundBuffer;
		delete sound;
	}
	
	void AudioComponent::SoundInit(std::string filePath, int vol)
	{
		soundBuffer->loadFromFile(filePath);
		sound->setBuffer(*soundBuffer);
		sound->setVolume(vol);
	}

	void AudioComponent::SoundPlay(std::string filePath)
	{
		sound->play();
	}
}
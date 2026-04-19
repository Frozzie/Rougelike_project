
#pragma once
#include "GameObject.h"
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>

namespace XYZEngine
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent(GameObject* gameObject);
		~AudioComponent();

		void Update(float deltaTime) {}; // needed for all of this to work
		void Render() {};

		void SoundInit(std::string filePath, int vol);
		void SoundPlay(std::string filePath);
	
	private:
		sf::SoundBuffer *soundBuffer;
		sf::Sound *sound;

	};
	
}
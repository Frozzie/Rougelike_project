#pragma once
#define NOMINMAX

#include "SFML/Graphics.hpp"

namespace XYZEngine
{
	class Engine
	{
	public:
		Engine(const Engine& app) = delete;
		Engine& operator= (const Engine&) = delete;

		static Engine* Instance();

		void Run(sf::Time dt);

		int Get_cur_lvl();
		void Set_cur_lvl(int num);

	private:
		Engine();
		~Engine() = default;

		int CurLevel;

		void setupLogger();
	};
}
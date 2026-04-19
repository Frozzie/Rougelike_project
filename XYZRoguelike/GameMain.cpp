// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include "DeveloperLevel.h"
#include "Level1.h"
#include "Engine.h"
#include "Matrix2D.h"
#include "Player.h"
#include "ResourceSystem.h"
#include <SFML/Graphics.hpp>

int main()
{
    XYZEngine::RenderSystem::Instance()->SetMainWindow(new sf::RenderWindow(sf::VideoMode(1280, 720), "XYZRoguelike"));

    // XYZEngine::ResourceSystem::Instance()->LoadTexture("ball", "Resources/Textures/ball.png");

    XYZEngine::ResourceSystem::Instance()->LoadTextureMap("player", "Resources/TextureMaps/Player.png", {48, 63}, 4, false);
    XYZEngine::ResourceSystem::Instance()->LoadTextureMap("enemy", "Resources/TextureMaps/Roamer.png", {48, 63}, 4, false);
    XYZEngine::ResourceSystem::Instance()->LoadTextureMap("level_floors", "Resources/TextureMaps/Floor.png", {16, 16}, 49, false);
    XYZEngine::ResourceSystem::Instance()->LoadTextureMap("level_walls", "Resources/TextureMaps/Wall.png", {16, 16}, 48, false);

    XYZEngine::ResourceSystem::Instance()->LoadSound("music", "Resources/Sounds/AppleEat.wav");

    auto developerLevel = std::make_shared<XYZRoguelike::DeveloperLevel>();
    auto lvl_1 = std::make_shared<XYZRoguelike::Level1>();
   // auto lvl_2 = std::make_shared<XYZRoguelike::Level2>();
	XYZEngine::Engine::Instance()->Set_cur_lvl(1);


    while (XYZEngine::RenderSystem::Instance()->GetMainWindow().isOpen())
    {
        if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 1)
        {
            lvl_1->Stop();
            developerLevel->Start(); 
            //lvl_1->player->GetGameObject<>
        }
        else
        {
			developerLevel->Stop();
            lvl_1->Start();
        }

        XYZEngine::Engine::Instance()->Run();
    }

    return 0;
}

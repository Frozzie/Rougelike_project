// ©2023, XYZ School. All rights reserved.
// Authored by Aleksandr Rybalka (polterageist@gmail.com)

#include "DeveloperLevel.h"
#include "Level1.h"
#include "Level2.h"
#include "Engine.h"
#include "Matrix2D.h"
#include "Player.h"
#include "ResourceSystem.h"
#include "TransformComponent.h"
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

    bool lvl_switch = true;
    bool flag = true;
    
    std::shared_ptr<XYZRoguelike::DeveloperLevel> lvl_1 = std::make_shared<XYZRoguelike::Level1>();
    std::shared_ptr<XYZRoguelike::DeveloperLevel> lvl_2 = std::make_shared<XYZRoguelike::Level2>();
    //XYZRoguelike::DeveloperLevel *lvl_2 = new XYZRoguelike::Level2;

    //XYZRoguelike::DeveloperLevel* cur_lvl = lvl_1;

    sf::Clock gameClock;
    sf::Time dt;

	XYZEngine::Engine::Instance()->Set_cur_lvl(1);

    while (XYZEngine::RenderSystem::Instance()->GetMainWindow().isOpen())
    {
        dt = gameClock.restart();
        if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 1 && lvl_switch)
        {
            lvl_2->Stop(); // Stops previous level
			//cur_lvl = lvl_1; // Sets current level to new level
			lvl_1->Start(); // Starts new level
			lvl_switch = false; // Resets flag to make sure the switch only happens once per level change
            dt = sf::Time::Zero + sf::seconds(01.f);
        }
        else if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 2 && lvl_switch)
        {
            lvl_1->Stop();
            //cur_lvl = lvl_2;
            lvl_2->Start();
            lvl_switch = false;
            dt = sf::Time::Zero + sf::seconds(01.f);
        }
        
        XYZEngine::Engine::Instance()->Run(dt); //freaks out for a few frames then calms down to normal, cause unknown
        //roamer update is making it crash i think


        /*if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 1)
        {
            if (lvl_1->GetPlayer()->GetGameObject()->GetComponent<TransformComponent>()->GetWorldPosition().y >= 1800.f && flag)
            {
                XYZEngine::Engine::Instance()->Set_cur_lvl(2);
                lvl_switch = true;
            } 
		}
        else if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 2)
        {
            if (lvl_2->GetPlayer()->GetGameObject()->GetComponent<TransformComponent>()->GetWorldPosition().y >= 1800.f && flag)
            {
                XYZEngine::Engine::Instance()->Set_cur_lvl(1);
                lvl_switch = true;
            }
        }*/

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        {
            XYZEngine::Engine::Instance()->Set_cur_lvl(1);
            lvl_switch = true;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        {
            XYZEngine::Engine::Instance()->Set_cur_lvl(2);
            lvl_switch = true;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 1)
            {
                XYZEngine::Vector2Df pos = lvl_1->GetPlayer()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->GetWorldPosition();
                lvl_1->GetPlayer()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->SetWorldPosition({ 15 / 2 * 128.f, 15 / 2 * 128.f });
                //flag = true;
            }
            else if (XYZEngine::Engine::Instance()->Get_cur_lvl() == 2)
            {
                XYZEngine::Vector2Df pos = lvl_2->GetPlayer()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->GetWorldPosition();
                lvl_2->GetPlayer()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->SetWorldPosition({ 15 / 2 * 128.f, 15 / 2 * 128.f });
                //flag = true;
            }
        }
    }


    return 0;
}

#pragma once

#include "DeveloperLevel.h"
#include "Floor.h"
#include "Music.h"
#include "Player.h"
#include "Roamer.h"
#include "Scene.h"
#include "Wall.h"
#include <array>
#include <iostream>

using namespace XYZEngine;

namespace XYZRoguelike
{
    class Level1 : public Scene
    {
    public:
        
        void Start();
        void Restart() override;
        void Stop() override;

        std::vector<std::unique_ptr<Wall>> walls;
        std::vector<std::unique_ptr<Floor>> floors;
        std::vector<std::unique_ptr<Roamer>> roamers;
        std::shared_ptr<Player> player;
    private:
        
        std::unique_ptr<Music> music;
    };
} // namespace XYZRoguelike

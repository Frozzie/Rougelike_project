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
    class Level2 : public DeveloperLevel
    {
    public:

        void Start() override;

    private:
    };
} // namespace XYZRoguelike

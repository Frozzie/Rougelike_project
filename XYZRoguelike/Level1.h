#pragma once

#include "DeveloperLevel.h"
#include "Floor.h"
#include "Music.h"
#include "Player.h"
#include "Roamer.h"
#include "Scene.h"
#include "Wall.h"
#include "Engine.h"
#include <array>
#include <iostream>

using namespace XYZEngine;

namespace XYZRoguelike
{
    class Level1 : public DeveloperLevel//, public Engine
    {
    public:

        void Start() override;
        XYZEngine::GameObject* gameObject;

    private:
    };
} // namespace XYZRoguelike

#pragma once

#include "GameObject.h"
#include <GameWorld.h>
#include <ResourceSystem.h>

namespace XYZRoguelike
{
class Wall
{
  public:
    Wall(const XYZEngine::Vector2Df position, int textureMapIndex);

  private:
    XYZEngine::GameObject *gameObject;
};
} // namespace XYZRoguelike

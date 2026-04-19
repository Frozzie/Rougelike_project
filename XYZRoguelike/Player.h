#pragma once

#include "CameraComponent.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "InputComponent.h"
#include "RenderSystem.h"
#include "SpriteRendererComponent.h"
#include "Vector.h"

namespace XYZRoguelike 
{
class Player : public XYZEngine::Component
{
  public:

    Player(const XYZEngine::Vector2Df &position);
    XYZEngine::GameObject *GetGameObject();

    void Update(float DeltaTime) override;
    void Render() override;

  private:
    XYZEngine::GameObject *gameObject;
};
} // namespace XYZRoguelike

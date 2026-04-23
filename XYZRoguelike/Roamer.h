#pragma once

#include "Component.h"
#include "GameObject.h"
#include "GameWorld.h"
#include "MovementComponent.h"
#include "SpriteColliderComponent.h"
#include "SpriteDirectionComponent.h"

namespace XYZRoguelike
{

class Roamer : public XYZEngine::Component
{
  public:

    //Roamer();
    //Roamer(XYZEngine::GameObject *gameObject);
    Roamer(const XYZEngine::Vector2Df vector);
    ~Roamer();

    void Update(float DeltaTime) override;
    void Render() override;
    //XYZEngine::GameObject GetGameObject();

    XYZEngine::Vector2Df Dir;

  private:
    float speed;

    XYZEngine::GameObject *gameObject;
};
} // namespace XYZRoguelike

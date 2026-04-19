
#include "Roamer.h"
#include "Component.h"
#include "pch.h"

namespace XYZRoguelike
{
// Class roamer that contains all the "parts" of a roamer and various functions
Roamer::Roamer()
{
    int randDir = rand() % 4;

    if (randDir == 0)
    {
        Dir.x = 0;
        Dir.y = -1;
    }
    else if (randDir == 1)
    {
        Dir.x = 0;
        Dir.y = 1;
    }
    else if (randDir == 2)
    {
        Dir.x = -1;
        Dir.y = 0;
    }
    else
    {
        Dir.x = 1;
        Dir.y = 0;
    }

    speed = 250.f;

    gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Roamer");

    auto transform = gameObject->GetComponent<XYZEngine::TransformComponent>();
    transform->SetWorldPosition(vector);
    transform->SetDir(Dir);

    auto renderer = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
    renderer->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("enemy", 0));
    renderer->SetPixelSize(100, 100);

    auto rigidbody = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
    rigidbody->SetKinematic(false);

    /*auto HP = gameObject->AddComponent<XYZEngine::HealthManager>();
    HP->Health_set(100);
    HP->Armor_set(0);*/

    std::function<void(XYZEngine::Collision)> flip;
    // Function for flipping direction after a collision
    flip = [](XYZEngine::Collision collision) {
        if (collision.getCollider()->GetGameObject()->GetName() != collision.getCollidee()->GetGameObject()->GetName())
        {
            // dir is impossible to get straight from the class, but by saving it in a component, its now easily
            // accesible
            XYZEngine::Vector2Df dir;
            dir = collision.getCollider()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->GetDir();
            XYZEngine::Vector2Df pos = collision.getCollider()
                ->GetGameObject()
                ->GetComponent<XYZEngine::TransformComponent>()
                ->GetWorldPosition();

            // "Bumping" the roamer away from the collision so he wouldnt get stuck in them
            if (dir.x > 0)
            {
                pos.x -= 20.f;
                dir.x = -1.f;
            }
            else if (dir.x < 0)
            {
                pos.x += 20.f;
                dir.x = 1.f;
            }
            if (dir.y > 0)
            {
                pos.y -= 10.f;
                dir.y = -1.f;
            }
            else if (dir.y < 0)
            {
                pos.y += 10.f;
                dir.y = 1.f;
            }

            // Saving the updated variables in roamer
            collision.getCollider()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->SetWorldPosition(
                pos);
            collision.getCollider()->GetGameObject()->GetComponent<XYZEngine::TransformComponent>()->SetDir(dir);
        }
        };

    auto collider = gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
    collider->SubscribeCollision(flip);
}

Roamer::Roamer(XYZEngine::GameObject *gameObj) : Roamer()
{
}

Roamer::Roamer(XYZEngine::Vector2Df vector) : Roamer()
{
    
}

void Roamer::Update(float DeltaTime)
{
    Dir = gameObject->GetComponent<XYZEngine::TransformComponent>()->GetDir();

    XYZEngine::Vector2Df pos = gameObject->GetComponent<XYZEngine::TransformComponent>()->GetWorldPosition();

    pos.x += DeltaTime * Dir.x * speed;
    pos.y += DeltaTime * Dir.y * speed;

    gameObject->GetComponent<XYZEngine::TransformComponent>()->SetWorldPosition(pos);
}

void Roamer::Render()
{
}
} // namespace XYZRoguelike

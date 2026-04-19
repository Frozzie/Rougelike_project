
#include "pch.h"
#include "Enemy_atk.h"

namespace XYZEngine
{
	Enemy_atk::Enemy_atk(XYZEngine::GameObject* gameObj)
	{
		gameObject = XYZEngine::GameWorld::Instance()->CreateGameObject("Enemy_atk");

		enemyObj = gameObj;

		auto transform_atk = gameObject->GetComponent<XYZEngine::TransformComponent>();
		transform_atk->SetWorldPosition(gameObj->GetComponent<TransformComponent>()->GetWorldPosition());

		auto renderer_atk = gameObject->AddComponent<XYZEngine::SpriteRendererComponent>();
		renderer_atk->SetTexture(*XYZEngine::ResourceSystem::Instance()->GetTextureMapElementShared("enemy_atk", 0));
		renderer_atk->SetPixelSize(200, 200);

		auto collider_atk = gameObject->AddComponent<XYZEngine::SpriteColliderComponent>();
		collider_atk->SetTrigger(true);

		auto rigidbody_atk = gameObject->AddComponent<XYZEngine::RigidbodyComponent>();
		rigidbody_atk->SetKinematic(false);

		std::function<void(XYZEngine::Trigger)> hit;

		hit = [](XYZEngine::Trigger trigger) {
			bool flag = true;
			if (flag = true)
			{
				if (trigger.getCollider()->GetGameObject()->GetName() != trigger.getCollidee()->GetGameObject()->GetName() && 
					trigger.getCollidee()->GetGameObject()->GetName() != "Wall")
				{
					trigger.getCollider()->GetGameObject()->GetComponent<XYZEngine::HealthManager>()->Health_down(10);
				}
					
				flag = false;
			}
			};

		collider_atk->SetTrigger(true);
		collider_atk->SubscribeTriggerEnter(hit);
	}

	Enemy_atk::Enemy_atk()
	{
		
	}

	void Enemy_atk::Update(float DeltaTime)
	{
		auto enemy_pos = enemyObj->GetComponent<XYZEngine::TransformComponent>()->GetWorldPosition();

		gameObject->GetComponent<XYZEngine::TransformComponent>()->SetWorldPosition(enemy_pos);

		// need to make a animator based on time
	}

	void Enemy_atk::Render()
	{

	}

}

#pragma once

#include "Component.h"
#include "GameWorld.h"
#include "GameObject.h"
#include "ResourceSystem.h"
#include "SpriteColliderComponent.h"
#include "MovementComponent.h"
#include "SpriteDirectionComponent.h"
#include "SpriteMovementAnimationComponent.h"
#include "HealthManagerComponent.h"

namespace XYZEngine
{
	class Enemy_atk : public XYZEngine::Component
	{
	public:

		Enemy_atk();
		Enemy_atk(XYZEngine::GameObject* gameObject);

		void Update(float DeltaTime) override;
		void Render() override;

	private:

		XYZEngine::GameObject* gameObject;

		XYZEngine::GameObject* enemyObj;

	};
}
#pragma once

#include "Component.h"
#include "GameObject.h"
#include "TransformComponent.h"

namespace XYZEngine
{
	class EnemyMoveComponent : public XYZEngine::Component
	{
	public:
		EnemyMoveComponent(XYZEngine::GameObject* gameObj);
		~EnemyMoveComponent();

		void SetDir(XYZEngine::Vector2Df newDir);
		XYZEngine::Vector2Df GetDir();

		void SetPos(XYZEngine::Vector2Df newPos);
		XYZEngine::Vector2Df GetPos();

		void SetGameObject(XYZEngine::GameObject* newGameObj);

		void Update(float DeltaTime) override;
		void Render() override;

	private:
		XYZEngine::GameObject* gameObject;
		XYZEngine::Vector2Df Dir;
		XYZEngine::Vector2Df Pos;
	
	};
}
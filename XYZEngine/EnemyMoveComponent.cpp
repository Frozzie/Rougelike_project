
#include "pch.h"
#include "EnemyMoveComponent.h"

namespace XYZEngine
{
	EnemyMoveComponent::EnemyMoveComponent(GameObject* gameObj)
	{
	}

	void EnemyMoveComponent::SetDir(XYZEngine::Vector2Df newDir)
	{
		Dir = newDir;
	}
	XYZEngine::Vector2Df EnemyMoveComponent::GetDir()
	{
		return Dir;
	}

	void EnemyMoveComponent::SetPos(XYZEngine::Vector2Df newPos)
	{
		Pos = newPos;
	}
	XYZEngine::Vector2Df EnemyMoveComponent::GetPos()
	{
		return Pos;
	}

	void EnemyMoveComponent::SetGameObject(XYZEngine::GameObject* newGameObj)
	{
		gameObject = newGameObj;
	}

	void EnemyMoveComponent::Update(float DeltaTime)
	{
		Pos.x += DeltaTime * Dir.x * 250.f;
		Pos.y += DeltaTime * Dir.y * 250.f;
		
		gameObject->GetComponent<XYZEngine::TransformComponent>()->SetWorldPosition(Pos);
	}

	void EnemyMoveComponent::Render()
	{
	}

	EnemyMoveComponent::~EnemyMoveComponent()
	{

	}
}
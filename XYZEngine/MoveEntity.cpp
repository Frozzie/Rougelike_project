
#include "pch.h"
#include "MoveEntity.h"

namespace XYZEngine
{
	MoveEntity::MoveEntity(GameObject* gameObject) : RigidbodyComponent(gameObject)
	{

	}

	MoveEntity::~MoveEntity()
	{
		
	}

	void MoveEntity::SetMoveVector(float vectorX, float vectorY)
	{
		Vector2Df vector;
		vector.x = vectorX;
		vector.y = vectorY;

		SetLinearVelocity(vector);
	}
}
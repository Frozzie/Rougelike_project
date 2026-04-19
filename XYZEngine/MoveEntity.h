
#pragma once

#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "RigidBodyComponent.h"

namespace XYZEngine
{
	class MoveEntity : public RigidbodyComponent
	{
	public:
		MoveEntity(GameObject *gameobject);
		~MoveEntity();

		void Update(float deltaTime) {};
		void Render() {};

		void SetMoveVector(float vectorX, float vectorY);

	private:

	};

}
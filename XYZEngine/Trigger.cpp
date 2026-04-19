
#include "pch.h"
#include "Trigger.h"

namespace XYZEngine
{
	ColliderComponent* Trigger::getCollider()
	{
		return first;
	}
	ColliderComponent* Trigger::getCollidee()
	{
		return second;
	}
}
#include "pch.h"
#include "Collision.h"

namespace XYZEngine
{
    ColliderComponent* Collision::getCollider()
    {
        return first;
    }
    ColliderComponent* Collision::getCollidee()
    {
        return second;
    }
}
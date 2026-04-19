
#include "pch.h"
#include "HealthManagerComponent.h"

namespace XYZEngine
{
	HealthManager::HealthManager(GameObject* gameObject) : Component(gameObject)
	{
		health = 1;
		armor = 1;
	}

	void HealthManager::Update(float DeltaTime)
	{

	}

	void HealthManager::Render()
	{

	}

	void HealthManager::Health_set(int num)
	{
		health = num;
	}
	int HealthManager::Health_get()
	{
		return health;
	}
	void HealthManager::Health_up(int num)
	{
		health += num;
	}
	void HealthManager::Health_down(int num)
	{
		health -= num;
	}

	void HealthManager::Armor_set(int num)
	{
		armor = num;
	}
	int HealthManager::Armor_get()
	{
		return armor;
	}
	void HealthManager::Armor_up(int num)
	{
		armor += num;
	}
	void HealthManager::Armor_down(int num)
	{
		armor -= num;
	}
	
}
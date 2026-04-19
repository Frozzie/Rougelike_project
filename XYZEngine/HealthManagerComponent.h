
#pragma once
#include "GameObject.h"

namespace XYZEngine
{
	class HealthManager : public Component
	{
	public:

		HealthManager(GameObject* gameObject);

		void Update(float DeltaTime) override;
		void Render() override;

		void Health_set(int num);
		int Health_get();
		void Health_up(int num);
		void Health_down(int num);

		void Armor_set(int num);
		int Armor_get();
		void Armor_up(int num);
		void Armor_down(int num);

	private:

		int health;
		int armor;
	};
}
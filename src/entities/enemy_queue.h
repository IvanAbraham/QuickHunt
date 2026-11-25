#pragma once

#include <random>
#include <vector>

#include <SFML/Graphics.hpp>

#include "enemy.h"

namespace quickhunt
{
	class EnemyQueue : public sf::Drawable
	{
	private:
		std::vector<Enemy*> enemies;
		sf::Vector2f frontPosition;
		std::mt19937 randomGenerator;

		Enemy* CreateRandomEnemy();
		void DeleteAll();
		void UpdatePositions();

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		EnemyQueue(sf::Vector2f frontPosition);
		~EnemyQueue();

		EnemyQueue(const EnemyQueue&) = delete;
		EnemyQueue& operator=(const EnemyQueue&) = delete;

		Enemy& Front();
		void KillFront();
		void Reset();
	};
}

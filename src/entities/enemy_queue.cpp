#include "enemy_queue.h"

#include "round_enemy.h"
#include "square_enemy.h"
#include "triangular_enemy.h"

namespace quickhunt
{
	enum class EnemyType
	{
		Square,
		Triangular,
		Round,
		Count
	};

	static const int enemyCount = 5;
	static const float enemySpacing = 100.0f;

	EnemyQueue::EnemyQueue(sf::Vector2f frontPosition) : frontPosition(frontPosition), randomGenerator(std::random_device{}())
	{
		Reset();
	}

	EnemyQueue::~EnemyQueue()
	{
		DeleteAll();
	}

	Enemy& EnemyQueue::Front()
	{
		return *enemies.front();
	}

	void EnemyQueue::KillFront()
	{
		delete enemies.front();
		enemies.erase(enemies.begin());

		enemies.push_back(CreateRandomEnemy());
		UpdatePositions();
	}

	void EnemyQueue::Reset()
	{
		DeleteAll();

		for (int i = 0; i < enemyCount; i++)
		{
			enemies.push_back(CreateRandomEnemy());
		}

		UpdatePositions();
	}

	Enemy* EnemyQueue::CreateRandomEnemy()
	{
		std::uniform_int_distribution<int> distribution(0, static_cast<int>(EnemyType::Count) - 1);
		EnemyType type = static_cast<EnemyType>(distribution(randomGenerator));

		switch (type)
		{
		case EnemyType::Square:
			return new SquareEnemy();

		case EnemyType::Triangular:
			return new TriangularEnemy();

		case EnemyType::Round:
		default:
			return new RoundEnemy();
		}
	}

	void EnemyQueue::DeleteAll()
	{
		for (Enemy* enemy : enemies)
		{
			delete enemy;
		}

		enemies.clear();
	}

	void EnemyQueue::UpdatePositions()
	{
		for (std::size_t i = 0; i < enemies.size(); i++)
		{
			float offsetX = enemySpacing * static_cast<float>(i);
			enemies[i]->SetPosition({ frontPosition.x + offsetX, frontPosition.y });
		}
	}

	void EnemyQueue::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (const Enemy* enemy : enemies)
		{
			target.draw(*enemy, states);
		}
	}
}

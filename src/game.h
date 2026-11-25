#pragma once
#include "entities/enemy_queue.h"
#include "entities/player.h"

namespace quickhunt
{

	class Game
	{
	private:
		sf::RenderWindow window;
		sf::Clock clock;
		
		Player player;
		EnemyQueue queue;

		void HandleEvents();
		void Update(float dt);
		void Draw();
		void Restart();

		void Hit();
		void Miss();

		bool LowTime() const;

		int score;
		float timeLeft;

	public:
		Game();
		
		void Run();
	};

}



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

	public:
		Game();
		
		void Run();
	};

}



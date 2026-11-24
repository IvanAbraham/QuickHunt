#pragma once

#include <SFML/Graphics.hpp>

#include "enemy.h"

namespace quickhunt
{
	class TriangularEnemy : public Enemy
	{
	private:
		sf::CircleShape shape;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		TriangularEnemy();

		void SetPosition(sf::Vector2f position) override;
	};
}

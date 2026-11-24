#pragma once

#include <SFML/Graphics.hpp>

#include "enemy.h"

namespace quickhunt
{
	class SquareEnemy : public Enemy
	{
	private:
		sf::RectangleShape shape;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		SquareEnemy();

		void SetPosition(sf::Vector2f position) override;
	};
}

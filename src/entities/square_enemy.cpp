#include "square_enemy.h"

namespace quickhunt
{
	static const sf::Vector2f squareSize = { 60.0f, 60.0f };
	static const sf::Color squareColor = sf::Color::Red;

	SquareEnemy::SquareEnemy() : Enemy(sf::Keyboard::Key::Z), shape(squareSize)
	{
		shape.setFillColor(squareColor);
		shape.setOrigin(squareSize / 2.0f);
	}

	void SquareEnemy::SetPosition(sf::Vector2f position)
	{
		shape.setPosition(position);
	}

	void SquareEnemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(shape, states);
	}
}

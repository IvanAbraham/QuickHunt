#include "round_enemy.h"

namespace quickhunt
{
	static const float circleRadius = 35.0f;
	static const sf::Color circleColor = sf::Color::Green;

	RoundEnemy::RoundEnemy() : Enemy(sf::Keyboard::Key::C), shape(circleRadius)
	{
		shape.setFillColor(circleColor);
		shape.setOrigin({ circleRadius, circleRadius });
	}

	void RoundEnemy::SetPosition(sf::Vector2f position)
	{
		shape.setPosition(position);
	}

	void RoundEnemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(shape, states);
	}
}

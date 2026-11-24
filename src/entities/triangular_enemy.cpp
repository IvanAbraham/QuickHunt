#include "triangular_enemy.h"

namespace quickhunt
{
	static const float triangleRadius = 40.0f;
	static const std::size_t trianglePoints = 3;
	static const sf::Color triangleColor = sf::Color::Blue;

	TriangularEnemy::TriangularEnemy() : Enemy(sf::Keyboard::Key::X), shape(triangleRadius, trianglePoints)
	{
		shape.setFillColor(triangleColor);
		shape.setOrigin({ triangleRadius, triangleRadius });
	}

	void TriangularEnemy::SetPosition(sf::Vector2f position)
	{
		shape.setPosition(position);
	}

	void TriangularEnemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(shape, states);
	}
}

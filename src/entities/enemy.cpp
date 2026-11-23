#include "enemy.h"

namespace quickhunt
{
	Enemy::Enemy(sf::Keyboard::Key requiredKey) : requiredKey(requiredKey)
	{
	}

	bool Enemy::IsRequiredKey(sf::Keyboard::Key key) const
	{
		return (key == requiredKey);
	}

	sf::Keyboard::Key Enemy::GetRequiredKey() const
	{
		return requiredKey;
	}
}
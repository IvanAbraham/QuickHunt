#include "player.h"

namespace quickhunt
{
	Player::Player(int hp, float attackCooldown, const sf::RectangleShape& shape) : hp(hp), attackCooldown(attackCooldown), cooldownLeft(0.0f), shape(shape)
	{
	}

	void Player::Update(float dt)
	{
		if (!CanAttack())
		{
			cooldownLeft -= dt;
		}
	}

	void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(shape, states);
	}

	void Player::Attack()
	{
		cooldownLeft = attackCooldown;
	}

	int Player::GetHP() const
	{
		return hp;
	}

	void Player::TakeDamage(int damage)
	{
		hp -= damage;
	}

	bool Player::CanAttack() const
	{
		return (cooldownLeft <= 0);
	}

	bool Player::IsAlive() const
	{
		return (hp > 0);
	}
}
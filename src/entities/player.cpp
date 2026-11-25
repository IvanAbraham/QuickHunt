#include "player.h"

namespace quickhunt
{
	Player::Player(int maxHp, float attackCooldown, const sf::RectangleShape& shape) : maxHp(maxHp), currentHp(maxHp), attackCooldown(attackCooldown), cooldownLeft(0.0f), shape(shape)
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
		return currentHp;
	}

	void Player::TakeDamage(int damage)
	{
		currentHp -= damage;
	}

	bool Player::CanAttack() const
	{
		return (cooldownLeft <= 0);
	}

	bool Player::IsAlive() const
	{
		return (currentHp > 0);
	}

	void Player::RevivePlayer()
	{
		currentHp = maxHp;
	}
}
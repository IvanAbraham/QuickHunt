#pragma once

#include <SFML/Graphics.hpp>

namespace quickhunt
{
	class Player : public sf::Drawable
	{
	private:
		int hp;
		float attackCooldown;
		float cooldownLeft;
		sf::RectangleShape shape;
		
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	public:
		Player(int hp, float attackCooldown, const sf::RectangleShape& shape);
		int GetHP() const;
		bool CanAttack() const;
		void Attack();
		void TakeDamage(int damage);
		bool IsAlive() const;
		void Update(float dt);
	};
}

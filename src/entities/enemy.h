#pragma once

#include <SFML/Graphics.hpp>

namespace quickhunt
{
	class Enemy : public sf::Drawable
	{
	private:
		sf::Keyboard::Key requiredKey;

	protected:
		Enemy(sf::Keyboard::Key requiredKey);

	public:
		bool IsRequiredKey(sf::Keyboard::Key key) const;
		sf::Keyboard::Key GetRequiredKey() const;

		virtual void SetPosition(sf::Vector2f position) = 0;
	};
}

#include "player.h"

namespace quickhunt
{
	Player::Player(int hp, float attackSpeed) : hp(hp), attackCooldown(attackSpeed)
	{
	}
}
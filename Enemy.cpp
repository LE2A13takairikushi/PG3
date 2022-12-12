#include "Enemy.h"
#include <stdio.h>

void (Enemy::* Enemy::stateTable[])() =
{
	&Enemy::ShortAttack,
	&Enemy::LongAttack,
	&Enemy::Escape,
};

Enemy::Enemy()
{
	printf("“G‚ª¶‚Ü‚ê‚½I\n");
	state = EnemyState::SHORTATTACK;
}

void Enemy::ShortAttack()
{
	printf("“G‚Ì‹ßÚUŒ‚I\n");
	state = EnemyState::LONGATTACK;
}

void Enemy::LongAttack()
{
	printf("“G‚Ì‰“‹——£UŒ‚I\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("“G‚ª“¦‚°‚Ä‚¢‚­I\n");
}

void Enemy::Update()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

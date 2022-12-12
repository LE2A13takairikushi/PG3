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
	printf("敵が生まれた！\n");
	state = EnemyState::SHORTATTACK;
}

void Enemy::ShortAttack()
{
	printf("敵の近接攻撃！\n");
	state = EnemyState::LONGATTACK;
}

void Enemy::LongAttack()
{
	printf("敵の遠距離攻撃！\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("敵が逃げていく！\n");
}

void Enemy::Update()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

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
	printf("�G�����܂ꂽ�I\n");
	state = EnemyState::SHORTATTACK;
}

void Enemy::ShortAttack()
{
	printf("�G�̋ߐڍU���I\n");
	state = EnemyState::LONGATTACK;
}

void Enemy::LongAttack()
{
	printf("�G�̉������U���I\n");
	state = EnemyState::ESCAPE;
}

void Enemy::Escape()
{
	printf("�G�������Ă����I\n");
}

void Enemy::Update()
{
	(this->*stateTable[static_cast<size_t>(state)])();
}

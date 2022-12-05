#include "Enemy.h"
#include <stdio.h>

bool Enemy::isAlive = true;

Enemy::Enemy()
{
	printf("敵が生まれた！\n");
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("敵はまだ生きている\n");
	}
	else
	{
		printf("敵は死んでいる\n");
	}
}

void Enemy::Kill()
{
	isAlive = false;
	printf("敵が死んだ！\n");
}

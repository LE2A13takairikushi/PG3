#include "Enemy.h"
#include <stdio.h>

bool Enemy::isAlive = true;

Enemy::Enemy()
{
	printf("�G�����܂ꂽ�I\n");
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("�G�͂܂������Ă���\n");
	}
	else
	{
		printf("�G�͎���ł���\n");
	}
}

void Enemy::Kill()
{
	isAlive = false;
	printf("�G�����񂾁I\n");
}

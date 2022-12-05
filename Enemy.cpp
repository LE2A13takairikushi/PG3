#include "Enemy.h"
#include <stdio.h>

bool Enemy::isAlive = true;

Enemy::Enemy()
{
	printf("“G‚ª¶‚Ü‚ê‚½I\n");
}

void Enemy::Draw()
{
	if (isAlive)
	{
		printf("“G‚Í‚Ü‚¾¶‚«‚Ä‚¢‚é\n");
	}
	else
	{
		printf("“G‚Í€‚ñ‚Å‚¢‚é\n");
	}
}

void Enemy::Kill()
{
	isAlive = false;
	printf("“G‚ª€‚ñ‚¾I\n");
}

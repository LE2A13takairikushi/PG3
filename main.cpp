#include <stdio.h>
#include <stdlib.h>
#include "Enemy.h"

int main()
{
	//敵の生成
	Enemy* enemy = new Enemy;
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;

	printf("\n");

	for (int i = 0; i < static_cast<int>(EnemyState::STATENUM); i++)
	{
		enemy->Update();
		enemy1->Update();
		enemy2->Update();
		printf("\n");
	}

	delete enemy;
	delete enemy1;
	delete enemy2;

	system("pause");

	return 0;
}
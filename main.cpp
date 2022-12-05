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

	//状態表示(生きている状態が表示されるはず)
	enemy->Draw();
	enemy1->Draw();
	enemy2->Draw();

	printf("\n");

	//敵を死んだ状態に
	enemy->Kill();

	printf("\n");

	//状態表示(死んだ状態が表示されるはず)
	enemy->Draw();
	enemy1->Draw();
	enemy2->Draw();

	printf("\n");

	delete enemy;
	delete enemy1;
	delete enemy2;

	system("pause");

	return 0;
}
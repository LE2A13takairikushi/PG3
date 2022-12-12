#pragma once

enum class EnemyState
{
	SHORTATTACK,
	LONGATTACK,
	ESCAPE,
	STATENUM,
};

class Enemy
{
public:
	Enemy();

	void ShortAttack();
	void LongAttack();
	void Escape();

	void Update();

	EnemyState state;

	static void (Enemy::*stateTable[])();
};


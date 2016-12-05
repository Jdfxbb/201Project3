#include "Enemy.h"

Enemy::Enemy() : Character() {}

void Enemy::SelectAction()
{
	int choice = GetRandom(1, 2);
	if (choice == 1)
		m_attacktype = OFFENSIVE;
	else m_attacktype = DEFENSIVE;
}
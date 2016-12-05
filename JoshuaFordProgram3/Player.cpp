#include "Player.h"

Player::Player() : Character() {}

void Player::SelectAction()
{
	int choice = GetUserInput(1, 2);
	if (choice == 1)
		m_attacktype = OFFENSIVE;
	else m_attacktype = DEFENSIVE;
}
#include "Character.h"

#ifndef _PLAYER
#define _PLAYER

class Player : public Character
{
public:
	Player();

	void SelectAction();
	//PRE: None
	//POST: AttackType initialized
	//RETURNS: None
};

#endif
#include "Character.h"

#ifndef _ENEMY
#define _ENEMY

class Enemy : public Character
{
public:
	Enemy();

	void SelectAction();
	//PRE: None
	//POST: AttackType initialized
	//RETURNS: None
};

#endif
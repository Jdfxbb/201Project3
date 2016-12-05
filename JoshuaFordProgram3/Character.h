#include <iostream>
#include <string>
#include <iomanip>
#include "Utils.h"
using namespace std;

#ifndef _CHARACTER
#define _CHARACTER

// initialize AttackType used for fighting style choices
enum AttackType { OFFENSIVE = 1, DEFENSIVE = 2};

class Character
{
protected:
	int m_hp;
	int m_atk;
	int m_def;
	string m_name;
	AttackType m_attacktype;
public:
	Character();

	void Setup(const string& name, int hp, int atk, int def);
	//PRE: Character object initialized
	//POST: Object now has selected attributes name, hp, atk, def
	//RETURNS: None
	void DisplayStats();
	//PRE: stats must be initialized
	//POST: prints name and stats
	//RETURNS: None
	void SelectAction();
	//PRE: None
	//POST: None
	//RETURNS: None
	int GetAttack();
	//PRE: AttackType must be initialized
	//POST: None
	//RETURNS: Total attack after modifier
	void GetHit(int attack);
	//PRE: AttackType must be initialized
	//POST: Damage subtracted from hp
	//RETURNS: None
	int GetHP();
	//PRE: Hp initialized
	//POST: None
	//RETURNS: Hp
	string GetName();
	//PRE: Name initialized
	//POST: None
	//RETURNS: Name
};

#endif
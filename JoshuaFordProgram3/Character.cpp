#include "Character.h"

Character::Character()
{
	m_name = "";
	m_hp = 0;
	m_atk = 0;
	m_def = 0;
	m_attacktype = DEFENSIVE;
}

void Character::Setup(const string& name, int hp, int atk, int def)
{
	m_name = name;
	m_hp = hp;
	m_atk = atk;
	m_def = def;
}

void Character::DisplayStats()
{
	cout << setw(30) << m_name << setw(3) <<  "HP: " << setw(7) << m_hp 
		<< setw(4) <<  "Atk: " << setw(6) << m_atk << setw(4) 
		<< "Def: " << setw(6) << m_def << endl;
}

void Character::SelectAction(){}

int Character::GetAttack()
{
	// get random attack modifier
	int atkmod = GetRandom(1, 3);

	// check attacktype
	if (m_attacktype == 1)
	{
		return m_atk + GetRandom(1, 3);
	}
	else
	{
		return m_atk;
	}
}

void Character::GetHit(int attack)
{
	int damage;
	// check attacktype
	if (m_attacktype == 1)
	{
		// subtract def from attack
		damage = attack - m_def;
		if (damage < 0)
			damage = 0;
		cout << m_name << " took " << damage << " damage" << endl;
		// subtract total damage from hp
		m_hp -= damage;
	}
	else 
	{
		// subtract defense and defense modifier from attack
		damage = attack - m_def - GetRandom(1, 3);
		if (damage < 0)
			damage = 0;
		cout << m_name << " took " << damage << " damage" << endl;
		// subtract total damage from hp
		m_hp -= damage;
	}

}

int Character::GetHP()
{
	return m_hp;
}

string Character::GetName()
{
	return m_name;
}
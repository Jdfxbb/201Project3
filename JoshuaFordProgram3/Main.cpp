/*********************************************

Name:	Joshua Ford
Course: CS 201

Program: Battle Game
Due Date: 28 February 2016
Description: Write a program where two characters battle and take damage based
	on attack style and preferences
Inputs:	User name and selections from keyboard
Outputs: User and enemy stats and fight options
Algorithm:	
1. While user continues play
	a. While user does not accept setup
		1. Get user name
		2. Get user fight style
		3. Get random stats for enemy
		4. Show user and enemy stats
		5. Ask user if setup is acceptable
	b. While user hp > 0 and enemy hp > 0
		1. Show round and stats
		2. Get user attack type
		3. Get random attack type for enemy
		4. Calculate and report damage
		5. Update stats
	c. Report winner
	d. Ask user to play again

*********************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include "Utils.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

void SetupCharacters(Player& player, Enemy& enemy);

void main()
{
	// initialize time seed and player/enemy objects
	srand(time(NULL));
	Player player;
	Enemy enemy;
	// restart loop variable
	int playAgain = 0;
	
	// outer loop
	while (playAgain != 2)
	{
		int accept = 0;
		int round = 1;
		
		// player creation loop
		while (accept != 1)
		{
			SetupCharacters(player, enemy);
			cout << "\n";
			player.DisplayStats();
			cout << "\n VERSUS \n" << endl;
			enemy.DisplayStats();

			// ask user if setup is okay
			cout << "\nSelect an option: " << endl;
			cout << "\n" << "1. Continue" << "\n" << "2. Reconfigure Player" 
				<< endl;
			cout << "---> ";
			accept = GetUserInput(1, 2);
		}

		// battle loop
		while (player.GetHP() > 0 && enemy.GetHP() > 0)
		{
			// show round and stats
			cout << "\n *** Round " << round << " ***\n" << endl;
			player.DisplayStats();
			cout << "\n";
			enemy.DisplayStats();

			// choose attack type
			cout << "\nSelect an attack type: \n"
				<< "\n1. Offensive\n2. Defensive\n";
			cout << "---> ";
			player.SelectAction();
			enemy.SelectAction();
			cout << "\n";

			// calculate damage
			enemy.GetHit(player.GetAttack());
			player.GetHit(enemy.GetAttack());

			round++;
		}

		/*  check who got knocked out, report winner; If both characters are 
			knocked out in same round, this reports player as loser. The 
			idea is that the player needs to knock out the enemy 
			and survive to win */
		if (player.GetHP() < 1)
			cout << "\nYou are knocked out!\n" << "You Lose!\n" << endl;
		else cout << "\n" << enemy.GetName() << " is knocked out!\n" 
			<< "You Win!\n" << endl;

		// prompt user for restart loop
		cout << "Would you like to play again?\n";
		cout << "1. Yes\n2. No" << endl;
		cout << "---> ";
		playAgain = GetUserInput(1, 2);
	}
}

void SetupCharacters(Player& player, Enemy& enemy)
{
	string name;
	string enemyName;
	int choice;
	int enemyChoice;

	// array of possible enemies, called randomly to fight
	string enemies[9] {"Biff Tannen", "The Joker", "Voldemort", "Darth Vader",
		"The Wicked Witch of the West",	"Magneto", "Lex Luthor", 
		"Dr. Octopus", "Loki"};

	// get information from user
	cout << "Enter your name to begin: \n---> ";
	getline(cin, name);
	cout << "\n" << "Hello " << name << "\n\n";
	cout << "Choose your fighting style: \n\n";
	cout << setw(10) << left << "Option" << setw(10) << left << "Attack" 
		<< setw(10) << left << "Defense" << endl;
	cout << setw(10) << left << "1" << setw(10) << left << "5" << setw(10) 
		<< left << "15" << endl;
	cout << setw(10) << left << "2" << setw(10) << left << "15" << setw(10) 
		<< left << "5" << endl;
	cout << setw(10) << left << "3" << setw(10) << left << "10" << setw(10) 
		<< left << "10" << endl;
	cout << "---> ";
	choice = GetUserInput(1, 3);

	// initialize player stats
	switch (choice)
	{
	case 1:
		player.Setup(name, 100, 5, 15);
		break;
	case 2:
		player.Setup(name, 100, 15, 5);
		break;
	case 3:
		player.Setup(name, 100, 10, 10);
		break;
	}

	// get random selections for enemy name and fight style
	enemyName = enemies[GetRandom(0, 8)];
	enemyChoice = GetRandom(1, 3);
	
	// initialize enemy stats
	switch (enemyChoice)
	{
	case 1:
		enemy.Setup(enemyName, 100, 5, 15);
		break;
	case 2:
		enemy.Setup(enemyName, 100, 15, 5);
		break;
	case 3:
		enemy.Setup(enemyName, 100, 10, 10);
		break;
	}
}
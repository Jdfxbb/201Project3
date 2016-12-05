#include "Utils.h"

int GetUserInput(int min, int max)
{
	char input; // input value initialized as character
	string overflow = ""; // string to check for overflow
	int asciiMin = min + '0'; // min and max converted to ascii
	int asciiMax = max + '0';

	cin >> input; // read in one character
	getline(cin, overflow); // get rest of line

	// checks if user entered more than one character and min/max parameters
	while (overflow != "" || ((int)input < asciiMin || (int)input > asciiMax))
	{
		cout << "Please enter a number between " << min << " and " << max 
			<< " inclusive" << endl;
		cin >> input;
		getline(cin, overflow);
	}

	// return input as int
	return (int)input - '0';
}

int GetRandom(int min, int max)
{
	// return random value within min/max parameters
	int random = rand() % max + min;
	return random;
}
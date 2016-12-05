#include <iostream>
#include <string>
#include <time.h>
using namespace std;

#ifndef _UTILS
#define _UTILS

int GetUserInput(int min, int max);
//PRE: None
//POST: None
//RETURNS: User selection between min and max
int GetRandom(int min, int max);
//PRE: <time.h> included
//POST: None
//RETURNS: Random value between min and max

#endif

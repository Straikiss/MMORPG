#ifndef _INCLUDES_H_
#define _INCLUDES_H_

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using std::string;
using std::istringstream;

using std::cout;
using std::endl;

// player and enemy configs
#include "Configs.h"

// check on empty stats and setting default stats 
#include "Empty.h"

// display sleep and console color
#include "DisplaySleep.h"
#include "SetConsoleColor.h"

// setting player and enemy
#include "SetupPlayer.h"
#include "SetupEnemy.h"

// player and enemy are fighthing
#include "PlayerFight.h"
#include "EnemyFight.h"

// setting run configs
#include "SetupRun.h"

// who's win after that fight
#include "Result.h"

// main program
#include "MAIN.h"

#endif // _INCLUDES_H_
#include "pch.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

// player and enemy configs
#include "Configs.h"

// display color
#include "SetConsoleColor.h"

// setting run configs
#include "SetupRun.h"

// display sleep 
#include "DisplaySleep.h"

// setting min and max value
#include "SetPlayerValue.h"
#include "SetEnemyValue.h"

// setting player and enemy
#include "SetupPlayer.h"
#include "SetupEnemy.h"

// player and enemy are fighthing
#include "PlayerFight.h"
#include "EnemyFight.h"

// who's win after that fight
#include "Result.h"

int main()
{
	bool StopProgram;
	bool IsEnemyDead;
	bool IsPlayerDead;

	CheckSetupRun();

	// setup configs for player and enemy
	SetupPlayer();
	SetupEnemy();

	// random number generator
	srand((unsigned int)time(NULL));

	do
	{
		// getting random % for stats
		// 0 - 0%, 1 - 100%, 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20%
		if(Player.CritChance != 0)
		{
			Player.Crit = rand() % Player.CritChance + 1;
		}

		if(Enemy.CritChance != 0)
		{
			Enemy.Crit = rand() % Enemy.CritChance + 1;
		}

		// 0 - 0%, 1 - 100% (cant be), 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20%
		if(Player.DodgeChange != 0)
		{
			Player.Dodge = rand() % Player.DodgeChange + 1;
		}

		if(Enemy.DodgeChange != 0)
		{
			Enemy.Dodge = rand() % Enemy.DodgeChange + 1;
		}

		// if enemy is dead - then finish this fight
		IsEnemyDead = PlayerFight(GetShowFullLog());

		// if player is dead - then finish this fight
		IsPlayerDead = EnemyFight(GetShowFullLog());

		// if enemy is dead or player is dead - then stop this program
		if(IsEnemyDead == true || IsPlayerDead == true)
		{
			StopProgram = true;
		}
	} 
	while(StopProgram != true);

	// checking who's win
	Result(GetSaveBattleLog(), GetLogFileName());

	system("pause");

	return 0;
}
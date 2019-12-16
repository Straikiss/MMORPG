#ifndef _RESULT_H_
#define _RESULT_H_

void Result(std::string SaveBattleLog, std::string LogFileName)
{
	std::ofstream File;

	if(SaveBattleLog == "true")
	{
		File.open("Data/" + LogFileName + ".txt", std::ios_base::app);
	}

	DisplaySleep();
	std::cout << std::endl;

	// if Player.Health > (player is alive) Enemy.Health then victory
	if(Player.Health > Enemy.Health)
	{
		SetConsoleColor("Green");
		std::cout << "[GAME] Victory" << std::endl;
		SetConsoleColor("Black");

		std::cout << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << std::endl << std::endl;

		if(SaveBattleLog == "true")
		{
			File << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << std::endl;
			std::cout << "[PROGRAM]" << " BattleLog saved to " << LogFileName << ".txt" << std::endl;
		}
	}

	// if Player.Health < (player is dead) Enemy.Health then defeat
	if(Player.Health < Enemy.Health)
	{
		SetConsoleColor("Red");
		std::cout << "[GAME] Defeat" << std::endl;
		SetConsoleColor("Black");

		std::cout << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << std::endl << std::endl;

		if(SaveBattleLog == "true")
		{
			File << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << std::endl;
			std::cout << "[PROGRAM]" << " BattleLog saved to " << LogFileName << ".txt" << std::endl;
		}
	}
}

#endif // _RESULT_H_
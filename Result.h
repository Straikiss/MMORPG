#pragma once
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
		std::cout << "[" << Lang.Game << "]" << " " << Lang.Victory << std::endl;
		SetConsoleColor("Black");

		std::cout << "[" << Lang.Game << "]" << " " << Player.Nickname << " " << Lang.IsAliveWith << " "<< Player.Health << " " << Lang.Health << std::endl << std::endl;

		if(SaveBattleLog == "true")
		{
			File << "[" << Lang.Game << "]" << " " << Player.Nickname << " " << Lang.IsAliveWith << " " << Player.Health << " " << Lang.Health << std::endl;
			std::cout << "[" << Lang.Program << "]" << " " << Lang.BattleLogSavedTo << " " << LogFileName << ".txt" << std::endl;
		}
	}

	// if Player.Health < (player is dead) Enemy.Health then defeat
	if(Player.Health < Enemy.Health)
	{
		SetConsoleColor("Red");
		std::cout << "[" << Lang.Game << "]" << " " << Lang.Defeat << std::endl;
		SetConsoleColor("Black");

		std::cout << "[" << Lang.Game << "]" << " " << Enemy.Nickname << " " << Lang.IsAliveWith << " " << Enemy.Health << " " << Lang.Health << std::endl << std::endl;

		if(SaveBattleLog == "true")
		{
			File << "[" << Lang.Game << "]" << " " << Enemy.Nickname << " " << Lang.IsAliveWith << " " << Enemy.Health << " " << Lang.Health << std::endl;
			std::cout << "[" << Lang.Program << "]" << " " << Lang.BattleLogSavedTo << " " << LogFileName << ".txt" << std::endl;
		}
	}
}

#endif // _RESULT_H_
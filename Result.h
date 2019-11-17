#ifndef _RESULT_H_
#define _RESULT_H_

std::ofstream File;

void Result(string SavingBattleLog, string LoggingFileName)
{
	if(SavingBattleLog == "true")
	{
		File.open(LoggingFileName + ".txt", std::ios_base::app);
	}

	DisplaySleep();
	cout << endl;

	// if Player.Health > (player is alive) Enemy.Health then victory
	if(Player.Health > Enemy.Health)
	{
		SetConsoleColor("Green");
		cout << "[GAME] Victory" << endl;
		SetConsoleColor("Black");

		cout << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << endl << endl;

		if(SavingBattleLog == "true")
		{
			File << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << endl;
			cout << "[PROGRAM]" << " BattleLog saved to " << LoggingFileName << ".txt" << endl;
		}
	}

	// if Player.Health < (player is dead) Enemy.Health then defeat
	if(Player.Health < Enemy.Health)
	{
		SetConsoleColor("Red");
		cout << "[GAME] Defeat" << endl;
		SetConsoleColor("Black");

		cout << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << endl << endl;

		if(SavingBattleLog == "true")
		{
			File << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << endl;
			cout << "[PROGRAM]" << " BattleLog saved to " << LoggingFileName << ".txt" << endl << endl;
		}
	}
}

#endif // _RESULT_H_
#pragma once

#ifndef _MAIN_H_
#define _MAIN_H_

void MAIN()
{
	int EXIT = 0;
	int MightMinusDefence;

	// Setup player configs
	PlayerSetup();

	// Setup enemy configs
	EnemySetup();

	// Getting GetShowFullLog from Run
	string FakeGetBattleSpeed;
	string GetShowFullLog;

	// Reading GetShowFullLog from Run
	ofstream Run;
	ifstream ReadFromRun("Run.txt");
	getline(ReadFromRun, FakeGetBattleSpeed);
	getline(ReadFromRun, GetShowFullLog);
	Run.close();

	// Read only after =
	GetShowFullLog.erase(0, 14);

	while(EXIT == 0)
	{
		srand(time(0));
		Player.Crit = (rand() % Player.CritChance);
		Enemy.Crit = (rand() % Enemy.CritChance);

		//Player.Dodge = (rand() % Player.DodgeChange);

		// While Player.Health is more than 0 we're fighting 
		if(Player.Health > 0)
		{
			// If Enemy.Defence is more than 0 then Enemy.Health minus (Player.Might minus Enemy.Defence)
			if(Enemy.Defence > 0)
			{
				// Save Player.Might for reset
				Player.ResetMight = Player.Might;

				// If rand() got 0 it'll have crit
				if(Player.Crit == 0)
				{
					DisplaySleep();
					cout << endl;

					// Calc Player.CritMight
					Player.CritMight = Player.Might * Player.CritBonus;
					cout << "[" << Player.Nickname << "]" << " CritMight: " << Player.CritMight << endl;
				}

				// If rand() didn't get 0 it won't have crit
				else
				{
					DisplaySleep();
					cout << endl;
					Player.CritMight = 0;
					cout << "[" << Player.Nickname << "]" << " Might: " << Player.Might << endl;
				}

				cout << "[" << Player.Nickname << "]" << " Enemy.Health before attacked: " << Enemy.Health << endl;

				// Getting % by Enemy.Defence
				double MinusDefence = Enemy.Defence / 100;

				if(GetShowFullLog == "true")
				{
					cout << "[" << Player.Nickname << "]" << " Enemy.Defence: " << Enemy.Defence << "%" << endl;
				}

				if(Player.Crit == 0)
				{
					// Calc Player.CritMight after Enemy.Defence
					MightMinusDefence = Player.CritMight * MinusDefence;

					// Player.CritMight after Enemy.Defence
					Player.CritMight -= MightMinusDefence;

					if(GetShowFullLog == "true")
					{
						cout << "[" << Player.Nickname << "]" << " CritMight after Enemy.Defence: " << Player.CritMight << endl;
					}

					Enemy.Health -= Player.CritMight;
				}

				// If we didn't get crit
				else
				{
					// Calc Player.Might after Enemy.Defence
					MightMinusDefence = Player.Might * MinusDefence;

					// Player.Might after Enemy.Defence
					Player.Might -= MightMinusDefence;

					if(GetShowFullLog == "true")
					{
						cout << "[" << Player.Nickname << "]" << " Might after Enemy.Defence: " << Player.Might << endl;
					}

					Enemy.Health -= Player.Might;
				}

				// If Enemy.Health is 0 we won
				if(Enemy.Health <= 0)
				{
					EXIT = 1;
					Enemy.Health = 0;
				}

				// Reset Player.Might to default
				Player.Might = Player.ResetMight;

				cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;

				// Regen
				if(Enemy.Health != 0 && GetShowFullLog == "true")
				{
					cout << "[" << Player.Nickname << "]" << " Enemy.Health before regened: " << Enemy.Health << endl;
					cout << "[" << Player.Nickname << "]" << " Enemy.Regen: " << Enemy.Regen << endl;
					Enemy.Health += Enemy.Regen;
					cout << "[" << Player.Nickname << "]" << " Enemy.Health after regened: " << Enemy.Health << endl;
				}
			}

			// If Enemy.Defence is 0 then Enemy.Health minus Player.Might
			if(Enemy.Defence == 0)
			{
				// Save Player.Might for reset
				Player.ResetMight = Player.Might;

				if (Player.Crit == 0)
				{
					DisplaySleep();
					cout << endl;

					// Calc Player.CritMight
					Player.CritMight = Player.Might * Player.CritBonus;
					cout << "[" << Player.Nickname << "]" << " CritMight: " << Player.CritMight << endl;
				}
				else
				{
					DisplaySleep();
					cout << endl;
					Player.CritMight = 0;
					cout << "[" << Player.Nickname << "]" << " Might: " << Player.Might << endl;
				}

				cout << "[" << Player.Nickname << "]" << " Enemy.Health before attacked: " << Enemy.Health << endl;

				if(Player.Crit == 0)
				{
					Enemy.Health -= Player.CritMight;
				}

				// If we didn't get crit
				else
				{
					Enemy.Health -= Player.Might;
				}

				// If Enemy.Health is 0 we won
				if(Enemy.Health <= 0)
				{
					EXIT = 1;
					Enemy.Health = 0;
				}

				// Reset Player.Might to default
				Player.Might = Player.ResetMight;

				cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;

				// Regen
				if(Enemy.Health != 0)
				{
					cout << "[" << Player.Nickname << "]" << " Enemy.Health before regened: " << Enemy.Health << endl;
					cout << "[" << Player.Nickname << "]" << " Enemy.Regen: " << Enemy.Regen << endl;
					Enemy.Health += Enemy.Regen;
					cout << "[" << Player.Nickname << "]" << " Enemy.Health after regened: " << Enemy.Health << endl;
				}
			}
		}

		// While Enemy.Health is more than 0 we're fighting 
		if (Enemy.Health > 0)
		{
			// If Player.Defence is more than 0 then Player.Health minus (Enemy.Might minus Player.Defence)
			if(Player.Defence > 0)
			{
				// Save Enemy.Might for reset
				Enemy.ResetMight = Enemy.Might;

				// If rand() got 0 it'll have crit
				if(Enemy.Crit == 0)
				{
					DisplaySleep();
					cout << endl;

					// Calc Enemy.CritMight
					Enemy.CritMight = Enemy.Might * Enemy.CritBonus;
					cout << "[" << Enemy.Nickname << "]" << " CritMight: " << Enemy.CritMight << endl;
				}

				// If rand() didn't get 0 it won't have crit
				else
				{
					DisplaySleep();
					cout << endl;
					Enemy.CritMight = 0;
					cout << "[" << Enemy.Nickname << "]" << " Might: " << Enemy.Might << endl;
				}

				cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

				// Getting % by player.Defence 
				double MinusDefence = Player.Defence / 100;

				if(GetShowFullLog == "true")
				{
					cout << "[" << Enemy.Nickname << "]" << " Player.Defence: " << Player.Defence << "%" << endl;
				}

				if(Enemy.Crit == 0)
				{
					// Calc Enemy.CritMight after Player.Defence
					MightMinusDefence = Enemy.CritMight * MinusDefence;

					// Enemy.CritMight after player.Defence
					Enemy.CritMight -= MightMinusDefence;

					if (GetShowFullLog == "true")
					{
						cout << "[" << Enemy.Nickname << "]" << " CritMight after player.Defence: " << Enemy.CritMight << endl;
					}

					Player.Health -= Enemy.CritMight;
				}
				else
				{
					// Calc Enemy.Might after Player.Defence
					MightMinusDefence = Enemy.Might * MinusDefence;

					// Enemy.Might after Player.Defence
					Enemy.Might -= MightMinusDefence;

					if (GetShowFullLog == "true")
					{
						cout << "[" << Enemy.Nickname << "]" << " Might after Player.Defence: " << Enemy.Might << endl;
					}

					Player.Health -= Enemy.Might;
				}

				// If Player.Health is 0 we won
				if(Player.Health <= 0)
				{
					EXIT = 1;
					Player.Health = 0;
				}

				// Reset Enemy.Might to default
				Enemy.Might = Enemy.ResetMight;

				cout << "[" << Enemy.Nickname << "]" << " Player.Health after attacked: " << Player.Health << endl;

				// Regen
				if(Player.Health != 0 && GetShowFullLog == "true")
				{
					cout << "[" << Enemy.Nickname << "]" << " Player.Health before regened: " << Player.Health << endl;
					cout << "[" << Enemy.Nickname << "]" << " Player.Regen: " << Player.Regen << endl;
					Player.Health += Player.Regen;
					cout << "[" << Enemy.Nickname << "]" << " Player.Health after regened: " << Player.Health << endl;
				}
			}

			// If Enemy.Defence is 0 then Enemy.Health minus Player.Might
			if(Enemy.Defence == 0)
			{
				// Save Enemy.Might for reset
				Enemy.ResetMight = Enemy.Might;

				if(Enemy.Crit == 0)
				{
					DisplaySleep();
					cout << endl;

					// Calc Enemy.CritMight
					Enemy.CritMight = Enemy.Might * Enemy.CritBonus;
					cout << "[" << Enemy.Nickname << "]" << " CritMight: " << Enemy.CritMight << endl;
				}
				else
				{
					DisplaySleep();
					cout << endl;
					Enemy.CritMight = 0;
					cout << "[" << Enemy.Nickname << "]" << " Might: " << Enemy.Might << endl;
				}

				cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

				if(Enemy.Crit == 0)
				{
					Player.Health -= Enemy.CritMight;
				}

				// If we didn't get crit
				else
				{
					Player.Health -= Enemy.Might;
				}

				// If Enemy.Health is 0 we won
				if(Player.Health <= 0)
				{
					EXIT = 1;
					Player.Health = 0;
				}

				// Reset Enemy.Might to default
				Enemy.Might = Enemy.ResetMight;

				cout << "[" << Enemy.Nickname << "]" << " Player.Health after attacked: " << Player.Health << endl;

				// Regen
				if(Player.Health != 0)
				{
					cout << "[" << Enemy.Nickname << "]" << " Player.Health before regened: " << Player.Health << endl;
					cout << "[" << Enemy.Nickname << "]" << " Player.Regen: " << Player.Regen << endl;
					Player.Health += Player.Regen;
					cout << "[" << Enemy.Nickname << "]" << " Player.Health after regened: " << Player.Health << endl;
				}
			}
		}
		
	}

	// Only when Player.Health is more than Enemy.Health we'll win
	if(Player.Health > Enemy.Health)
	{
		DisplaySleep();
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << "[GAME] Victory" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << endl << endl;
	}

	// If Player.Health is 0 or Player.Health is 0 and Enemy.Health is 0 we won't win
	if(Player.Health < Enemy.Health)
	{
		DisplaySleep();
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "[GAME] Defeat" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << endl << endl;
	}
}

#endif
#pragma once

#ifndef _MAIN_H_
#define _MAIN_H_

using std::cout;
using std::endl;

void MAIN()
{
	int EXIT = 0;
	int MightMinusDefence;

	// Setup player configs
	SetupPlayer();

	// Setup enemy configs
	SetupEnemy();

	// Getting ShowFullLog from Run
	std::string FakeSetBattleSpeed;
	std::string ShowFullLog;

	// Reading ShowFullLog from Run
	std::ofstream Run;
	std::ifstream ReadFromRun("Run.txt");
	std::getline(ReadFromRun, FakeSetBattleSpeed);
	getline(ReadFromRun, ShowFullLog);
	Run.close();

	// Read only after =
	ShowFullLog.erase(0, 14);

	while(EXIT == 0)
	{
		srand(time(NULL));
		Player.Crit = rand() % Player.CritChance;
		Enemy.Crit = rand() % Enemy.CritChance;
		Player.Dodge = rand() % Player.DodgeChange;
		Enemy.Dodge = rand() % Enemy.DodgeChange;

		// While Player.Health is more than 0 we're fighting 
		if(Player.Health > 0 && Enemy.Dodge != 0)
		{
			// Save Player.Might for reset
			Player.ResetMight = Player.Might;

			DisplaySleep();
			cout << endl;

			// If rand() got 0 it'll have crit
			if(Player.Crit == 0)
			{
				// Setting Player.CritMight
				Player.CritMight = Player.Might * Player.CritBonus;
				cout << "[" << Player.Nickname << "]" << " CritMight: " << Player.CritMight << endl;
			}

			// If rand() didn't get 0 it won't have crit
			else
			{
				// Setting Player.CritMight
				Player.CritMight = 0;
				cout << "[" << Player.Nickname << "]" << " Might: " << Player.Might << endl;
			}

			cout << "[" << Player.Nickname << "]" << " Enemy.Health before attacked: " << Enemy.Health << endl;

			// Getting % by Enemy.Defence
			double MinusDefence = Enemy.Defence / 100;

			if(ShowFullLog == "true")
			{
				cout << "[" << Player.Nickname << "]" << " Enemy.Defence: " << Enemy.Defence << "%" << endl;
			}

			if(Player.Crit == 0)
			{
				// Calc Player.CritMight after Enemy.Defence
				MightMinusDefence = Player.CritMight * MinusDefence;

				// Player.CritMight after Enemy.Defence
				Player.CritMight -= MightMinusDefence;

				if(ShowFullLog == "true")
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

				if(ShowFullLog == "true")
				{
					cout << "[" << Player.Nickname << "]" << " Might after Enemy.Defence: " << Player.Might << endl;
				}

				Enemy.Health -= Player.Might;
			}

			// If Enemy.Health == 0 we won
			if(Enemy.Health <= 0)
			{
				EXIT = 1;
				Enemy.Health = 0;
			}

			// Reset Player.Might to default
			Player.Might = Player.ResetMight;

			cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;

			// Regen
			if(Enemy.Health != 0 && Enemy.Dodge != 0)
			{
				if(ShowFullLog == "true")
				{
					cout << "[" << Player.Nickname << "]" << " Enemy.Health before regened: " << Enemy.Health << endl;
					cout << "[" << Player.Nickname << "]" << " Enemy.Regen: " << Enemy.Regen << endl;
				}

				Enemy.Health += Enemy.Regen;

				if(ShowFullLog == "true")
				{
					cout << "[" << Player.Nickname << "]" << " Enemy.Health after regened: " << Enemy.Health << endl;
				}
			}
		}

		// If Enemy.Dodge == 0
		else
		{
			cout << endl;
			cout << "[" << Player.Nickname << "]" << " Enemy.Dodge" << endl;
		}

		// While Enemy.Health is more than 0 we're fighting 
		if(Enemy.Health > 0 && Player.Dodge != 0)
		{	
			// Save Enemy.Might for reset
			Enemy.ResetMight = Enemy.Might;

			DisplaySleep();
			cout << endl;

			// If rand() == 0 it'll have crit
			if(Enemy.Crit == 0)
			{
				// Setting Enemy.CritMight
				Enemy.CritMight = Enemy.Might * Enemy.CritBonus;
				cout << "[" << Enemy.Nickname << "]" << " CritMight: " << Enemy.CritMight << endl;
			}

			// If rand() != 0 it won't have crit
			else
			{
				// Setting Enemy.CritMight
				Enemy.CritMight = 0;
				cout << "[" << Enemy.Nickname << "]" << " Might: " << Enemy.Might << endl;
			}

			cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

			// Getting % by player.Defence 
			double MinusDefence = Player.Defence / 100;

			if(ShowFullLog == "true")
			{
				cout << "[" << Enemy.Nickname << "]" << " Player.Defence: " << Player.Defence << "%" << endl;
			}

			if(Enemy.Crit == 0)
			{
				// Calc Enemy.CritMight after Player.Defence
				MightMinusDefence = Enemy.CritMight * MinusDefence;

				// Enemy.CritMight after player.Defence
				Enemy.CritMight -= MightMinusDefence;

				if(ShowFullLog == "true")
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

				if(ShowFullLog == "true")
				{
					cout << "[" << Enemy.Nickname << "]" << " Might after Player.Defence: " << Enemy.Might << endl;
				}

				Player.Health -= Enemy.Might;
			}

			// If Player.Health == 0 we won
			if(Player.Health <= 0)
			{
				EXIT = 1;
				Player.Health = 0;
			}

			// Reset Enemy.Might to default
			Enemy.Might = Enemy.ResetMight;

			cout << "[" << Enemy.Nickname << "]" << " Player.Health after attacked: " << Player.Health << endl;

			// Regen
			if(Player.Health != 0 && Player.Dodge != 0)
			{
				if(ShowFullLog == "true")
				{
					cout << "[" << Enemy.Nickname << "]" << " Player.Health before regened: " << Player.Health << endl;
					cout << "[" << Enemy.Nickname << "]" << " Player.Regen: " << Player.Regen << endl;
				}

				Player.Health += Player.Regen;

				if(ShowFullLog == "true")
				{
					cout << "[" << Enemy.Nickname << "]" << " Player.Health after regened: " << Player.Health << endl;
				}
			}
		}

		// If Player.Dodge == 0
		else
		{
			cout << endl;
			cout << "[" << Enemy.Nickname << "]" << " Player.Dodge" << endl;
		}
	}

	DisplaySleep();
	cout << endl;

	// If Player.Health > Enemy.Health then victory
	if(Player.Health > Enemy.Health)
	{
		SetConsoleColor("Green");
		cout << "[GAME] Victory" << endl;
		SetConsoleColor("Black");
		cout << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << endl << endl;
	}

	// If Player.Health < Enemy.Health then defeat
	if(Player.Health < Enemy.Health)
	{
		SetConsoleColor("Red");
		cout << "[GAME] Defeat" << endl;
		SetConsoleColor("Black");
		cout << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << endl << endl;
	}
}

#endif
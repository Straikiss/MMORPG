#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

// add regen after taking damage

using namespace std;

void DisplaySleep()
{
	Sleep(100);
}

int main()
{
	int EXIT = 0;
	int MightMinusDefence;
	struct Stats
	{
		int Health;
		int Might;
		double Defence;
		int CritMight;
		int CritBonus;
		int CritChance;
		int Crit;
		int ResetMight;
		//int Regen;
		string Nickname;
	} Player, Enemy;

	Player.Health = 500;
	Player.Might = 100;
	Player.Defence = 50; // 10 - 10% 
	//Player.Regen = 50;
	Player.CritChance = 2; // 1 - 100% 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20% etc
	Player.CritBonus = 2; // 2 - * 2
					 					   
	Enemy.Health = 500;
	Enemy.Might = 100;
	Enemy.Defence = 50; // 0.50
	//Enemy.Regen = 50;
	Enemy.CritChance = 2; // 1 - 100% 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20% etc
	Enemy.CritBonus = 2; // 2 - * 2			

	// 1 is min CritBonus
	if(Player.CritBonus == 0)
	{
		Player.CritBonus = 1;
	}

	// 1 is min CritBonus
	if(Enemy.CritBonus == 0)
	{
		Enemy.CritBonus = 1;
	}

	// 70 - 70% is max
	if(Player.Defence > 70 )
	{
		Player.Defence = 70;
	}

	// 70 - 70% is max
	if(Enemy.Defence > 70)
	{
		Enemy.Defence = 70;
	}

	Player.Nickname = "Fire_mn_29";
	Enemy.Nickname = "Straikiss";

	while(EXIT == 0)
	{
		srand(time(0));
		Player.Crit = (rand() % Player.CritChance);
		Enemy.Crit = (rand() % Enemy.CritChance);

		// While Player.Health is more than 0 and Enemy.Health is more that 0 they're fighting
		if(Player.Health > 0 && Enemy.Health > 0)
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

				DisplaySleep();
				cout << "[" << Player.Nickname << "]" << " Enemy.Health before attacked: " << Enemy.Health << endl;

				// Getting % by Enemy.Defence
				double MinusDefence = Enemy.Defence / 100;

				cout << "[" << Player.Nickname << "]" << " Enemy.Defence: " << Enemy.Defence << "%" << endl;

				if(Player.Crit == 0)
				{
					// Calc Player.CritMight after Enemy.Defence
					MightMinusDefence = Player.CritMight * MinusDefence;

					// Player.CritMight after Enemy.Defence
					Player.CritMight -= MightMinusDefence;

					cout << "[" << Player.Nickname << "]" << " CritMight after Enemy.Defence: " << Player.CritMight << endl;

					Enemy.Health -= Player.CritMight;

					//Player.CritMight = Z2;
				}

				// If we didn't get crit
				else
				{
					// Calc Player.Might after Enemy.Defence
					MightMinusDefence = Player.Might * MinusDefence;

					// Player.Might after Enemy.Defence
					Player.Might -= MightMinusDefence;

					cout << "[" << Player.Nickname << "]" << " Might after Enemy.Defence: " << Player.Might << endl;

					Enemy.Health -= Player.Might;
				}

				// If Enemy.Health is 0 we won
				if (Enemy.Health <= 0)
				{
					EXIT = 1;
					Enemy.Health = 0;
				}

				// Reset Player.Might to default
				Player.Might = Player.ResetMight;

				cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;
			}

			// If Enemy.Defence is 0 then Enemy.Health minus Player.Might
			else
			{
				DisplaySleep();
				cout << "[" << Player.Nickname << "]" << " Enemy.Health before attacked: " << Enemy.Health << endl;

				if(Player.Crit == 0)
				{
					Enemy.Health -= Player.CritMight;
				}
				else
				{
					Enemy.Health -= Player.Might;
				}

				// If Enemy.Health is 0 we won
				if (Enemy.Health <= 0)
				{
					EXIT = 1;
					Enemy.Health = 0;
				}

				cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;
			}

			// If Player.Defence is more than 0 then Player.Health minus (Enemy.Might minus Player.Defence)
			if(Player.Defence > 0)
			{
				// Save Enemy.Might for reset
				Enemy.ResetMight = Enemy.Might;

				// If rand() got 0 it'll have crit
				if (Enemy.Crit == 0)
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

				DisplaySleep();

				cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

				// Getting % by player.Defence 
				double MinusDefence = Player.Defence / 100;

				cout << "[" << Enemy.Nickname << "]" << " Player.Defence: " << Player.Defence << "%" << endl;

				if (Enemy.Crit == 0)
				{
					// Calc Enemy.CritMight after Player.Defence
					MightMinusDefence = Enemy.CritMight * MinusDefence;

					// Enemy.CritMight after player.Defence
					Enemy.CritMight -= MightMinusDefence;

					cout << "[" << Enemy.Nickname << "]" << " CritMight after player.Defence: " << Enemy.CritMight << endl;

					Player.Health -= Enemy.CritMight;
				}
				else
				{
					// Calc Enemy.Might after Player.Defence
					MightMinusDefence = Enemy.Might * MinusDefence;

					// Enemy.Might after Player.Defence
					Enemy.Might -= MightMinusDefence;

					cout << "[" << Enemy.Nickname << "]" << " Might after Player.Defence: " << Enemy.Might << endl;

					Player.Health -= Enemy.Might;
				}

				// If Player.Health is 0 we won
				if (Player.Health <= 0)
				{
					EXIT = 1;
					Player.Health = 0;
				}

				// Reset Enemy.Might to default
				Enemy.Might = Enemy.ResetMight;

				cout << "[" << Enemy.Nickname << "]" << " Player.Health after attacked: " << Player.Health << endl;
			}

			// If Player.Defence is 0 then Player.Health minus Enemy.Might
			else
			{
				DisplaySleep();

				cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

				if (Enemy.Crit == 0)
				{
					Player.Health -= Enemy.CritMight;
				}
				else
				{
					Player.Health -= Enemy.Might;
				}

				// If Player.Health is 0 we won
				if (Player.Health <= 0)
				{
					EXIT = 1;
					Player.Health = 0;
				}

				cout << "[" << Enemy.Nickname << "]" << " Player.Health after attacked: " << Player.Health << endl;
			}
		}
	}

	// Only when Player.Health is more than Enemy.Health we'll win
	if(Player.Health > Enemy.Health)
	{
		DisplaySleep();
		cout << endl;
		cout << "[GAME] Victory" << endl;
		cout << "[GAME] " << Player.Nickname << " is alive with " << Player.Health << " Health" << endl << endl;
	}

	// If Player.Health is 0 or Player.Health is 0 and Enemy.Health is 0 we won't win
	else
	{
		DisplaySleep();
		cout << endl;
		cout << "[GAME] Defeat" << endl;
		cout << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << endl << endl;
	}

	system("pause");
	return 0;
}
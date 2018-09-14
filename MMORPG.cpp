#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

using namespace std;

void DisplaySleep()
{
	Sleep(250);
}

int main()
{
	int EXIT = 0;
	int MightMinusDefence;
	
	struct Stats
	{
		string Nickname;
		int Health;
		int Might;
		double Defence;
		int CritMight;
		int CritChance;
		int CritBonus;
		int Crit;
		int ResetMight;
	} Player, Enemy;

	// Getting Player.Stats from DBPlayer
	string GetPlayerNickname;
	string GetPlayerHealth;
	string GetPlayerMight;
	string GetPlayerDefence;
	string GetPlayerCritChance;
	string GetPlayerCritBonus;

	// Getting Enemy.Stats from DBEnemy
	string GetEnemyNickname;
	string GetEnemyHealth;
	string GetEnemyMight;
	string GetEnemyDefence;
	string GetEnemyCritChance;
	string GetEnemyCritBonus;

	// Reading Player.Stats from DBPlayer
	ofstream DBPlayer;
	ifstream ReadFromDBPlayer("DBPlayer.txt");
	getline(ReadFromDBPlayer, GetPlayerNickname);
	getline(ReadFromDBPlayer, GetPlayerHealth);
	getline(ReadFromDBPlayer, GetPlayerMight);
	getline(ReadFromDBPlayer, GetPlayerDefence);
	getline(ReadFromDBPlayer, GetPlayerCritChance);
	getline(ReadFromDBPlayer, GetPlayerCritBonus);
	DBPlayer.close();

	// Reading Enemy.Stats from DBEnemy
	ofstream DBEnemy;
	ifstream ReadFromDBEnemy("DBEnemy.txt");
	getline(ReadFromDBEnemy, GetEnemyNickname);
	getline(ReadFromDBEnemy, GetEnemyHealth);
	getline(ReadFromDBEnemy, GetEnemyMight);
	getline(ReadFromDBEnemy, GetEnemyDefence);
	getline(ReadFromDBEnemy, GetEnemyCritChance);
	getline(ReadFromDBEnemy, GetEnemyCritBonus);
	DBEnemy.close();

	// Read only after =
	GetPlayerNickname.erase(0, 18);
	GetPlayerHealth.erase(0, 16);
	GetPlayerMight.erase(0, 15);
	GetPlayerDefence.erase(0, 17);
	GetPlayerCritChance.erase(0, 20);
	GetPlayerCritBonus.erase(0, 19);

	// Read only after =
	GetEnemyNickname.erase(0, 17);
	GetEnemyHealth.erase(0, 15);
	GetEnemyMight.erase(0, 14);
	GetEnemyDefence.erase(0, 16);
	GetEnemyCritChance.erase(0, 19);
	GetEnemyCritBonus.erase(0, 18);

	// Setting stats from DBPlayer to Player.Stats
	Player.Nickname = GetPlayerNickname;
	istringstream(GetPlayerHealth) >> Player.Health;
	istringstream(GetPlayerMight) >> Player.Might;
	istringstream(GetPlayerDefence) >> Player.Defence;
	istringstream(GetPlayerCritChance) >> Player.CritChance;
	istringstream(GetPlayerCritBonus) >> Player.CritBonus;

	// Setting stats from DBPlayer to Player.Stats
	Enemy.Nickname = GetEnemyNickname;
	istringstream(GetEnemyHealth) >> Enemy.Health;
	istringstream(GetEnemyMight) >> Enemy.Might;
	istringstream(GetEnemyDefence) >> Enemy.Defence;
	istringstream(GetEnemyCritChance) >> Enemy.CritChance;
	istringstream(GetEnemyCritBonus) >> Enemy.CritBonus;

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

	cout << "Starting...";
	Sleep(2500);
	system("cls");

	while(EXIT == 0)
	{
		srand(time(0));
		Player.Crit = (rand() % Player.CritChance);
		Enemy.Crit = (rand() % Enemy.CritChance);

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
				if(Enemy.Health <= 0)
				{
					EXIT = 1;
					Enemy.Health = 0;
				}

				// Reset Player.Might to default
				Player.Might = Player.ResetMight;

				std::cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;
			}

			// If Enemy.Defence is 0 then Enemy.Health minus Player.Might
			if(Enemy.Defence == 0)
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
				if(Enemy.Health <= 0)
				{
					EXIT = 1;
					Enemy.Health = 0;
				}

				cout << "[" << Player.Nickname << "]" << " Enemy.Health after attacked: " << Enemy.Health << endl;
			}
		}

		// While Enemy.Health is more than 0 we're fighting 
		if(Enemy.Health > 0)
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

				DisplaySleep();

				cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

				// Getting % by player.Defence 
				double MinusDefence = Player.Defence / 100;

				cout << "[" << Enemy.Nickname << "]" << " Player.Defence: " << Player.Defence << "%" << endl;

				if(Enemy.Crit == 0)
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
				if(Player.Health <= 0)
				{
					EXIT = 1;
					Player.Health = 0;
				}

				// Reset Enemy.Might to default
				Enemy.Might = Enemy.ResetMight;

				cout << "[" << Enemy.Nickname << "]" << " Player.Health after attacked: " << Player.Health << endl;
			}

			// If Player.Defence is 0 then Player.Health minus Enemy.Might
			if(Player.Defence == 0)
			{
				DisplaySleep();

				cout << "[" << Enemy.Nickname << "]" << " Player.Health before attacked: " << Player.Health << endl;

				if(Enemy.Crit == 0)
				{
					Player.Health -= Enemy.CritMight;
				}
				else
				{
					Player.Health -= Enemy.Might;
				}

				// If Player.Health is 0 we won
				if(Player.Health <= 0)
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
	if(Player.Health < Enemy.Health)
	{
		DisplaySleep();
		cout << endl;
		cout << "[GAME] Defeat" << endl;
		cout << "[GAME] " << Enemy.Nickname << " is alive with " << Enemy.Health << " Health" << endl << endl;
	}

	system("pause");
	return 0;
}
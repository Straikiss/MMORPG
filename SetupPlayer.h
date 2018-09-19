#pragma once

#ifndef _SetupPlayer_H_
#define _SetupPlayer_H_

void PlayerSetup()
{
	// Getting Player.Stats from DBPlayer
	string GetPlayerNickname;
	string GetPlayerHealth;
	string GetPlayerMight;
	string GetPlayerDefence;
	string GetPlayerCritChance;
	string GetPlayerCritBonus;
	string GetPlayerRegen;

	// Reading Player.Stats from DBPlayer
	ofstream DBPlayer;
	ifstream ReadFromDBPlayer("DBPlayer.txt");
	getline(ReadFromDBPlayer, GetPlayerNickname);
	getline(ReadFromDBPlayer, GetPlayerHealth);
	getline(ReadFromDBPlayer, GetPlayerMight);
	getline(ReadFromDBPlayer, GetPlayerDefence);
	getline(ReadFromDBPlayer, GetPlayerCritChance);
	getline(ReadFromDBPlayer, GetPlayerCritBonus);
	getline(ReadFromDBPlayer, GetPlayerRegen);
	DBPlayer.close();

	// Read only after =
	GetPlayerNickname.erase(0, 18);
	GetPlayerHealth.erase(0, 16);
	GetPlayerMight.erase(0, 15);
	GetPlayerDefence.erase(0, 17);
	GetPlayerCritChance.erase(0, 20);
	GetPlayerCritBonus.erase(0, 19);
	GetPlayerRegen.erase(0, 15);

	// Setting stats from DBPlayer to Player.Stats
	Player.Nickname = GetPlayerNickname;
	istringstream(GetPlayerHealth) >> Player.Health;
	istringstream(GetPlayerMight) >> Player.Might;
	istringstream(GetPlayerDefence) >> Player.Defence;
	istringstream(GetPlayerCritChance) >> Player.CritChance;
	istringstream(GetPlayerCritBonus) >> Player.CritBonus;
	istringstream(GetPlayerRegen) >> Player.Regen;
	//Player.DodgeChange = 2;

	// 1 is min Health
	if(Player.Health == 0)
	{
		Player.Health = 100;
	}

	// 1 is min CritChance
	if(Player.CritChance == 0)
	{
		Player.CritChance = 1;
	}

	// 1 is min CritBonus
	if(Player.CritBonus == 0)
	{
		Player.CritBonus = 1;
	}

	// 70 - 70% is max
	if(Player.Defence > 70)
	{
		Player.Defence = 70;
	}
}

#endif
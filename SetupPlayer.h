#pragma once

#ifndef _SetupPlayer_H_
#define _SetupPlayer_H_

using std::string;
using std::istringstream;

void SetupPlayer()
{
	// Getting Player.Stats from DBPlayer
	string PlayerNickname;
	string PlayerHealth;
	string PlayerMight;
	string PlayerDefence;
	string PlayerCritChance;
	string PlayerCritBonus;
	string PlayerRegen;
	string PlayerDodgeChange;

	// Reading Player.Stats from DBPlayer
	std::ofstream DBPlayer;
	std::ifstream ReadFromDBPlayer("DBPlayer.txt");
	std::getline(ReadFromDBPlayer, PlayerNickname);
	getline(ReadFromDBPlayer, PlayerHealth);
	getline(ReadFromDBPlayer, PlayerMight);
	getline(ReadFromDBPlayer, PlayerDefence);
	getline(ReadFromDBPlayer, PlayerCritChance);
	getline(ReadFromDBPlayer, PlayerCritBonus);
	getline(ReadFromDBPlayer, PlayerRegen);
	getline(ReadFromDBPlayer, PlayerDodgeChange);
	DBPlayer.close();

	// Read only after =
	PlayerNickname.erase(0, 18);
	PlayerHealth.erase(0, 16);
	PlayerMight.erase(0, 15);
	PlayerDefence.erase(0, 17);
	PlayerCritChance.erase(0, 20);
	PlayerCritBonus.erase(0, 19);
	PlayerRegen.erase(0, 15);
	PlayerDodgeChange.erase(0, 21);

	// Setting stats from DBPlayer to Player.Stats
	Player.Nickname = PlayerNickname;
	istringstream(PlayerHealth) >> Player.Health;
	istringstream(PlayerMight) >> Player.Might;
	istringstream(PlayerDefence) >> Player.Defence;
	istringstream(PlayerCritChance) >> Player.CritChance;
	istringstream(PlayerCritBonus) >> Player.CritBonus;
	istringstream(PlayerRegen) >> Player.Regen;
	istringstream(PlayerDodgeChange) >> Player.DodgeChange;

	if(Player.Health == 0)
	{
		Player.Health = 100;
	}

	if(Player.Might == 0)
	{
		Player.Might = 10;
	}

	if(Player.Defence == 0)
	{
		Player.Defence = 1;
	}

	if(Player.Defence > 70)
	{
		Player.Defence = 70;
	}

	if(Player.CritChance == 0)
	{
		Player.CritChance = 1;
	}

	if(Player.CritBonus == 0)
	{
		Player.CritBonus = 1;
	}

	if(Player.Regen == 0)
	{
		Player.Regen = 5;
	}
}

#endif
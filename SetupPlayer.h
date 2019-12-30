#pragma once
#ifndef _SETUPPLAYER_H_
#define _SETUPPLAYER_H_

bool SetupPlayer()
{
	std::string PlayerNickname;
	std::string PlayerHealth;
	std::string PlayerMight;
	std::string PlayerDefence;
	std::string PlayerCritChance;
	std::string PlayerCritBonus;
	std::string PlayerRegen;
	std::string PlayerDodgeChange;
	std::string PlayerLifesteal;

	// reading player stats from Player.txt
	std::ifstream Read("Data/Player.txt");
	if(Read.is_open())
	{
		std::getline(Read, PlayerNickname);
		std::getline(Read, PlayerHealth);
		std::getline(Read, PlayerMight);
		std::getline(Read, PlayerDefence);
		std::getline(Read, PlayerCritChance);
		std::getline(Read, PlayerCritBonus);
		std::getline(Read, PlayerRegen);
		std::getline(Read, PlayerDodgeChange);
		std::getline(Read, PlayerLifesteal);

		// reading only after =
		PlayerNickname.erase(0, 11);
		PlayerHealth.erase(0, 9);
		PlayerMight.erase(0, 8);
		PlayerDefence.erase(0, 10);
		PlayerCritChance.erase(0, 13);
		PlayerCritBonus.erase(0, 12);
		PlayerRegen.erase(0, 8);
		PlayerDodgeChange.erase(0, 14);
		PlayerLifesteal.erase(0, 12);

		// setting stats from Player.txt to player
		Player.Nickname = PlayerNickname;
		std::istringstream(PlayerHealth) >> Player.Health;
		std::istringstream(PlayerMight) >> Player.Might;
		std::istringstream(PlayerDefence) >> Player.Defence;
		std::istringstream(PlayerCritChance) >> Player.CritChance;
		std::istringstream(PlayerCritBonus) >> Player.CritBonus;
		std::istringstream(PlayerRegen) >> Player.Regen;
		std::istringstream(PlayerDodgeChange) >> Player.DodgeChange;
		std::istringstream(PlayerLifesteal) >> Player.Lifesteal;

		return true;
	} 
	else 
	{
		return false;
	}

	// setting min and max value
	SetPlayerValue();
}

#endif // _SETUPPLAYER_H_
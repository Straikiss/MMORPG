#ifndef _SETUPPLAYER_H_
#define _SETUPPLAYER_H_

void SetupPlayer()
{
	string PlayerNickname;
	string PlayerHealth;
	string PlayerMight;
	string PlayerDefence;
	string PlayerCritChance;
	string PlayerCritBonus;
	string PlayerRegen;
	string PlayerDodgeChange;
	string PlayerLifesteal;

	// reading Player.Stats from DBPlayer
	std::ofstream DBPlayer;
	std::ifstream ReadFromDBPlayer("Player.txt");
	getline(ReadFromDBPlayer, PlayerNickname);
	getline(ReadFromDBPlayer, PlayerHealth);
	getline(ReadFromDBPlayer, PlayerMight);
	getline(ReadFromDBPlayer, PlayerDefence);
	getline(ReadFromDBPlayer, PlayerCritChance);
	getline(ReadFromDBPlayer, PlayerCritBonus);
	getline(ReadFromDBPlayer, PlayerRegen);
	getline(ReadFromDBPlayer, PlayerDodgeChange);
	getline(ReadFromDBPlayer, PlayerLifesteal);
	DBPlayer.close();

	// read only after =
	PlayerNickname.erase(0, 11);
	PlayerHealth.erase(0, 9);
	PlayerMight.erase(0, 8);
	PlayerDefence.erase(0, 10);
	PlayerCritChance.erase(0, 13);
	PlayerCritBonus.erase(0, 12);
	PlayerRegen.erase(0, 8);
	PlayerDodgeChange.erase(0, 14);
	PlayerLifesteal.erase(0, 12);

	// setting stats from DBPlayer to Player.Stats
	Player.Nickname = PlayerNickname;
	istringstream(PlayerHealth) >> Player.Health;
	istringstream(PlayerMight) >> Player.Might;
	istringstream(PlayerDefence) >> Player.Defence;
	istringstream(PlayerCritChance) >> Player.CritChance;
	istringstream(PlayerCritBonus) >> Player.CritBonus;
	istringstream(PlayerRegen) >> Player.Regen;
	istringstream(PlayerDodgeChange) >> Player.DodgeChange;
	istringstream(PlayerLifesteal) >> Player.Lifesteal;

	CheckOnEmpty("Player");
}

#endif // _SETUPPLAYER_H_
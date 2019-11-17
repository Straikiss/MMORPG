#ifndef _CONFIGS_H_
#define _CONFIGS_H_

struct Stats
{
	std::string Nickname;
	int Health;
	int Might;
	double Defence;
	int CritMight;
	int CritChance;
	int CritBonus;
	int Crit;
	int ResetMight;
	int Regen;
	int Dodge;
	int DodgeChange;
	double Lifesteal;
} Player, Enemy;

#endif // _CONFIGS_H_
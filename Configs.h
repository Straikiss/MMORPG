#pragma once
#ifndef _CONFIGS_H_
#define _CONFIGS_H_

void ERRORLOG(std::string ErrorText)
{
	SetConsoleColor("Red");
	std::cout << "[ERROR]";
	SetConsoleColor("Black");
	std::cout << " " << ErrorText << std::endl;
}

struct Stats
{
	std::string Nickname;
	int Health;
	int Might;
	double Defence;
	int CritChance;
	int CritBonus;
	int Regen;
	int DodgeChange;
	double Lifesteal;
	int Crit;
	int Dodge;
	int CritMight;
	int LifestealHealth;
	int ResetMight;
} Player, Enemy;

struct Lang
{
	std::string GotDodge;
	std::string CritMight;
	std::string Might;
	std::string HealthBeforeAttack;
	std::string Defence;
	std::string CritMightAfter;
	std::string HealthBeforeLifesteal;
	std::string Lifesteal;
	std::string HealthAfterLifesteal;
	std::string MightAfter;
	std::string HealthAfterAttack;
	std::string HealthBeforeRegen;
	std::string Regen;
	std::string HealthAfterRegen;
	std::string Victory;
	std::string Defeat;
	std::string IsAliveWith;
	std::string Health;
	std::string BattleLogSavedTo;
	std::string Game;
	std::string Program;
} Lang;

#endif // _CONFIGS_H_
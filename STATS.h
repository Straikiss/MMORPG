#pragma once

#ifndef _STATS_H_
#define _STATS_H_

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
} Player, Enemy;

#endif
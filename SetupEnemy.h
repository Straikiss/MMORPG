#pragma once

#ifndef _SetupEnemy_H_
#define _SetupEnemy_H_

void EnemySetup()
{
	// Getting Enemy.Stats from DBEnemy
	string GetEnemyNickname;
	string GetEnemyHealth;
	string GetEnemyMight;
	string GetEnemyDefence;
	string GetEnemyCritChance;
	string GetEnemyCritBonus;
	string GetEnemyRegen;

	// Reading Enemy.Stats from DBEnemy
	ofstream DBEnemy;
	ifstream ReadFromDBEnemy("DBEnemy.txt");
	getline(ReadFromDBEnemy, GetEnemyNickname);
	getline(ReadFromDBEnemy, GetEnemyHealth);
	getline(ReadFromDBEnemy, GetEnemyMight);
	getline(ReadFromDBEnemy, GetEnemyDefence);
	getline(ReadFromDBEnemy, GetEnemyCritChance);
	getline(ReadFromDBEnemy, GetEnemyCritBonus);
	getline(ReadFromDBEnemy, GetEnemyRegen);
	DBEnemy.close();

	// Read only after =
	GetEnemyNickname.erase(0, 17);
	GetEnemyHealth.erase(0, 15);
	GetEnemyMight.erase(0, 14);
	GetEnemyDefence.erase(0, 16);
	GetEnemyCritChance.erase(0, 19);
	GetEnemyCritBonus.erase(0, 18);
	GetEnemyRegen.erase(0, 14);

	// Setting stats from DBPlayer to Player.Stats
	Enemy.Nickname = GetEnemyNickname;
	istringstream(GetEnemyHealth) >> Enemy.Health;
	istringstream(GetEnemyMight) >> Enemy.Might;
	istringstream(GetEnemyDefence) >> Enemy.Defence;
	istringstream(GetEnemyCritChance) >> Enemy.CritChance;
	istringstream(GetEnemyCritBonus) >> Enemy.CritBonus;
	istringstream(GetEnemyRegen) >> Enemy.Regen;

	// 1 is min Health
	if(Enemy.Health == 0)
	{
		Enemy.Health = 100;
	}

	// 1 is min CritChance
	if(Enemy.CritChance == 0)
	{
		Enemy.CritChance = 1;
	}

	// 1 is min CritBonus
	if(Enemy.CritBonus == 0)
	{
		Enemy.CritBonus = 1;
	}

	// 70 - 70% is max
	if(Enemy.Defence > 70)
	{
		Enemy.Defence = 70;
	}
}

#endif
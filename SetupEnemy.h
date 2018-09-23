#pragma once

#ifndef _SetupEnemy_H_
#define _SetupEnemy_H_

using std::string;
using std::istringstream;

void SetupEnemy()
{
	// Getting Enemy.Stats from DBEnemy
	string EnemyNickname;
	string EnemyHealth;
	string EnemyMight;
	string EnemyDefence;
	string EnemyCritChance;
	string EnemyCritBonus;
	string EnemyRegen;
	string EnemyDodgeChange;

	// Reading Enemy.Stats from DBEnemy
	std::ofstream DBEnemy;
	std::ifstream ReadFromDBEnemy("DBEnemy.txt");
	std::getline(ReadFromDBEnemy, EnemyNickname);
	getline(ReadFromDBEnemy, EnemyHealth);
	getline(ReadFromDBEnemy, EnemyMight);
	getline(ReadFromDBEnemy, EnemyDefence);
	getline(ReadFromDBEnemy, EnemyCritChance);
	getline(ReadFromDBEnemy, EnemyCritBonus);
	getline(ReadFromDBEnemy, EnemyRegen);
	getline(ReadFromDBEnemy, EnemyDodgeChange);
	DBEnemy.close();

	// Read only after =
	EnemyNickname.erase(0, 17);
	EnemyHealth.erase(0, 15);
	EnemyMight.erase(0, 14);
	EnemyDefence.erase(0, 16);
	EnemyCritChance.erase(0, 19);
	EnemyCritBonus.erase(0, 18);
	EnemyRegen.erase(0, 14);
	EnemyDodgeChange.erase(0, 20);

	// Setting stats from DBPlayer to Enemy.Stats
	Enemy.Nickname = EnemyNickname;
	istringstream(EnemyHealth) >> Enemy.Health;
	istringstream(EnemyMight) >> Enemy.Might;
	istringstream(EnemyDefence) >> Enemy.Defence;
	istringstream(EnemyCritChance) >> Enemy.CritChance;
	istringstream(EnemyCritBonus) >> Enemy.CritBonus;
	istringstream(EnemyRegen) >> Enemy.Regen;
	istringstream(EnemyDodgeChange) >> Enemy.DodgeChange;

	if(Enemy.Health == 0)
	{
		Enemy.Health = 100;
	}

	if(Enemy.Might == 0)
	{
		Enemy.Might = 10;
	}

	if(Enemy.Defence == 0)
	{
		Enemy.Defence = 1;
	}

	if(Enemy.Defence > 70)
	{
		Enemy.Defence = 70;
	}

	if(Enemy.CritChance == 0)
	{
		Enemy.CritChance = 1;
	}

	if(Enemy.CritBonus == 0)
	{
		Enemy.CritBonus = 1;
	}

	if(Enemy.Regen == 0)
	{
		Enemy.Regen = 5;
	}
}

#endif
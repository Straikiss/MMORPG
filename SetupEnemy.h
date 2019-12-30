#pragma once
#ifndef _SETUPENEMY_H_
#define _SETUPENEMY_H_

bool SetupEnemy()
{
	std::string EnemyNickname;
	std::string EnemyHealth;
	std::string EnemyMight;
	std::string EnemyDefence;
	std::string EnemyCritChance;
	std::string EnemyCritBonus;
	std::string EnemyRegen;
	std::string EnemyDodgeChange;
	std::string EnemyLifesteal;

	// reading enemy stats from Enemy.txt
	std::ifstream Read("Data/Enemy.txt");
	if(Read.is_open()) 
	{
		std::getline(Read, EnemyNickname);
		std::getline(Read, EnemyHealth);
		std::getline(Read, EnemyMight);
		std::getline(Read, EnemyDefence);
		std::getline(Read, EnemyCritChance);
		std::getline(Read, EnemyCritBonus);
		std::getline(Read, EnemyRegen);
		std::getline(Read, EnemyDodgeChange);
		std::getline(Read, EnemyLifesteal);

		// reading only after =
		EnemyNickname.erase(0, 11);
		EnemyHealth.erase(0, 9);
		EnemyMight.erase(0, 8);
		EnemyDefence.erase(0, 10);
		EnemyCritChance.erase(0, 13);
		EnemyCritBonus.erase(0, 12);
		EnemyRegen.erase(0, 8);
		EnemyDodgeChange.erase(0, 14);
		EnemyLifesteal.erase(0, 12);

		// setting stats from Enemy.txt to enemy
		Enemy.Nickname = EnemyNickname;
		std::istringstream(EnemyHealth) >> Enemy.Health;
		std::istringstream(EnemyMight) >> Enemy.Might;
		std::istringstream(EnemyDefence) >> Enemy.Defence;
		std::istringstream(EnemyCritChance) >> Enemy.CritChance;
		std::istringstream(EnemyCritBonus) >> Enemy.CritBonus;
		std::istringstream(EnemyRegen) >> Enemy.Regen;
		std::istringstream(EnemyDodgeChange) >> Enemy.DodgeChange;
		std::istringstream(EnemyLifesteal) >> Enemy.Lifesteal;

		return true;
	}
	else 
	{
		return false;
	}

	// setting min and max value
	SetEnemyValue();
}

#endif // _SETUPENEMY_H_
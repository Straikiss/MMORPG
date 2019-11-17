#ifndef _SETUPENEMY_H_
#define _SETUPENEMY_H

void SetupEnemy()
{
	// getting Enemy.Stats from DBEnemy
	string EnemyNickname;
	string EnemyHealth;
	string EnemyMight;
	string EnemyDefence;
	string EnemyCritChance;
	string EnemyCritBonus;
	string EnemyRegen;
	string EnemyDodgeChange;
	string EnemyLifesteal;

	// reading Enemy.Stats from DBEnemy
	std::ofstream DBEnemy;
	std::ifstream ReadFromDBEnemy("Enemy.txt");
	std::getline(ReadFromDBEnemy, EnemyNickname);
	getline(ReadFromDBEnemy, EnemyHealth);
	getline(ReadFromDBEnemy, EnemyMight);
	getline(ReadFromDBEnemy, EnemyDefence);
	getline(ReadFromDBEnemy, EnemyCritChance);
	getline(ReadFromDBEnemy, EnemyCritBonus);
	getline(ReadFromDBEnemy, EnemyRegen);
	getline(ReadFromDBEnemy, EnemyDodgeChange);
	getline(ReadFromDBEnemy, EnemyLifesteal);
	DBEnemy.close();

	// read only after =
	EnemyNickname.erase(0, 11);
	EnemyHealth.erase(0, 9);
	EnemyMight.erase(0, 8);
	EnemyDefence.erase(0, 10);
	EnemyCritChance.erase(0, 13);
	EnemyCritBonus.erase(0, 12);
	EnemyRegen.erase(0, 8);
	EnemyDodgeChange.erase(0, 14);
	EnemyLifesteal.erase(0, 12);

	// setting stats from DBPlayer to Enemy.Stats
	Enemy.Nickname = EnemyNickname;
	istringstream(EnemyHealth) >> Enemy.Health;
	istringstream(EnemyMight) >> Enemy.Might;
	istringstream(EnemyDefence) >> Enemy.Defence;
	istringstream(EnemyCritChance) >> Enemy.CritChance;
	istringstream(EnemyCritBonus) >> Enemy.CritBonus;
	istringstream(EnemyRegen) >> Enemy.Regen;
	istringstream(EnemyDodgeChange) >> Enemy.DodgeChange;
	istringstream(EnemyLifesteal) >> Enemy.Lifesteal;

	CheckOnEmpty("Enemy");
}

#endif // _SETUPENEMY_H_
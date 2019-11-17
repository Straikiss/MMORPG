#ifndef _MAIN_H_
#define _MAIN_H_

void MAIN()
{
	int StopProgram;
	int IsEnemyDead;
	int IsPlayerDead;

	// setup configs for player and enemy
	SetupPlayer();
	SetupEnemy();

	// random number generator
	srand((unsigned int)time(NULL));

	do
	{
		// getting random % for stats
		Player.Crit = rand() % Player.CritChance;
		Enemy.Crit = rand() % Enemy.CritChance;
		Player.Dodge = rand() % Player.DodgeChange;
		Enemy.Dodge = rand() % Enemy.DodgeChange;

		// if enemy is dead - then finish this fight
		IsEnemyDead = PlayerFight(SetupRun("ShowFullLog"));

		// if player is dead - then finish this fight
		IsPlayerDead = EnemyFight(SetupRun("ShowFullLog"));

		// if enemy is dead or player is dead then stop program
		if(IsEnemyDead == 1 || IsPlayerDead == 1)
		{
			StopProgram = 1;
		}
	} 
	while(StopProgram != 1);

	// checking who's win
	Result(SetupRun("SaveBattleLog"), SetupRun("LogFileName"));
}

#endif // _MAIN_H_
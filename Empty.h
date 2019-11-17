#ifndef _EMPTY_H_
#define _EMPTY_H_

void CheckOnEmpty(string Nickname)
{
	// minimum and maximum of values that player and enemy can have
	// fix
	int MinHealth = 100;
	int MinMight = 10;
	int MinRegen = 5;
	int MinCritBonus = 1;
	int MinCritChance = 1;
	int MinLifesteal = 10;
	int MaxLifesteal = 50;
	int MinDefence = 10;
	int MaxDefence = 700;
	int MinDodgeChange = 10;
	int Zero = 0;

	if(Nickname == "Player")
	{
		if(Player.Nickname == " " || Player.Nickname == "")
		{
			Player.Nickname = "Player";
		}

		if(Player.Health == Zero)
		{
			Player.Health = MinHealth;
		}

		if(Player.Might == Zero)
		{
			Player.Might = MinMight;
		}

		if(Player.Defence == Zero)
		{
			Player.Defence = MinDefence;
		}

		if(Player.Defence > MaxDefence)
		{
			Player.Defence = MaxDefence;
		}

		if(Player.CritChance == Zero)
		{
			Player.CritChance = MinCritChance;
		}

		if(Player.CritBonus == Zero)
		{
			Player.CritBonus = MinCritBonus;
		}

		if(Player.Regen == Zero)
		{
			Player.Regen = MinRegen;
		}

		if(Player.Lifesteal == Zero)
		{
			Player.Lifesteal = MinLifesteal;
		}

		if(Player.Lifesteal > MaxLifesteal)
		{
			Player.Lifesteal = MaxLifesteal;
		}

		if(Player.DodgeChange == Zero)
		{
			Player.DodgeChange = MinDodgeChange;
		}
	}

	if(Nickname == "Enemy")
	{
		if(Enemy.Nickname == " " || Enemy.Nickname == "")
		{
			Enemy.Nickname = "Enemy";
		}

		if(Enemy.Health == Zero)
		{
			Enemy.Health = MinHealth;
		}

		if(Enemy.Might == Zero)
		{
			Enemy.Might = MinMight;
		}

		if(Enemy.Defence == Zero)
		{
			Enemy.Defence = MinDefence;
		}

		if(Enemy.Defence > MaxDefence)
		{
			Enemy.Defence = MaxDefence;
		}

		if(Enemy.CritChance == Zero)
		{
			Enemy.CritChance = MinCritChance;
		}

		if(Enemy.CritBonus == Zero)
		{
			Enemy.CritBonus = MinCritBonus;
		}

		if(Enemy.Regen == Zero)
		{
			Enemy.Regen = MinRegen;
		}

		if(Enemy.Lifesteal == Zero)
		{
			Enemy.Lifesteal = MinLifesteal;
		}

		if(Enemy.Lifesteal > MaxLifesteal)
		{
			Enemy.Lifesteal = MaxLifesteal;
		}

		if(Enemy.DodgeChange == Zero)
		{
			Enemy.DodgeChange = MinDodgeChange;
		}
	}
}

#endif // _CONFIGS_H_
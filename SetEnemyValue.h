#ifndef _SETENEMYVALUE_H_
#define _SETENEMYVALUE_H_

void SetEnemyValue()
{
	// minimum and maximum of values which enemy can have
	std::string ShowLogErrors = GetLogErrors();

	if(Enemy.Nickname.length() < 3)
	{
		Enemy.Nickname = DefaultEnemyNickname;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Nickname is too small, Enemy.Nickname was set by default nickname");
		}
	}

	if(Enemy.Nickname.length() > 15)
	{
		Enemy.Nickname = DefaultEnemyNickname;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Nickname is too large, Enemy.Nickname was set by default nickname");
		}
	}

	if(Enemy.Health < MinHealth)
	{
		Enemy.Health = MinHealth;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Health is too small, Enemy.Health was set by default with min value");
		}
	}

	if(Enemy.Health > MaxHealth)
	{
		Enemy.Health = MaxHealth;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Health is too large, Enemy.Health was set by default with max value");
		}
	}

	if(Enemy.Might < MinMight)
	{
		Enemy.Might = MinMight;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Might is too small, Enemy.Might was set by default with min value");
		}
	}

	if(Enemy.Might > MaxMight)
	{
		Enemy.Might = MaxMight;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Might is too large, Enemy.Might was set by default with max value");
		}
	}

	if(Enemy.Defence > MaxDefence)
	{
		Enemy.Defence = MaxDefence;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Defence is too large, Enemy.Defence was set by default with max value");
		}
	}

	if(Enemy.CritChance > MaxCritChance)
	{
		Enemy.CritChance = MaxCritChance;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.CritChance is too large, Enemy.CritChance was set by default with max value");
		}
	}

	if(Enemy.CritBonus == 1)
	{
		Enemy.CritBonus = 0;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.CritBonus isn't correct, Enemy.CritBonus was set by default with min value");
		}
	}

	if(Enemy.CritBonus > MaxCritBonus)
	{
		Enemy.CritBonus = MaxCritBonus;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.CritBonus is too large, Enemy.CritBonus was set by default with max value");
		}
	}

	if(Enemy.Regen > MaxRegen)
	{
		Enemy.Regen = MaxRegen;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Regen is too large, Enemy.Regen was set by default with max value");
		}
	}

	if(Enemy.DodgeChange == 1)
	{
		Enemy.DodgeChange = 0;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.DodgeChange isn't correct, Enemy.DodgeChange was set by default with min value");
		}
	}

	if(Enemy.DodgeChange > MaxDodgeChange)
	{
		Enemy.DodgeChange = MaxDodgeChange;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.DodgeChange is too large, Enemy.DodgeChange was set by default with max value");
		}
	}

	if(Enemy.Lifesteal > MaxLifesteal)
	{
		Enemy.Lifesteal = MaxLifesteal;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Enemy.Lifesteal is too large, Enemy.Lifesteal was set by default with max value");
		}
	}
}

#endif // _SETENEMYVALUE_H_
#pragma once
#ifndef _SETPLAYERVALUE_H_
#define _SETPLAYERVALUE_H_

void SetPlayerValue()
{
	// minimum and maximum of values which player can have
	std::string ShowLogErrors = GetLogErrors();

	if(Player.Nickname.length() < 3)
	{
		Player.Nickname = DefaultPlayerNickname;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Nickname is too small, Player.Nickname was set by default nickname");
		}
	}

	if(Player.Nickname.length() > 15)
	{
		Player.Nickname = DefaultPlayerNickname;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Nickname is too large, Player.Nickname was set by default nickname");
		}
	}

	if(Player.Health < MinHealth)
	{
		Player.Health = MinHealth;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Health is too small, Player.Health was set by default with min value");
		}
	}

	if(Player.Health > MaxHealth)
	{
		Player.Health = MaxHealth;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Health is too large, Player.Health was set by default with max value");
		}
	}

	if(Player.Might < MinMight)
	{
		Player.Might = MinMight;

		if (ShowLogErrors == "true")
		{
			ERRORLOG("Player.Might is too small, Player.Might was set by default with min value");
		}
	}

	if(Player.Might > MaxMight)
	{
		Player.Might = MaxMight;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Might is too large, Player.Might was set by default with max value");
		}
	}

	if(Player.Defence > MaxDefence)
	{
		Player.Defence = MaxDefence;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Defence is too large, Player.Defence was set by default with max value");
		}
	}

	if(Player.CritChance > MaxCritChance)
	{
		Player.CritChance = MaxCritChance;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.CritChance is too large, Player.CritChance was set by default with max value");
		}
	}

	if(Player.CritBonus == 0 || Player.CritBonus == 1)
	{
		Player.CritBonus = 2;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.CritBonus isn't correct, Player.CritBonus was set by default with min value");
		}
	}

	if(Player.CritBonus > MaxCritBonus)
	{
		Player.CritBonus = MaxCritBonus;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.CritBonus is too large, Player.CritBonus was set by default with max value");
		}
	}

	if(Player.Regen > MaxRegen)
	{
		Player.Regen = MaxRegen;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Regen is too large, Player.Regen was set by default with max value");
		}
	}

	if(Player.DodgeChange == 1)
	{
		Player.DodgeChange = 0;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.DodgeChange isn't correct, Player.DodgeChange was set by default with min value");
		}
	}

	if(Player.DodgeChange > MaxDodgeChange)
	{
		Player.DodgeChange = MaxDodgeChange;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.DodgeChange is too large, Player.DodgeChange was set by default with max value");
		}
	}

	if(Player.Lifesteal > MaxLifesteal)
	{
		Player.Lifesteal = MaxLifesteal;

		if(ShowLogErrors == "true")
		{
			ERRORLOG("Player.Lifesteal is too large, Player.Lifesteal was set by default with max value");
		}
	}
}

#endif // _SETPLAYERVALUE_H_
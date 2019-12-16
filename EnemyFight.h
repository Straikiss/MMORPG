#ifndef _ENEMYFIGHT_H_
#define _ENEMYFIGHT_H_

bool EnemyFight(std::string ShowFullLog)
{
	// if Enemy.Health > 0 (enemy isn't dead) && Player.Dodge == 1 (player got dodge) we don't hit player
	if(Enemy.Health > 0 && Player.Dodge == 1)
	{
		std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " got dodge" << std::endl;
	}

	if(Enemy.Health > 0 && Player.Health > 0 && Player.Dodge != 1)
	{
		DisplaySleep();
		std::cout << std::endl;

		// save Enemy.Might for reset after every fight
		Enemy.ResetMight = Enemy.Might;

		// if rand() got 1 enemy will have crit
		if(Enemy.Crit == 1)
		{
			// setting Enemy.CritMight with Enemy.CritBonus
			Enemy.CritMight = Enemy.Might * Enemy.CritBonus;
			std::cout << "[" << Enemy.Nickname << "]" << " crit might: " << Enemy.CritMight << std::endl;
		}
		else
		{
			std::cout << "[" << Enemy.Nickname << "]" << " might: " << Enemy.Might << std::endl;
		}

		std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health before attack: " << Player.Health << std::endl;

		if(ShowFullLog == "true")
		{
			std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " defence: " << Player.Defence << " = " << Player.Defence << "%" << std::endl;
		}

		// if rand() got 1 player will have crit
		if(Enemy.Crit == 1)
		{
			if(Player.Defence > 0)
			{
				// getting Enemy.Might after Player.Defence, getting % by Player.Defence to get less damage
				Enemy.CritMight -= (int)(Enemy.CritMight * (Player.Defence / 100));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " crit might after " << Player.Nickname << " defence: " << Enemy.CritMight << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " health before lifesteal: " << Enemy.Health << std::endl;
			}

			if(Enemy.Lifesteal > 0)
			{
				// calc Enemy.LifeSteel after crit might, getting % by Enemy.LifeSteel to regen after a hit
				Enemy.Health += (Enemy.LifestealHealth = (int)(Enemy.CritMight * (Enemy.Lifesteal / 100)));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " lifesteal: " << Enemy.LifestealHealth << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " health after lifesteal: " << Enemy.Health << std::endl;
			}

			Player.Health -= Enemy.CritMight;
		}
		else
		{
			if(Player.Defence > 0)
			{
				// getting Enemy.Might after Player.Defence, getting % by Player.Defence to get less damage
				Enemy.Might -= (int)(Enemy.Might * (Player.Defence / 100));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " might after " << Player.Nickname << " defence: " << Enemy.Might << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " health before lifesteal: " << Enemy.Health << std::endl;
			}

			if(Enemy.Lifesteal > 0)
			{
				// calc Enemy.LifeSteel after crit might, getting % by Enemy.LifeSteel to regen after a hit
				Enemy.Health += (Enemy.LifestealHealth = (int)(Enemy.Might * (Enemy.Lifesteal / 100)));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " lifesteal: " << Enemy.LifestealHealth << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " health after lifesteal: " << Enemy.Health << std::endl;
			}

			Player.Health -= Enemy.Might;
		}

		// reset Enemy.Might to default
		Enemy.Might = Enemy.ResetMight;

		if(Player.Health < 0)
		{
			Player.Health = 0;
		}

		std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health after attack: " << Player.Health << std::endl;

		// if Player.Health > 0 (player isn't dead)
		if(Player.Health > 0)
		{
			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health before regen: " << Player.Health << std::endl;
				std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " regen: " << Player.Regen << std::endl;
			}

			if(Player.Regen > 0)
			{
				// add regen health to enemy health
				Player.Health += Player.Regen;
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health after regen: " << Player.Health << std::endl;
			}
		}
	}

	// if Player.Health == 0 player is dead - stop fighting
	if(Player.Health == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // _ENEMYFIGHT_H_
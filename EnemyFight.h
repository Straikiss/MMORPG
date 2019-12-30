#pragma once
#ifndef _ENEMYFIGHT_H_
#define _ENEMYFIGHT_H_

bool EnemyFight(std::string ShowFullLog)
{
	DisplaySleep();

	// if Enemy.Health > 0 (enemy isn't dead) && Player.Dodge == 1 (player got dodge) we don't hit enemy
	if(Enemy.Health > 0 && Player.Dodge == 1)
	{
		std::cout << std::endl;
		std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.GotDodge << std::endl;
	}

	if(Enemy.Health > 0 && Player.Health > 0 && Player.Dodge != 1)
	{
		std::cout << std::endl;

		// save Enemy.Might for reset after every fight
		Enemy.ResetMight = Enemy.Might;

		// if rand() got 1 player will have crit
		if(Enemy.Crit == 1)
		{
			// setting Enemy.CritMight with Enemy.CritBonus
			Enemy.CritMight = Enemy.Might * Enemy.CritBonus;
			std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.CritMight << ": " << Enemy.CritMight << std::endl;
		}
		else
		{
			std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.Might << ": " << Enemy.Might << std::endl;
		}

		std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.HealthBeforeAttack << ": " << Player.Health << std::endl;

		if(ShowFullLog == "true")
		{
			std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.Defence << ": " << Player.Defence << " = " << Player.Defence << "%" << std::endl;
		}

		// if rand() got 1 enemy will have crit
		if(Enemy.Crit == 1)
		{
			if(Player.Defence > 0)
			{
				// getting Enemy.Might after Player.Defence, getting % by Player.Defence to get less damage
				Enemy.CritMight -= (int)(Enemy.CritMight * (Player.Defence / 100));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.CritMightAfter << " " << Player.Nickname << " " << Lang.Defence << ": " << Enemy.CritMight << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.HealthBeforeLifesteal << ": " << Enemy.Health << std::endl;
			}

			if(Enemy.Lifesteal > 0)
			{
				// getting Enemy.LifeSteel after crit might, getting % by Enemy.LifeSteel to regen after a hit
				Enemy.Health += (Enemy.LifestealHealth = (int)(Enemy.CritMight * (Enemy.Lifesteal / 100)));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.Lifesteal << ": " << Enemy.LifestealHealth << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.HealthAfterLifesteal << ": " << Enemy.Health << std::endl;
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
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.MightAfter << " " << Player.Nickname << " " << Lang.Defence << ": " << Enemy.Might << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.HealthBeforeLifesteal << ": " << Enemy.Health << std::endl;
			}

			if(Enemy.Lifesteal > 0)
			{
				// getting Enemy.LifeSteel after crit might, getting % by Enemy.LifeSteel to regen after a hit
				Enemy.Health += (Enemy.LifestealHealth = (int)(Enemy.Might * (Enemy.Lifesteal / 100)));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.Lifesteal << ": " << Enemy.LifestealHealth << std::endl;
				std::cout << "[" << Enemy.Nickname << "]" << " " << Lang.HealthAfterLifesteal << ": " << Enemy.Health << std::endl;
			}

			Player.Health -= Enemy.Might;
		}

		// reset Enemy.Might to default
		Enemy.Might = Enemy.ResetMight;

		if(Player.Health < 0)
		{
			Player.Health = 0;
		}

		std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.HealthAfterAttack << ": " << Player.Health << std::endl;

		// if Player.Health > 0 (player isn't dead)
		if(Player.Health > 0)
		{
			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.HealthBeforeRegen << ": " << Player.Health << std::endl;
				std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.Regen << ": " << Player.Regen << std::endl;
			}

			if(Player.Regen > 0)
			{
				// add regen health to player health
				Player.Health += Player.Regen;
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " " << Lang.HealthAfterRegen << ": " << Player.Health << std::endl;
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

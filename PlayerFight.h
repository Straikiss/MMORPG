#pragma once
#ifndef _PLAYERFIGHT_H_
#define _PLAYERFIGHT_H_

bool PlayerFight(std::string ShowFullLog)
{
	DisplaySleep();

	// if Player.Health > 0 (player isn't dead) && Enemy.Dodge == 1 (enemy got dodge) we don't hit enemy
	if(Player.Health > 0 && Enemy.Dodge == 1)
	{
		std::cout << std::endl;
		std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.GotDodge << std::endl;
	}

	if(Player.Health > 0 && Enemy.Health > 0 && Enemy.Dodge != 1)
	{
		std::cout << std::endl;

		// save Player.Might for reset after every fight
		Player.ResetMight = Player.Might;

		// if rand() got 1 player will have crit
		if(Player.Crit == 1)
		{
			// setting Player.CritMight with Player.CritBonus
			Player.CritMight = Player.Might * Player.CritBonus;
			std::cout << "[" << Player.Nickname << "]" << " " << Lang.CritMight << ": " << Player.CritMight << std::endl;
		}
		else
		{
			std::cout << "[" << Player.Nickname << "]" << " " << Lang.Might << ": " << Player.Might << std::endl;
		}

		std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.HealthBeforeAttack << ": " << Enemy.Health << std::endl;

		if(ShowFullLog == "true")
		{
			std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.Defence << ": " << Enemy.Defence << " = " << Enemy.Defence << "%" << std::endl;
		}

		// if rand() got 1 player will have crit
		if(Player.Crit == 1)
		{
			if(Enemy.Defence > 0)
			{
				// getting Player.Might after Enemy.Defence, getting % by Enemy.Defence to get less damage
				Player.CritMight -= (int)(Player.CritMight * (Enemy.Defence / 100));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.CritMightAfter << " " << Enemy.Nickname << " " << Lang.Defence << ": " << Player.CritMight << std::endl;
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.HealthBeforeLifesteal << ": " << Player.Health << std::endl;
			}

			if(Player.Lifesteal > 0)
			{
				// getting Player.LifeSteel after crit might, getting % by Player.LifeSteel to regen after a hit
				Player.Health += (Player.LifestealHealth = (int)(Player.CritMight * (Player.Lifesteal / 100)));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Player.Nickname << "]" << " "  << Lang.Lifesteal << ": "<< Player.LifestealHealth << std::endl;
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.HealthAfterLifesteal << ": " << Player.Health << std::endl;
			}

			Enemy.Health -= Player.CritMight;
		}
		else
		{
			if(Enemy.Defence > 0)
			{
				// getting Player.Might after Enemy.Defence, getting % by Enemy.Defence to get less damage
				Player.Might -= (int)(Player.Might * (Enemy.Defence / 100));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.MightAfter << " " << Enemy.Nickname << " " << Lang.Defence << ": " << Player.Might << std::endl;
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.HealthBeforeLifesteal << ": " << Player.Health << std::endl;
			}

			if(Player.Lifesteal > 0)
			{
				// getting Player.LifeSteel after crit might, getting % by Player.LifeSteel to regen after a hit
				Player.Health += (Player.LifestealHealth = (int)(Player.Might * (Player.Lifesteal / 100)));
			}

			if(ShowFullLog == "true")
			{
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.Lifesteal << ": " << Player.LifestealHealth << std::endl;
				std::cout << "[" << Player.Nickname << "]" << " " << Lang.HealthAfterLifesteal << ": " << Player.Health << std::endl;
			}

			Enemy.Health -= Player.Might;
		}

		// reset Player.Might to default
		Player.Might = Player.ResetMight;

		if(Enemy.Health < 0)
		{
			Enemy.Health = 0;
		}

		std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.HealthAfterAttack << ": " << Enemy.Health << std::endl;

		// if Enemy.Health > 0 (enemy isn't dead)
		if(Enemy.Health > 0)
		{
			if(ShowFullLog == "true")
			{
				std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.HealthBeforeRegen << ": " << Enemy.Health << std::endl;
				std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.Regen << ": " << Enemy.Regen << std::endl;
			}

			if(Enemy.Regen > 0)
			{
				// add regen health to enemy health
				Enemy.Health += Enemy.Regen;
			}
			
			if(ShowFullLog == "true")
			{
				std::cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " " << Lang.HealthAfterRegen << ": " << Enemy.Health << std::endl;
			}
		}
	}

	// if Enemy.Health == 0 enemy is dead - stop fighting
	if(Enemy.Health == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // _PLAYERFIGHT_H_
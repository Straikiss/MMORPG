#ifndef _PLAYERFIGHT_H_
#define _PLAYERFIGHT_H_

int PlayerFight(string ShowFullLog)
{
	int BattleResult;
	int MightMinusDefence;
	int LifestealHealth;
	double MinusDefence;
	double LifestealWithHit;
	int IsTrue = 0;

	// if Player.Health > 0 (player isn't dead) && Enemy.Dodge == 0 (enemy got dodge) we don't hit enemy
	if(Player.Health != IsTrue && Enemy.Dodge == IsTrue)
	{
		cout << endl;
		cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " got dodge" << endl;
	}

	if(Player.Health > IsTrue && Enemy.Health > IsTrue && Enemy.Dodge != IsTrue)
	{
		// save Player.Might for reset after fight
		Player.ResetMight = Player.Might;

		DisplaySleep();
		cout << endl;

		// if rand() got 0 it'll have crit
		if(Player.Crit == IsTrue)
		{
			// setting Player.CritMight
			Player.CritMight = Player.Might * Player.CritBonus;
			cout << "[" << Player.Nickname << "]" << " crit might: " << Player.CritMight << endl;
		}

		// if rand() didn't get 0 it won't have crit
		else
		{
			// Setting Player.CritMight
			Player.CritMight = IsTrue;
			cout << "[" << Player.Nickname << "]" << " might: " << Player.Might << endl;
		}

		cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " health before attack: " << Enemy.Health << endl;

		// getting % by Enemy.Defence to get less damage
		MinusDefence = Enemy.Defence / 1000;

		// getting % by Player.LifeSteel to regen after a hit
		LifestealWithHit = Player.Lifesteal / 100;

		if(ShowFullLog == "true")
		{
			// fix
			cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " defence: " << Enemy.Defence << " = " << Enemy.Defence / 10 << "%" << endl;
		}

		if(Player.Crit == 0)
		{
			// getting Player.CritMight after Enemy.Defence
			MightMinusDefence = Player.CritMight * MinusDefence;

			// player.CritMight after Enemy.Defence
			Player.CritMight -= MightMinusDefence;

			// calc Player.LifeSteel after crit might
			LifestealHealth = Player.CritMight * LifestealWithHit;
			cout << "LifestealHealth: " << LifestealHealth;

			// fix
			if(ShowFullLog == "true")
			{
				cout << "[" << Player.Nickname << "]" << " crit might after " << Enemy.Nickname << " defence: " << Player.CritMight << endl;
				//cout << "[" << Player.Nickname << "]" <<  << endl;
			}

			Enemy.Health -= Player.CritMight;
		}

		// if we didn't get crit
		else
		{
			// calc Player.Might after Enemy.Defence
			MightMinusDefence = Player.Might * MinusDefence;

			// calc Player.LifeSteel after might
			LifestealHealth = Player.Might * LifestealWithHit;
			cout << "LifestealHealth: " << LifestealHealth;

			// Player.Might after Enemy.Defence
			Player.Might -= MightMinusDefence;

			if(ShowFullLog == "true")
			{
				cout << "[" << Player.Nickname << "]" << " might after " << Enemy.Nickname << " defence: " << Player.Might << endl;
			}

			Enemy.Health -= Player.Might;
		}

		// reset Player.Might to default
		Player.Might = Player.ResetMight;

		// if Enemy.Health != 0 (enemy isn't dead)
		if(Enemy.Health > IsTrue)
		{
			cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " health after attack: " << Enemy.Health << endl;

			if(ShowFullLog == "true")
			{
				cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " health before regen: " << Enemy.Health << endl;
				cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " regen: " << Enemy.Regen << endl;
			}

			// add regen health to enemy health
			Enemy.Health += Enemy.Regen;

			if(ShowFullLog == "true")
			{
				cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " health after regen: " << Enemy.Health << endl;
			}
		}
		else
		{
			Enemy.Health = IsTrue;
			cout << "[" << Player.Nickname << "] " << Enemy.Nickname << " health after attack: " << Enemy.Health << endl;
		}
	}

	// if Enemy.Health == 0 we won
	if(Enemy.Health <= IsTrue)
	{
		// enemy is dead - stop fighting
		Enemy.Health = IsTrue;
		BattleResult = 1;
	}

	return BattleResult;
}

#endif // _PLAYERFIGHT_H_
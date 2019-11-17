#ifndef _ENEMYFIGHT_H_
#define _ENEMYFIGHT_H_

int EnemyFight(string ShowFullLog)
{
	int BattleResult;
	int MightMinusDefence;

	// if Enemy.Health > 0 (enemy isn't dead) && Player.Dodge == 0 (player got dodge) we don't hit player
	if(Enemy.Health != 0 && Player.Dodge == 0)
	{
		cout << endl;
		cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " got dodge" << endl;
	}

	if(Enemy.Health > 0 && Player.Health > 0 && Player.Dodge != 0)
	{
		// save Enemy.Might for reset
		Enemy.ResetMight = Enemy.Might;

		DisplaySleep();
		cout << endl;

		// if rand() == 0 it'll have crit
		if(Enemy.Crit == 0)
		{
			// setting Enemy.CritMight
			Enemy.CritMight = Enemy.Might * Enemy.CritBonus;
			cout << "[" << Enemy.Nickname << "]" << " crit might: " << Enemy.CritMight << endl;
		}

		// if rand() != 0 it won't have crit
		else
		{
			// setting Enemy.CritMight
			Enemy.CritMight = 0;
			cout << "[" << Enemy.Nickname << "]" << " might: " << Enemy.Might << endl;
		}

		cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health before attack: " << Player.Health << endl;

		// getting % by player.Defence 
		// double MinusDefence = Player.Defence / 100;
		double MinusDefence = Player.Defence / 1000;

		if(ShowFullLog == "true")
		{
			cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " defence: " << Player.Defence / 10 << "%" << endl;
		}

		if(Enemy.Crit == 0)
		{
			// calc Enemy.CritMight after Player.Defence
			MightMinusDefence = Enemy.CritMight * MinusDefence;

			// enemy.CritMight after player.Defence
			Enemy.CritMight -= MightMinusDefence;

			if(ShowFullLog == "true")
			{
				cout << "[" << Enemy.Nickname << "]" << " crit might after " << Player.Nickname << " defence: " << Enemy.CritMight << endl;
			}

			Player.Health -= Enemy.CritMight;
		}
		else
		{
			// calc Enemy.Might after Player.Defence
			MightMinusDefence = Enemy.Might * MinusDefence;

			// Enemy.Might after Player.Defence
			Enemy.Might -= MightMinusDefence;

			if(ShowFullLog == "true")
			{
				cout << "[" << Enemy.Nickname << "]" << " might after " << Player.Nickname << " defence: " << Enemy.Might << endl;
			}

			Player.Health -= Enemy.Might;
		}

		// reset Enemy.Might to default
		Enemy.Might = Enemy.ResetMight;

		// if Enemy.Health != 0 (player isn't dead)
		if(Player.Health > 0)
		{
			cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health after attack: " << Player.Health << endl;

			if(ShowFullLog == "true")
			{
				cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health before regen: " << Player.Health << endl;
				cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " regen: " << Player.Regen << endl;
			}

			// add regen health to player health
			Player.Health += Player.Regen;

			if(ShowFullLog == "true")
			{
				cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health after regen: " << Player.Health << endl;
			}
		}
		else
		{
			Player.Health = 0;
			cout << "[" << Enemy.Nickname << "] " << Player.Nickname << " health after attack: " << Player.Health << endl;
		}
	}

	// if Player.Health == 0 we won
	if(Player.Health <= 0)
	{
		// player is dead - stop fighting
		BattleResult = 1;
		Player.Health = 0;
	}

	return BattleResult;
}

#endif // _ENEMYFIGHT_H_
#pragma once
#ifndef _LANG_H_
#define _LANG_H_

bool SetLangEN()
{
	std::ifstream Read("Lang/en_lang.txt");
	if(Read.is_open())
	{
		std::getline(Read, Lang.GotDodge);
		std::getline(Read, Lang.CritMight);
		std::getline(Read, Lang.Might);
		std::getline(Read, Lang.HealthBeforeAttack);
		std::getline(Read, Lang.Defence);
		std::getline(Read, Lang.CritMightAfter);
		std::getline(Read, Lang.HealthBeforeLifesteal);
		std::getline(Read, Lang.Lifesteal);
		std::getline(Read, Lang.HealthAfterLifesteal);
		std::getline(Read, Lang.MightAfter);
		std::getline(Read, Lang.HealthAfterAttack);
		std::getline(Read, Lang.HealthBeforeRegen);
		std::getline(Read, Lang.Regen);
		std::getline(Read, Lang.HealthAfterRegen);
		std::getline(Read, Lang.Victory);
		std::getline(Read, Lang.Defeat);
		std::getline(Read, Lang.IsAliveWith);
		std::getline(Read, Lang.Health);
		std::getline(Read, Lang.BattleLogSavedTo);
		std::getline(Read, Lang.Game);
		std::getline(Read, Lang.Program);

		// read only after =
		Lang.GotDodge.erase(0, 16);
		Lang.CritMight.erase(0, 17);
		Lang.Might.erase(0, 13);
		Lang.HealthBeforeAttack.erase(0, 26);
		Lang.Defence.erase(0, 15);
		Lang.CritMightAfter.erase(0, 22);
		Lang.HealthBeforeLifesteal.erase(0, 29);
		Lang.Lifesteal.erase(0, 17);
		Lang.HealthAfterLifesteal.erase(0, 28);
		Lang.MightAfter.erase(0, 18);
		Lang.HealthAfterAttack.erase(0, 25);
		Lang.HealthBeforeRegen.erase(0, 25);
		Lang.Regen.erase(0, 13);
		Lang.HealthAfterRegen.erase(0, 25);
		Lang.Victory.erase(0, 15);
		Lang.Defeat.erase(0, 14);
		Lang.IsAliveWith.erase(0, 19);
		Lang.Health.erase(0, 14);
		Lang.BattleLogSavedTo.erase(0, 24);
		Lang.Game.erase(0, 12);
		Lang.Program.erase(0, 15);

		return true;
	}
	else
	{
		return false;
	}
}

#endif // _LANG_H_
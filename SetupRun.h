#pragma once
#ifndef _SETUPRUN_H_
#define _SETUPRUN_H_

const std::string DefaultEnemyNickname = "Enemy";
const std::string DefaultPlayerNickname = "Player";

const int MinHealth = 300;
const int MaxHealth = 5000;

const int MinMight = 50;
const int MaxMight = 1000;

// 0 - 0% reduce might, 70 - 70% (max)
const int MaxDefence = 70;

// 0 - 0%, 1 - 100%, 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20%
const int MaxCritChance = 5;

// 0 = x0 might (cant be), 1 = x1 might (cant be), 2 = x2 might, 5 = x5 might (max)
const int MaxCritBonus = 5;

const int MaxRegen = 50;

// 0 - 0%, 1 - 100% (cant be), 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20%
const int MaxDodgeChange = 5;

// 0 - 0% 100 - 100% (max)
// Might/CritMight * Lifesteal, 200 * (MaxLifesteal / 100) = 200 * 1 = 200 
const int MaxLifesteal = 100;

// getting ShowFullLog from Run
std::string FakeSetBattleSpeed;
std::string ShowFullLog;
std::string SaveBattleLog;
std::string LogFileName;
std::string LogErrors;
std::string SetLang;

bool SetupRun()
{
	std::ifstream Read("Data/Run.txt");
	if(Read.is_open())
	{
		std::getline(Read, FakeSetBattleSpeed);
		std::getline(Read, ShowFullLog);
		std::getline(Read, SaveBattleLog);
		std::getline(Read, LogFileName);
		std::getline(Read, LogErrors);
		std::getline(Read, SetLang);

		// read only after =
		ShowFullLog.erase(0, 14);
		SaveBattleLog.erase(0, 16);
		LogFileName.erase(0, 14);
		LogErrors.erase(0, 12);
		SetLang.erase(0, 11);

		return true;
	}
	else
	{
		return false;
	}

	if(SetLang == "en")
	{
		SetLangEN();
	}
	else
	{
		ERRORLOG("Language isn't correct, Language was set by default");
		SetLangEN();
	}
}

std::string GetShowFullLog()
{
	return ShowFullLog;
}

std::string GetSaveBattleLog()
{
	return SaveBattleLog;
}

std::string GetLogFileName()
{
	return LogFileName;
}

std::string GetLogErrors()
{
	return LogErrors;
}

#endif // _SETUP_H_
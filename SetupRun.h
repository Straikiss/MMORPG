#ifndef _SETUPRUN_H_
#define _SETUPRUN_H_

std::string DefaultEnemyNickname = "Enemy";
std::string DefaultPlayerNickname = "Player";

int MinHealth = 300;
int MaxHealth = 5000;

int MinMight = 50;
int MaxMight = 1000;

// 0 - 0% reduce might, 70 - 70% (max)
int MaxDefence = 70;

// 0 - 0%, 1 - 100%, 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20%
int MaxCritChance = 5;

// 0 = x0 might (cant be), 1 = x1 might (cant be), 2 = x2 might, 5 = x5 might (max)
int MaxCritBonus = 5;

int MaxRegen = 50;

// 0 - 0%, 1 - 100% (cant be), 2 - 50%, 3 - 33%, 4 - 25%, 5 - 20%
int MaxDodgeChange = 5;

// 0 - 0% 100 - 100% (max)
// Might/CritMight * Lifesteal, 200 * (MaxLifesteal / 100) = 200 * 1 = 200 
int MaxLifesteal = 100;

// getting ShowFullLog from Run
std::string FakeSetBattleSpeed;
std::string ShowFullLog;
std::string SaveBattleLog;
std::string LogFileName;
std::string LogErrors;

void ERRORLOG(std::string ErrorText)
{
	SetConsoleColor("Red");
	std::cout << "[ERROR]";
	SetConsoleColor("Black");
	std::cout << " " << ErrorText << std::endl;
}

void CheckSetupRun()
{
	std::ifstream Read("Data/Run.txt");
	if(Read.is_open())
	{
		std::getline(Read, FakeSetBattleSpeed);
		std::getline(Read, ShowFullLog);
		std::getline(Read, SaveBattleLog);
		std::getline(Read, LogFileName);
		std::getline(Read, LogErrors);

		// read only after =
		ShowFullLog.erase(0, 14);
		SaveBattleLog.erase(0, 16);
		LogFileName.erase(0, 14);
		LogErrors.erase(0, 12);
	}
	else
	{
		ERRORLOG("Run.txt wasn't found, Run.txt was set by default stats");
		ShowFullLog = "false";
		SaveBattleLog = "false";
		LogFileName = "LOGFILE";
		LogErrors = "false";
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
#ifndef _DISPLAYSLEEP_H_
#define _DISPLAYSLEEP_H_

void DisplaySleep()
{
	std::string SetBattleSpeed;

	// reading SetBattleSpeed from Run
	std::ifstream Read("Data/Run.txt");
	if(Read.is_open())
	{
		std::getline(Read, SetBattleSpeed);

		// read only after =
		SetBattleSpeed.erase(0, 14);
	} 
	else 
	{
		ERRORLOG("Run.txt wasn't found, Run.txt was set by default stats");
		Sleep(300);
	}

	if(SetBattleSpeed == "turbo")
	{
		Sleep(0);
	}

	if(SetBattleSpeed == "fast")
	{
		Sleep(150);
	}

	if(SetBattleSpeed == "normal")
	{
		Sleep(300);
	}

	if(SetBattleSpeed == "slow")
	{
		Sleep(600);
	}
}

#endif // _DISPLAYSLEEP_H_
#pragma once
#ifndef _DISPLAYSLEEP_H_
#define _DISPLAYSLEEP_H_

void DisplaySleep()
{
	std::string SetBattleSpeed;

	// reading SetBattleSpeed from Run
	std::ifstream Read("Data/Run.txt");
	
	std::getline(Read, SetBattleSpeed);

	// read only after =
	SetBattleSpeed.erase(0, 14);

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
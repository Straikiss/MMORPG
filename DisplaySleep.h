#ifndef _DISPLAYSLEEP_H_
#define _DISPLAYSLEEP_H_

void DisplaySleep()
{
	// getting SetBattleSpeed from Run
	string SetBattleSpeed;

	// reading SetBattleSpeed from Run
	std::ofstream Run;
	std::ifstream ReadFromRun("Run.txt");
	std::getline(ReadFromRun, SetBattleSpeed);
	Run.close();

	// read only after =
	SetBattleSpeed.erase(0, 14);

	// setting battle speed
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
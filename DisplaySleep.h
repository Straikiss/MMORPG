#pragma once

#ifndef _DisplaySleep_H_
#define _DisplaySleep_H_

void DisplaySleep()
{
	// Getting SetBattleSpeed from Run
	std::string SetBattleSpeed;

	// Reading SetBattleSpeed from Run
	std::ofstream Run;
	std::ifstream ReadFromRun("Run.txt");
	std::getline(ReadFromRun, SetBattleSpeed);
	Run.close();

	// Read only after =
	SetBattleSpeed.erase(0, 14);

	// Setting battle speed
	if(SetBattleSpeed == "fast")
	{
		Sleep(0);
	}

	if(SetBattleSpeed == "normal")
	{
		Sleep(500);
	}
	
	if(SetBattleSpeed == "slow")
	{
		Sleep(1000);
	}
}

void SetConsoleColor(std::string ColorName)
{
	if(ColorName == "Red")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	}

	if(ColorName == "Green")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	}

	if(ColorName == "Black")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

#endif
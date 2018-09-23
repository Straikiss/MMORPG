#pragma once

#ifndef _DisplaySleep_H_
#define _DisplaySleep_H_

void DisplaySleep()
{
	// Getting SetBattleSpeed from Run
	std::string SetBattleSpeed;
	int BattleSpeed;

	// Reading SetBattleSpeed from Run
	std::ofstream Run;
	std::ifstream ReadFromRun("Run.txt");
	std::getline(ReadFromRun, SetBattleSpeed);
	Run.close();

	// Read only after =
	SetBattleSpeed.erase(0, 14);

	// Setting stats from Run to BattleSpeed
	std::istringstream(SetBattleSpeed) >> BattleSpeed;

	// Setting battle speed
	Sleep(BattleSpeed);
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
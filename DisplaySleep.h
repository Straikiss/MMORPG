#pragma once

#ifndef _DisplaySleep_H_
#define _DisplaySleep_H_

void DisplaySleep()
{
	// Getting GetBattleSpeed from Run
	string GetBattleSpeed;
	int BattleSpeed;

	// Reading GetBattleSpeed from Run
	ofstream Run;
	ifstream ReadFromRun("Run.txt");
	getline(ReadFromRun, GetBattleSpeed);
	Run.close();

	// Read only after =
	GetBattleSpeed.erase(0, 14);

	// Setting stats from Run to BattleSpeed
	istringstream(GetBattleSpeed) >> BattleSpeed;

	// Setting battle speed
	Sleep(BattleSpeed);
}

#endif
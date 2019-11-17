#ifndef _SETUPRUN_H_
#define _SETUPRUN_H_

string SetupRun(string Return)
{
	// getting ShowFullLog from Run
	string FakeSetBattleSpeed;
	string ShowFullLog;
	string SaveBattleLog;
	string LogFileName;
	
	// reading ShowFullLog from Run
	std::ofstream Run;
	std::ifstream ReadFromRun("Run.txt");
	getline(ReadFromRun, FakeSetBattleSpeed);
	getline(ReadFromRun, ShowFullLog);
	getline(ReadFromRun, SaveBattleLog);
	getline(ReadFromRun, LogFileName);
	Run.close();

	// read only after =
	FakeSetBattleSpeed.erase(0, 0);
	ShowFullLog.erase(0, 14);
	SaveBattleLog.erase(0, 16);
	LogFileName.erase(0, 14);
	
	if(Return == "ShowFullLog")
	{
		return ShowFullLog;
	}

	if(Return == "SaveBattleLog")
	{
		return SaveBattleLog;
	}

	if(Return == "LogFileName")
	{
		return LogFileName;
	}
}

#endif // _SETUP_H_
#pragma once
#ifndef _SETCONSOLECOLOR_H_
#define _SETCONSOLECOLOR_H_

void SetConsoleColor(std::string Color)
{
	if(Color == "Red")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	}

	if(Color == "Green")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	}

	if(Color == "Black")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

#endif // _SETCONSOLEOLOR_H_
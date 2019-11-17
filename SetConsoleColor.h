#ifndef _SETCONSOLECOLOR_H_
#define _SETCONSOLECOLOR_H_

void SetConsoleColor(string ColorName)
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

#endif // _SETCONSOLEOLOR_H_
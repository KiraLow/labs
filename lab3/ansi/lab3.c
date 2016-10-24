#include <stdio.h>
#include <windows.h>

#include "lab3.h"

char *replace(char *s, char oldChar, char newChar)
{
	char *p = s;
	while(*p) 
	{
		if(*p == oldChar)
		*p = newChar;
		++p;
	}
	return s;
}


int fileExists(void)
{
	FILE *f;
	errno_t err;
	err = fopen_s(&f, "dataFile.csv", "r"); 
	if (err == 2) 
		// no data file
		return 0;
	else
	{
		fclose(f);
		return 1;
	}
}

void writeValueToDataFile(double xValue, double yValue)
{
	FILE *f;
	int err;
	char xStr[255];
	char yStr[255];

	sprintf_s(xStr, 255, "%.10lf", xValue);
	sprintf_s(yStr, 255, "%.10lf", yValue);
	
	err = fileExists();
	if (err == 1)
	{
		// file exists
		fopen_s(&f, "dataFile.csv", "a");  // open file for writing
		//write the data
		fprintf_s(f, "%s;%s\n", replace(xStr, '.', ','), replace(yStr, '.', ','));
		// close file
		fclose(f);		
	}
	else
	{
		// file do not exists
		fopen_s(&f, "dataFile.csv", "w+");  // open file for writing and creates file
		//write the data
		fprintf_s(f, "%s;%s\n", replace(xStr, '.', ','), replace(yStr, '.', ','));
		// close file
		fclose(f);
	}

	strcpy_s(xStr, 255, "");
	strcpy_s(yStr, 255, "");
}

void clearDataFile(void)
{
	_unlink("dataFile.csv");
}
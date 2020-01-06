// GoAwayTimeWasters.cpp : Defines the entry points of the console application
//

#include "stdafx.h"
#include <ctime>
#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>


namespace gatw 
{

	void killProcessesByName(const wchar_t* processName) 
	{ 
		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(entry);
		BOOL hasEntry = Process32First(snapshot, &entry);
		while (hasEntry) 
		{
			if (wcscmp(entry.szExeFile, processName) == 0) {
				HANDLE process = OpenProcess(PROCESS_TERMINATE, 0, entry.th32ProcessID);
				if (process != NULL) 
				{
					TerminateProcess(process, 1000);
					CloseHandle(snapshot);
				}
			}

			hasEntry = Process32Next(snapshot, &entry);
		}


		CloseHandle(snapshot);
	}




	[[ noreturn ]] void start() 
	{

		while (true) 
		{

			time_t rawTime;
			time(&rawTime);

			tm timeInfo;
			localtime_s(&timeInfo, &rawTime);

			int wday = timeInfo.tm_wday;
			int tmhour = timeInfo.tm_hour;

			if (wday >= 1 && wday <= 5 && tmhour >= 1 && tmhour < 17) 
			{
				//....
			}

			Sleep(250);
		}
	}
}

int main()
{
	gatw::start();
	return 0;
}
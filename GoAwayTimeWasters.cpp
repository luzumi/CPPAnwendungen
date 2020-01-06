// GoAwayTimeWasters.cpp : Defines the entry points of the console application
//

#include "stdafx.h"
#include <ctime>
#include <Windows.h>
#include <TlHelp32.h>

namespace gatw {

	void killProcessesByName(const wchar_t* processName) {

	}




	[[ noreturn ]] void start() {

		while (true) {

			time_t rawTime;
			time(&rawTime);

			tm timeInfo;
			localtime_s(&timeInfo, &rawTime);

			int wday = timeInfo.tm_wday;
			int tmhour = timeInfo.tm_hour;

			if (wday >= 1 && wday <= 5 && tmhour >= 1 && tmhour < 17) {
				//....
			}

			Sleep(250);
		}
	}
}

int main() {
	gatw::start();
	return 0;
}
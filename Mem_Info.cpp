//Collect information about memory available, used, and total.
#include "Mem_Info.h"
#include <windows.h>
#include <iostream>

//Function to obtain memory information
void PrintMemoryInformation() {
	MEMORYSTATUSEX memStatus;
	memStatus.dwLength = sizeof(memStatus);
	if (GlobalMemoryStatusEx(&memStatus)) {
		std::cout << "Total Physical Memory: " << memStatus.ullTotalPhys / (1024 * 1024) << " MB" << std::endl;
		std::cout << "Available Physical Memory: " << memStatus.ullAvailPhys / (1024 * 1024) << " MB" << std::endl;
		std::cout << "Memory Load: " << memStatus.dwMemoryLoad << " %" << std::endl;
	}
	else {
		std::cerr << "Failed to retrieve memory information." << std::endl;
	}
}



//Collect disk information such as total, free, and used space.
#include "Disk_Info.h"
#include <windows.h>
#include <iostream>

//function to obtain disk information
void PrintDiskInformation() {
	ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
	if (GetDiskFreeSpaceExA(
		"C:\\",
		&freeBytesAvailable,
		&totalNumberOfBytes,
		&totalNumberOfFreeBytes) != 0)
	{
		std::cout << "Total Disk Space: " << totalNumberOfBytes.QuadPart / (1024 * 1024 * 1024) << " GB" << std::endl;
		std::cout << "Free Disk Space: " << totalNumberOfFreeBytes.QuadPart / (1024 * 1024 * 1024) << " GB" << std::endl;
		std::cout << "Used Disk Space: " << (totalNumberOfBytes.QuadPart - totalNumberOfFreeBytes.QuadPart) / (1024 * 1024 * 1024) << " GB" << std::endl;
	}
	else {
		std::cerr << "Failed to retrieve disk information." << std::endl;
	}
}
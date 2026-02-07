//Gather information about the CPU: Cores, Threads, Cache Size, etc.
#include "CPU_Info.h"
#include <windows.h>
#include <iostream>
#include <thread>
#include <vector>

int CountPhysicalCores()
{
	DWORD length = 0;
	GetLogicalProcessorInformationEx(RelationProcessorCore, nullptr, &length);

	std::vector<UINT32> buffer(length);
	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX info = reinterpret_cast<PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX>(buffer.data());

	GetLogicalProcessorInformationEx(RelationProcessorCore, info, &length);

	DWORD count = 0;
	char* ptr = reinterpret_cast<char*>(buffer.data());
	char* end = ptr + length;

	while (ptr < end)
	{
		PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX entry =
			reinterpret_cast<PSYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX>(ptr);

		if (entry->Relationship == RelationProcessorCore)
		{
			count++;
		}
		ptr += entry->Size;
	}
	return count;
}


bool IsVirtualMachine()
{
	HKEY hkey;
	char value[256];
	DWORD size = sizeof(value);

	if (RegOpenKeyExA(
		HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System",
		0,
		KEY_READ,
		&hkey) != ERROR_SUCCESS)
	{
		return false;
	}

	if (RegQueryValueExA(
		hkey,
		"SystemBiosVersion",
		nullptr,
		nullptr,
		(LPBYTE)value,
		&size) == ERROR_SUCCESS)
	{
		// Add logic to check for VM strings if needed
		// Example: return strstr(value, "VIRTUAL") != nullptr;
		std::string bios(value);

		if (bios.find("VMware") != std::string::npos || bios.find("VirtualBox") != std::string::npos || bios.find("Hyper-V") != std::string::npos)
		{
			RegCloseKey(hkey);
			return true;
		}
	}
	RegCloseKey(hkey);
	return false;
}

//I wont have the main function here, but I will have a function that gathers CPU information and prints it out.
void PrintCUPUInformation() {

	DWORD physicalCores = CountPhysicalCores();
	unsigned int logicalCores = std::thread::hardware_concurrency();

	std::cout << "Physical Cores: " << physicalCores << std::endl;
	std::cout << "Logical Processors: " << logicalCores << std::endl;

	//virtual machine logic here
	if (IsVirtualMachine())
	{
		std::cout << "Environment virtual machine" << std::endl;
	}
	else {
		std::cout << "Environment physical machine" << std::endl;
	}
	
	//Get the number of hardware threads (logical processors)
	unsigned int numThreads = logicalCores;
	
	if (numThreads == 0)
	{
		std::cout << "Unable to get Hardware Threads" << std::endl;
	}
	else {
		std::cout << "Number of Hardware Threads (Logical Processors): " << numThreads << std::endl;
	}

	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	switch (sysInfo.wProcessorArchitecture) 
	{
	case PROCESSOR_ARCHITECTURE_AMD64:
		std::cout << "Processor Architecture x64 (AMD or INTEL)" << std::endl;
		break;

	case PROCESSOR_ARCHITECTURE_ARM:
		std::cout << "Processor Architecture ARM" << std::endl;
		break;

	case PROCESSOR_ARCHITECTURE_INTEL:
		std::cout << "Processor Architecture x86" << std::endl;
		break;

	default:
		std::cout << "Processor Architecture Unknown" << std::endl;
		break;
	}

	std::cout << "Number of Logical Processors (Windows view): " << sysInfo.dwNumberOfProcessors << std::endl;

}


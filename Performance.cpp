#include "CPU_Info.h"
#include "Mem_Info.h"
#include "Disk_Info.h"
#include "GPU_Info.h"
#include <iostream>

int main()
{
    std::cout << "*--------Gathering CPU Information...--------*" << std::endl;
    PrintCPUInformation();
	std::cout << "CPU Information complete." << std::endl;
    std::cout << "*---------------------------------------------*" << std::endl;

    std::cout << "############################################################" << std::endl;

    std::cout << "*--------Gathering MEMORY Information...--------*" << std::endl;
    PrintMemoryInformation();
    std::cout << "MEMORY Information gathering complete.." << std::endl;
    std::cout << "*----------------------------------------------*" << std::endl;
    
    std::cout << "############################################################" << std::endl;

    std::cout << "*--------Gathering DISK Information...--------*" << std::endl;
    PrintDiskInformation();
    std::cout << "DISK Information gathering complete.." << std::endl;
    std::cout << "*----------------------------------------------*" << std::endl;


    std::cout << "*--------Gathering DIGPUSK Information...--------*" << std::endl;
    PrintGPUInformation();
    std::cout << "GPU Information gathering complete.." << std::endl;
    std::cout << "*----------------------------------------------*" << std::endl;


    std::cin.get();
    return 0;
}

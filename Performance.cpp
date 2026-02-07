#include "CPU_Info.h"
#include <iostream>

int main()
{
    std::cout << "Gathering CPU Information..." << std::endl;
    PrintCUPUInformation();
	std::cout << "CPU Information gathering complete. Type 'Enter' to exit." << std::endl;
    std::cin.get();
    return 0;
}

#include "CPU_Info.h"
#include "Mem_Info.h"
#include <iostream>

int main()
{
    std::cout << "*--------Gathering CPU Information...--------*" << std::endl;
    PrintCUPUInformation();
	std::cout << "CPU Information complete." << std::endl;
    std::cout << "*---------------------------------------------*" << std::endl;

    std::cout << "############################################################" << std::endl;

    std::cout << "*--------Gathering MEMORY Information...--------*" << std::endl;
    PrintMemoryInformation();
    std::cout << "MEMORY Information gathering complete.." << std::endl;
    std::cout << "*--------------------------------------.--------*" << std::endl;
    
    std::cin.get();
    return 0;
}

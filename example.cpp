#include "Memoriah/Memoriah.hpp"

#include <iostream>
#include <string>

int main()
{
	Memoriah::HProcess process{ TEXT("AssaultCube"), Memoriah::ProcessAccess::ALL_ACCESS };
	auto status = process.Initialize(true);

	process.ListModules();

	DWORD dllNt = process.GetModuleAddress(TEXT("ntdll.dll"));

	std::cout << std::hex << dllNt << std::endl;

	if (status)
	{
		Memoriah::Manager::DebugConsoleLog("Status : ", "");
		Memoriah::Manager::DebugConsoleLog("[OK]", Memoriah::ConsoleTextColor::GREEN,"\n");

	}

	DWORD health = 0;

    
	while (status)
	{
		health = process.RPM<DWORD>(0x0104A6A8 /*adresse dynamique*/);
		std::cout << health << std::endl;
		Memoriah::Manager::Delay(1000);
	}

	Memoriah::Manager::ExitMemoriahApp(Memoriah::ExitCode::SUCCESS);
}
#include "Manager.hpp"

using namespace Memoriah;

 
void Manager::DebugConsoleLog(const std::string& log, const WORD attributes, const std::string& end)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole == nullptr)
		return;

	CONSOLE_SCREEN_BUFFER_INFO info;

	GetConsoleScreenBufferInfo(hConsole, &info);

	SetConsoleTextAttribute(hConsole, attributes);
	std::cout << log << end;

	SetConsoleTextAttribute(hConsole, info.wAttributes);
}

void Manager::DebugConsoleLog(const std::string& log, const std::string& end)
{
	std::cout << log << end;
}
void Manager::Delay(DWORD ms)
{
	Sleep(ms);
}

void Manager::ExitMemoriahApp(const ExitCode code)
{
	ExitProcess(static_cast<UINT>(code));
}
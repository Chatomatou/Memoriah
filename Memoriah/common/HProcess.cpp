#include "HProcess.hpp"

using namespace Memoriah;

#include <iostream>

HProcess::HProcess(const std::wstring& appName, const ProcessAccess& type) :
	m_access{ type },
	m_appName{appName},
	m_hProcess{nullptr},
	m_hWindow{nullptr},
	m_processID{0}
{

}

HProcess::~HProcess()
{
	if(m_hWindow != nullptr)
		CloseWindow(m_hWindow);
	if(m_hProcess != nullptr)
		CloseHandle(m_hProcess);
}

BOOL HProcess::Initialize(const BOOL stuck)
{
	if (stuck)
	{
		do
		{
			m_hWindow = FindWindow(nullptr, m_appName.data());
		} while (m_hWindow == nullptr);
	}
	else
	{
		m_hWindow = FindWindow(nullptr, m_appName.data());
	}

	if (m_hWindow == INVALID_HANDLE_VALUE)
		return FALSE;
	
	GetWindowThreadProcessId(m_hWindow, &m_processID);

	m_hProcess = OpenProcess(static_cast<DWORD>(m_access), FALSE, m_processID);

	if (m_hProcess == INVALID_HANDLE_VALUE)
		return FALSE;

	return TRUE;
}

DWORD HProcess::GetModuleAddress(const std::wstring& moduleName)
{
	DWORD moduleLocation = 0;

	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, m_processID);
 

	if (snapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 hModule;
		ZeroMemory(&hModule, sizeof(hModule));

		hModule.dwSize = sizeof(hModule);
	
		if (Module32First(snapshot, &hModule))
		{
			do
			{
				std::wstring name = hModule.szModule;
		
				if (name == moduleName)
					moduleLocation = reinterpret_cast<DWORD>(hModule.modBaseAddr);

			} while (Module32Next(snapshot, &hModule));
		}
	}
	CloseHandle(snapshot);

	return moduleLocation;
}

void HProcess::ListModules()
{
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, m_processID);

	if (snapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 hModule;
		ZeroMemory(&hModule, sizeof(hModule));

		hModule.dwSize = sizeof(hModule);

		if (Module32First(snapshot, &hModule))
		{
			do
			{
				std::wcout << hModule.szModule << "  -> 0x" << hModule.modBaseAddr << std::endl;
			} while (Module32Next(snapshot, &hModule));
		}
	}
	CloseHandle(snapshot);
}

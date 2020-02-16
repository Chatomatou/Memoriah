#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include "EProcessAccess.hpp"

namespace Memoriah
{
    class HProcess
    {
    public:
        HProcess() = delete;
        HProcess(const std::wstring& appName, const ProcessAccess& type);
        ~HProcess();

        BOOL Initialize(const BOOL stuck);
        
        template<typename T>
        void WPM(const DWORD address, T data)
        {
            WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(address), &data, sizeof(data), nullptr);
        }

        template<typename T>
        T RPM(const DWORD address)
        {
            T buffer;
            ReadProcessMemory(m_hProcess, reinterpret_cast<LPCVOID>(address), &buffer, sizeof(buffer), nullptr);
            return buffer;
        }

        DWORD GetModuleAddress(const std::wstring& moduleName);
        void ListModules();
         
        
    private:
        ProcessAccess m_access;
        std::wstring m_appName;
        DWORD m_processID;
        HWND m_hWindow;
        HANDLE m_hProcess;
    };
}
 

#pragma once

#include <Windows.h>
#include <iostream>
#include <cstdlib>

#include "EConsoleColor.hpp"

namespace Memoriah
{
    enum class ExitCode : UINT
    {
        FAILURE = EXIT_FAILURE,
        SUCCESS = EXIT_SUCCESS
    };

    struct Manager
    {
        static void DebugConsoleLog(const std::string& log, const WORD attributes, const std::string& end="\n");
        static void DebugConsoleLog(const std::string& log, const std::string& end="\n");
        static void Delay(DWORD ms);
        static void ExitMemoriahApp(const ExitCode code);
    };
}
 
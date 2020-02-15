#pragma once

#include <Windows.h>

namespace Memoriah
{
	namespace ConsoleTextColor
	{
		enum
		{
			BLUE = FOREGROUND_BLUE,
			GREEN = FOREGROUND_GREEN,
			RED = FOREGROUND_RED,
			INTENSITY = FOREGROUND_INTENSITY,
		};
	}
	namespace ConsoleBackgroundColor
	{
		enum
		{
			BLUE = BACKGROUND_BLUE,
			GREEN = BACKGROUND_GREEN,
			RED = BACKGROUND_RED,
			INTENSITY = BACKGROUND_INTENSITY
		};
	}
  
}
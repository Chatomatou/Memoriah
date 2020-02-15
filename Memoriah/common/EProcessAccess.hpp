#pragma once

 
#include <minwindef.h>
 
namespace Memoriah
{
	enum class ProcessAccess : DWORD
	{
		ALL_ACCESS = PROCESS_ALL_ACCESS, // Lecture & Ecriture 
		READ = PROCESS_VM_READ, // Lecture 
		WRITE = PROCESS_VM_WRITE // Ecriture
	};
}
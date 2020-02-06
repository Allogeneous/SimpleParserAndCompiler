#pragma once
#ifndef __PROC__
#define __PROC__

#include "Instruction.h"
#include <string>

class PROC : public Instruction {
	public:

		PROC(std::string proc);
		PROC();

		std::string proc;
		void execute(class ProgramExecutor* pe);
};


#endif // !__PROC__

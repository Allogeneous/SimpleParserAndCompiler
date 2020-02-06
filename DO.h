#pragma once
#include "Instruction.h"
#include <string>

class DO : public Instruction {
	public:

		DO(std::string var, std::string proc);
		DO();

		std::string var;
		std::string proc;
		void execute(class ProgramExecutor* pe);
		void runproc(class ProgramExecutor* pe, std::string proc);
};
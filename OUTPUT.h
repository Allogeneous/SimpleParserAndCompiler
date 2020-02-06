#pragma once
#ifndef __OUTPUT__
#define __OUTPUT__

#include "Instruction.h"
#include <string>

class OUTPUT : public Instruction {
	public:

		OUTPUT(std::string output);
		OUTPUT();

		std::string output;
		void execute(class ProgramExecutor* pe);
};

#endif // !__OUTPUT__

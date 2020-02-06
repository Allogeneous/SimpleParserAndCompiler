#pragma once
#ifndef __INPUT__
#define __INPUT__

#include "Instruction.h"
#include <string>

class INPUT : public Instruction {
public:

	INPUT(std::string output);
	INPUT();

	std::string input;
	void execute(class ProgramExecutor* pe);
};

#endif // !__INPUT__
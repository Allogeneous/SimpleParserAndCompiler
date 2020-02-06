#pragma once
#ifndef __ASSIGN2__
#define __ASSIGN2__

#include "Instruction.h"
#include <string>

class ASSIGN2 : public Instruction {
	public:

		ASSIGN2(std::string lhs, std::string rhs);
		ASSIGN2();

		std::string lhs;
		std::string rhs;
		void execute(class ProgramExecutor* pe);
};

#endif // !

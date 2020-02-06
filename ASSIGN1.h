#pragma once
#ifndef __ASSIGN1__
#define __ASSIGN1__

#include "Instruction.h"
#include <string>

class ASSIGN1 : public Instruction {

	public:

		ASSIGN1(std::string lhs, std::string var1, std::string var2, Operator op);
		ASSIGN1();

		std::string lhs;
		std::string var1;
		std::string var2;
		Operator op;
		void execute(class ProgramExecutor* pe);
		int math(int var1, int va2, Operator op);
};


#endif // !__ASSIGN1__

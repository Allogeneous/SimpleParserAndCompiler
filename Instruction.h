#pragma once
#ifndef __INSTRUCTION__
#define __INSTRUCTION__

#include "ProgramExecutor.h"

typedef enum{ADD, SUB, MULTI, DIVI} Operator;

class Instruction {
	public:
		virtual void execute(class ProgramExecutor* pe) { std::cout << "I am not being overriden" << std::endl; };
};

#endif

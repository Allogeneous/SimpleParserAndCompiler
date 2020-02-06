#ifndef __PROGRAM_EXECUTOR__
#define __PROGRAM_EXECUTOR__

#include <vector>
#include <map>
#include <iostream>
#include <string>
#include "Instruction.h"

class ProgramExecutor {	
	public:

		std::vector<class Instruction*> program;
		std::map<std::string, std::vector<class Instruction*> > procedures;
		std::map<std::string, int> variables;
		std::vector<int> inputs;

		void executeProgram();

};


#endif // !__PROGRAM_EXECUTOR__


#include "OUTPUT.h"

OUTPUT::OUTPUT(std::string output) {
	this->output = output;
}

OUTPUT::OUTPUT() {}

void OUTPUT::execute(ProgramExecutor* pe) {
	std::cout << pe->variables.find(output)->second << " ";

	//std::cout << "OUTPUT" << std::endl;
}
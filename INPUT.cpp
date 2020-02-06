#include "INPUT.h"

INPUT::INPUT(std::string input) {
	this->input = input;
}

INPUT::INPUT() {}

void INPUT::execute(ProgramExecutor* pe) {
	pe->variables.find(input)->second = pe->inputs[0];
	pe->inputs.erase(pe->inputs.begin());

	//std::cout << "INPUT" << std::endl;
}
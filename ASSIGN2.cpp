#include "ASSIGN2.h"

ASSIGN2::ASSIGN2(std::string lhs, std::string rhs) {
	this->lhs = lhs;
	this->rhs = rhs;
}

ASSIGN2::ASSIGN2() {}

void ASSIGN2::execute(ProgramExecutor* pe) {

	pe->variables.find(lhs)->second = pe->variables.find(rhs)->second;

	//std::cout << "ASSIGN2" << std::endl;

}
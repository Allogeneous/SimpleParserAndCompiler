#include "ASSIGN1.h"

ASSIGN1::ASSIGN1(std::string lhs, std::string var1, std::string var2, Operator op) {
	this->lhs = lhs;
	this->var1 = var1;
	this->var2 = var2;
	this->op = op;
}

ASSIGN1::ASSIGN1() {}

void ASSIGN1::execute(ProgramExecutor* pe) {

	std::map<std::string, int>::iterator it;

	//std::cout << "var1: " << var1 << std::endl;

	pe->variables.find(lhs)->second = math(pe->variables.find(var1)->second, pe->variables.find(var2)->second, op);

	//std::cout << "ASSIGN1" << std::endl;
	
}

int ASSIGN1::math(int var1, int var2, Operator op) {

	//std::cout << "var1: " << var1 << std::endl;
	//std::cout << "var2: " << var2 << std::endl;

	int result = 0;

	if (op == ADD) {
		result = var1 + var2;
	}
	else if (op == SUB) {
		result = var1 - var2;
	}
	else if (op == MULTI) {
		result = var1 * var2;
	}
	else if (op == DIVI) {
		result = var1 / var2;
	}
	return result;

}


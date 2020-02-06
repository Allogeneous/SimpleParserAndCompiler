#include "DO.h"

DO::DO(std::string var, std::string proc) {
	this->var = var;
	this->proc = proc;
}

DO::DO() {}

void DO::execute(ProgramExecutor* pe) {
	for (int i = 0; i < pe->variables.find(var)->second; i++) {
		runproc(pe, proc);
	}
	//std::cout << "DO" << std::endl;
}

void DO::runproc(ProgramExecutor* pe, std::string proc) {
	std::vector<Instruction*> procInst = pe->procedures.find(proc)->second;
	for (int i = 0; i < procInst.size(); i++) {
		procInst[i]->execute(pe);
	}
}
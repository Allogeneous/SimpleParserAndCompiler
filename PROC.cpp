#include "PROC.h"

PROC::PROC(std::string proc) {
	this->proc = proc;
}

PROC::PROC() {};

void PROC::execute(ProgramExecutor* pe) {
	std::vector<Instruction*> procInst = pe->procedures.find(proc)->second;
	for (int i = 0; i < procInst.size(); i++) {
		procInst[i]->execute(pe);
	}
	//std::cout << "PROC" << std::endl;
}
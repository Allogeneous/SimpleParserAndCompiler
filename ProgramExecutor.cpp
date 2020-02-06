#include "ProgramExecutor.h"

void ProgramExecutor::executeProgram() {
	for (int i = 0; i < program.size(); i++) {
		program[i]->execute(this);
	}
}

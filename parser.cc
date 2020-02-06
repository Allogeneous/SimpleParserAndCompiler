/*
 * Copyright (C) Rida Bazzi, 2017
 *
 * Do not share this file with anyone
 *
 * Do not post this file or derivatives of
 * of this file online
 *
 */
#include <iostream>
#include <cstdlib>
#include "parser.h"
#include "ProgramExecutor.h"
#include "ASSIGN1.h"
#include "ASSIGN2.h"
#include "DO.h"
#include "PROC.h"
#include "OUTPUT.h"
#include "INPUT.h"


using namespace std;

void Parser::syntax_error()
{
    cout << "SYNTAX ERROR\n";
    exit(1);
}

// this function gets a token and checks if it is
// of the expected type. If it is, the token is
// returned, otherwise, synatx_error() is generated
// this function is particularly useful to match
// terminals in a right hand side of a rule.
// Written by Mohsen Zohrevandi
Token Parser::expect(TokenType expected_type)
{
    Token t = lexer.GetToken();
    if (t.token_type != expected_type)
        syntax_error();
    return t;
}

// this function simply checks the next token without
// consuming the input
// Written by Mohsen Zohrevandi
Token Parser::peek()
{
    Token t = lexer.GetToken();
    lexer.UngetToken(t);
    return t;
}

// Parsing

void Parser::parseInputFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, string name) {
	string id;
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		
		if (token->token_type == ID) {
			id = token->lexeme;
			*token = lexer->GetToken();
			if (token->token_type != END_OF_FILE) {
				
				if (token->token_type == SEMICOLON) {
					class INPUT* nIn = new class INPUT(id);
					pe->procedures[name].push_back(nIn);
					return;
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseOutputFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, string name) {
	string id;
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		
		if (token->token_type == ID) {
			id = token->lexeme;
			if (pe->variables.find(id) == pe->variables.end()) {
				pe->variables[id] = 0;
			}
			*token = lexer->GetToken();
			if (token->token_type != END_OF_FILE) {
				
				if (token->token_type == SEMICOLON) {
					class OUTPUT* nOut = new class OUTPUT(id);
					pe->procedures[name].push_back(nOut);
					return;
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseIdFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, string name) {
	string lhs;
	string rhs;
	string var2;
	Operator op;
	*token = lexer->GetToken();
	if (token->token_type == ID) {
		
		lhs = token->lexeme;
		if (pe->variables.find(lhs) == pe->variables.end()) {
			pe->variables[lhs] = 0;
		}
		*token = lexer->GetToken();
		if (token->token_type != END_OF_FILE) {
			
			if (token->token_type == EQUAL) {
				*token = lexer->GetToken();
				if (token->token_type != END_OF_FILE) {
					
					if (token->token_type == ID || token->token_type == NUM) {
						rhs = token->lexeme;
						if (token->token_type == ID) {
							if (pe->variables.find(rhs) == pe->variables.end()) {
								pe->variables[rhs] = 0;
							}
						}
						else if (token->token_type == NUM) {
							if (pe->variables.find(rhs) == pe->variables.end()) {
								pe->variables[rhs] = atoi(rhs.c_str());
							}
						}
						*token = lexer->GetToken();
						if (token->token_type != END_OF_FILE) {
							
							if (token->token_type == SEMICOLON) {
								ASSIGN2* nAssign2 = new class ASSIGN2(lhs, rhs);
								pe->procedures[name].push_back(nAssign2);
								return;
							}
							else if (token->token_type == MULT || token->token_type == DIV || token->token_type == PLUS || token->token_type == MINUS) {
								if (token->token_type == MULT) {
									op = MULTI;
								}
								else if (token->token_type == DIV) {
									op = DIVI;
								}
								else if (token->token_type == PLUS) {
									op = ADD;
								}
								else if (token->token_type == MINUS) {
									op = SUB;
								}
								*token = lexer->GetToken();
								if (token->token_type != END_OF_FILE) {
									
									if (token->token_type == ID || token->token_type == NUM) {
										var2 = token->lexeme;
										if (token->token_type == ID) {
											if (pe->variables.find(var2) == pe->variables.end()) {
												pe->variables[var2] = 0;
											}
										}
										else if (token->token_type == NUM) {
											if (pe->variables.find(var2) == pe->variables.end()) {
												pe->variables[var2] = atoi(var2.c_str());
											}
										}
										*token = lexer->GetToken();
										if (token->token_type != END_OF_FILE) {
											
											if (token->token_type == SEMICOLON) {
												ASSIGN1* nAssign1 = new class ASSIGN1(lhs, rhs, var2, op);
												pe->procedures[name].push_back(nAssign1);
												return;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseDoFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, string name) {
	class DO* nDo = new class DO();
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		
		if (token->token_type == ID || token->token_type == NUM) {
			nDo->var = token->lexeme;
			if (token->token_type == ID) {
				if (pe->variables.find(nDo->var) == pe->variables.end()) {
					pe->variables[nDo->var] = 0;
				}
			}
			else if (token->token_type == NUM) {
				if (pe->variables.find(nDo->var) == pe->variables.end()) {
					pe->variables[nDo->var] = atoi(nDo->var.c_str());
				}
			}
			*token = lexer->GetToken();
			if (token->token_type != END_OF_FILE) {
				
				if (token->token_type == ID) {
					nDo->proc = token->lexeme;
					*token = lexer->GetToken();
					if (token->token_type != END_OF_FILE) {
						
						if (token->token_type == SEMICOLON) {
							pe->procedures[name].push_back(nDo);
							return;
						}
					}
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseInput(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	string id;
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		if (token->token_type == ID) {
			id = token->lexeme;
			*token = lexer->GetToken();
			if (token->token_type != END_OF_FILE) {
				
				if (token->token_type == SEMICOLON) {
					
					class INPUT* nIn = new class INPUT(id);
					pe->program.push_back(nIn);
					
					return;
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseOutput(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	string id;
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		
		if (token->token_type == ID) {
			id = token->lexeme;
			if (pe->variables.find(id) == pe->variables.end()) {
				pe->variables[id] = 0;
			}
			*token = lexer->GetToken();
			if (token->token_type != END_OF_FILE) {
				
				if (token->token_type == SEMICOLON) {
					class OUTPUT* nOut = new class OUTPUT(id);
					pe->program.push_back(nOut);
					return;
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseId(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	string lhs;
	string rhs;
	string var2;
	Operator op;
	*token = lexer->GetToken();
	if (token->token_type == ID) {
		
		lhs = token->lexeme;
		if (pe->variables.find(lhs) == pe->variables.end()) {
			pe->variables[lhs] = 0;
		}
		*token = lexer->GetToken();
		if (token->token_type != END_OF_FILE) {
			
			if (token->token_type == EQUAL) {
				*token = lexer->GetToken();
				if (token->token_type != END_OF_FILE) {
					
					if (token->token_type == ID || token->token_type == NUM) {
						rhs = token->lexeme;
						if (token->token_type == ID) {
							if (pe->variables.find(rhs) == pe->variables.end()) {
								pe->variables[rhs] = 0;
							}
						}
						else if (token->token_type == NUM) {
							if (pe->variables.find(rhs) == pe->variables.end()) {
								pe->variables[rhs] = atoi(rhs.c_str());
							}
						}
						*token = lexer->GetToken();
						if (token->token_type != END_OF_FILE) {
							
							if (token->token_type == SEMICOLON) {
								ASSIGN2* nAssign2 = new class ASSIGN2(lhs, rhs);
								pe->program.push_back(nAssign2);
								return;
							}
							else if (token->token_type == MULT || token->token_type == DIV || token->token_type == PLUS || token->token_type == MINUS) {
								if (token->token_type == MULT) {
									op = MULTI;
								}else if (token->token_type == DIV) {
									op = DIVI;
								}else if (token->token_type == PLUS) {
									op = ADD;
								}else if (token->token_type == MINUS) {
									op = SUB;
								}
								*token = lexer->GetToken();
								if (token->token_type != END_OF_FILE) {
									
									if (token->token_type == ID || token->token_type == NUM) {
										var2 = token->lexeme;
										if (token->token_type == ID) {
											if (pe->variables.find(var2) == pe->variables.end()) {
												pe->variables[var2] = 0;
											}
										}
										else if (token->token_type == NUM) {
											if (pe->variables.find(var2) == pe->variables.end()) {
												pe->variables[var2] = atoi(var2.c_str());
											}
										}
										*token = lexer->GetToken();
										if (token->token_type != END_OF_FILE) {
											
											if (token->token_type == SEMICOLON) {
												ASSIGN1* nAssign1 = new class ASSIGN1(lhs, rhs, var2, op);
												pe->program.push_back(nAssign1);
												return;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	parser->syntax_error();
}

string Parser::parseProcStart(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		
		if (token->token_type == ID) {
			string procname = token->lexeme;
			if (pe->procedures.find(procname) == pe->procedures.end()) {
				vector<Instruction*> procList;
				pe->procedures[procname] = procList;
				//class PROC* nProc = new class PROC(procname);
				//pe->program.push_back(nProc);
			}
			return procname;
		}
	}
	parser->syntax_error();
	return "";
}

void Parser::parseDo(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	class DO* nDo = new class DO();
	*token = lexer->GetToken();
	if (token->token_type != END_OF_FILE) {
		
		if (token->token_type == ID || token->token_type == NUM) {
			nDo->var = token->lexeme;
			if (token->token_type == ID) {
				if (pe->variables.find(nDo->var) == pe->variables.end()) {
					pe->variables[nDo->var] = 0;
				}
			}
			else if (token->token_type == NUM) {
				if (pe->variables.find(nDo->var) == pe->variables.end()) {
					pe->variables[nDo->var] = atoi(nDo->var.c_str());
				}
			}
			*token = lexer->GetToken();
			if (token->token_type != END_OF_FILE) {
				
				if (token->token_type == ID ) {
					nDo->proc = token->lexeme;
					*token = lexer->GetToken();
					if (token->token_type != END_OF_FILE) {
						
						if (token->token_type == SEMICOLON) {
							pe->program.push_back(nDo);
							return;
						}
					}
				}
			}
		}
	}
	parser->syntax_error();
}

void Parser::parseNum(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	*token = lexer->GetToken();
	if (token->token_type == NUM) {
		int input = atoi(token->lexeme.c_str());
		pe->inputs.push_back(input);
	}
}

void Parser::parseProcCall(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token) {
	string name;
	*token = lexer->GetToken();
	if (token->token_type == ID) {
		name = token->lexeme;
		if (token->token_type != END_OF_FILE) {
			*token = lexer->GetToken();
			
			if (token->token_type == SEMICOLON) {
				class PROC* proc = new class PROC(name);
				pe->program.push_back(proc);
				return;
			}
		}
	}
}

void Parser::parseProcCallFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, string name) {
	string nameP;
	*token = lexer->GetToken();
	if (token->token_type == ID) {
		nameP = token->lexeme;
		*token = lexer->GetToken();
		if (token->token_type != END_OF_FILE) {
			
			if (token->token_type == SEMICOLON) {
				class PROC* proc = new class PROC(nameP);
				pe->procedures[name].push_back(proc);
				return;
			}
		}
	}
}


int main()
{
	ProgramExecutor pe = ProgramExecutor();
    LexicalAnalyzer lexer = LexicalAnalyzer();
	Parser parser = Parser();
    Token token;
	bool procFlag = false;
	string procName = "";

	
    
    token = lexer.GetToken();
    //token.Print();

	if (token.token_type != MAIN && token.token_type != PROC) {
		parser.syntax_error();
	}

	if (token.token_type == PROC) {
		procFlag = true;
		procName = parser.parseProcStart(&lexer, &pe, &parser, &token);
	}

	//cout << "HI" << endl;

    while (token.token_type != END_OF_FILE)
    {
        token = lexer.GetToken();
		if (token.token_type == INPUT) {
			if (!procFlag) {
				parser.parseInput(&lexer, &pe, &parser, &token);
			}
			else {
				parser.parseInputFunc(&lexer, &pe, &parser, &token, procName);
			}
			//cout << "HI1" << endl;
		}else if (token.token_type == OUTPUT) {
			if (!procFlag) {
				parser.parseOutput(&lexer, &pe, &parser, &token);
			}
			else {
				parser.parseOutputFunc(&lexer, &pe, &parser, &token, procName);
			}
			//cout << "HI2" << endl;
		}else if (token.token_type == ID) {
			if (pe.procedures.find(token.lexeme) != pe.procedures.end()) {
				lexer.UngetToken(token);
				if (!procFlag) {
					parser.parseProcCall(&lexer, &pe, &parser, &token);
				}
				else {
					parser.parseProcCallFunc(&lexer, &pe, &parser, &token, procName);
				}
			}else {
				lexer.UngetToken(token);
				if (!procFlag) {
					parser.parseId(&lexer, &pe, &parser, &token);
				}
				else {
					parser.parseIdFunc(&lexer, &pe, &parser, &token, procName);
				}
			}
			
			
			
			//cout << "HI3" << endl;
		}else if (token.token_type == DO) {
			if (!procFlag) {
				parser.parseDo(&lexer, &pe, &parser, &token);
			}
			else {
				parser.parseDoFunc(&lexer, &pe, &parser, &token, procName);
			}
			//cout << "HI4" << endl;
		}else if (token.token_type == NUM) {
			lexer.UngetToken(token);
			parser.parseNum(&lexer, &pe, &parser, &token);
			//cout << "HI5" << endl;
		}else if (token.token_type == PROC) {
			procFlag = true;
			procName = parser.parseProcStart(&lexer, &pe, &parser, &token);
			//cout << "HI6" << endl;
		}else if (token.token_type == ENDPROC) {
			procFlag = false;
			//cout << "HI7" << endl;
		}
		else if (token.token_type == MAIN) {

		}else if(token.token_type == END_OF_FILE){
			//cout << "HERE" << endl;
			break;
		}else {
			//cout << "HI8" << endl;
			parser.syntax_error();
		}
		//cout << pe.program.size() << endl;
    }

	pe.executeProgram();

	return 0;
}

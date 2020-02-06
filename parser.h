/*
 * Copyright (C) Rida Bazzi, 2019
 *
 * Do not share this file with anyone
 */
#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include "lexer.h"
#include "ProgramExecutor.h"

class Parser {
  private:
    LexicalAnalyzer lexer;
  public:
    void syntax_error();
    Token expect(TokenType expected_type);
    Token peek();

	std::string parseProcStart(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);
	void parseInput(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);
	void parseOutput(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);
	void parseId(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);
	void parseNum(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);
	void parseDo(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);
	void parseProcCall(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token);

	void parseInputFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, std::string name);
	void parseOutputFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, std::string name);
	void parseIdFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, std::string name);
	void parseDoFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, std::string name);
	void parseProcCallFunc(LexicalAnalyzer* lexer, ProgramExecutor* pe, Parser* parser, Token* token, std::string);
};

#endif


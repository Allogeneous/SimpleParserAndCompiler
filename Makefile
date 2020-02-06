EXEC = a.out
CC = g++
CFLAGS = -c -Wall

$(EXEC) :parser.o lexer.o inputbuf.o ProgramExecutor.o ASSIGN1.o ASSIGN2.o DO.o INPUT.o OUTPUT.o PROC.o
	$(CC) -o $(EXEC) parser.o lexer.o inputbuf.o ProgramExecutor.o ASSIGN1.o ASSIGN2.o DO.o INPUT.o OUTPUT.o PROC.o
parser.o	:parser.h parser.cc
	$(CC) $(CFLAGS) parser.cc
lexer.o	:lexer.h lexer.cc
	$(CC) $(CFLAGS) lexer.cc
inputbuf.o	:inputbuf.h inputbuf.cc
	$(CC) $(CFLAGS) inputbuf.cc
ProgramExecutor.o	:ProgramExecutor.h ProgramExecutor.cpp
	$(CC) $(CFLAGS) ProgramExecutor.cpp
ASSIGN1.o	:ASSIGN1.h ASSIGN1.cpp
	$(CC) $(CFLAGS) ASSIGN1.cpp
ASSIGN2.o	:ASSIGN2.h ASSIGN2.cpp
	$(CC) $(CFLAGS) ASSIGN2.cpp
DO.o	:DO.h DO.cpp
	$(CC) $(CFLAGS) DO.cpp
INPUT.o	:INPUT.h INPUT.cpp
	$(CC) $(CFLAGS) INPUT.cpp
OUTPUT.o	:OUTPUT.h OUTPUT.cpp
	$(CC) $(CFLAGS) OUTPUT.cpp
PROC.o	:PROC.h PROC.cpp
	$(CC) $(CFLAGS) PROC.cpp
clean	:
	rm *.o

CC = gcc
CFLAGS = -Wall -g

run: 
	yacc -d -Wcounterexamples parser.y
	lex lexer.l
	gcc lex.yy.c y.tab.c main.c -o sql_parser
	./sql_parser select.sql

y.tab.c y.tab.h: a.y
	yacc -d -Wcounterexamples a.y

lex.yy.c: lexer.l y.tab.h
	lex lexer.l

clean:
	rm -f sql_parser lex.yy.c y.tab.c y.tab.h *.o

.PHONY: clean
make: parser.y lexer.l
	bison -d parser.y
	flex lexer.l
	g++ -std=c++17 -o compiler lex.yy.c parser.tab.c functions.cpp -lfl

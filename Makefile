CC = gcc
CFLAGS = -Wall

all: compilador

compilador: lex.yy.c parser.tab.c
	$(CC) $(CFLAGS) -o compilador lex.yy.c parser.tab.c -lfl

lex.yy.c: lexica.l parser.tab.h
	flex lexica.l

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

test: compilador
	./compilador teste.txt

clean:
	rm -f compilador lex.yy.c parser.tab.c parser.tab.h
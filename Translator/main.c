#include "lexical.h"
#include "translator.h"
#include "syntax.h"
#include "RPN.h"

char buf[BUFFER_SIZE];
char ch;
int d;
int buff_index = 0;

extern lex cur_lex;

FILE *input = NULL;
FILE *output = NULL;

extern char buffer[SIZE_OF_SINGLE_OP];
extern char internalRepresentation[NUMBER_OF_OP][SIZE_OF_SINGLE_OP];

void main(int argc, char *argv[]) {
	// Lexical analysis
	lexManager();
	// Syntax + semantic analysis
	syntax_manager();

	expression();
	arithmeticParser();

	printf("%s", internalRepresentation[0]);

	printf("\n");
	system("PAUSE");
}

#pragma region UTILITY

int parseInt() {
	char c;
	int number = 0;
	int length;
	length = strlen(buf);

	for (int i = 0; i < length; i++) {
		c = buf[i];
		if (c == '\0')
			continue;

		number += (c - '0') * (int)pow(10, length - i - 1);
	}

	return number;
}

void error(char *error) {
	printf("%s\n", error);
	system("PAUSE");
	exit(0);
}

#pragma endregion
#include "scanner.h"

typedef struct {
	const char* start; 
	const char* current;
} Scanner;

Scanner scanner;

void initScanner(const char* source) {
	scanner.start = source;
	scanner.current = source;
}

static bool isAtEnd() {
	return *scanner.current == '\0';
}

static bool isDigit(char c) {
	return c >= '0' && c <= 9;
}

static char advance() {
	scanner.current++;
	return scanner.current[-1];
}

static char peek() {
    return *scanner.current;
}

static char peekNext() {
    if (isAtEnd()) return '\0';
    return scanner.current[1];
}

static TokenType number() {
  while (isDigit(peek())) advance();
  return TOKEN_NUMBER;
}

TokenType scanToken() {
	scanner.start = scanner.current;

	if (isAtEnd()) return TOKEN_EOF;
	char c = advance();
	if (isDigit(c)) return number();

	// no need to scan for "=" since
	// that is what triggers the running of the scanner and calculator

	switch(c) {
		case '(': return TOKEN_LEFT_PAREN;
        case ')': return TOKEN_RIGHT_PAREN;
        case '-': return TOKEN_MINUS;
        case '+': return TOKEN_PLUS;
        case '/': return TOKEN_SLASH;
        case '*': return TOKEN_STAR;
		case '\0': return TOKEN_EOF;
	}

}
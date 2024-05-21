#pragma once

typedef enum {
	TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
	TOKEN_MINUS, TOKEN_PLUS,
	TOKEN_COLON, 
	TOKEN_SLASH, TOKEN_STAR,
	TOKEN_NUMBER,
	TOKEN_EOF
} TokenType;

void initScanner(const char* source);
TokenType scanToken();
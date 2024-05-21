// #include "maths.hpp"
// #include "scanner.h"
// #define STACK_MAX 64

// typedef struct {
// 	TokenType current; 
// 	TokenType previous;
// } Parser;

// Parser parser;

// static void advance() {
// 	parser.previous = parser.current;

// 	for (;;) {
// 		parser.current = scanToken(); 
// 		std::cout << parser.current << std::endl;
// 		if (parser.current != TOKEN_EOF) break;
// 	}
// }

// long long compile(const char* source) {
// 	initScanner(source);
// 	advance();
// }

// Value pop() {
//     vm.stackTop--;
//     return *vm.stackTop;
// }

// void push(Value value) {
//   *vm.stackTop = value;
//   vm.stackTop++;
// }

// void InitVM() {
// 	vm.stackTop = vm.stack;
// }



// static InterpretResult run() {
// #define READ_BYTE() (*vm->ip++)
// #define BINARY_OP(valueType, op) \
//     do { \
//       double b = AS_NUMBER(pop()); \
//       double a = AS_NUMBER(pop()); \
//       push(valueType(a op b)); \
//     } while (false)


// 	uint8_t instruction;
// 	switch (instruction = READ_BYTE())
// 	{
// 		case OP_ADD: {
// 			double b = AS_NUMBER(pop());
// 			double a = AS_NUMBER(pop());
// 			push(NUMBER_VAL(a + b));
// 			break;
// 		} 

// 		case OP_SUBTRACT: BINARY_OP(NUMBER_VAL, -); break;
// 		case OP_MULTIPLY: BINARY_OP(NUMBER_VAL, *); break;
// 		case OP_DIVIDE:   BINARY_OP(NUMBER_VAL, /); break;
// 	}
// }

// int main() {
// 	const char* test = "2*2";

// 	initScanner(test); 
// 	advance();


// }

#pragma once

#include <iostream> 
#include <vector>
#include <stack> 
#include <cctype>
#include <string>

#define UINT8_COUNT (UINT8_MAX + 1)
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

// typedef uint64_t Value;

// typedef struct {
// 	Value stack[STACK_MAX];
// 	Value* stackTop;
// 	// instruction pointer
// 	uint8_t* ip;
// } VM; 

// extern VM vm;

// static inline double valueToNum(Value value) {
//     double num;
//     memcpy(&num, &value, sizeof(Value));
//     return num;
// }

// #define AS_NUMBER(value)    valueToNum(value)

// typedef enum {
//     INTERPRET_OK, 
//     INTERPRET_COMPILE_ERROR, 
//     INTERPRET_RUNTIME_ERROR, 
// } InterpretResult;

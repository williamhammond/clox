#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "chunk.h"
#include "object.h"
#include "table.h"
#include "value.h"

// TODO makes this dynamically sized
#define FRAMES_MAX 64
#define STACK_MAX (FRAMES_MAX * UINT8_COUNT)

typedef struct {
  ObjClosure *closure;
  uint8_t *ip;
  Value *slots;
} CallFrame;

typedef struct {
  Chunk *chunk;
  uint8_t *ip;
  CallFrame frames[FRAMES_MAX];
  int frameCount;
  Value stack[STACK_MAX];
  Value *stackTop;
  Table globals;
  Table strings;
  ObjUpvalue *openUpvalues;
  ObjString* initString;

  size_t bytesAllocated;
  size_t nextGC;
  Obj *objects;
  int grayCount;
  int grayCapacity;
  Obj **grayStack;
} VM;

typedef enum {
  INTERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR,

} InterpretResult;

extern VM vm;

void initVM();
void freeVM();
static InterpretResult run();
InterpretResult interpret(const char *source);
void push(Value value);
Value pop();

#endif // CLOX_VM_H

#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
  initVM();
  Chunk chunk;

  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 1);
  writeChunk(&chunk, constant, 1);

  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 2);
  writeChunk(&chunk, constant, 2);

  writeChunk(&chunk, OP_ADD, 2);

  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 2);
  writeChunk(&chunk, constant, 2);

  writeChunk(&chunk, OP_DIVIDE, 2);

  writeChunk(&chunk, OP_NEGATE, 2);

  writeChunk(&chunk, OP_RETURN, 3);

  interpret(&chunk);

  freeVM();
  freeChunk(&chunk);

  return 0;
}

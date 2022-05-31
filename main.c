#include "chunk.h"
#include "debug.h"

int main(int argc, const char *argv[]) {
  Chunk chunk;

  initChunk(&chunk);

  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 1);
  writeChunk(&chunk, constant, 1);

  int constantB = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 2);
  writeChunk(&chunk, constantB, 2);

  writeChunk(&chunk, OP_RETURN, 3);

  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  initValueArray(&chunk->lines);
  initValueArray(&chunk->constants);
}

void freeChunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  freeValueArray(&chunk->lines);
  freeValueArray(&chunk->constants);
  initChunk(chunk);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
  if (chunk->capacity < chunk->count + 1) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
  }

  if (line > chunk->lines.count || chunk->lines.count == 0) {
    writeValueArray(&chunk->lines, NUMBER_VAL(0));
  }
  Value *value = getValue(&chunk->lines, line - 1);
  setValue(&chunk->lines, line - 1, NUMBER_VAL(AS_NUMBER(*value) + 1));

  chunk->code[chunk->count] = byte;
  chunk->count++;
}

int addConstant(Chunk *chunk, Value value) {
  writeValueArray(&chunk->constants, value);
  return chunk->constants.count - 1;
}

int getLine(Chunk *chunk, int offset) {
  if (offset > chunk->count) {
    return -1;
  }
  int lines[chunk->count];
  for (int i = 0; i < chunk->count; i++) {
    lines[i] = 0;
  }

  int size = 0;
  for (int line = 0; line < chunk->lines.count; line++) {
    double count = AS_NUMBER(chunk->lines.values[line]);
    for (int i = size; i < size + count; i++) {
      lines[i] = line + 1;
    }
    size += count;
  }

  return lines[offset];
}

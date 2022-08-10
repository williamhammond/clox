#ifndef COMPILER_H_
#define COMPILER_H_

#include "object.h"
#include "vm.h"

bool compile(const char *source, Chunk *chunk);

#endif // COMPILER_H_

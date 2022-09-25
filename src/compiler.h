#ifndef COMPILER_H_
#define COMPILER_H_

#include "object.h"
#include "vm.h"

ObjFunction* compile(const char *source);
void markCompilerRoots();

#endif // COMPILER_H_

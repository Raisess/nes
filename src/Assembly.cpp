#include "Assembly.h"

Assembly::Assembly(void) {}
Assembly::~Assembly(void) {}

void Assembly::attach_to_cpu(Computer::Cpu *cpu) {
  this->cpu = cpu;
}

// addressing modes
bool Assembly::AM_IMP() {
  return 0;
}

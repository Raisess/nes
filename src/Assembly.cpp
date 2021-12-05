#include "Assembly.h"

Assembly::Assembly(void) {}
Assembly::~Assembly() {}

void Assembly::attach_to_cpu(Computer::Cpu *cpu) {
  this->cpu = cpu;
}

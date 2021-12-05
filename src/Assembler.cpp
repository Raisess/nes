#include "Assembler.h"

Assembler::Assembler(void) {}
Assembler::~Assembler(void) {}

std::vector<Assembler::Instruction> Assembler::instructions = {
  // 0 to F
  { "BRK_IMP", 0x07, &Assembler::BRK, &Assembler::AM_IMP },
  { "ORA_INX", 0x06, &Assembler::ORA, &Assembler::AM_INX },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "ORA_ZP", 0x03, &Assembler::ORA, &Assembler::AM_ZP },
  { "ASL_ZP", 0x05 , &Assembler::ASL, &Assembler::AM_ZP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "PHP_IMP", 0x03 , &Assembler::PHP, &Assembler::AM_IMP },
  { "ORA_IMM", 0x02 , &Assembler::ORA, &Assembler::AM_IMM },
  { "ASL_ACC", 0x02 , &Assembler::ASL, &Assembler::AM_ACC },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "ORA_ABS", 0x04, &Assembler::ORA, &Assembler::AM_ABS },
  { "ASL_ABS", 0x06 , &Assembler::ASL, &Assembler::AM_ABS },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  // 1 to F
  { "BPL_REL", 0x02 , &Assembler::BPL, &Assembler::AM_REL },
  { "ORA_INY", 0x05 , &Assembler::ORA, &Assembler::AM_INY },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "ORA_ZPX", 0x04 , &Assembler::ORA, &Assembler::AM_ZPX },
  { "ASL_ZPX", 0x06 , &Assembler::ASL, &Assembler::AM_ZPX },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "CLC_IMP", 0x02 , &Assembler::CLC, &Assembler::AM_IMP },
  { "ORA_ABY", 0x04 , &Assembler::ORA, &Assembler::AM_ABY },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
  { "ORA_ABX", 0x04 , &Assembler::ORA, &Assembler::AM_ABX },
  { "ASL_ABX", 0x04 , &Assembler::ASL, &Assembler::AM_ABX },
  { "XXX", 0x02, &Assembler::XXX, &Assembler::AM_IMP },
};

void Assembler::attach_to_cpu(Computer::Cpu *cpu) {
  this->cpu = cpu;
}

// addressing modes
bool Assembler::AM_IMP() {
  return 0;
}

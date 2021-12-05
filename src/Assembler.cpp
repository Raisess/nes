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

// opcodes
uint8_t Assembler::ADC() {
  return 0;
}

uint8_t Assembler::AND() {
  return 0;
}

uint8_t Assembler::ASL() {
  return 0;
}

uint8_t Assembler::BCC() {
  return 0;
}

uint8_t Assembler::BCS() {
  return 0;
}

uint8_t Assembler::BEO() {
  return 0;
}

uint8_t Assembler::BIT() {
  return 0;
}

uint8_t Assembler::BMI() {
  return 0;
}

uint8_t Assembler::BNE() {
  return 0;
}

uint8_t Assembler::BPL() {
  return 0;
}

uint8_t Assembler::BRK() {
  return 0;
}

uint8_t Assembler::BVC() {
  return 0;
}

uint8_t Assembler::BVS() {
  return 0;
}

uint8_t Assembler::CLC() {
  return 0;
}

uint8_t Assembler::CLD() {
  return 0;
}

uint8_t Assembler::CLI() {
  return 0;
}

uint8_t Assembler::CLV() {
  return 0;
}

uint8_t Assembler::CMP() {
  return 0;
}

uint8_t Assembler::CPX() {
  return 0;
}

uint8_t Assembler::CPY() {
  return 0;
}

uint8_t Assembler::DEC() {
  return 0;
}

uint8_t Assembler::DEX() {
  return 0;
}

uint8_t Assembler::DEY() {
  return 0;
}

uint8_t Assembler::EOR() {
  return 0;
}

uint8_t Assembler::INC() {
  return 0;
}

uint8_t Assembler::INX() {
  return 0;
}

uint8_t Assembler::INY() {
  return 0;
}

uint8_t Assembler::JMP() {
  return 0;
}

uint8_t Assembler::JSR() {
  return 0;
}

uint8_t Assembler::LDA() {
  return 0;
}

uint8_t Assembler::LDX() {
  return 0;
}

uint8_t Assembler::LDY() {
  return 0;
}

uint8_t Assembler::LSR() {
  return 0;
}

uint8_t Assembler::NOP() {
  return 0;
}

uint8_t Assembler::ORA() {
  return 0;
}

uint8_t Assembler::PHA() {
  return 0;
}

uint8_t Assembler::PHP() {
  return 0;
}

uint8_t Assembler::PLA() {
  return 0;
}

uint8_t Assembler::PLP() {
  return 0;
}

uint8_t Assembler::ROL() {
  return 0;
}

uint8_t Assembler::RTI() {
  return 0;
}

uint8_t Assembler::RTS() {
  return 0;
}

uint8_t Assembler::SBC() {
  return 0;
}

uint8_t Assembler::SEC() {
  return 0;
}

uint8_t Assembler::SED() {
  return 0;
}

uint8_t Assembler::SEI() {
  return 0;
}

uint8_t Assembler::STA() {
  return 0;
}

uint8_t Assembler::STX() {
  return 0;
}

uint8_t Assembler::STY() {
  return 0;
}

uint8_t Assembler::TAX() {
  return 0;
}

uint8_t Assembler::TAY() {
  return 0;
}

uint8_t Assembler::TSX() {
  return 0;
}

uint8_t Assembler::TXA() {
  return 0;
}

uint8_t Assembler::TXS() {
  return 0;
}

uint8_t Assembler::TYA() {
  return 0;
}

uint8_t Assembler::XXX() {
  return 0;
}

// addressing modes
uint8_t Assembler::AM_ABI() {
  return 0;
}

uint8_t Assembler::AM_ABS() {
  uint16_t lower = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;
  uint16_t higher = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;

  this->cpu->instruction_absolute_address = (higher << 8) | lower;
  return 0;
}

uint8_t Assembler::AM_ABX() {
  uint16_t lower = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;
  uint16_t higher = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;

  this->cpu->instruction_absolute_address = (higher << 8) | lower;
  this->cpu->instruction_absolute_address += this->cpu->register_x;

  if ((this->cpu->instruction_absolute_address & 0xFF00) != (higher << 8)) {
    return 1;
  }

  return 0;
}

uint8_t Assembler::AM_ABY() {
  uint16_t lower = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;
  uint16_t higher = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;

  this->cpu->instruction_absolute_address = (higher << 8) | lower;
  this->cpu->instruction_absolute_address += this->cpu->register_y;

  if ((this->cpu->instruction_absolute_address & 0xFF00) != (higher << 8)) {
    return 1;
  }

  return 0;
}

uint8_t Assembler::AM_ACC() {
  return 0;
}

uint8_t Assembler::AM_IMM() {
  this->cpu->instruction_absolute_address = this->cpu->program_counter;
  return 0;
}

uint8_t Assembler::AM_IMP() {
  this->cpu->fetched = this->cpu->accumulator;
  return 0;
}

uint8_t Assembler::AM_IND() {
  return 0;
}

uint8_t Assembler::AM_INX() {
  return 0;
}

uint8_t Assembler::AM_INY() {
  return 0;
}

uint8_t Assembler::AM_REL() {
  this->cpu->instruction_relative_address = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;

  if (this->cpu->instruction_relative_address & 0x80) {
    this->cpu->instruction_relative_address |= 0xFF00;
  }

  return 0;
}

uint8_t Assembler::AM_ZP() {
  this->cpu->instruction_absolute_address = this->cpu->read(this->cpu->program_counter);
  this->cpu->program_counter++;
  this->cpu->instruction_absolute_address &= 0x00FF;
  return 0;
}

uint8_t Assembler::AM_ZPX() {
  this->cpu->instruction_absolute_address = this->cpu->read(this->cpu->program_counter + this->cpu->register_x);
  this->cpu->program_counter++;
  this->cpu->instruction_absolute_address &= 0x00FF;
  return 0;
}

uint8_t Assembler::AM_ZPY() {
  this->cpu->instruction_absolute_address = this->cpu->read(this->cpu->program_counter + this->cpu->register_y);
  this->cpu->program_counter++;
  this->cpu->instruction_absolute_address &= 0x00FF;
  return 0;
}

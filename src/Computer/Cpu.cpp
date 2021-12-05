#include "Cpu.h"
#include "../Assembly.h"

Computer::Cpu::Cpu(void) {
  this->instructions = {
    // 0 to F
    { "BRK_IMP", 0x07, &Assembly::BRK, &Assembly::AM_IMP },
    { "ORA_INX", 0x06, &Assembly::ORA, &Assembly::AM_INX },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "ORA_ZP", 0x03, &Assembly::ORA, &Assembly::AM_ZP },
    { "ASL_ZP", 0x05 , &Assembly::ASL, &Assembly::AM_ZP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "PHP_IMP", 0x03 , &Assembly::PHP, &Assembly::AM_IMP },
    { "ORA_IMM", 0x02 , &Assembly::ORA, &Assembly::AM_IMM },
    { "ASL_ACC", 0x02 , &Assembly::ASL, &Assembly::AM_ACC },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "ORA_ABS", 0x04, &Assembly::ORA, &Assembly::AM_ABS },
    { "ASL_ABS", 0x06 , &Assembly::ASL, &Assembly::AM_ABS },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    // 1 to F
    { "BPL_REL", 0x02 , &Assembly::BPL, &Assembly::AM_REL },
    { "ORA_INY", 0x05 , &Assembly::ORA, &Assembly::AM_INY },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "ORA_ZPX", 0x04 , &Assembly::ORA, &Assembly::AM_ZPX },
    { "ASL_ZPX", 0x06 , &Assembly::ASL, &Assembly::AM_ZPX },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "CLC_IMP", 0x02 , &Assembly::CLC, &Assembly::AM_IMP },
    { "ORA_ABY", 0x04 , &Assembly::ORA, &Assembly::AM_ABY },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
    { "ORA_ABX", 0x04 , &Assembly::ORA, &Assembly::AM_ABX },
    { "ASL_ABX", 0x04 , &Assembly::ASL, &Assembly::AM_ABX },
    { "XXX", 0x02, &Assembly::XXX, &Assembly::AM_IMP },
  };
}
Computer::Cpu::~Cpu(void) {}

void Computer::Cpu::set_flag(FLAGS flag, bool value) {
  value ? this->flag |= flag : this->flag &= ~flag;
}

uint8_t Computer::Cpu::get_flag(void) {
  return this->flag;
}

void Computer::Cpu::attach_to_bus(Bus *bus) {
  this->bus = bus;
}

void Computer::Cpu::write(uint8_t address, uint16_t value) {
  this->bus->write(address, value);
}

uint16_t Computer::Cpu::read(uint8_t address) {
  return this->bus->read(address);
}

void Computer::Cpu::clock(void) {
  if (this->clock_cycles == 0x00) {
    this->opcode = this->read(this->program_counter);
    this->program_counter++;

    Instruction instruction = this->instructions[this->opcode];

    this->clock_cycles = instruction.clock_cycles;

    uint8_t address_mode_cycles = instruction.address_mode();
    uint8_t execution_cycles = instruction.execute();

    this->clock_cycles += (address_mode_cycles & execution_cycles);
  }

  this->clock_cycles--;
}

void Computer::Cpu::reset(void) {
  this->clock_cycles = 0x00;
  this->opcode = 0x00;
  this->flag = 0x00;
  this->accumulator = 0x00;
  this->register_x = 0x00;
  this->register_y = 0x00;
  this->stack_pointer = 0x00;
  this->program_counter = 0x00;

  this->instruction_entry_point_address = 0x00;
  this->instruction_relative_point_address = 0x00;
}

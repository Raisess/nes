#include "Cpu.h"

Computer::Cpu::Cpu(void) {
  this->instructions = {};
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

    this->clock_cycles = this->instructions[this->opcode].clock_cycles;

    uint8_t address_mode_cycles = this->instructions[this->opcode].address_mode();
    uint8_t execution_cycles = this->instructions[this->opcode].execute();

    this->clock_cycles += (address_mode_cycles + execution_cycles);
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

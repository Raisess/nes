#include <iostream>
#include "Cpu.h"
#include "Bus.h"

Computer::Cpu::Cpu() {}

void Computer::Cpu::attach_to_bus(Bus *bus) {
  this->bus = bus;
}

void Computer::Cpu::write(uint8_t address, uint16_t value) {
  this->bus->write(address, value);
}

uint16_t Computer::Cpu::read(uint8_t address) {
  return this->bus->read(address);
}

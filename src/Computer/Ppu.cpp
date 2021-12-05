#include "Ppu.h"

Computer::Ppu::Ppu(void) {}
Computer::Ppu::~Ppu(void) {}

void Computer::Ppu::attach_to_bus(Bus *bus) {
  this->bus = bus;
}

void Computer::Ppu::write(uint8_t address, uint16_t value) {
  this->bus->write(address, value);
}

uint16_t Computer::Ppu::read(uint8_t address) {
  return this->bus->read(address);
}

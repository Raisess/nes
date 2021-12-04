#include "Bus.h"

Computer::Bus::Bus() {}

void Computer::Bus::attach_to_ram(Ram *ram) {
  this->ram = ram;
}

void Computer::Bus::write(uint16_t address, uint8_t value) {
  if (address >= 0x00 && address <= 0xFFFF) {
    this->ram->write(address, value);
  }
}

uint8_t Computer::Bus::read(uint16_t address) {
  if (address >= 0x00 && address <= 0xFFFF) {
    return this->ram->read(address);
  }

  return 0x00;
}

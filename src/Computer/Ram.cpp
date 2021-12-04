#include "Ram.h"

Computer::Ram::Ram() {
  const uint8_t ram_size =  this->memory.size();

  for (uint8_t i = 0x00; i < ram_size; i++) {
    this->memory[i] = 0x00;
  }
}

void Computer::Ram::write(uint16_t address, uint8_t value) {
  this->memory[address] = value;
}

uint8_t Computer::Ram::read(uint16_t address) {
  return this->memory[address];
}

void Computer::Ram::load_trash(uint16_t size = 0xFF) {
  for (uint8_t i = 0x00; i < size; i++) {
    this->memory[i] = i;
  }
}

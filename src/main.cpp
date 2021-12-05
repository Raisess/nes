#include <iostream>
#include "Computer/Cpu.h"
#include "Computer/Ppu.h"
#include "Computer/Ram.h"
#include "Computer/Bus.h"
#include "Assembler.h"

int main(void) {
  Computer::Ram *ram = new Computer::Ram();
  Computer::Bus *bus = new Computer::Bus();
  Computer::Ppu *ppu = new Computer::Ppu();
  Computer::Cpu *cpu = new Computer::Cpu();

  bus->attach_to_ram(ram);
  ppu->attach_to_bus(bus);
  cpu->attach_to_bus(bus);

  Assembler *assembler = new Assembler();
  assembler->attach_to_cpu(cpu);

  ram->load_trash(0x0F);

  for (int i = 0x00; i < 0x14; i++) {
    std::cout << "cpu: " << cpu->read(i) << std::endl;
    std::cout << "ppu: " << ppu->read(i) << std::endl;
  }

  cpu->write(0x0E, 0xFF);
  uint8_t value = ppu->read(0x0E);

  std::cout << "ppu 0x0E (needs to be 0xFF): " << std::to_string(value) << ", is it: " << std::to_string(!!value) << std::endl;

  cpu->reset();

  return 0;
}

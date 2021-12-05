#include <iostream>
#include "Computer/Cpu.h"
#include "Computer/Ppu.h"
#include "Computer/Ram.h"
#include "Computer/Bus.h"
#include "Assembler.h"

int main(void) {
  Computer::Ram *ram = new Computer::Ram();
  Computer::Bus *bus = new Computer::Bus();
  Computer::Cpu *cpu = new Computer::Cpu();
  Computer::Ppu *ppu = new Computer::Ppu();

  Assembler *assembler = new Assembler();

  bus->attach_to_ram(ram);
  cpu->attach_to_bus(bus);
  ppu->attach_to_bus(bus);
  assembler->attach_to_cpu(cpu);

  ram->load_trash(0x0F);

  assembler->AM_IMP();

  for (int i = 0x00; i < 0x14; i++) {
    std::cout << "cpu: " << cpu->read(i) << std::endl;
    std::cout << "ppu: " << ppu->read(i) << std::endl;
  }

  cpu->write(0x0E, 0xFF);
  uint8_t value = ppu->read(0x0E);

  std::cout << "ppu 0x0E (needs to be 0xFF): " << std::to_string(value) << ", is it: " << std::to_string(!!value) << std::endl;

  return 0;
}

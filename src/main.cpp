#include <iostream>
#include "Computer/Cpu.h"
#include "Computer/Ppu.h"
#include "Computer/Ram.h"
#include "Computer/Bus.h"

int main(void) {
  Computer::Ram *ram = new Computer::Ram();
  Computer::Bus *bus = new Computer::Bus();
  Computer::Cpu *cpu = new Computer::Cpu();
  Computer::Ppu *ppu = new Computer::Ppu();

  bus->attach_to_ram(ram);
  cpu->attach_to_bus(bus);
  ppu->attach_to_bus(bus);

  ram->load_trash(0x0F);

  for (int i = 0x00; i < 0x14; i++) {
    std::cout << "cpu: " << cpu->read(i) << std::endl;
    std::cout << "ppu: " << ppu->read(i) << std::endl;
  }

  return 0;
}

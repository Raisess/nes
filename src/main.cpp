#include <iostream>
#include "Computer/Cpu.h"
#include "Computer/Ram.h"
#include "Computer/Bus.h"

int main(void) {
  Computer::Cpu *cpu = new Computer::Cpu();
  Computer::Bus *bus = new Computer::Bus();
  Computer::Ram *ram = new Computer::Ram();

  cpu->attach_to_bus(bus);
  bus->attach_to_ram(ram);

  ram->load_trash(0x0F);

  for (int i = 0x00; i < 0x14; i++) {
    std::cout << "cpu: " << cpu->read(i) << std::endl;
  }

  return 0;
}

#pragma once

#include "Bus.h"

namespace Computer {

class Cpu {
  private:
    Bus *bus = nullptr;
   
  public:
    Cpu();
    ~Cpu();

    void attach_to_bus(Bus *bus);
    void write(uint8_t address, uint16_t value);
    uint16_t read(uint8_t address);
};

}

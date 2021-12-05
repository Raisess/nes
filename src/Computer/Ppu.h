#pragma once

#include "Bus.h"

namespace Computer {

class Ppu {
  private:
    Bus *bus = nullptr;

  public:
    Ppu(void);
    ~Ppu(void);

    void attach_to_bus(Bus *bus);

    void write(uint8_t address, uint16_t value);
    uint16_t read(uint8_t address);
};

}

#pragma once

#include <cstdint>
#include "Ram.h"

namespace Computer {

class Bus {
  private:
    Ram *ram = nullptr;

  public:
    Bus();
    ~Bus();

    void attach_to_ram(Ram *ram);
    void write(uint16_t address, uint8_t value);
    uint8_t read(uint16_t address);
};

}

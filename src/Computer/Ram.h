#pragma once

#include <array>
#include <cstdint>

namespace Computer {

class Ram {
  private:
    std::array<uint8_t, 1024 * 64> memory;

  public:
    Ram(void);
    ~Ram(void);

    void write(uint16_t address, uint8_t value);
    uint8_t read(uint16_t address);

    void load_trash(uint16_t size);
};

}

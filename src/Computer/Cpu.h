#pragma once

#include <string>
#include <vector>
#include "Bus.h"

enum FLAGS {
  Carry = (1 << 0),
  Zero = (1 << 1),
  InterruptDisable = (1 << 2),
  Decimal = (1 << 3),
  Break = (1 << 4),
  BFlag = (1 << 5),
  Overflow = (1 << 6),
  Negative = (1 << 7),
};

namespace Computer {

class Cpu {
  private:
    Bus *bus = nullptr;

  public:
    Cpu(void);
    ~Cpu(void);

    uint8_t clock_cycles = 0x00;
    uint8_t opcode = 0x00;

    uint8_t fetched = 0x00;
    uint16_t instruction_absolute_address = 0x00;
    uint16_t instruction_relative_address = 0x00;

    // registers
    uint8_t flag = 0x00;
    uint8_t accumulator = 0x00;
    uint8_t register_x = 0x00;
    uint8_t register_y = 0x00;
    uint8_t stack_pointer = 0x00;
    uint8_t program_counter = 0x00;

    void attach_to_bus(Bus *bus);

    void write(uint8_t address, uint16_t value);
    uint16_t read(uint8_t address);

    // for assembly use methods
    void set_flag(FLAGS flag, bool value);
    uint8_t get_flag(void);
    // external signals
    void clock(void);
    void reset(void);
    void interrupt_request(void);
    void non_maskable(void);
};

}

#pragma once

#include <cstdint>
#include <string>
#include "Computer/Cpu.h"

class Assembler {
  private:
    Computer::Cpu *cpu = nullptr;

    // opcodes (56)
    // impl later
    uint8_t ADC(); // add with carry
    uint8_t AND(); // and (with accumulator)
    uint8_t ASL(); // arithmetic shift left
    uint8_t BCC(); // branch on carry clear
    uint8_t BCS(); // branch on carry set
    uint8_t BEO(); // branch on equal (zero set)
    uint8_t BIT(); // bit test
    uint8_t BMI(); // branch on minus (negative set)
    uint8_t BNE(); // branch on not equal (zero clear)
    uint8_t BPL(); // branch on plus (negative clear)
    uint8_t BRK(); // break / interrupt
    uint8_t BVC(); // branch on overflow clear
    uint8_t BVS(); // branch on overflow set
    uint8_t CLC(); // clear carry
    uint8_t CLD(); // clear decimal
    uint8_t CLI(); // clear interrupt disable
    uint8_t CLV(); // clear overflow
    uint8_t CMP(); // compare (with accumulator)
    uint8_t CPX(); // compare with X
    uint8_t CPY(); // compare with Y
    uint8_t DEC(); // decrement
    uint8_t DEX(); // decrement X
    uint8_t DEY(); // decrement Y
    uint8_t EOR(); // exclusive or (with accumulator)
    uint8_t INC(); // increment
    uint8_t INX(); // increment X
    uint8_t INY(); // increment Y
    uint8_t JMP(); // jump
    uint8_t JSR(); // jump sub routine
    uint8_t LDA(); // load accumulator
    uint8_t LDX(); // load X
    uint8_t LDY(); // load Y
    uint8_t LSR(); // logical shift right
    uint8_t NOP(); // no operation
    uint8_t ORA(); // or with accumulator
    uint8_t PHA(); // push accumulator
    uint8_t PHP(); // push processor status (SR)
    uint8_t PLA(); // pull accumulator
    uint8_t PLP(); // pull processor status (SR)
    uint8_t ROL(); // rotate left
    uint8_t ROR(); // rotate right
    uint8_t RTI(); // return from interrupt
    uint8_t RTS(); // return from subroutine
    uint8_t SBC(); // subtract with carry
    uint8_t SEC(); // set carry
    uint8_t SED(); // set decimal
    uint8_t SEI(); // set interrupt disable
    uint8_t STA(); // store accumulator
    uint8_t STX(); // store X
    uint8_t STY(); // store Y
    uint8_t TAX(); // transfer accumulator to X
    uint8_t TAY(); // transfer accumulator to Y
    uint8_t TSX(); // transfer stack pointer to X
    uint8_t TXA(); // transfer X to accumulator
    uint8_t TXS(); // transfer X to stack pointer
    uint8_t TYA(); // transfer Y to accumulator
    uint8_t XXX(); // blank instruction

    // addressing modes
    uint8_t AM_ABI(); // absolute indirect [Indirect]
    uint8_t AM_ABS(); // absolute addressing
    uint8_t AM_ABX(); // indexed absolute addressing X
    uint8_t AM_ABY(); // ... Y
    uint8_t AM_ACC(); // accumulator addressing [Accum]
    uint8_t AM_IMM(); // immediate address
    uint8_t AM_IMP(); // implied address [Implied]
    uint8_t AM_IND(); // indirect addressing
    uint8_t AM_INX(); // indexed indirect addressing X [(IND, X)]
    uint8_t AM_INY(); // indirect indexed addressing Y [(IND, Y)]
    uint8_t AM_REL(); // relative addressing [Relative]
    uint8_t AM_ZP();  // zero page addressing
    uint8_t AM_ZPX(); // indexed zero page addressing X
    uint8_t AM_ZPY(); // ... Y

  public:
    Assembler(void);
    ~Assembler(void);

    typedef struct Instruction {
      std::string name;
      uint8_t clock_cycles = 0x00;

      // if the instruction operation need aditional cycles return true
      // for the operation
      uint8_t(Assembler::*execute)(void) = nullptr; // execute a opcode function
      uint8_t(Assembler::*address_mode)(void) = nullptr;
    } Instruction;
    static std::vector<Assembler::Instruction> instructions;

    void attach_to_cpu(Computer::Cpu *cpu);
};

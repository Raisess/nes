#pragma once

#include "Computer/Cpu.h"

class Assembly {
  private:
    Computer::Cpu *cpu = nullptr;

  public:
    Assembly(void);
    ~Assembly(void);

    void attach_to_cpu(Computer::Cpu *cpu);

    // opcodes (56)
    // impl later
    bool ADC(); // add with carry
    bool AND(); // and (with accumulator)
    bool ASL(); // arithmetic shift left
    bool BCC(); // branch on carry clear
    bool BCS(); // branch on carry set
    bool BEO(); // branch on equal (zero set)
    bool BIT(); // bit test
    bool BMI(); // branch on minus (negative set)
    bool BNE(); // branch on not equal (zero clear)
    bool BPL(); // branch on plus (negative clear)
    bool BRK(); // break / interrupt
    bool BVC(); // branch on overflow clear
    bool BVS(); // branch on overflow set
    bool CLC(); // clear carry
    bool CLD(); // clear decimal
    bool CLI(); // clear interrupt disable
    bool CLV(); // clear overflow
    bool CMP(); // compare (with accumulator)
    bool CPX(); // compare with X
    bool CPY(); // compare with Y
    bool DEC(); // decrement
    bool DEX(); // decrement X
    bool DEY(); // decrement Y
    bool EOR(); // exclusive or (with accumulator)
    bool INC(); // increment
    bool INX(); // increment X
    bool INY(); // increment Y
    bool JMP(); // jump
    bool JSR(); // jump sub routine
    bool LDA(); // load accumulator
    bool LDX(); // load X
    bool LDY(); // load Y
    bool LSR(); // logical shift right
    bool NOP(); // no operation
    bool ORA(); // or with accumulator
    bool PHA(); // push accumulator
    bool PHP(); // push processor status (SR)
    bool PLA(); // pull accumulator
    bool PLP(); // pull processor status (SR)
    bool ROL(); // rotate left
    bool ROR(); // rotate right
    bool RTI(); // return from interrupt
    bool RTS(); // return from subroutine
    bool SBC(); // subtract with carry
    bool SEC(); // set carry
    bool SED(); // set decimal
    bool SEI(); // set interrupt disable
    bool STA(); // store accumulator
    bool STX(); // store X
    bool STY(); // store Y
    bool TAX(); // transfer accumulator to X
    bool TAY(); // transfer accumulator to Y
    bool TSX(); // transfer stack pointer to X
    bool TXA(); // transfer X to accumulator
    bool TXS(); // transfer X to stack pointer
    bool TYA(); // transfer Y to accumulator
    bool XXX(); // blank instruction

    // addressing modes
    bool AM_ABS(); // absolute addressing
    bool AM_ABX(); // indexed absolute addressing X
    bool AM_ABY(); // ... Y
    bool AM_ABI(); // absolute indirect [Indirect]
    bool AM_ACC(); // accumulator addressing [Accum]
    bool AM_IND(); // indirect addressing
    bool AM_INX(); // indexed indirect addressing X [(IND, X)]
    bool AM_INY(); // indirect indexed addressing Y [(IND, Y)]
    bool AM_IMM(); // immediate address
    bool AM_IMP(); // implied address [Implied]
    bool AM_REL(); // relative addressing [Relative]
    bool AM_ZP();  // zero page addressing
    bool AM_ZPX(); // indexed zero page addressing X
    bool AM_ZPY(); // ... Y
};

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

typedef enum
{
  SYS = 0x0000,    // [IGNORED] 0nnn - jump to machine code routine at nnn
  CLS = 0x00E0,    // clear screen
  RET = 0x00EE,    // return from subroutine
  JP_IMM = 0x1000, // 1nnn - jump to location nnn
  CALL_IMM = 0x2000,
  SE_IMM = 0x3000,
  SNE_IMM = 0x4000,
  SE_REG = 0x5000,
  LD_REG_IMM = 0x6000,
  ADD_IMM = 0x7000,
  LD_REG_REG = 0x8000,
  OR = 0x8001,
  AND = 0x8002,
  XOR = 0x8003,
  ADD_REG = 0x8004,
  SUB = 0x8005,
  SHR = 0x8006,
  SUBN = 0x8007,
  SHL = 0x800E,
  SNE_REG = 0x9000,
  LD_I_IMM = 0xA000,
  JP_V0 = 0xB000,
  RND = 0xC000,
  DRW = 0xD000,
  SKP = 0xE09E,
  SKNP = 0xE0A1,
  LD_REG_DT = 0xF007,
  LD_REG_K = 0xF00A,
  LD_DT_REG = 0xF015,
  LD_ST_REG = 0xF018,
  ADD_I = 0xF01E,
  LD_I_SPT = 0xF029,
  LD_IM_BCD = 0xF033,
  LD_IM_REGS = 0xF055,
  LD_REGS_IM = 0xF065
} CHIP8_INSTRUCTION;

#endif

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "chip8.h"
#include <stdint.h>

typedef enum
{
  CHIP8_INSTRUCTION_SYS = 0x0000,     // [IGNORED] 0nnn - jump to machine code routine at nnn
  CHIP8_INSTRUCTION_CLS = 0x00E0,     // clear screen
  CHIP8_INSTRUCTION_RET = 0x00EE,     // return from subroutine
  CHIP8_INSTRUCTION_JP_ADDR = 0x1000, // 1nnn - jump to location nnn
  CHIP8_INSTRUCTION_CALL_ADDR = 0x2000,
  CHIP8_INSTRUCTION_SE_BYTE = 0x3000,
  CHIP8_INSTRUCTION_SNE_BYTE = 0x4000,
  CHIP8_INSTRUCTION_SE_REG = 0x5000,
  CHIP8_INSTRUCTION_LD_REG_BYTE = 0x6000,
  CHIP8_INSTRUCTION_ADD_BYTE = 0x7000,
  CHIP8_INSTRUCTION_LD_REG_REG = 0x8000,
  CHIP8_INSTRUCTION_OR = 0x8001,
  CHIP8_INSTRUCTION_AND = 0x8002,
  CHIP8_INSTRUCTION_XOR = 0x8003,
  CHIP8_INSTRUCTION_ADD_REG = 0x8004,
  CHIP8_INSTRUCTION_SUB = 0x8005,
  CHIP8_INSTRUCTION_SHR = 0x8006,
  CHIP8_INSTRUCTION_SUBN = 0x8007,
  CHIP8_INSTRUCTION_SHL = 0x800E,
  CHIP8_INSTRUCTION_SNE_REG = 0x9000,
  CHIP8_INSTRUCTION_LD_I_ADDR = 0xA000,
  CHIP8_INSTRUCTION_JP_V0 = 0xB000,
  CHIP8_INSTRUCTION_RND = 0xC000,
  CHIP8_INSTRUCTION_DRW = 0xD000,
  CHIP8_INSTRUCTION_SKP = 0xE09E,
  CHIP8_INSTRUCTION_SKNP = 0xE0A1,
  CHIP8_INSTRUCTION_LD_REG_DT = 0xF007,
  CHIP8_INSTRUCTION_LD_REG_K = 0xF00A,
  CHIP8_INSTRUCTION_LD_DT_REG = 0xF015,
  CHIP8_INSTRUCTION_LD_ST_REG = 0xF018,
  CHIP8_INSTRUCTION_ADD_I = 0xF01E,
  CHIP8_INSTRUCTION_LD_I_SPT = 0xF029,
  CHIP8_INSTRUCTION_LD_IM_BCD = 0xF033,
  CHIP8_INSTRUCTION_LD_IM_REGS = 0xF055,
  CHIP8_INSTRUCTION_LD_REGS_IM = 0xF065
} CHIP8_INSTRUCTION;

void chip8_instruction_cls(const Chip8 *chip8);

void chip8_instruction_ret(Chip8 *chip8);

void chip8_instruction_jp_addr(Chip8 *chip8, uint16_t addr);

void chip8_instruction_call_addr(Chip8 *chip8, uint16_t addr);

void chip8_instruction_se_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

void chip8_instruction_sne_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

void chip8_instruction_se_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_ld_reg_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

void chip8_instruction_add_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

void chip8_instruction_ld_reg_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_or(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_and(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_xor(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_add_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_sub(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_shr(Chip8 *chip8, uint8_t vx);

void chip8_instruction_subn(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_shl(Chip8 *chip8, uint8_t vx);

void chip8_instruction_sne_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

void chip8_instruction_ld_i_addr(Chip8 *chip8, uint16_t addr);

void chip8_instruction_jp_v0(Chip8 *chip8, uint16_t addr);

void chip8_instruction_rnd(Chip8 *chip8, uint8_t vx, uint8_t byte);

void chip8_instruction_drw(Chip8 *chip8, uint8_t vx, uint8_t vy, uint8_t nibble);

void chip8_instruction_skp(Chip8 *chip8, uint8_t vx);

void chip8_instruction_sknp(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_reg_dt(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_reg_k(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_dt_reg(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_st_reg(Chip8 *chip8, uint8_t vx);

void chip8_instruction_add_i(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_i_spt(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_im_bcd(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_im_regs(Chip8 *chip8, uint8_t vx);

void chip8_instruction_ld_regs_im(Chip8 *chip8, uint8_t vx);

#endif

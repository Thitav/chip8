#include "chip8.h"
#include "instructions.h"

extern void chip8_instruction_cls(const Chip8 *chip8);

extern void chip8_instruction_ret(Chip8 *chip8);

extern void chip8_instruction_jp_addr(Chip8 *chip8, uint16_t addr);

extern void chip8_instruction_call_addr(Chip8 *chip8, uint16_t addr);

extern void chip8_instruction_se_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

extern void chip8_instruction_sne_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

extern void chip8_instruction_se_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_ld_reg_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

extern void chip8_instruction_add_byte(Chip8 *chip8, uint8_t vx, uint8_t byte);

extern void chip8_instruction_ld_reg_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_or(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_and(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_xor(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_add_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_sub(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_shr(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_subn(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_shl(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_sne_reg(Chip8 *chip8, uint8_t vx, uint8_t vy);

extern void chip8_instruction_ld_i_addr(Chip8 *chip8, uint16_t addr);

extern void chip8_instruction_jp_v0(Chip8 *chip8, uint16_t addr);

extern void chip8_instruction_rnd(Chip8 *chip8, uint8_t vx, uint8_t byte);

extern void chip8_instruction_drw(const Chip8 *chip8, uint8_t vx, uint8_t vy, uint8_t nibble);

extern void chip8_instruction_skp(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_sknp(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_reg_dt(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_reg_k(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_dt_reg(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_st_reg(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_add_i(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_i_spt(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_im_bcd(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_im_regs(Chip8 *chip8, uint8_t vx);

extern void chip8_instruction_ld_regs_im(Chip8 *chip8, uint8_t vx);

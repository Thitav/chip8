#include "instructions.h"
#include <stdlib.h>
#include "chip8.h"

void inline chip8_instruction_cls(const Chip8 *chip8)
{
  chip8->io.clear_screen();
}

void inline chip8_instruction_ret(Chip8 *chip8)
{
  chip8->pc = chip8->stack[chip8->sp];
  chip8->sp--;
}

void inline chip8_instruction_jp_addr(Chip8 *chip8, const uint16_t addr)
{
  chip8->pc = addr;
}

void inline chip8_instruction_call_addr(Chip8 *chip8, const uint16_t addr)
{
  chip8->sp++;
  chip8->stack[chip8->sp] = chip8->pc;
  chip8->pc = addr;
}

void inline chip8_instruction_se_byte(Chip8 *chip8, const uint8_t vx, const uint8_t byte)
{
  if (chip8->v[vx] == byte)
  {
    chip8->pc += 2;
  }
}

void inline chip8_instruction_sne_byte(Chip8 *chip8, const uint8_t vx, const uint8_t byte)
{
  if (chip8->v[vx] != byte)
  {
    chip8->pc += 2;
  }
}

void inline chip8_instruction_se_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  if (chip8->v[vx] == chip8->v[vy])
  {
    chip8->pc += 2;
  }
}

void inline chip8_instruction_ld_reg_byte(Chip8 *chip8, const uint8_t vx, const uint8_t byte)
{
  chip8->v[vx] = byte;
}

void inline chip8_instruction_add_byte(Chip8 *chip8, const uint8_t vx, const uint8_t byte)
{
  chip8->v[vx] += byte;
}

void inline chip8_instruction_ld_reg_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] = chip8->v[vy];
}

void inline chip8_instruction_or(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] |= chip8->v[vy];
}

void inline chip8_instruction_and(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] &= chip8->v[vy];
}

void inline chip8_instruction_xor(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] ^= chip8->v[vy];
}

void inline chip8_instruction_add_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  const uint16_t sum = chip8->v[vx] + chip8->v[vy];
  chip8->v[0xF] = (uint8_t) (sum > UINT8_MAX);
  chip8->v[vx] = (uint8_t) (sum & 0xFF);
}

void inline chip8_instruction_sub(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[0xF] = chip8->v[vx] > chip8->v[vy];
  chip8->v[vx] -= chip8->v[vy];
}

void inline chip8_instruction_shr(Chip8 *chip8, const uint8_t vx)
{
  chip8->v[0xF] = chip8->v[vx] & 0xFE;
  chip8->v[vx] >>= 1;
}

void inline chip8_instruction_subn(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[0xF] = chip8->v[vy] > chip8->v[vx];
  chip8->v[vx] = chip8->v[vy] - chip8->v[vx];
}

void inline chip8_instruction_shl(Chip8 *chip8, const uint8_t vx)
{
  chip8->v[0xF] = chip8->v[vx] >> 7;
  chip8->v[vx] <<= 1;
}

void inline chip8_instruction_sne_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  if (chip8->v[vx] != chip8->v[vy])
  {
    chip8->pc += 2;
  }
}

void inline chip8_instruction_ld_i_addr(Chip8 *chip8, const uint16_t addr)
{
  chip8->i = addr;
}

void inline chip8_instruction_jp_v0(Chip8 *chip8, const uint16_t addr)
{
  chip8->pc = chip8->v[0] + addr;
}


void inline chip8_instruction_rnd(Chip8 *chip8, const uint8_t vx, const uint8_t byte)
{
  chip8->v[vx] = rand() & byte;
}

void inline chip8_instruction_drw(const Chip8 *chip8, const uint8_t vx, const uint8_t vy, const uint8_t nibble)
{
  chip8->io.draw_sprite(chip8->v[vx], chip8->v[vy]);
}

void inline chip8_instruction_skp(Chip8 *chip8, const uint8_t vx)
{
  if (chip8->io.get_key_state(chip8->v[vx]))
  {
    chip8->pc += 2;
  }
}

void inline chip8_instruction_sknp(Chip8 *chip8, const uint8_t vx)
{
  if (!chip8->io.get_key_state(chip8->v[vx]))
  {
    chip8->pc += 2;
  }
}

void inline chip8_instruction_ld_reg_dt(Chip8 *chip8, const uint8_t vx)
{
  chip8->v[vx] = chip8->dt;
}

void inline chip8_instruction_ld_reg_k(Chip8 *chip8, const uint8_t vx)
{
  chip8->v[vx] = chip8->io.wait_key_press();
}

void inline chip8_instruction_ld_dt_reg(Chip8 *chip8, const uint8_t vx)
{
  chip8->dt = chip8->v[vx];
}

void inline chip8_instruction_ld_st_reg(Chip8 *chip8, const uint8_t vx)
{
  chip8->st = chip8->v[vx];
}

void inline chip8_instruction_add_i(Chip8 *chip8, const uint8_t vx)
{
  chip8->i += chip8->v[vx];
}

void inline chip8_instruction_ld_i_spt(Chip8 *chip8, const uint8_t vx)
{
  // load addr of sprite[v[vx]] into i
}

void inline chip8_instruction_ld_im_bcd(Chip8 *chip8, const uint8_t vx)
{
  chip8->memory[chip8->i] = chip8->v[vx] / 100;
  chip8->memory[chip8->i + 1] = chip8->v[vx] / 10 % 10;
  chip8->memory[chip8->i + 2] = chip8->v[vx] % 10;
}

void inline chip8_instruction_ld_im_regs(Chip8 *chip8, const uint8_t vx)
{
  for (uint8_t r = 0; r <= vx; r++)
  {
    chip8->memory[chip8->i + r] = chip8->v[r];
  }
}

void inline chip8_instruction_ld_regs_im(Chip8 *chip8, const uint8_t vx)
{
  for (uint8_t r = 0; r <= vx; r++)
  {
    chip8->v[r] = chip8->memory[chip8->i + r];
  }
}

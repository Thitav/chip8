#include "instructions.h"
#include "chip8.h"

void chip8_instruction_cls(const Chip8 *chip8)
{
  chip8->video.clear_screen();
}

void chip8_instruction_ret(Chip8 *chip8)
{
  chip8->pc = chip8->stack[chip8->sp];
  chip8->sp--;
}

void chip8_instruction_jp_imm(Chip8 *chip8, const uint16_t imm)
{
  chip8->pc = imm;
}

void chip8_instruction_call_imm(Chip8 *chip8, const uint16_t imm)
{
  chip8->sp++;
  chip8->stack[chip8->sp] = chip8->pc;
  chip8->pc = imm;
}

void chip8_instruction_se_imm(Chip8 *chip8, const uint8_t vx, const uint8_t imm)
{
  if (chip8->v[vx] == imm)
  {
    chip8->pc += 2;
  }
}

void chip8_instruction_sne_imm(Chip8 *chip8, const uint8_t vx, const uint8_t imm)
{
  if (chip8->v[vx] != imm)
  {
    chip8->pc += 2;
  }
}

void chip8_instruction_se_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  if (chip8->v[vx] == chip8->v[vy])
  {
    chip8->pc += 2;
  }
}

void chip8_instruction_ld_reg_imm(Chip8 *chip8, const uint8_t vx, const uint8_t imm)
{
  chip8->v[vx] = imm;
}

void chip8_instruction_add_imm(Chip8 *chip8, const uint8_t vx, const uint8_t imm)
{
  chip8->v[vx] += imm;
}

void chip8_instruction_ld_reg_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] = chip8->v[vy];
}

void chip8_instruction_or(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] |= chip8->v[vy];
}

void chip8_instruction_and(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] &= chip8->v[vy];
}

void chip8_instruction_xor(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[vx] ^= chip8->v[vy];
}

void chip8_instruction_add_reg(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  const uint16_t sum = chip8->v[vx] + chip8->v[vy];
  chip8->v[0xF] = (uint8_t) (sum > UINT8_MAX);
  chip8->v[vx] = (uint8_t) (sum & 0xFF);
}

void chip8_instruction_sub(Chip8 *chip8, const uint8_t vx, const uint8_t vy)
{
  chip8->v[0xF] = (uint8_t) (chip8->v[vy] > chip8->v[vx]);
  chip8->v[vx] = chip8->v[vy] - chip8->v[vx];
}

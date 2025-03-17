#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>
#include <time.h>
#include "io.h"

typedef struct
{
  uint8_t memory[4096];
  uint16_t stack[16];
  uint8_t v[16];
  uint8_t sp;
  uint8_t dt;
  uint8_t st;
  uint16_t pc;
  uint16_t i;
  IO_Interface io_interface;
  clock_t last_tick;
} Chip8;

inline uint16_t chip8_fetch_instruction(const Chip8 *chip8)
{
  return chip8->memory[chip8->pc] << 8 | chip8->memory[chip8->pc + 1];
}

inline uint16_t chip8_fetch_instruction_addr(const uint16_t instruction)
{
  return instruction & 0x0FFF;
}

inline uint8_t chip8_fetch_instruction_byte(const uint16_t instruction)
{
  return instruction & 0x00FF;
}

inline uint8_t chip8_fetch_instruction_nibble(const uint16_t instruction)
{
  return instruction & 0x000F;
}

inline uint8_t chip8_fetch_instruction_vx(const uint16_t instruction)
{
  return (instruction & 0x0F00) >> 8;
}

inline uint8_t chip8_fetch_instruction_vy(const uint16_t instruction)
{
  return (instruction & 0x00F0) >> 4;
}

void chip8_init(Chip8 *chip8, IO_MODE io_mode);

void chip8_tick(Chip8 *chip8);

bool chip8_load_rom(Chip8 *chip8, const char *filename);

#endif

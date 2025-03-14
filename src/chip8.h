#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>
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
} Chip8;

inline uint16_t chip8_fetch_instruction(const Chip8 *chip8)
{
  return chip8->memory[chip8->pc] << 8 | chip8->memory[chip8->pc + 1];
}

void chip8_init(Chip8 *chip8, IO_MODE io_mode);

#endif

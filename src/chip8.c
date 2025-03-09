#include "chip8.h"
#include <stdint.h>

void chip8_init(Chip8 *chip8)
{
}

uint16_t chip8_fetch_instruction(const Chip8 *chip8)
{
  return chip8->memory[chip8->pc] << 8 | chip8->memory[chip8->pc + 1];
}

void chip8_tick(Chip8 *chip8)
{
  const uint16_t instruction = chip8_fetch_instruction(chip8);

  switch (instruction & 0xF000)
  {
    case 0x0000:
      switch (instruction & 0x00FF)
      {
        case 0x00E0:
        // clear display
        case 0x00EE:
          // ret
        default:
          // error



      }
    case 0x1000:
    // jump
    case 0x2000:
    // call
    case 0x3000:
      // skip if vx = kk;
    default:



  }

  chip8->pc += 2;
}

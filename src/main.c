#include <stdio.h>
#include "chip8.h"
#include "instructions.h"

int main(void)
{
  Chip8 chip8;
  chip8_init(&chip8, IO_MODE_CONSOLE);
  chip8.i = 5;
  chip8_instruction_drw(&chip8, 10, 10, 5);

  while (1)
  {
  }

  return 0;
}

#include <stdio.h>
#include "chip8.h"
#include "instructions.h"

int main()
{
  Chip8 chip8;
  chip8_init(&chip8, IO_MODE_CONSOLE);
  chip8_load_rom(&chip8, "C:\\Users\\thitav\\Documents\\chip8\\1-chip8-logo.ch8");

  // uint8_t data[] = {0xD0, 0x15};
  // memcpy(&chip8.memory[0x200], data, sizeof(data));
  // chip8.pc = 0x200;
  while (1)
  {
    _getch();
    chip8_tick(&chip8);
  }

  return 0;
}

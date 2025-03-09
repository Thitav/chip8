#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>

typedef struct
{
  void (*clear_screen)();
} VideoInterface;

typedef struct
{
  uint8_t memory[4096];
  uint16_t stack[16];
  uint8_t v[16];
  uint8_t sp;
  uint16_t pc;
  uint16_t i;
  VideoInterface video;
} Chip8;


#endif

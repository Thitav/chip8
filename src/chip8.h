#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  void (*clear_screen)();

  void (*draw_sprite)(uint8_t x, uint8_t y);

  bool (*get_key_state)(uint8_t key);

  uint8_t (*wait_key_press)();
} IO_Interface;

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
  IO_Interface io;
} Chip8;


#endif

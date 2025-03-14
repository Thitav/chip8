#ifndef IO_H
#define IO_H

#include <stdint.h>
#include <stdbool.h>
#include "../lib/simple-console-engine/src/console.h"

typedef enum
{
  IO_MODE_CONSOLE
} IO_MODE;

typedef union
{
  SCE_Console console;
} IO_Backend;

typedef struct IO_Interface
{
  IO_MODE mode;
  IO_Backend backend;

  void (*draw_sprite)(const struct IO_Interface *io_interface);

  void (*clear_screen)(const struct IO_Interface *io_interface);

  bool (*get_key_state)(const struct IO_Interface *io_interface, uint8_t key);

  uint8_t (*wait_key_press)(const struct IO_Interface *io_interface);
} IO_Interface;

void io_interface_init(IO_Interface *io_interface, IO_MODE mode);

#endif

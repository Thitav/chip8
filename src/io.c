#include "io.h"

void io_interface_console_draw_sprite(const IO_Interface *io_interface, const uint8_t *sprite_base, const uint8_t x,
                                      const uint8_t y,
                                      const uint8_t height)
{
  for (uint8_t i = 0; i < height; i++)
  {
    for (uint8_t j = 0; j < 8; j++)
    {
      if (sprite_base[i] << j & 0x80)
      {
        sce_console_set_cell(&io_interface->backend.console, x + j, y + i, (SCE_ConsoleCell){
                               SCE_ASCII_FULL_BLOCK,
                               SCE_FOREGROUND_WHITE | SCE_BACKGROUND_WHITE
                             }
        );
      }
    }
  }
  sce_console_render(&io_interface->backend.console);
}

void io_interface_console_clear_screen(const IO_Interface *io_interface)
{
  sce_console_clear(&io_interface->backend.console);
}

bool io_interface_console_get_key_state(const IO_Interface *io_interface, const uint8_t key)
{
  return true;
}

uint8_t io_interface_console_wait_key_press(IO_Interface *io_interface)
{
  return 0;
}

void io_interface_init(IO_Interface *io_interface, const IO_MODE mode)
{
  switch (mode)
  {
    case IO_MODE_CONSOLE:
      SCE_Console console;
      sce_console_init(&console, 64, 32,
                       (SCE_ConsoleBufferAttributes){SCE_CONSOLE_BUFFER_CLIP_WRAP, SCE_CONSOLE_BUFFER_OVERLAP_XOR});

      io_interface->backend.console = console;
      io_interface->draw_sprite = io_interface_console_draw_sprite;
      io_interface->clear_screen = io_interface_console_clear_screen;
      io_interface->get_key_state = io_interface_console_get_key_state;
      break;
  }

  io_interface->mode = mode;
}

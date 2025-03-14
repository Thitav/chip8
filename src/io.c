#include "io.h"

void io_interface_console_draw_sprite()
{
}

void io_interface_console_clear_screen(const IO_Interface *io_interface)
{
  sce_console_clear(&io_interface->backend.console);
}

bool io_interface_console_get_key_state(IO_Interface *io_interface, uint8_t key)
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
      sce_console_init(&console, 64, 32, SCE_CONSOLE_BUFFER_CLIP_WRAP | SCE_CONSOLE_BUFFER_OVERLAP_XOR);

      io_interface->backend.console = console;
      io_interface->draw_sprite = io_interface_console_draw_sprite;
      io_interface->clear_screen = io_interface_console_clear_screen;
      io_interface->get_key_state = io_interface_console_get_key_state;
      break;
  }

  io_interface->mode = mode;
}

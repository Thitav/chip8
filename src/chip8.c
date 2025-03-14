#include "chip8.h"
#include <stdint.h>
#include "instructions.h"

static const uint8_t DIGITS_SPRITES[] =
{
  0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
  0x20, 0x60, 0x20, 0x20, 0x70, // 1
  0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
  0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
  0x90, 0x90, 0xF0, 0x10, 0x10, // 4
  0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
  0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
  0xF0, 0x10, 0x20, 0x40, 0x40, // 7
  0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
  0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
  0xF0, 0x90, 0xF0, 0x90, 0x90, // A
  0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
  0xF0, 0x80, 0x80, 0x80, 0xF0, // C
  0xE0, 0x90, 0x90, 0x90, 0xE0, // D
  0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
  0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

void chip8_init(Chip8 *chip8, const IO_MODE io_mode)
{
  io_interface_init(&chip8->io_interface, io_mode);

  chip8->memory = {DIGITS_SPRITES};
  chip8->v = {0};
  chip8->sp = 0;
  chip8->dt = 0;
  chip8->st = 0;
  chip8->pc = 0;
  chip8->i = 0;
}

void chip8_tick(Chip8 *chip8)
{
  const uint16_t instruction = chip8_fetch_instruction(chip8);
  const uint16_t addr = instruction & 0x0FFF;
  const uint8_t byte = instruction & 0x00FF;
  const uint8_t nibble = instruction & 0x000F;
  const uint8_t vx = instruction & 0x0F00;
  const uint8_t vy = instruction & 0x00F0;

  switch (instruction & 0xF000)
  {
    case 0x0000:
      switch (instruction)
      {
        case CHIP8_INSTRUCTION_SYS:
          // ignored
          break;
        case CHIP8_INSTRUCTION_CLS:
          chip8_instruction_cls(chip8);
          break;
        case 0x00EE:
          chip8_instruction_ret(chip8);
          break;
        default:
          // error
          return;
      }
    case CHIP8_INSTRUCTION_JP_ADDR:
      chip8_instruction_jp_addr(chip8, addr);
      break;
    case CHIP8_INSTRUCTION_CALL_ADDR:
      chip8_instruction_call_addr(chip8, addr);
      break;
    case CHIP8_INSTRUCTION_SE_BYTE:
      chip8_instruction_se_byte(chip8, vx, byte);
      break;
    case CHIP8_INSTRUCTION_SNE_BYTE:
      chip8_instruction_sne_byte(chip8, vx, byte);
      break;
    case CHIP8_INSTRUCTION_SE_REG:
      chip8_instruction_se_reg(chip8, vx, vy);
      break;
    case CHIP8_INSTRUCTION_LD_REG_BYTE:
      chip8_instruction_ld_reg_byte(chip8, vx, byte);
      break;
    case CHIP8_INSTRUCTION_ADD_BYTE:
      chip8_instruction_add_byte(chip8, vx, byte);
      break;
    case 0x8000:
      switch (instruction & 0xF00F)
      {
        case CHIP8_INSTRUCTION_LD_REG_REG:
          chip8_instruction_ld_reg_reg(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_OR:
          chip8_instruction_or(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_AND:
          chip8_instruction_and(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_XOR:
          chip8_instruction_xor(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_ADD_REG:
          chip8_instruction_add_reg(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_SUB:
          chip8_instruction_sub(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_SHR:
          chip8_instruction_shr(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_SUBN:
          chip8_instruction_subn(chip8, vx, vy);
          break;
        case CHIP8_INSTRUCTION_SHL:
          chip8_instruction_shl(chip8, vx);
          break;
        default:
          return;
      }
    case CHIP8_INSTRUCTION_SNE_REG:
      chip8_instruction_sne_reg(chip8, vx, vy);
      break;
    case CHIP8_INSTRUCTION_LD_I_ADDR:
      chip8_instruction_ld_i_addr(chip8, addr);
      break;
    case CHIP8_INSTRUCTION_JP_V0:
      chip8_instruction_jp_v0(chip8, addr);
      break;
    case CHIP8_INSTRUCTION_RND:
      chip8_instruction_rnd(chip8, vx, byte);
      break;
    case CHIP8_INSTRUCTION_DRW:
      chip8_instruction_drw(chip8, vx, vy, nibble);
      break;
    case 0xE000:
      switch (instruction & 0xF0FF)
      {
        case CHIP8_INSTRUCTION_SKP:
          chip8_instruction_skp(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_SKNP:
          chip8_instruction_sknp(chip8, vx);
        default:
          return;
      }
    case 0xF000:
      switch (instruction & 0xF0FF)
      {
        case CHIP8_INSTRUCTION_LD_REG_DT:
          chip8_instruction_ld_reg_dt(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_REG_K:
          chip8_instruction_ld_reg_k(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_DT_REG:
          chip8_instruction_ld_dt_reg(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_ST_REG:
          chip8_instruction_ld_st_reg(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_ADD_I:
          chip8_instruction_add_i(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_I_SPT:
          chip8_instruction_ld_i_spt(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_IM_BCD:
          chip8_instruction_ld_im_bcd(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_IM_REGS:
          chip8_instruction_ld_im_regs(chip8, vx);
          break;
        case CHIP8_INSTRUCTION_LD_REGS_IM:
          chip8_instruction_ld_regs_im(chip8, vx);
          break;
        default:
          return;
      }
    default:
      return;
  }

  chip8->pc += 2;
}

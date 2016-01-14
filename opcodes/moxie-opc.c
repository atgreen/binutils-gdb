/* moxie-opc.c -- Definitions for moxie opcodes.
   Copyright (C) 2009-2014 Free Software Foundation, Inc.
   Contributed by Anthony Green (green@moxielogic.com).

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "sysdep.h"
#include "opcode/moxie.h"

/* The moxie processor's 16-bit instructions come in two forms:

  FORM 1 instructions start with a 0 bit...

    0oooooooaaaabbbb
    0              F

   ooooooo - form 1 opcode number
   aaaa    - operand A
   bbbb    - operand B

  FORM 2 instructions start with bits "10"...

    10ooaaaavvvvvvvv
    0              F

   oo       - form 2 opcode number
   aaaa     - operand A
   vvvvvvvv - 8-bit immediate value

  FORM 3 instructions start with a bits "11"...

    11oooovvvvvvvvvv
    0              F

   oooo         - form 3 opcode number
   vvvvvvvvvv   - 10-bit immediate value.  */

moxie_opc_info_t moxie_form1_opc_info[128] =
  {
    { 0x00, 0, MOXIE_BAD,     "bad" },  // Reserved as bad.
    { 0x01, 0, MOXIE_F1_A4,   "ldi.l" },
    { 0x02, 0, MOXIE_F1_AB,   "mov" },
    { 0x03, 0, MOXIE_F1_M,    "jsra" },
    { 0x04, 0, MOXIE_F1_NARG, "ret" },
    { 0x05, 0, MOXIE_F1_AB,   "add.l" },
    { 0x06, 0, MOXIE_F1_AB,   "push" },
    { 0x07, 0, MOXIE_F1_AB,   "pop" },
    { 0x08, 0, MOXIE_F1_A4,   "lda.l" },
    { 0x09, 0, MOXIE_F1_4A,   "sta.l" },
    { 0x0a, 0, MOXIE_F1_ABi,  "ld.l" },
    { 0x0b, 0, MOXIE_F1_AiB,  "st.l" },
    { 0x0c, 0, MOXIE_F1_ABi4, "ldo.l" },
    { 0x0d, 0, MOXIE_F1_AiB4, "sto.l" },
    { 0x0e, 0, MOXIE_F1_AB,   "cmp" },
    { 0x0f, 0, MOXIE_F1_NARG, "nop" },
    { 0x10, 0, MOXIE_F1_AB,   "sex.b" },
    { 0x11, 0, MOXIE_F1_AB,   "sex.s" },
    { 0x12, 0, MOXIE_BAD,     "bad" },
    { 0x13, 0, MOXIE_BAD,     "bad" },
    { 0x14, 0, MOXIE_BAD,     "bad" },
    { 0x15, 0, MOXIE_BAD,     "bad" },
    { 0x16, 0, MOXIE_BAD,     "bad" },
    { 0x17, 0, MOXIE_BAD,     "bad" },
    { 0x18, 0, MOXIE_BAD,     "bad" },
    { 0x19, 0, MOXIE_F1_A,    "jsr" },
    { 0x1a, 0, MOXIE_F1_M,    "jmpa" },
    { 0x1b, 0, MOXIE_F1_A4,   "ldi.b" },
    { 0x1c, 0, MOXIE_F1_ABi,  "ld.b" },
    { 0x1d, 0, MOXIE_F1_A4,   "lda.b" },
    { 0x1e, 0, MOXIE_F1_AiB,  "st.b" },
    { 0x1f, 0, MOXIE_F1_4A,   "sta.b" },
    { 0x20, 0, MOXIE_F1_A4,   "ldi.s" },
    { 0x21, 0, MOXIE_F1_ABi,  "ld.s" },
    { 0x22, 0, MOXIE_F1_A4,   "lda.s" },
    { 0x23, 0, MOXIE_F1_AiB,  "st.s" },
    { 0x24, 0, MOXIE_F1_4A,   "sta.s" },
    { 0x25, 0, MOXIE_F1_A,    "jmp" },
    { 0x26, 0, MOXIE_F1_AB,   "and" },
    { 0x27, 0, MOXIE_F1_AB,   "lshr" },
    { 0x28, 0, MOXIE_F1_AB,   "ashl" },
    { 0x29, 0, MOXIE_F1_AB,   "sub.l" },
    { 0x2a, 0, MOXIE_F1_AB,   "neg" },
    { 0x2b, 0, MOXIE_F1_AB,   "or" },
    { 0x2c, 0, MOXIE_F1_AB,   "not" },
    { 0x2d, 0, MOXIE_F1_AB,   "ashr" },
    { 0x2e, 0, MOXIE_F1_AB,   "xor" },
    { 0x2f, 0, MOXIE_F1_AB,   "mul.l" },
    { 0x30, 0, MOXIE_F1_4,    "swi" },
    { 0x31, 0, MOXIE_F1_AB,   "div.l" },
    { 0x32, 0, MOXIE_F1_AB,   "udiv.l" },
    { 0x33, 0, MOXIE_F1_AB,   "mod.l" },
    { 0x34, 0, MOXIE_F1_AB,   "umod.l" },
    { 0x35, 0, MOXIE_F1_NARG, "brk" },
    { 0x36, 0, MOXIE_F1_ABi4, "ldo.b" },
    { 0x37, 0, MOXIE_F1_AiB4, "sto.b" },
    { 0x38, 0, MOXIE_F1_ABi4, "ldo.s" },
    { 0x39, 0, MOXIE_F1_AiB4, "sto.s" },
    { 0x3a, 0, MOXIE_BAD,     "bad" },
    { 0x3b, 0, MOXIE_BAD,     "bad" },
    { 0x3c, 0, MOXIE_BAD,     "bad" },
    { 0x3d, 0, MOXIE_BAD,     "bad" },
    { 0x3e, 0, MOXIE_BAD,     "bad" },
    { 0x3f, 0, MOXIE_BAD,     "bad" },
    { 0x40, 0, MOXIE_BAD,     "bad" },
    { 0x41, 0, MOXIE_BAD,     "bad" },
    { 0x42, 0, MOXIE_BAD,     "bad" },
    { 0x43, 0, MOXIE_BAD,     "bad" },
    { 0x44, 0, MOXIE_BAD,     "bad" },
    { 0x45, 0, MOXIE_BAD,     "bad" },
    { 0x46, 0, MOXIE_BAD,     "bad" },
    { 0x47, 0, MOXIE_BAD,     "bad" },
    { 0x48, 0, MOXIE_BAD,     "bad" },
    { 0x49, 0, MOXIE_BAD,     "bad" },
    { 0x4a, 0, MOXIE_BAD,     "bad" },
    { 0x4b, 0, MOXIE_BAD,     "bad" },
    { 0x4c, 0, MOXIE_BAD,     "bad" },
    { 0x4d, 0, MOXIE_BAD,     "bad" },
    { 0x4e, 0, MOXIE_BAD,     "bad" },
    { 0x4f, 0, MOXIE_BAD,     "bad" },
    { 0x50, 0, MOXIE_BAD,     "bad" },
    { 0x51, 0, MOXIE_BAD,     "bad" },
    { 0x52, 0, MOXIE_BAD,     "bad" },
    { 0x53, 0, MOXIE_BAD,     "bad" },
    { 0x54, 0, MOXIE_BAD,     "bad" },
    { 0x55, 0, MOXIE_BAD,     "bad" },
    { 0x56, 0, MOXIE_BAD,     "bad" },
    { 0x57, 0, MOXIE_BAD,     "bad" },
    { 0x58, 0, MOXIE_BAD,     "bad" },
    { 0x59, 0, MOXIE_BAD,     "bad" },
    { 0x5a, 0, MOXIE_BAD,     "bad" },
    { 0x5b, 0, MOXIE_BAD,     "bad" },
    { 0x5c, 0, MOXIE_BAD,     "bad" },
    { 0x5d, 0, MOXIE_BAD,     "bad" },
    { 0x5e, 0, MOXIE_BAD,     "bad" },
    { 0x5f, 0, MOXIE_BAD,     "bad" },
    { 0x60, 0, MOXIE_BAD,     "bad" },
    { 0x61, 0, MOXIE_BAD,     "bad" },
    { 0x62, 0, MOXIE_BAD,     "bad" },
    { 0x63, 0, MOXIE_BAD,     "bad" },
    { 0x64, 0, MOXIE_BAD,     "bad" },
    { 0x65, 0, MOXIE_BAD,     "bad" },
    { 0x66, 0, MOXIE_BAD,     "bad" },
    { 0x67, 0, MOXIE_BAD,     "bad" },
    { 0x68, 0, MOXIE_BAD,     "bad" },
    { 0x69, 0, MOXIE_BAD,     "bad" },
    { 0x6a, 0, MOXIE_BAD,     "bad" },
    { 0x6b, 0, MOXIE_BAD,     "bad" },
    { 0x6c, 0, MOXIE_BAD,     "bad" },
    { 0x6d, 0, MOXIE_BAD,     "bad" },
    { 0x6e, 0, MOXIE_BAD,     "bad" },
    { 0x6f, 0, MOXIE_BAD,     "bad" },
    { 0x70, 0, MOXIE_BAD,     "bad" },
    { 0x71, 0, MOXIE_BAD,     "bad" },
    { 0x72, 0, MOXIE_BAD,     "bad" },
    { 0x73, 0, MOXIE_BAD,     "bad" },
    { 0x74, 0, MOXIE_BAD,     "bad" },
    { 0x75, 0, MOXIE_BAD,     "bad" },
    { 0x76, 0, MOXIE_BAD,     "bad" },
    { 0x77, 0, MOXIE_BAD,     "bad" },
    { 0x78, 0, MOXIE_BAD,     "bad" },
    { 0x79, 0, MOXIE_BAD,     "bad" },
    { 0x7a, 0, MOXIE_BAD,     "bad" },
    { 0x7b, 0, MOXIE_BAD,     "bad" },
    { 0x7c, 0, MOXIE_BAD,     "bad" },
    { 0x7d, 0, MOXIE_BAD,     "bad" },
    { 0x7e, 0, MOXIE_BAD,     "bad" },
    { 0x7f, 0, MOXIE_BAD,     "bad" }
  };

moxie_opc_info_t moxie_form2_opc_info[4] =
  {
    { 0x00, 0, MOXIE_F2_A8V,  "inc" },
    { 0x01, 0, MOXIE_F2_A8V,  "dec" },
    { 0x02, 0, MOXIE_F2_A8V,  "gsr" },
    { 0x03, 0, MOXIE_F2_A8V,  "ssr" }
  };

moxie_opc_info_t moxie_form3_opc_info[16] =
  {
    { 0x00, 0, MOXIE_F3_PCREL,"beq" },
    { 0x01, 0, MOXIE_F3_PCREL,"bne" },
    { 0x02, 0, MOXIE_F3_PCREL,"blt" },
    { 0x03, 0, MOXIE_F3_PCREL,"bgt" },
    { 0x04, 0, MOXIE_F3_PCREL,"bltu" },
    { 0x05, 0, MOXIE_F3_PCREL,"bgtu" },
    { 0x06, 0, MOXIE_F3_PCREL,"bge" },
    { 0x07, 0, MOXIE_F3_PCREL,"ble" },
    { 0x08, 0, MOXIE_F3_PCREL,"bgeu" },
    { 0x09, 0, MOXIE_F3_PCREL,"bleu" },
    { 0x0a, 0, MOXIE_BAD,     "bad" },
    { 0x0b, 0, MOXIE_BAD,     "bad" },
    { 0x0c, 0, MOXIE_BAD,     "bad" },
    { 0x0d, 0, MOXIE_BAD,     "bad" },
    { 0x0e, 0, MOXIE_BAD,     "bad" },
    { 0x0f, 0, MOXIE_BAD,     "bad" }  // Reserved as bad.
  };

/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfigPre.h"

#if HAS_GRAPHICAL_TFT

extern const uint8_t refresh_32x32x4[512] = {
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x79, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9f, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x79, 0xff, 0x57, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0xaf, 0xff, 0x9a, 0x87, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x79, 0xff, 0xff, 0xff, 0xfe, 0x97, 0x78, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0xaf, 0xff, 0xce, 0xff, 0xfd, 0x77, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x77, 0x88, 0x6a, 0xff, 0x55, 0x5c, 0xff, 0xd7, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0xa7, 0x78, 0x86, 0x9f, 0x57, 0x75, 0x8f, 0xfb, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x78, 0xfc, 0x78, 0x88, 0x69, 0x67, 0x88, 0x69, 0xff, 0x78, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x7c, 0xff, 0x58, 0x88, 0x87, 0x58, 0x88, 0x86, 0xff, 0xa7, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x7e, 0xfa, 0x58, 0x88, 0x88, 0x88, 0x88, 0x87, 0xbf, 0xe5, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x7f, 0xf8, 0x68, 0x88, 0x88, 0x88, 0x88, 0x87, 0xaf, 0xf5, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x7f, 0xf8, 0x68, 0x88, 0x88, 0x88, 0x88, 0x87, 0xaf, 0xf5, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x7e, 0xfa, 0x68, 0x88, 0x88, 0x88, 0x88, 0x87, 0xcf, 0xe5, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x7c, 0xff, 0x68, 0x88, 0x87, 0x78, 0x88, 0x77, 0xff, 0xa5, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x78, 0xff, 0xa7, 0x88, 0x78, 0xb7, 0x88, 0x77, 0xbf, 0x66, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x87, 0xbf, 0xf9, 0x77, 0x77, 0xfb, 0x78, 0x88, 0x68, 0x57, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x6d, 0xff, 0xd8, 0x77, 0xff, 0xb7, 0x78, 0x87, 0x68, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x85, 0xcf, 0xff, 0xfd, 0xff, 0xfb, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x57, 0xef, 0xff, 0xff, 0xff, 0x87, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x55, 0x89, 0xff, 0xf8, 0x47, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x65, 0xff, 0x75, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf7, 0x57, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x78, 0x75, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88
};

#endif // HAS_GRAPHICAL_TFT
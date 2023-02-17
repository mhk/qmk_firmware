// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts those identifiers into a two-dimensional array which
 * represents the switch matrix.
 */

// clang-format off
#define LAYOUT( \
  L00, L01, L02, L03, L04, L05, L06,           R00, R01, R02, R03, R04, R05, R06, \
  L10, L11, L12, L13, L14, L15, L16,           R10, R11, R12, R13, R14, R15, R16, \
  L20, L21, L22, L23, L24, L25,                     R20, R21, R22, R23, R24, R25, \
                      LT0, LT1, LT2, LT3, RT3, RT2, RT1, RT0                      \
  ) \
  { \
    { L00, L01, L02, L03, L04, L05, L06, LT3 }, \
    { L10, L11, L12, L13, L14, L15, L16, LT2 }, \
    { L20, L21, L22, L23, L24, L25, LT0, LT1 }, \
    { R06, R05, R04, R03, R02, R01, R00, RT3 }, \
    { R16, R15, R14, R13, R12, R11, R10, RT2 }, \
    { R25, R24, R23, R22, R21, R20, RT0, RT1 }, \
  }
// clang-format on

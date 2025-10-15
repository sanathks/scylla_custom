// Copyright 2025 @sanath
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "quantum.h"

/*
 * Scylla Keyboard Layout
 *
 * 4x6 main grid + 5 thumb keys per hand = 29 keys per hand (58 total)
 *
 * Layout visualization:
 *
 * Left Hand:                        Right Hand:
 * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
 * │L00│L01│L02│L03│L04│L05│        │R00│R01│R02│R03│R04│R05│
 * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
 * │L10│L11│L12│L13│L14│L15│        │R10│R11│R12│R13│R14│R15│
 * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
 * │L20│L21│L22│L23│L24│L25│        │R20│R21│R22│R23│R24│R25│
 * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
 * │L30│L31│L32│L33│L34│L35│        │R30│R31│R32│R33│R34│R35│
 * └───┴───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┴───┘
 *     │L40│L41│                        │R44│R45│
 *     └───┴───┴───┬───┬───┐        ┌───┬───┬───┘
 *             │L42│L43│L44│        │R41│R42│R43│
 *             └───┴───┴───┘        └───┴───┴───┘
 *
 * Matrix Rows: 10 (5 per hand: rows 0-4 for left, rows 5-9 for right)
 * Matrix Columns: 6
 */

#define LAYOUT_split_4x6_5( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35,           R30, R31, R32, R33, R34, R35, \
                        L43, L44, L41,      R41, R44, R43, \
                             L45, L42,      R42, R45 \
) { \
    { L00, L01, L02, L03, L04, L05 }, \
    { L10, L11, L12, L13, L14, L15 }, \
    { L20, L21, L22, L23, L24, L25 }, \
    { L30, L31, L32, L33, L34, L35 }, \
    { L43, L44, L41, L45, L42, KC_NO }, \
    { R05, R04, R03, R02, R01, R00 }, \
    { R15, R14, R13, R12, R11, R10 }, \
    { R25, R24, R23, R22, R21, R20 }, \
    { R35, R34, R33, R32, R31, R30 }, \
    { KC_NO, R45, R42, R43, R44, R41 } \
}

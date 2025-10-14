// Copyright 2025 @sanath
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
 * Matrix Test Keymap
 *
 * Each key outputs a unique identifier showing its matrix position.
 * This helps identify which physical key corresponds to which matrix position.
 *
 * Format: Each key types a number (1-58)
 * Compare what you see with where you pressed to map your wiring.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        // Left hand - Row 0 (Matrix row 0)
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        // Right hand - Row 0 (Matrix row 5)
                                                         KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,

        // Left hand - Row 1 (Matrix row 1)
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,
        // Right hand - Row 1 (Matrix row 6)
                                                         KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,

        // Left hand - Row 2 (Matrix row 2)
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,
        // Right hand - Row 2 (Matrix row 7)
                                                         KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,

        // Left hand - Row 3 (Matrix row 3)
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,
        // Right hand - Row 3 (Matrix row 8)
                                                         KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_DOWN,

        // Left hand - Row 4 / Thumb cluster (Matrix row 4)
                 KC_LCTL, KC_LALT,
        // Right hand - Row 4 / Thumb cluster (Matrix row 9)
                                                                           KC_LEFT, KC_RGHT,

        // Thumb cluster continued
                                   KC_SPC,  KC_BSPC, KC_TAB,
                                                         KC_DEL,  KC_ESC,  KC_GRV
    )
};

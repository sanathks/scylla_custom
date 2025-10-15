// Copyright 2025 @sanath
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Layer 0: Base QWERTY
     */
    [0] = LAYOUT_split_4x6_5(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                   KC_0,    KC_1,    KC_2,              KC_5,    KC_6,    KC_7,
                                            KC_3,    KC_4,              KC_8,    KC_9
    ),

    /*
     * Layer 1: Lower (Symbols and Navigation)
     */
    [1] = LAYOUT_split_4x6_5(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_PIPE,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQUO,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, _______,
                                   _______, _______, _______,           _______, MO(3),   _______,
                                            _______, _______,           _______, _______
    ),

    /*
     * Layer 2: Raise (Function Keys and Numpad)
     */
    [2] = LAYOUT_split_4x6_5(
        QK_BOOT, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_PLUS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
                                   _______, MO(3),   _______,           _______, _______, _______,
                                            _______, _______,           _______, _______
    ),

    /*
     * Layer 3: Adjust (System Controls)
     */
    [3] = LAYOUT_split_4x6_5(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                   _______, _______, _______,           _______, _______, _______,
                                            _______, _______,           _______, _______
    )
};

// Copyright 2025 @sanath
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layer definitions
enum layers {
    _BASE,   // Base QWERTY layer
    _LOWER,  // Lower layer (numbers, symbols)
    _RAISE,  // Raise layer (function keys, navigation)
    _ADJUST  // Adjust layer (system controls, keyboard settings)
};

// Custom keycodes
enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: QWERTY
     *
     * Left Hand:                        Right Hand:
     * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │        │ 6 │ 7 │ 8 │ 9 │ 0 │ - │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Tab│ Q │ W │ E │ R │ T │        │ Y │ U │ I │ O │ P │ \ │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Esc│ A │ S │ D │ F │ G │        │ H │ J │ K │ L │ ; │ ' │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │        │ N │ M │ , │ . │ / │Sft│
     * └───┴───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┴───┘
     *     │Alt│GUI│                        │App│Ctl│
     *     └───┴───┴───┬───┬───┐        ┌───┬───┬───┘
     *             │Bsp│Low│Spc│        │Ent│Rai│Del│
     *             └───┴───┴───┘        └───┴───┴───┘
     */
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_LALT, KC_LGUI,                                               KC_APP,  KC_RCTL,
                                            KC_BSPC, LOWER,   KC_SPC,   KC_ENT,  RAISE,   KC_DEL
    ),

    /*
     * Lower Layer: Numbers, Symbols, and Navigation
     *
     * Left Hand:                        Right Hand:
     * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
     * │ ~ │ ! │ @ │ # │ $ │ % │        │ ^ │ & │ * │ ( │ ) │ _ │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Tab│   │   │   │   │   │        │Hom│PgD│PgU│End│   │ | │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Esc│   │   │   │   │   │        │Lft│Dwn│ Up│Rgt│ : │ " │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Sft│   │   │   │   │   │        │   │   │ < │ > │ ? │Sft│
     * └───┴───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┴───┘
     *     │Alt│GUI│                        │App│Ctl│
     *     └───┴───┴───┬───┬───┐        ┌───┬───┬───┘
     *             │Bsp│   │Spc│        │Ent│Adj│Del│
     *             └───┴───┴───┘        └───┴───┴───┘
     */
    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_PIPE,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_DQUO,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   KC_QUES, _______,
                          _______, _______,                                                _______, _______,
                                            _______, _______, _______,  _______, ADJUST,  _______
    ),

    /*
     * Raise Layer: Function Keys and Media Controls
     *
     * Left Hand:                        Right Hand:
     * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
     * │F1 │F2 │F3 │F4 │F5 │F6 │        │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Tab│   │   │   │   │   │        │   │ 7 │ 8 │ 9 │   │   │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Esc│   │   │   │   │   │        │   │ 4 │ 5 │ 6 │ = │ + │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │Sft│   │   │   │   │   │        │ 0 │ 1 │ 2 │ 3 │   │Sft│
     * └───┴───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┴───┘
     *     │Alt│GUI│                        │App│Ctl│
     *     └───┴───┴───┬───┬───┐        ┌───┬───┬───┘
     *             │Bsp│Adj│Spc│        │Ent│   │Del│
     *             └───┴───┴───┘        └───┴───┴───┘
     */
    [_RAISE] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_PLUS,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
                          _______, _______,                                                _______, _______,
                                            _______, ADJUST,  _______,  _______, _______, _______
    ),

    /*
     * Adjust Layer: System Controls and Settings
     *
     * Left Hand:                        Right Hand:
     * ┌───┬───┬───┬───┬───┬───┐        ┌───┬───┬───┬───┬───┬───┐
     * │Rst│   │   │   │   │   │        │   │   │   │   │   │Rst│
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │        │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │        │   │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │        │   │Mut│Vl-│Vl+│   │   │
     * └───┴───┼───┼───┼───┼───┤        ├───┼───┼───┼───┼───┴───┘
     *     │   │   │                        │   │   │
     *     └───┴───┴───┬───┬───┐        ┌───┬───┬───┘
     *             │   │   │   │        │   │   │   │
     *             └───┴───┴───┘        └───┴───┴───┘
     */
    [_ADJUST] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                          _______, _______,                                                _______, _______,
                                            _______, _______, _______,  _______, _______, _______
    )
};

// Layer state management
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Optional: Custom keycode handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
            } else {
                layer_off(_LOWER);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
    }
    return true;
}

// Copyright 2025 @sanath
// SPDX-License-Identifier: GPL-2.0-or-later

#include "scylla_custom.h"

// Optional: Add keyboard-level initialization code here
void keyboard_post_init_kb(void) {
    // Debug LED or other initialization can go here
    keyboard_post_init_user();
}

// Optional: Add custom matrix scanning code if needed
// bool matrix_scan_kb(void) {
//     // Custom matrix scanning code
//     return matrix_scan_user();
// }

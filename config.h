// Copyright 2025 @sanath
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Split keyboard settings
 * These settings are specific to the split configuration
 * and not available in keyboard.json
 */

/* Handedness detection - Force left as master */
// #define SPLIT_HAND_PIN GP16  // Disabled - causes detection issues
#define MASTER_LEFT          // Left half is always the master

/* Serial communication between halves using UART */
#define SERIAL_USART_FULL_DUPLEX   // Enable full duplex operation
#define SERIAL_USART_TX_PIN GP0     // UART TX pin
#define SERIAL_USART_RX_PIN GP1     // UART RX pin
#define SERIAL_USART_PIN_SWAP       // Swap TX and RX on right half

/* Debounce reduces chatter (unintended double-presses) */
#define DEBOUNCE 5

/* RP2040-specific settings */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET              // Enable double-tap reset
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U // Timeout in ms
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U  // No LED indicator

/* Optional: Increase the number of layers if needed (default is 4) */
#define LAYER_STATE_8BIT  // Support up to 8 layers

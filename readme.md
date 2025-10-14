# Scylla Custom - Handwired RP2040

A handwired Scylla keyboard (4x6+5 split ergonomic keyboard) using ProMicro RP2040 controllers.

## Keyboard Info

- **Keyboard Maintainer**: [sanath](https://github.com/yourusername)
- **Hardware Supported**: Handwired Scylla with ProMicro RP2040
- **Hardware Availability**: Handwired custom build

## Features

- 58 keys total (29 per hand)
- 4x6 main grid + 5 thumb keys per hand
- Split keyboard with UART serial communication
- RP2040-based controllers
- Custom GPIO pin mapping

## Pin Configuration

### Row Pins (Blue wires)
- ROW0: GP23
- ROW1: GP24
- ROW2: GP25
- ROW3: GP26
- ROW4: GP27

### Column Pins
- COL0: GP3
- COL1: GP4
- COL2: GP5
- COL3: GP6
- COL4: GP7
- COL5: GP8

### Serial Communication
- TX: GP0
- RX: GP1

## Building Firmware

Make example for this keyboard (after setting up your build environment):

    make handwired/scylla_custom:default

Flash to the keyboard:

    make handwired/scylla_custom:default:flash

Or use QMK CLI:

    qmk compile -kb handwired/scylla_custom -km default
    qmk flash -kb handwired/scylla_custom -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Flashing Instructions

### Entering Bootloader Mode

The RP2040 bootloader can be entered in the following ways:

1. **Double-tap reset**: Quickly press the reset button twice
2. **Bootmagic reset**: Hold down the top-left key while plugging in the keyboard
3. **Physical button**: Hold the BOOTSEL button on the RP2040 while plugging in the USB cable

### Flashing Process

1. Enter bootloader mode (the RP2040 will appear as a USB mass storage device named "RPI-RP2")
2. Copy the generated `.uf2` file to the RPI-RP2 drive
3. The keyboard will automatically reboot with the new firmware

## Layout

The default keymap provides a standard QWERTY layout with multiple layers:

- **Base Layer**: Standard QWERTY layout
- **Lower Layer**: Numbers, symbols, and navigation
- **Raise Layer**: Function keys and numpad
- **Adjust Layer**: System controls and media keys

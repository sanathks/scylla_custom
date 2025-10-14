# Scylla Custom - Flashing and Testing Guide

## Overview

This guide covers flashing the firmware to your Scylla Custom keyboard with RP2040 controllers, testing the matrix, and troubleshooting common issues.

## Firmware Location

After compilation, the firmware file is located at:
```
~/Code/qmk/qmk_firmware/handwired_scylla_custom_default.uf2
```

---

## Flashing Instructions

### Method 1: Bootloader Mode (Recommended)

1. **Enter Bootloader Mode** on the left half (master) controller:
   - **Option A - Double-tap reset**: Quickly press the reset button twice (if configured)
   - **Option B - BOOTSEL button**: Hold the BOOTSEL button on the RP2040 while plugging in the USB cable
   - **Option C - Bootmagic**: Hold the top-left key (usually Grave/Tilde) while plugging in USB

2. **Verify Bootloader Mode**:
   - The RP2040 will appear as a USB mass storage device named **"RPI-RP2"**
   - On macOS, it will mount automatically as a drive

3. **Flash the Firmware**:
   ```bash
   cp ~/Code/qmk/qmk_firmware/handwired_scylla_custom_default.uf2 /Volumes/RPI-RP2/
   ```
   - Or drag and drop the `.uf2` file onto the RPI-RP2 drive
   - The device will automatically reboot with the new firmware

4. **Repeat for Right Half**:
   - Disconnect the left half
   - Connect the right half
   - Enter bootloader mode
   - Flash the same `.uf2` file

### Method 2: Using QMK CLI

1. **Enter Bootloader Mode** (see Method 1, Step 1)

2. **Flash with QMK**:
   ```bash
   cd ~/Code/qmk/qmk_firmware
   qmk flash -kb handwired/scylla_custom -km default
   ```

3. **Repeat for the other half**

---

## Testing the Keyboard

### Initial Connection Test

1. **Connect the left half** (master) to your computer via USB
2. **Check if the keyboard is recognized**:
   ```bash
   # macOS
   ioreg -p IOUSB | grep -i keyboard

   # Or use QMK
   qmk list
   ```

3. **Expected output**: You should see "Scylla Custom RP2040" or similar

### Testing Individual Keys

#### Method 1: Key Tester Website
1. Go to [https://www.keyboardtester.com/](https://www.keyboardtester.com/)
2. Press each key on the keyboard
3. Verify that the correct key lights up on the website
4. Test all 58 keys (29 per hand)

#### Method 2: QMK Testing
```bash
cd ~/Code/qmk/qmk_firmware
qmk console
```
Then press keys - you should see output in the console showing which keys are being pressed.

### Testing Split Communication

1. **Connect the left half** to the computer via USB
2. **Connect the right half** to the left half using a TRRS cable
   - Use a 4-pole TRRS cable (not TRS)
   - Connection: GP0 (TX) and GP1 (RX) via TRRS jack
3. **Test keys on both halves**
4. **Expected behavior**: Both halves should work when left half is connected to USB

### Testing Layers

1. **Base Layer**: Type normally - should produce QWERTY letters
2. **Lower Layer**:
   - Hold the left thumb cluster middle key (Lower)
   - Press keys to access symbols and navigation
3. **Raise Layer**:
   - Hold the right thumb cluster middle key (Raise)
   - Press keys to access function keys and numpad
4. **Adjust Layer**:
   - Hold both Lower and Raise simultaneously
   - Access system controls and reset

---

## Matrix Testing

### Visual Matrix Map

```
Left Hand Matrix:               Right Hand Matrix:
Row 0: Keys 1-6                 Row 5: Keys 1-6
Row 1: Keys 7-12                Row 6: Keys 7-12
Row 2: Keys 13-18               Row 7: Keys 13-18
Row 3: Keys 19-24               Row 8: Keys 19-24
Row 4: Keys 25-29               Row 9: Keys 25-29
```

### Matrix Testing Command

```bash
cd ~/Code/qmk/qmk_firmware
qmk console
```

Enable console output in keymap (if needed):
1. Edit `keyboards/handwired/scylla_custom/keyboard.json`
2. Set `"console": true` in features
3. Recompile and flash

---

## Troubleshooting

### Issue: Keyboard Not Recognized

**Symptoms**: Computer doesn't detect the keyboard when plugged in

**Solutions**:
1. Check USB cable - try a different cable
2. Verify the RP2040 is powered (LED should light up)
3. Re-enter bootloader mode and re-flash firmware
4. Check for shorts in the wiring

### Issue: Some Keys Don't Work

**Symptoms**: Certain keys don't register when pressed

**Solutions**:
1. **Check diode orientation**: Black band should point away from row wires (COL2ROW)
2. **Check solder joints**: Re-solder any cold joints
3. **Verify wiring**:
   - Rows: GP23, GP24, GP25, GP26, GP27
   - Columns: GP3, GP4, GP5, GP6, GP7, GP8
4. **Test with QMK console** to see which matrix position isn't working

### Issue: Ghost Keypresses

**Symptoms**: Pressing one key triggers multiple keys

**Solutions**:
1. **Check diode installation**: Ensure all diodes are present and correctly oriented
2. **Increase debounce**: Edit `config.h` and increase `DEBOUNCE` value (default: 5)
3. **Check for shorts**: Inspect wiring for accidental connections

### Issue: Right Half Not Working

**Symptoms**: Only left half works, right half doesn't respond

**Solutions**:
1. **Check TRRS cable**: Ensure it's a 4-pole TRRS cable, not 3-pole TRS
2. **Verify serial pins**: GP0 and GP1 should be connected via TRRS
3. **Flash both halves**: Make sure both controllers have the same firmware
4. **Test right half independently**: Plug USB directly into right half to verify it works
5. **Check TRRS jack wiring**:
   - GP0 (TX) connects through TRRS
   - GP1 (RX) connects through TRRS
   - Ground connects through TRRS
   - VCC may connect through TRRS (for power)

### Issue: Can't Enter Bootloader Mode

**Symptoms**: Can't get RP2040 to show up as RPI-RP2 drive

**Solutions**:
1. **Try double-tap reset** if you have a reset button wired
2. **Hold BOOTSEL and press reset** (if you have both buttons)
3. **Hold BOOTSEL while plugging in USB** (always works)
4. **Short RUN pin to ground** briefly to reset
5. **Check USB connection** - try different ports

### Issue: Firmware Too Large

**Symptoms**: Compilation succeeds but firmware doesn't fit or keyboard acts strangely

**Solutions**:
1. Already enabled: LTO (Link Time Optimization)
2. Disable unused features in `keyboard.json`:
   ```json
   "features": {
       "mousekey": false,
       "console": false
   }
   ```
3. Remove animations if you add RGB later

---

## Customizing Your Keymap

### Creating a New Keymap

1. **Copy the default keymap**:
   ```bash
   cp -r ~/Code/qmk/qmk_firmware/keyboards/handwired/scylla_custom/keymaps/default \
         ~/Code/qmk/qmk_firmware/keyboards/handwired/scylla_custom/keymaps/my_keymap
   ```

2. **Edit the keymap**:
   ```bash
   nano ~/Code/qmk/qmk_firmware/keyboards/handwired/scylla_custom/keymaps/my_keymap/keymap.c
   ```

3. **Compile with your keymap**:
   ```bash
   cd ~/Code/qmk/qmk_firmware
   make handwired/scylla_custom:my_keymap
   ```

4. **Flash the new firmware**:
   - Follow the flashing instructions above with your new `.uf2` file

### Key Code Reference

Common QMK keycodes:
- **Modifiers**: `KC_LSFT`, `KC_LCTL`, `KC_LALT`, `KC_LGUI`
- **Function keys**: `KC_F1` through `KC_F24`
- **Media keys**: `KC_MUTE`, `KC_VOLU`, `KC_VOLD`, `KC_MPLY`
- **Mouse keys**: `KC_MS_U`, `KC_MS_D`, `KC_MS_L`, `KC_MS_R`, `KC_BTN1`
- **Layers**: `MO(layer)`, `TG(layer)`, `LT(layer, kc)`

Full reference: [QMK Keycodes](https://docs.qmk.fm/keycodes)

---

## Advanced Configuration

### Enabling Via/Vial Support

Via/Vial allows GUI-based keymap editing without recompiling.

1. **Add Via support** to `keyboard.json`:
   ```json
   "features": {
       "via": true
   }
   ```

2. **Recompile and flash**

3. **Download Via**: [https://www.caniusevia.com/](https://www.caniusevia.com/)

### Adjusting Debounce

If you experience key chatter:

1. **Edit** `config.h`:
   ```c
   #define DEBOUNCE 10  // Increase from 5 to 10
   ```

2. **Recompile and flash**

### Split Handedness

Current configuration uses `MASTER_LEFT` (left half is always master).

Alternative options in `config.h`:
```c
// Option 1: Always left (current)
#define MASTER_LEFT

// Option 2: Always right
#define MASTER_RIGHT

// Option 3: Use EEPROM (requires flashing different firmware to each half)
#define EE_HANDS
```

---

## Maintenance

### Keeping QMK Updated

```bash
cd ~/Code/qmk/qmk_firmware
git pull
qmk doctor  # Check for issues
make handwired/scylla_custom:default  # Rebuild
```

### Backing Up Your Configuration

```bash
# Backup your entire keyboard folder
tar -czf scylla_custom_backup.tar.gz \
    ~/Code/qmk/qmk_firmware/keyboards/handwired/scylla_custom/
```

---

## Resources

- **QMK Documentation**: [https://docs.qmk.fm/](https://docs.qmk.fm/)
- **RP2040 Guide**: [https://docs.qmk.fm/platformdev_rp2040](https://docs.qmk.fm/platformdev_rp2040)
- **BastardKB Docs**: [https://docs.bastardkb.com/](https://docs.bastardkb.com/)
- **QMK Discord**: Join for community support
- **Scylla Info**: [https://bastardkb.com/scylla/](https://bastardkb.com/scylla/)

---

## Quick Reference Commands

```bash
# Compile firmware
cd ~/Code/qmk/qmk_firmware && make handwired/scylla_custom:default

# Flash firmware (after entering bootloader)
qmk flash -kb handwired/scylla_custom -km default

# Copy to RPI-RP2 drive
cp ~/Code/qmk/qmk_firmware/handwired_scylla_custom_default.uf2 /Volumes/RPI-RP2/

# Open QMK console for debugging
qmk console

# Check QMK setup
qmk doctor

# Clean build files
qmk clean
```

---

## Pin Configuration Quick Reference

### Left/Right Hand (Both use same pins)

**Rows (Blue wires)**:
- ROW0: GP23
- ROW1: GP24
- ROW2: GP25
- ROW3: GP26
- ROW4: GP27

**Columns**:
- COL0: GP3
- COL1: GP4
- COL2: GP5
- COL3: GP6
- COL4: GP7
- COL5: GP8

**Serial Communication**:
- TX: GP0
- RX: GP1

**Handedness Detection**: GP16

---

## Success Checklist

- [ ] Firmware compiles without errors
- [ ] .uf2 file is generated
- [ ] Left half flashed successfully
- [ ] Right half flashed successfully
- [ ] Keyboard recognized by computer
- [ ] All 29 keys on left half work
- [ ] All 29 keys on right half work
- [ ] No ghost keypresses
- [ ] TRRS cable connects both halves
- [ ] Layer switching works (Lower, Raise, Adjust)
- [ ] No keys are chattering

If all checkboxes are checked, congratulations! Your Scylla Custom keyboard is fully functional!

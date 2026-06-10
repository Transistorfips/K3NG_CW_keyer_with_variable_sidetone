# K3NG CW Keyer with Variable Sidetone

This is my personal version of the famous [K3NG CW Keyer](https://github.com/k3ng/k3ng_cw_keyer) 
by Anthony Good K3NG, modified for use with an Arduino Uno with a variable sidetone frequency.

## Hardware Configuration

| Function | Pin |
|---|---|
| Dit paddle | D2 |
| Dah paddle | D5 |
| Audio sidetone output | D4 |
| WPM speed potentiometer | A0 |
| Sidetone frequency potentiometer | A1 |

## Modifications

### Variable Sidetone Frequency (new feature)
A second potentiometer on pin A1 controls the sidetone frequency in real time.
Range: 300 Hz to 2000 Hz.

## Important Notes

### EEPROM Reset required on first boot
After uploading the firmware for the first time, all `initial_` values in 
`keyer_settings.h` are ignored until the EEPROM is cleared.

**Factory Reset:** Hold both paddles simultaneously and press the Reset button.
The keyer will beep to confirm the reset.

### Do not enable DEBUG defines
Enabling any `DEBUG_` define in `keyer_features_and_options.h` will cause RAM 
overflow on the Uno (only 2048 bytes RAM), resulting in erratic behavior:
- Potentiometer ignored or behaves strangely
- Paddles stop working
- Continuous tone output

### Windows Driver Issue (CH340 USB chip)
If you use an Arduino Nano Clone with CH340 USB chip:
- Driver version 3.9.2024.9 is **broken** – causes `cannot set com-state` error
- Solution: Downgrade to driver version **3.7.2022.1**
- Download: https://support.arduino.cc/hc/en-us/articles/13148652511260

## My Settings

```cpp
#define initial_pot_wpm_low_value 7
#define initial_pot_wpm_high_value 35
#define wpm_limit_low 2
#define wpm_limit_high 60
#define initial_sidetone_freq 800
```

## Credits
Original K3NG CW Keyer by Anthony Good K3NG  
https://github.com/k3ng/k3ng_cw_keyer

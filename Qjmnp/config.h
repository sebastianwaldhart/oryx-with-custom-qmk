#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef DEBOUNCE
#define DEBOUNCE 10

#define COMBO_TERM 15

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 60000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5

#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 10

#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 36

#define SERIAL_NUMBER "Qjmnp/nQ5M0"
#define LAYER_STATE_8BIT
#define COMBO_COUNT 1

#define RGB_MATRIX_STARTUP_SPD 60


#define UNICODE_SELECTED_MODES UNICODE_MODE_WINDOWS, UNICODE_MODE_MACOS

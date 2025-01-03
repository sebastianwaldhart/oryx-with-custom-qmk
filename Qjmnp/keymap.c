#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};


enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
};

enum unicode_names {
  UM_AE_LOWER,
  UM_AE_UPPER,
  UM_UE_LOWER,
  UM_UE_UPPER,
  UM_OE_LOWER,
  UM_OE_UPPER,
  MARK_A_LOWER,
  MARK_A_UPPER,
  MARK_E_LOWER,
  MARK_E_UPPER,
  MARK_I_LOWER,
  MARK_I_UPPER,
  MARK_O_LOWER,
  MARK_O_UPPER,
  MARK_U_LOWER,
  MARK_U_UPPER,
  UM_SS,
  NJ_LOWER,
  NJ_UPPER,
  CUR_EUR,
  INV_EX,
  INV_QU,
  MATH_MU,
  MATH_DEGREE,
  DBL_LEFT,
  DBL_RIGHT,
};

const uint32_t PROGMEM unicode_map[] = {
  [UM_AE_LOWER] = 0x00E4,
  [UM_AE_UPPER] = 0x00C4,
  [UM_UE_LOWER] = 0x00FC,
  [UM_UE_UPPER] = 0x00DC,
  [UM_OE_LOWER] = 0x00F6,
  [UM_OE_UPPER] = 0x00D6,
  [MARK_A_LOWER] = 0x00E1,
  [MARK_A_UPPER] = 0x00C1,
  [MARK_E_LOWER] = 0x00E9,
  [MARK_E_UPPER] = 0x00C9,
  [MARK_I_LOWER] = 0x00ED,
  [MARK_I_UPPER] = 0x00CD,
  [MARK_O_LOWER] = 0x00F3,
  [MARK_O_UPPER] = 0x00D3,
  [MARK_U_LOWER] = 0x00FA,
  [MARK_U_UPPER] = 0x00DA,
  [UM_SS] = 0x00DF,
  [NJ_LOWER] = 0x00F1,
  [NJ_UPPER] = 0x00D1,
  [CUR_EUR] = 0x20AC,
  [INV_EX] = 0x00A1,
  [INV_QU] = 0x00BF,
  [MATH_MU] = 0x00B5,
  [MATH_DEGREE] = 0x00B0,
  [DBL_LEFT] = 0x00AB,
  [DBL_RIGHT] = 0x00BB,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(
    KC_ESCAPE,      KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,       
    KC_TAB,         KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_SCLN,        KC_Q,           KC_J,           KC_K,           KC_X,           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_ALT,    MO(5),          MO(1),          KC_SPACE,       KC_NO,          MO(2),          OSL(6),         KC_LBRC,        KC_RBRC,        KC_RIGHT_CTRL
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_DELETE,      KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,          KC_HOME,        KC_PAGE_UP,     KC_UP,          KC_PGDN,        KC_END,         KC_EQUAL,       
    KC_NO,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_BSLS,        
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,          KC_INSERT,      KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC,        KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_ALT,   KC_RIGHT_GUI,   KC_TRANSPARENT
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_GRAVE,       ST_MACRO_0,     ST_MACRO_1,     KC_LCBR,        KC_RCBR,        KC_NO,          KC_NUM,         KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    
    KC_NO,          KC_UNDS,        KC_PIPE,        KC_LPRN,        KC_RPRN,        KC_NO,          KC_NO,          KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     
    KC_TRANSPARENT, KC_BSLS,        KC_SLASH,       KC_LBRC,        KC_RBRC,        KC_NO,          KC_KP_DOT,      KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_ENTER,       KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_RIGHT_GUI,   KC_TRANSPARENT
  ),

  [_ADJUST] = LAYOUT_planck_grid(
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_EQUAL,       
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLS,        
    KC_TRANSPARENT, LGUI(LSFT(KC_1)),LGUI(LSFT(KC_2)),LGUI(LSFT(KC_3)),LGUI(LSFT(KC_4)),LGUI(LSFT(KC_5)),LGUI(LSFT(KC_6)),LGUI(LSFT(KC_7)),LGUI(LSFT(KC_8)),LGUI(LSFT(KC_9)),LGUI(LSFT(KC_0)),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_RIGHT_GUI,   KC_TRANSPARENT
  ),

  [_LAYER4] = LAYOUT_planck_grid(
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [_LAYER5] = LAYOUT_planck_grid(
    QK_LLCK,        KC_NO,          KC_NO,          KC_MS_UP,       KC_NO,          KC_AUDIO_VOL_UP,KC_NO,          KC_MS_BTN1,     KC_UP,          KC_MS_BTN2,     KC_MS_BTN3,     KC_BRIGHTNESS_UP,
    KC_NO,          KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_AUDIO_VOL_DOWN,KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_WH_UP,    KC_BRIGHTNESS_DOWN,
    KC_TRANSPARENT, KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_WH_DOWN,  RGB_TOG,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          MU_TOGG,        AU_TOGG,        KC_NO
  ),

  [_LAYER6] = LAYOUT_planck_grid(
    UC(MATH_DEGREE), UP(UM_AE_LOWER, UM_AE_UPPER), UP(UM_OE_LOWER, UM_OE_UPPER), KC_TRANSPARENT, UP(UM_UE_LOWER, UM_UE_UPPER), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(CUR_EUR), KC_TRANSPARENT, KC_TRANSPARENT, UP(INV_EX, INV_QU), 
    KC_CAPS,        UP(MARK_A_LOWER, MARK_A_UPPER), UP(MARK_O_LOWER, MARK_O_UPPER), UP(MARK_E_LOWER, MARK_E_UPPER), UP(MARK_U_LOWER, MARK_U_UPPER), UP(MARK_I_LOWER, MARK_I_UPPER), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UP(NJ_LOWER, NJ_UPPER), UC(UM_SS), 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC(MATH_MU), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, UC_NEXT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_RIGHT_ALT,   UC(DBL_LEFT), UC(DBL_RIGHT), KC_TRANSPARENT
  ),

};

const uint16_t PROGMEM combo0[] = { KC_SPACE, KC_LBRC, KC_RBRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(4)),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {85,203,158}, {85,203,158}, {134,255,213}, {85,203,158}, {85,203,158}, {0,0,255}, {0,0,255}, {134,255,213} },

    [1] = { {243,222,234}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,0}, {14,255,255}, {85,203,158}, {156,255,255}, {85,203,158}, {14,255,255}, {0,0,255}, {0,0,0}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,0}, {0,0,0}, {156,255,255}, {156,255,255}, {156,255,255}, {0,0,0}, {0,0,255}, {134,255,213}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {0,0,0}, {32,176,255}, {85,203,158}, {85,203,158}, {85,203,158}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {156,255,255}, {243,222,234}, {156,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213} },

    [2] = { {0,0,255}, {0,0,255}, {0,0,255}, {32,176,255}, {32,176,255}, {0,0,0}, {32,176,255}, {14,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {14,255,255}, {0,0,0}, {0,0,255}, {0,0,255}, {243,222,234}, {243,222,234}, {0,0,0}, {0,0,0}, {14,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {14,255,255}, {134,255,213}, {0,0,255}, {0,0,255}, {14,255,255}, {14,255,255}, {0,0,0}, {85,203,158}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {85,203,158}, {134,255,213}, {85,203,158}, {134,255,213}, {85,203,158}, {134,255,213}, {134,255,213} },

    [3] = { {0,0,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {14,255,255}, {0,0,255}, {0,0,0}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {32,176,255}, {0,0,255}, {134,255,213}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213} },

    [4] = { {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {134,255,213}, {134,255,213}, {85,203,158}, {85,203,158}, {134,255,213}, {85,203,158}, {134,255,213}, {0,0,255}, {0,0,255}, {134,255,213} },

    [5] = { {0,0,255}, {0,0,0}, {0,0,0}, {243,222,234}, {0,0,0}, {134,255,213}, {0,0,0}, {32,176,255}, {134,255,213}, {32,176,255}, {14,255,255}, {32,176,255}, {0,0,0}, {0,0,0}, {243,222,234}, {243,222,234}, {243,222,234}, {134,255,213}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {85,203,158}, {32,176,255}, {134,255,213}, {0,0,0}, {85,203,158}, {85,203,158}, {85,203,158}, {156,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {14,255,255}, {134,255,213}, {134,255,213}, {134,255,213}, {0,0,255}, {85,203,158}, {243,222,234}, {85,203,158}, {0,0,0}, {32,176,255}, {14,255,255}, {0,0,0} },

    [6] = { {32,176,255}, {14,255,255}, {14,255,255}, {0,0,255}, {14,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {243,222,234}, {14,255,255}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {32,176,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {134,255,213}, {85,203,158}, {85,203,158}, {0,0,0}, {85,203,158}, {134,255,213}, {32,176,255}, {32,176,255}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_RSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_MINUS));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_RSFT(SS_TAP(X_DOT)));
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint8_t layer_state_set_user(uint8_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}




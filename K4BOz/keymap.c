#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
};



enum tap_dance_codes {
  DANCE_0,
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_BRIGHTNESS_UP,                                KC_AUDIO_VOL_UP,KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,       
    KC_GRAVE,       KC_QUOTE,       KC_COMMA,       KC_DOT,         KC_P,           KC_Y,           KC_BRIGHTNESS_DOWN,                                KC_AUDIO_VOL_DOWN,KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_SLASH,       
    KC_TAB,         KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           TD(DANCE_0),                                                                    KC_AUDIO_MUTE,  KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_SCLN,        KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           KC_RIGHT_SHIFT, 
    KC_LEFT_CTRL,   KC_LEFT_GUI,    KC_LEFT_ALT,    MO(5),          MO(2),          KC_ESCAPE,                                                                                                      KC_ESCAPE,      MO(3),          OSL(6),         KC_LBRC,        KC_RBRC,        KC_RIGHT_CTRL,  
    KC_SPACE,       KC_BSPC,        KC_LEFT_GUI,                    KC_RIGHT_GUI,   KC_ESCAPE,      KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,       
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_DELETE,      KC_F9,          KC_F10,         KC_F11,         KC_F12,         KC_NO,          KC_NO,                                          KC_NO,          KC_HOME,        KC_PAGE_UP,     KC_UP,          KC_PGDN,        KC_END,         KC_EQUAL,       
    KC_NO,          KC_F5,          KC_F6,          KC_F7,          KC_F8,          KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_BSLS,        
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                                          KC_INSERT,      KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, MO(4),          KC_TRANSPARENT, KC_NO,          KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_BSPC
  ),
  [3] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_GRAVE,       ST_MACRO_0,     ST_MACRO_1,     KC_LCBR,        KC_RCBR,        KC_NO,          KC_NO,                                          KC_NO,          KC_NUM,         KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    
    KC_NO,          KC_UNDS,        KC_PIPE,        KC_LPRN,        KC_RPRN,        KC_NO,          KC_NO,                                                                          KC_NO,          KC_NO,          KC_KP_ASTERISK, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     
    KC_TRANSPARENT, KC_BSLS,        KC_SLASH,       KC_LBRC,        KC_RBRC,        KC_NO,                                          KC_KP_DOT,      KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          MO(4),          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EQUAL,       KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          RSFT(KC_1),     RSFT(KC_2),     RSFT(KC_3),     RSFT(KC_4),     RSFT(KC_5),     KC_NO,                                          KC_NO,          LSFT(KC_6),     LSFT(KC_7),     LSFT(KC_8),     LSFT(KC_9),     LSFT(KC_0),     KC_EQUAL,       
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_BSLS,        
    KC_TRANSPARENT, RGUI(RSFT(KC_1)),RGUI(RSFT(KC_2)),RGUI(RSFT(KC_3)),RGUI(RSFT(KC_4)),RGUI(RSFT(KC_5)),                                LGUI(LSFT(KC_6)),LGUI(LSFT(KC_7)),LGUI(LSFT(KC_8)),LGUI(LSFT(KC_9)),LGUI(LSFT(KC_0)),KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_RIGHT_GUI,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    QK_LLCK,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          AU_TOGG,                                        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_MS_UP,       KC_NO,          KC_AUDIO_VOL_UP,MU_TOGG,                                        KC_NO,          KC_NO,          KC_MS_BTN1,     KC_UP,          KC_MS_BTN2,     KC_MS_BTN3,     KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_AUDIO_VOL_DOWN,MU_NEXT,                                                                        KC_NO,          KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_MS_WH_UP,    KC_NO,          
    KC_TRANSPARENT, KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_AUDIO_MUTE,                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_MS_WH_DOWN,  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, DE_AE,          DE_OE,          KC_TRANSPARENT, DE_UE,          KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_ALT,   KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
const uint16_t PROGMEM combo0[] = { KC_LBRC, KC_SPACE, KC_RBRC, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, TG(1)),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {243,222,234}, {0,0,255}, {85,203,158}, {134,255,213}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {10,225,255}, {10,225,255}, {85,203,158}, {85,203,158}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,255}, {0,0,255}, {0,0,0}, {134,255,213}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {156,255,255}, {85,203,158}, {243,222,234}, {134,255,213}, {243,222,234} },

    [1] = { {0,0,255}, {243,222,234}, {85,203,158}, {134,255,213}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {85,203,158}, {85,203,158}, {134,255,213}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {85,203,158}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {156,255,255}, {134,255,213}, {243,222,234}, {134,255,213}, {243,222,234} },

    [2] = { {0,0,0}, {243,222,234}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {32,176,255}, {10,225,255}, {243,222,234}, {134,255,213}, {0,0,0}, {32,176,255}, {10,225,255}, {243,222,234}, {134,255,213}, {0,0,0}, {32,176,255}, {10,225,255}, {243,222,234}, {0,0,0}, {0,0,0}, {32,176,255}, {10,225,255}, {243,222,234}, {156,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,0}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {0,0,0}, {10,225,255}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {85,203,158}, {134,255,213}, {85,203,158}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {85,203,158}, {134,255,213}, {0,0,0}, {85,203,158}, {134,255,213}, {85,203,158}, {156,255,255}, {0,0,0}, {10,225,255}, {0,0,0}, {35,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {243,222,234}, {134,255,213}, {243,222,234} },

    [3] = { {0,0,0}, {0,0,255}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,255}, {0,0,255}, {134,255,213}, {0,0,0}, {32,176,255}, {243,222,234}, {10,225,255}, {0,0,0}, {0,0,0}, {32,176,255}, {243,222,234}, {10,225,255}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,0}, {14,255,255}, {14,255,255}, {134,255,213}, {134,255,213}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {134,255,213}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {85,203,158}, {0,0,0}, {141,255,233}, {141,255,233}, {141,255,233}, {134,255,213}, {0,0,0}, {14,255,255}, {14,255,255}, {141,255,233}, {85,203,158}, {0,0,0}, {35,255,255}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {243,222,234}, {134,255,213}, {243,222,234} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {134,255,213}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {134,255,213}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {0,0,0}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {0,255,255}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,0}, {0,0,255}, {0,0,255}, {134,255,213}, {134,255,213}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {134,255,213}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {0,0,0}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {134,255,213}, {0,0,0}, {10,225,255}, {35,255,255}, {243,222,234}, {249,228,255}, {0,0,0}, {10,225,255}, {32,176,255}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {134,255,213}, {243,222,234} },

    [5] = { {0,0,255}, {247,255,128}, {85,203,158}, {134,255,213}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {134,255,213}, {0,0,0}, {243,222,234}, {243,222,234}, {85,203,158}, {0,0,255}, {0,0,0}, {0,0,0}, {243,222,234}, {85,203,158}, {85,203,158}, {0,0,0}, {134,255,213}, {134,255,213}, {156,255,255}, {243,222,234}, {35,255,255}, {10,225,255}, {243,222,234}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {0,0,0}, {10,225,255}, {85,203,158}, {85,203,158}, {0,0,0}, {0,0,0}, {35,255,255}, {134,255,213}, {0,0,255}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {85,203,158}, {0,0,0}, {0,0,0}, {35,255,255}, {134,255,213}, {134,255,213}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {243,222,234}, {243,222,234}, {134,255,213}, {243,222,234} },

    [6] = { {243,222,234}, {0,0,0}, {85,203,158}, {0,0,0}, {134,255,213}, {35,255,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,255}, {0,0,0}, {85,203,158}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {10,225,255}, {10,225,255}, {85,203,158}, {85,203,158}, {243,222,234}, {134,255,213}, {243,222,234}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {134,255,213}, {134,255,213}, {156,255,255}, {85,203,158}, {243,222,234}, {134,255,213}, {243,222,234} },

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
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));
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


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[1];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: register_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: unregister_code16(KC_MEDIA_PREV_TRACK); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
};

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_dvorak.h"
#define _QW 0
#define _RS 1
#define _LW 2
#define _DV 3
#define _DVRS 4
#define _DVLW 5

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_QW] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_NO,        KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_NO,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_NO,
        KC_NO,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_NO,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_NO,
        KC_NO,        KC_ESC,       KC_TAB, KC_LGUI, KC_LSFT,
                                              KC_NO,  KC_NO,
                                                              KC_NO,
                                              KC_SPC,CTL_T(KC_BSPC),KC_NO,
        // right hand
             KC_RGHT,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             KC_NO,
             KC_NO,       KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_NO,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,          KC_NO,
             KC_NO,       KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,          KC_NO,
                                 MO(_RS),KC_QUOT,KC_LBRC,KC_ENT,           KC_NO,
             KC_NO,        KC_NO,
             KC_NO,
        KC_NO,ALT_T(KC_TAB), KC_ENT
    ),



/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[_RS] = LAYOUT_ergodox(
       // left hand
       KC_NO,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_NO,   KC_EXLM, KC_AT,   KC_UP,   DV_LCBR, DV_RCBR, KC_TRNS,
       KC_NO,KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,
       KC_NO,DV_LBRC, DV_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_TRNS,
       EPRM,TG(_LW), KC_INS,  KC_LGUI, KC_LSFT,
                                       KC_NO,KC_TRNS,
                                               KC_TRNS,
                           KC_SPC, CTL_T(KC_BSPC),KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_PGUP, KC_7,    KC_8,   KC_9,    DV_ASTR ,KC_NO,
                KC_PGDN, KC_4,   KC_5,    KC_6,    DV_PLUS, KC_NO,
       KC_TRNS, KC_GRV,  KC_1,   KC_2,    KC_3,    DV_BSLS, KC_NO,
                         KC_TRNS,KC_DOT,  KC_0,    DV_EQL,  KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, ALT_T(KC_TAB), KC_ENT
),


/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_LW] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_TRNS,
       KC_TRNS, KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,
       KC_TRNS, KC_MPLY, KC_VOLU, KC_MUTE, KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS, KC_MNXT, KC_VOLD, KC_LGUI, KC_LSFT,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                             KC_SPC, CTL_T(KC_BSPC),KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
                    KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_NO,
       KC_TRNS,  TG(_DV), KC_F1,   KC_F2,   KC_F3,   KC_F12, KC_TRNS,
                    TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, ALT_T(KC_TAB), KC_ENT
),
};


/*
 [_DV] = KEYMAP(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                  KC_F,    KC_G,      KC_C,    KC_R,    KC_L   ,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                  KC_D,    KC_H,      KC_T,    KC_N,    KC_S   ,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                  KC_B,    KC_M,      KC_W,    KC_V,    KC_Z   ,
    KC_ESC,  KC_TAB, KC_LGUI,  KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  MO(_DVRS), KC_MINS, KC_SLSH, KC_ENT ),

[_DVRS] = KEYMAP(
    KC_EXLM,   KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                               KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH,   KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                                KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC,   KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                               KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_DVLW), KC_INS,  KC_LGUI, KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),

[_DVLW] = KEYMAP(
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                               KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                               KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_MPLY, KC_VOLU, KC_MUTE, KC_NO,   RESET,                                 TO(_QW), KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_MNXT, KC_VOLD, KC_LGUI, KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_SPC,  TO(_DV), KC_PSCR, KC_SLCK, KC_PAUS )

*/

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(_RS)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

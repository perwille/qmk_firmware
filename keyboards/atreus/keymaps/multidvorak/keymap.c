// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus.h"
#include "keymap_dvorak.h"
// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2
#define _DV 3
#define _DVRS 4
#define _DVLW 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = LAYOUT( /* soft dvorak */
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                 KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
  KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  MO(_RS), KC_QUOT, KC_LBRC, KC_ENT  ),
/*
 *  !       @     up     {    }            ||         pgup    7     8     9    *
 *  #     left   down  right  $            ||         pgdn    4     5     6    +
 *  [       ]      (     )    &            ||           `     1     2     3    \
 * lw     insert super shift  sp ctrl/bksp || alt/tab enter   fn    .     0    =
 */
[_RS] = LAYOUT( /* [> RAISE <] */
  KC_EXLM, KC_AT,   KC_UP,   DV_LCBR, DV_RCBR,                               KC_PGUP, KC_7,    KC_8,   KC_9, DV_ASTR ,
  KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                                KC_PGDN, KC_4,    KC_5,   KC_6, DV_PLUS ,
  DV_LBRC, DV_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                               KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
  TG(_LW), KC_INS,  KC_LGUI, KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  KC_TRNS, KC_DOT, KC_0, DV_EQL  ),
/*
 * insert home   up  end   pgup        ||      up     F7    F8    F9   F10
 *  del   left  down right pgdn        ||     down    F4    F5    F6   F11
 *  play  volup mute       reset       ||     dvorak  F1    F2    F3   F12
 *  next  voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
 */
[_LW] = LAYOUT( /* [> LOWER <] */
  KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                               KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
  KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                               KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
  KC_MPLY, KC_VOLU, KC_MUTE, KC_NO,   RESET,                                 TG(_DV), KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
  KC_MNXT, KC_VOLD, KC_LGUI, KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS ),

[_DV] = LAYOUT( /* dvorak */
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                                  KC_F,    KC_G,      KC_C,    KC_R,    KC_L   ,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                                  KC_D,    KC_H,      KC_T,    KC_N,    KC_S   ,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                                  KC_B,    KC_M,      KC_W,    KC_V,    KC_Z   ,
    KC_ESC,  KC_TAB, KC_LGUI,  KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  MO(_DVRS), KC_MINS, KC_SLSH, KC_ENT ),

[_DVRS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM,   KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                               KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH,   KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                                KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC,   KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                               KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_DVLW), KC_INS,  KC_LGUI, KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_ENT,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),

[_DVLW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                               KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                               KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_MPLY, KC_VOLU, KC_MUTE, KC_NO,   RESET,                                 TO(_QW), KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_MNXT, KC_VOLD, KC_LGUI, KC_LSFT, KC_SPC, CTL_T(KC_BSPC), ALT_T(KC_TAB), KC_SPC,  TO(_DV), KC_PSCR, KC_SLCK, KC_PAUS )

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

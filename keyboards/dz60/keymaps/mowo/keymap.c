#include "dz60.h"
#include "action_layer.h"

// My layout is practically the default HHKB layout.
#define _BL  0
#define _HLa 1
#define _HLb 2
#define _HL  3
#define _XL  4
#define ______ KC_TRNS

enum hype_keycodes {
  FN_HLa = SAFE_RANGE,
  FN_HLb
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BL] = KEYMAP_HHKB(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,  KC_BSLS, KC_DEL,
		KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSPC,
		KC_LCTL,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,           KC_RSFT, MO(_HLa),
		         KC_LGUI,          KC_LALT,                   KC_SPC,                                      KC_RALT,           MO(_HLb)),

	[_HLa] = KEYMAP_HHKB(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  KC_INS,  KC_DEL,
		KC_CAPS,          ______,  ______,  ______,  ______,  ______,  ______,  ______,  KC_PSCR, KC_SLCK, KC_PAUS,  KC_UP,   ______,  RESET,
		______,           KC_VOLD, KC_VOLU, KC_MUTE, ______,  ______,  KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT,  KC_RGHT, ______,
		______,  ______,  KC_MPRV, KC_MPLY, KC_MNXT, ______,  ______,  KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,           ______,  ______,
		         ______,           ______,                    KC_MPLY,                                      ______,            ______),

	[_HLb] = KEYMAP_HHKB(
		RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, ______, ______, ______, ______, ______, ______,
		RGB_MOD,          RGB_HUI, RGB_SAI, RGB_VAI,  ______,   ______,  ______,  ______,  ______, ______, ______, ______, ______, ______,
		______,           RGB_HUD, RGB_SAD, RGB_VAD,  ______,   ______,  ______,  ______,  ______, ______, ______, ______, ______,
		______,  ______,  ______,  ______,  BL_DEC,   BL_TOGG,  BL_INC,  ______,  ______,  ______, ______, ______,         ______, ______,
		         ______,           ______,                      ______,                                    ______,         ______),

	[_HL] = KEYMAP_HHKB(
		RGB_TOG, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, BL_BRTG, BL_OFF, BL_STEP, BL_ON, BL_DEC, BL_INC, LALT(KC_F4),
		RGB_MOD,          RGB_HUI, RGB_SAI, RGB_VAI,  ______,   ______,  ______,  ______,  ______, ______, ______, ______, ______, ______,
		______,           RGB_HUD, RGB_SAD, RGB_VAD,  ______,   ______,  ______,  ______,  ______, ______, ______, ______, ______,
		______,  ______,  ______,  ______,  BL_DEC,   BL_TOGG,  BL_INC,  ______,  ______,  ______, ______, ______,         ______, ______,
		         ______,           ______,                      ______,                                    ______,         ______),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FN_HLa:
      if (record->event.pressed)
      {
        layer_on(_HLa);
        update_tri_layer(_HLa, _HLb, _HL);
      }
      else
      {
        layer_off(_HLa);
        update_tri_layer(_HLa, _HLb, _HL);
      }
      return false;
      break;
    case FN_HLb:
      if (record->event.pressed)
      {
        layer_on(_HLb);
        update_tri_layer(_HLa, _HLb, _HL);
      }
      else
      {
        layer_off(_HLb);
        update_tri_layer(_HLa, _HLb, _HL);
      }
      return false;
      break;
  }
  return true;
}

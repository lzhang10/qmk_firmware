// -*- truncate-lines: t; -*-
/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "common/manna-harbour_miryoku.h"
#include "common/layout.h"
#include "common/my_keycode.h"
#include "common/tapdance.h"

#ifdef COMBO_ENABLE
// qmk doc
// (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md#combos)
// states to put combo in keymap.c. It does not work if put in my_keycode.c
// (https://github.com/qmk/qmk_firmware/issues/21137)
#include "g/keymap_combo.h"
#endif


#define SPACE_FN LT(NAV, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_magic(
CW_TOGG, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,KC_F11,  KC_F12, XXX,
KC_GRV,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL, KC_BSPC,
KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,KC_BSLS,
KC_ESC,   LGUI_T(KC_A),LALT_T(KC_S),LSFT_T(KC_D),LCTL_T(KC_F), KC_G,  KC_H,  LCTL_T(KC_J),LSFT_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN), KC_QUOT,      KC_ENT,
OSM(MOD_LSFT),   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  OSM(MOD_RSFT), KC_UP,
KC_LCTL, KC_LALT, KC_LGUI,             SPACE_FN,                TD(TD_CPY_CUT),KC_RALT,    KC_LEFT, KC_DOWN, KC_RGHT
),
    [NAV] = LAYOUT_magic(
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  TRNS,   TRNS,   TRNS, TRNS, TRNS, TRNS, TRNS,  STR_A, TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  TRNS,   TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS, TRNS, TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  U_TERM, TRNS,  KC_PGDN,  KC_PGUP,  TRNS,  TRNS, TRNS, TRNS,TRNS,
TRNS, TRNS,  TRNS,  M_CODE,U_WEB, U_WEB2,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  TRNS,  TRNS,     TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  U_EMACS,  KC_HOME, KC_DEL, KC_INS, KC_END,  TRNS,  TRNS,TRNS,
TRNS, TRNS,  TRNS,                TRNS,                TRNS,TRNS,    TRNS, TRNS, TRNS
    )
};

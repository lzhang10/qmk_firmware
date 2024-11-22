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

#include "layout.h"
#include "macro.h"
#include "casemodes.h"
#include "g/keymap_combo.h"
#include "code.c"

#define SPACE_FN LT(NAV, KC_SPC)
enum layers { BASE, MBO, MEDIA, NAV, MOUSE, SYM, NUM, FUN };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [BASE] = LAYOUT_magic(
CAPSWORD, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,KC_F11,  KC_F12, XXX,
KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL, KC_BSPC,
KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,KC_BSLS,
KC_ESC, LGUI_T(KC_A),LALT_T(KC_S),LSFT_T(KC_D),LCTL_T(KC_F), KC_G,  KC_H,  LCTL_T(KC_J),LSFT_T(KC_K),LALT_T(KC_L),LGUI_T(KC_SCLN), KC_QUOT,      KC_ENT,
OSM(MOD_LSFT),   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  OSM(MOD_RSFT), KC_UP,
KC_LCTL, KC_LALT, KC_LGUI,             LT(NAV, KC_SPC),                KC_RGUI,KC_RALT,    KC_LEFT, KC_DOWN, KC_RGHT
),
    [NAV] = LAYOUT_magic(
TRNS, STR_A, STR_B, TRNS, TRNS, TRNS, TRNS,   TRNS, TRNS, TRNS, TRNS,TRNS,  TRNS, TRNS,
TRNS, TRNS,  TRNS,  TRNS, TRNS, TRNS, TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS, TRNS, TRNS,
TRNS, TRNS,  TRNS,  TRNS, TRNS, KC_F20,TRNS,  KC_PGDN,  KC_PGUP,  TRNS,  TRNS, TRNS, TRNS,TRNS,
TRNS, TRNS,  TRNS,  KC_F16,  KC_F17,  KC_F18,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  TRNS,  TRNS,     TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  KC_F14,  KC_HOME, KC_DEL, KC_INS, KC_END,  TRNS,  TRNS,TRNS,
TRNS, TRNS, TRNS,                TRNS,                TRNS,TRNS,    TRNS, TRNS, TRNS
    )
};

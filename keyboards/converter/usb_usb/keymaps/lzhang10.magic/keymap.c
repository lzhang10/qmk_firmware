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
#define CMD_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
#define CTL_J LCTL_T(KC_J)
#define SFT_K LSFT_T(KC_K)
#define ALT_L LALT_T(KC_L)
#define CMD_SC LGUI_T(KC_SCLN)
#define O_LSFT OSM(MOD_LSFT)
#define O_RSFT OSM(MOD_RSFT)

#define CPY_CUT TD(TD_CPY_CUT)
#define PASTE C(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_magic(
CW_TOGG, U_WEB,  M_CODE,   U_TERM,  U_WEB2,  U_EMACS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,  KC_F12, XXX,
KC_GRV,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,   KC_MINS, KC_EQL, KC_BSPC,
KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,
KC_ESC,   CMD_A, ALT_S, SFT_D, CTL_F, KC_G,  KC_H,  CTL_J, SFT_K, ALT_L, CMD_SC, KC_QUOT,      KC_ENT,
O_LSFT,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  O_RSFT,       KC_UP,
KC_LCTL, KC_LALT, TD(TD_CPY_PST),         SPACE_FN,        KC_LGUI, KC_LALT,               KC_LEFT, KC_DOWN, KC_RGHT
),
    [NAV] = LAYOUT_magic(
TRNS, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, STR_A, TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  TRNS,   TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS, TRNS, TRNS,
TRNS, TRNS,  M_CHAT,U_FILE,U_WEB2,U_TERM, TRNS,   KC_PGDN,  KC_PGUP,  TRNS,  TRNS, TRNS, TRNS,TRNS,
TRNS, TRNS,  TRNS,  M_CODE,U_WEB, U_MAIL,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  TRNS,  TRNS,     TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  U_EMACS,  KC_HOME, KC_DEL, KC_INS, KC_END,  TRNS,  TRNS, DSP_P,
TRNS, TRNS,  TRNS,                TRNS,                TRNS,TRNS,                   WIN_L, DSP_N, WIN_R
    )
};

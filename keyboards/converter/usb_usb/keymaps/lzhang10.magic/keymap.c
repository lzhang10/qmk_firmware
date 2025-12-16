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

#define CPY_CUT TD(TD_CPY_CUT)
#define PASTE C(KC_V)

/*
Left and right ALTs are mapped to MOUSE BUTTON 4 for easy mouse scrolling when pressed.
*/
// switch between application window on Mac
#define APP_W LCTL(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_magic(
APP_W,    U_WEB,M_CODE,U_WEB2,U_TERM,U_EMACS, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,  KC_F12, XXX,
KC_GRV,   KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,   KC_9,  KC_0,   KC_MINS, KC_EQL, KC_BSPC,
KC_TAB,   KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,
KC_ESC,   CMD_A, SFT_S, ALT_D, CTL_F, KC_G,  KC_H,  CTL_J, ALT_K, SFT_L, CMD_SC, KC_QUOT,      KC_ENT,
O_LSFT,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  O_RSFT,       KC_UP,
KC_LCTL,  KC_MS_BTN4, CPY_CUT,         SPACE_FN,        PASTE, KC_MS_BTN4,             KC_LEFT, KC_DOWN, KC_RGHT
),
    [NAV] = LAYOUT_magic(
DSP_N, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, STR_A, TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  TRNS,   TRNS,   TRNS,  TRNS,  TRNS,  TRNS,  TRNS, TRNS, KC_DEL,
TRNS, TRNS,  M_CHAT,U_FILE,U_WEB2,U_TERM, TRNS,   KC_MS_WH_UP,  KC_PGUP,  TRNS,  TRNS, TRNS, TRNS,TRNS,
TRNS, TRNS,  TRNS,  M_CODE,U_WEB, U_MAIL,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  TRNS,  TRNS,     TRNS,
TRNS, TRNS,  TRNS,  TRNS,  TRNS,  U_EMACS,  KC_MS_WH_DOWN, KC_PGDN, TRNS, TRNS,  TRNS,   TRNS,    WIN_M,
TRNS, TRNS,  TRNS,                TRNS,                TRNS,TRNS,                   WIN_L, WIN_RST, WIN_R
    )
};

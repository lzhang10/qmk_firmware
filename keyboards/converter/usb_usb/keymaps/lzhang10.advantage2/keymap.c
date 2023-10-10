// -*- truncate-lines: t; -*-
#include "advantage2.h"
#include "layout.h"

#include "my_keycode.h"

#ifdef COMBO_ENABLE
// qmk doc
// (https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md#combos)
// states to put combo in keymap.c. It does not work if put in my_keycode.c
// (https://github.com/qmk/qmk_firmware/issues/21137)
#include "g/keymap_combo.h"
#endif

#define XXX KC_NO

// Tap Dance declarations https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
enum {
    TD_ESC_CAPS,
    TD_0_1,
    TD_CPY_PST,
    TD_CPY_CUT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_0_1] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_1),
    [TD_CPY_PST] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_V)),
    [TD_CPY_CUT] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_X)),
};


// character stats: http://xahlee.info/comp/computer_language_char_distribution.html
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_kinesis(
// ^: KC_CIRC
// invert number row: KC_EQL, KC_EXLM,KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_0,    KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_SCLN,

// unused special key codes: NUMWORD
// old paste key: S(KC_INS)
KC_ESC,  KC_F1,  KC_F2,   KC_F3,  KC_F4,  KC_F5,   KC_F6,   KC_F7,   KC_F8,      KC_F9,   KC_F10,  WAKE_M32U,KC_F12, KC_MUTE, KC_VOLD, KC_VOLU,  XXX,  XXX,
                          KC_EQL, KC_1,   KC_2,    KC_3,    KC_4,     KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
                        CAPSWORD, KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SCLN,
                       CTRL_PGDN, MTLGUI, MTLALT,  MTLSFT,  MTLCTL ,  KC_G,      KC_H,    KC_J,    KC_K,    KC_L,    KC_MINS, KC_QUOT,
                  OSM(MOD_LSFT),  KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,      KC_N,    MTRCTL,  KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_RSFT),
                                KC_GRV, KC_BSLS,KC_LEFT, KC_RGHT,                         KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,
                                                    KC_TAB, TD(TD_CPY_CUT),      LSFT(KC_LGUI),    KC_F12,
                                                                   C(KC_V),      KC_PGUP,
                                KC_BSPC,  LT(NUM, KC_ESC),LT(FUN, KC_SCLN),      KC_PGDN, LT(SYM, KC_ENT),LT(NAV, KC_SPC)
  ),

  [NAV] = LAYOUT_kinesis(
CTRL_ALT_DEL,KC_INS,STR_B,STR_C,  TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,   TRNS, XXX,  XXX,
                          TRNS,   TMUX1,  TMUX2,  TMUX3,   TMUX4,   TMUX5,       TMUX6,   TMUX7,   TMUX8,   TMUX9,   TRNS,    TRNS,
                          TRNS,   TRNS,   M_CHAT, U_FILE,  U_WEB2,  U_TERM,      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                          TRNS,   KC_COLN,KC_LALT,M_CODE,  U_WEB,   U_MAIL,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TRNS,    TRNS,
                          TRNS,   KC_GRV, TRNS,   TRNS,    TRNS,    U_EMACS,     TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                                  TRNS,   TRNS,   TRNS,    TRNS,                          KC_HOME, KC_END,  TRNS,    TRNS,
                                                           LALT(KC_F6),TRNS,     TRNS,    TRNS,
                                                                    TRNS,        TRNS,
                                                  KC_SPC,  TRNS,    KC_DEL,      TRNS,    TRNS,   TRNS
  ),

  [NUM] = LAYOUT_kinesis(
TRNS,    TRNS,   TRNS,    TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    KC_BRID,  KC_BRIU, XXX,  XXX,
                        KC_EQL,     KC_1,   KC_2,   KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
                          TRNS,     TRNS,   TRNS,   KC_K,    KC_PERC, KC_J,        TRNS,    TRNS,    KC_DOT,  CAPSWORD,KC_QUOT, TRNS,
                          TRNS,     KC_6,   KC_4,   KC_0,    KC_2,    TRNS,        KC_EQL,  KC_3,    KC_1,    KC_5,    KC_7,    TRNS,
                          TRNS,     TRNS,   TRNS,  NUM_G,    KC_8,    TRNS,        KC_PIPE, KC_9,    TRNS,    KC_DOT,  TRNS, TRNS,
                                    TRNS,   TRNS,   TRNS,    TRNS,                          TRNS,    TRNS,    TRNS,    TRNS,
                                                             TRNS,    TRNS,        TRNS,    TRNS,
                                                                      TRNS,        KC_HOME,
                                                    TRNS,    TRNS,    TRNS,        KC_END,  TRNS,   TRNS
),
  [SYM] = LAYOUT_kinesis(
TRNS,    TRNS,   TRNS,    TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,   TRNS,   XXX,  XXX,
                          TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                          TRNS,     KC_LCBR,KC_AMPR,KC_ASTR, KC_LPRN, KC_RCBR,     M_ARROW_RMINUS,TRNS,TRNS,  TRNS,    TRNS,    TRNS,
                          TRNS,     KC_COLN,KC_DLR, KC_PERC, KC_CIRC, KC_PLUS,     M_ARROW_REQL,TRNS,TRNS,    TRNS,    TRNS,    TRNS,
                          TRNS,     KC_TILD,KC_EXLM,KC_AT,   KC_HASH, KC_PIPE,     M_ARROW_RMINUS_BRACES,TRNS,TRNS,    TRNS,    TRNS,    TRNS,
                                    TRNS,   TRNS,   TRNS,    TRNS,                          TRNS,    TRNS,    TRNS,    TRNS,
                                                             TRNS,    TRNS,        TRNS,    TRNS,
                                                                      TRNS,        TRNS,
                                                    TRNS,    TRNS,    TRNS,        TRNS,    TRNS,   TRNS
  ),

  [FUN] = LAYOUT_kinesis(
TRNS,    KC_F13,   KC_F14,KC_F15,   KC_F16, KC_F17,KC_F18,   KC_F19,KC_F20,        KC_F21,  KC_F22,  KC_F23,  STR_A,   TRNS,    TRNS,   TRNS,   XXX,  XXX,
                          TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                          TRNS,     KC_F12, KC_F7,  KC_F8,   KC_F9,   TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                          TRNS,     KC_F11, KC_F4,  KC_F5,   KC_F6,   TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                          TRNS,     KC_F10, KC_F1,  KC_F2,   KC_F3,   TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
                                    TRNS,   TRNS,   TRNS,    TRNS,                          TRNS,    TRNS,    TRNS,    TRNS,
                                                             TRNS,    TRNS,        TRNS,    TRNS,
                                                                      TRNS,        TRNS,
                                                    TRNS,    TRNS,    TRNS,        TRNS,    TRNS,   TRNS
  ),

  /* [FUN] = LAYOUT_miryoku( */
  /*   KC_F12,  KC_F7,   KC_F8,   KC_F9,   U_TERM, U_NA, U_NA,    U_NA,    U_NA,    RESET, */
  /*   KC_F11,  KC_F4,   U_WORK,  U_WEB,   U_MAIL, U_NA,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, */
  /*   KC_F10,  KC_F1,   KC_F2,   KC_F3,   U_EMACS,U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA, */
  /*   U_NP,    U_NP,    KC_APP,  KC_SPC,  KC_TAB,  U_NA,    U_NA,    U_NA,    U_NP,    U_NP */
  /* ) */

  // MOUSE layer can be disabled to save space:
  // MOUSEKEY_ENABLE = no in rules.mk
  [MOUSE] = LAYOUT_miryoku(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_BTN1, KC_BTN2, KC_BTN3, U_NP,    U_NP
  ),

  // MEDIA layer can be disabled to save space:
  // EXTRAKEY_ENABLE = no in rules.mk
  [MEDIA] = LAYOUT_miryoku(
    U_NA,    U_NA,    U_NA,    U_NA,    U_NA,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NU,
    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,    U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
    U_NP,    U_NP,    U_NA,    U_NA,    U_NA,    KC_MSTP, KC_MPLY, KC_MUTE, U_NP,    U_NP
  ),

  [MBO] = LAYOUT_miryoku(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS, KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
    U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
    U_NP,    U_NP,    KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_BTN3, KC_BTN2, U_NP,    U_NP
  ),

};

/*   [BASE] = LAYOUT_kinesis( */
/* U_NA,  U_NA,  U_NA,   U_NA,   U_NA,   U_NA,   U_NA,   U_NA,    U_NA,        U_NA,    U_NA,   U_NA,    U_NA,    U_NA,   U_NA, U_NA,  XXX,  XXX, */
/*               U_NA,   U_NA,   U_NA,   U_NA,   U_NA,   U_NA,    U_NA,        U_NA,    U_NA,   U_NA,    U_NA,    U_NA, */
/*               U_NA,   U_NA,   U_NA,   U_NA,   U_NA,   U_NA,    U_NA,        U_NA,    U_NA,   U_NA,    U_NA,    U_NA, */
/*               U_NA,   U_NA,   U_NA,   U_NA,   U_NA,   U_NA,    U_NA,        U_NA,    U_NA,   U_NA,    U_NA,    U_NA, */
/*               U_NA,   U_NA,   U_NA,   U_NA,   U_NA,   U_NA,    U_NA,        U_NA,    U_NA,   U_NA,    U_NA,    U_NA, */
/*                               U_NA,   U_NA,   U_NA,   U_NA,                          U_NA,   U_NA,    U_NA,    U_NA, */
/*                                                       U_NA,    U_NA,        U_NA,    U_NA, */
/*                                                                U_NA,        U_NA, */
/*                                               U_NA,   U_NA,    U_NA,        U_NA,    U_NA,   U_NA */
/*   ), */
/*   [TRNS] = LAYOUT_kinesis( */
/* TRNS,    TRNS,   TRNS,    TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,   TRNS,   XXX,  XXX, */
/*                           TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS, */
/*                           TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS, */
/*                           TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS, */
/*                           TRNS,     TRNS,   TRNS,   TRNS,    TRNS,    TRNS,        TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS, */
/*                                     TRNS,   TRNS,   TRNS,    TRNS,                          TRNS,    TRNS,    TRNS,    TRNS, */
/*                                                              TRNS,    TRNS,        TRNS,    TRNS, */
/*                                                                       TRNS,        TRNS, */
/*                                                     TRNS,    TRNS,    TRNS,        TRNS,    TRNS,   TRNS */
/*   ), */
/*   [Kinesis default] = LAYOUT_kinesis( */
/* KC_ESC,  KC_F1,  KC_F2,   KC_F3,    KC_F4,  KC_F5,  KC_F6,   KC_F7,   KC_F8,      KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR, KC_SLCK, KC_PAUS,  XXX,  XXX, */
/*                           KC_EQL,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, */
/*                           KC_TAB,   KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS, */
/*                           KC_CAPS,  KC_A,   KC_S,   KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, */
/*                           KC_LSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, */
/*                                     KC_GRV, XXX,    KC_LEFT, KC_RGHT,                      KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, */
/*                                                              KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL, */
/*                                                                       KC_HOME,    KC_PGUP, */
/*                                                     KC_BSPC, KC_DEL,  KC_END,     KC_PGDN, KC_ENT, KC_SPC */
/*   ), */

#ifdef COMBO_ENABLE
// Combos
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    // Home-row and other tight combos
    /* case tab: */
    /* case escape: */
  //case scln:
    //case dquo:
  //case coln:
    /* case enter: */
    /* case quot: */
    /* case circ: */
    /* case dlr: */
    /* case vsp: */
    //return COMBO_TERM;
    // Vertical combos, very relaxed
    /* case small_left_arrow: */
    /* case lt_eq: */
    /* case large_right_arrow: */
    /* case small_right_arrow: */
    /* case pipe_to: */
    /* case sp: */
    /* case gt_eq: */
    /*     return COMBO_TERM + 55; */
    // Regular combos, slightly relaxed
  default:
    return COMBO_TERM + 25;
  }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  switch (index) {
    /* case del: */
    /* case backsp: */
    /* case q_comb: */
    /* case qu_comb: */
    /* case z_comb: */
    /* case num: */
    /* case sp_ampr: */
    /* case sp_pipe: */
    /* case sp_plus: */
    /* case sp_astr: */
    /* case sp_mins: */
    /* case sp_perc: */
    /* case sp_grv: */
    /* case sp_labk: */
    /* case sp_rabk: */
    /* case sp_lcbr: */
    /* case sp_bsls: */
    /* case sp_hash: */
    /* case rev_rep: */
    /* case lprn_arng: */
    /* case rprn_adia: */
    /* case unds_odia: */
    /* case eql: */
    /*     return false; */
  default:
    return true;
  }
}

/* bool combo_should_trigger(uint16_t combo_index, combo_t *combo) { */
/*     // FIXME this doesn't seem to work? */
/*     return true; */
/* } */
#endif

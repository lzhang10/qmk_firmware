#include "advantage2.h"
#include "secret_var.h"
#include "my_keycode.h"
#include "casemodes.h"
#include "layermodes.h"
//#include "repeat.h"

/* lower and title capitals versions (setup at start). */
static char *usr_str_lut[2][26] = {
  {
    USR_STR_A, USR_STR_B, USR_STR_C, USR_STR_D, USR_STR_E, USR_STR_F,
    USR_STR_G, USR_STR_H, USR_STR_I, USR_STR_J, USR_STR_K, USR_STR_L,
    USR_STR_M, USR_STR_N, USR_STR_O, USR_STR_P, USR_STR_Q, USR_STR_R,
    USR_STR_S, USR_STR_T, USR_STR_U, USR_STR_V, USR_STR_W, USR_STR_X,
    USR_STR_Y, USR_STR_Z,
  },
  {NULL}
};

#define WITHOUT_MODS(...)                       \
  do {                                          \
    uint8_t _real_mods = get_mods();            \
    clear_mods();                               \
    { __VA_ARGS__ }                             \
    set_mods(_real_mods);                       \
  } while (0)


/* send things like USR_STR_A defined in usr_str_lut */
void send_user_string(uint16_t keycode) {
      uint8_t shift_index = (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) ? 1 : 0;
      const char *word = usr_str_lut[shift_index][keycode - STR_A];
      if (*word) {
        WITHOUT_MODS({
            send_string(word);
          });
      }
}

//  If these functions return true QMK will process the keycodes as usual. That
//  can be handy for extending the functionality of a key rather than replacing
//  it. If these functions return false QMK will skip the normal key handling,
//  and it will be up to you to send any key up or down events that are
//  required.
//
//  doc for send_string(): https://github.com/qmk/qmk_firmware/blob/master/docs/feature_send_string.md
bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_num_word(keycode, record)) {
    return false;
  }
  if (!process_case_modes(keycode, record)) {
    return false;
  }

  switch (keycode) {
  case TO_NUM:
    layer_on(NUM);
    return false;
  case NUMWORD:
    process_num_word_activation(record);
    return false;
  case CAPSWORD:
    if (record->event.pressed) {
      enable_caps_word();
    }
    return false;
  case WAKE_M32U:
    if (record->event.pressed) {
      /* wait up and then sleep for 20 seconds, and then wake it up */
      SEND_STRING_DELAY("123456", 50);
      SEND_STRING(SS_DELAY(1500));
      SEND_STRING_DELAY("\b\b\b\b\b\b\e", 50);
      SEND_STRING(SS_DELAY(20000)); // somehow 20 * 1000 does not work
      SEND_STRING("\e");
      SEND_STRING(SS_DELAY(5000));
      send_user_string(STR_A);
    }
    return false;
  case NUM_G:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT("g"));
    }
    return false;
  case CTRL_PGDN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_PGDN)));
    }
    break;
#if 0
  case REPEAT:
    update_repeat_key(record);
    return false;
#endif
  case CANCEL:
    layer_off(NUM);
    /* layer_off(_LMOD); */
    /* layer_off(_RMOD); */
    /* disable_gaming(); */
    return false;
  case CTRL_ALT_DEL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DELETE))));
    }
    break;
  case M_ARROW_RMINUS:  /* -> */
    if (record->event.pressed) {
      SEND_STRING("->");
      return false;
    }
    break;
  case M_ARROW_REQL:  /* => */
    if (record->event.pressed) {
      SEND_STRING("=>");
      return false;
    }
    break;
  case M_ARROW_RMINUS_BRACES:  /* ->{} and left */
    if (record->event.pressed) {
      SEND_STRING("->{}" SS_TAP(X_LEFT));
      return false;
    }
    break;

#ifdef CFQ_USE_SHIFT_QUOTES
  case KC_LSFT:  /* '' */
    if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_RSFT)))) {
      WITHOUT_MODS({
          SEND_STRING("''" SS_TAP(X_LEFT) SS_DOWN(X_RSFT) SS_DOWN(X_LSFT));
        });
      return false;
    }
    break;
  case KC_RSFT:  /* "" */
    if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_LSFT)))) {
      WITHOUT_MODS({
          SEND_STRING("\x22\x22" SS_TAP(X_LEFT) SS_DOWN(X_LSFT) SS_DOWN(X_RSFT));
        });
      return false;
    }
    break;
#endif  /* CFQ_USE_SHIFT_QUOTES */

  case STR_A...STR_Z:
    {
      if (record->event.pressed) {
        send_user_string(keycode);
        return false;
      }
      break;
    }
  case TMUX1...TMUX9:
    if (record->event.pressed) {
      // when keycode QMKBEST is pressed
      char numString[5];
      itoa(keycode-TMUX1+1, numString, 10);
      SEND_STRING(SS_LCTL("t"));
      send_string(numString);
    }
    break;
  }
  return true;
}

//  If these functions return true QMK will process the keycodes as usual. That
//  can be handy for extending the functionality of a key rather than replacing
//  it. If these functions return false QMK will skip the normal key handling,
//  and it will be up to you to send any key up or down events that are
//  required.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // from: https://github.com/qmk/qmk_firmware/issues/714#issuecomment-244339010
  // keylogger for stats analysis
  // the logged data can be parsed with https://github.com/algernon/ergodox-layout/blob/master/tools/log-to-heatmap.py

#ifdef CONSOLE_ENABLE
  uprintf("KL: key=%X%X pressed=%d\n",
          record->event.key.row, record->event.key.col,
          record->event.pressed);
#endif

  bool res = _process_record_user(keycode, record);

  // If `false` was returned, then we did something special and should register that manually.
  // Otherwise register it here by default.
  // Skip Space to not interfere with NAV toggling.
#if 0
  if (res /*&& record->event.pressed && keycode != MT_SPC*/) {
    register_key_to_repeat(keycode);
  }
#endif


  return res;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case MTLGUI:
  case MTRGUI:
    return TAPPING_TERM;
  case MTLALT:
    return TAPPING_TERM + 50;
  case MTRALT:
  case MTLSFT:
  case MTRSFT:
    return TAPPING_TERM;
  case MTLCTL:
  case MTRCTL:
    return TAPPING_TERM;
  default:
    return TAPPING_TERM;
  }
}

// This function is implemented in upstream but I can not use it due to firmware bloat after rebasing
// use get_auto_shifted_key() below instead
/*
  bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_Q:
  return true;
  default:
  return false;
  }
  }
*/
/*
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
  // disable autoshift for certain vim keys
  // note autoshift is disabled for modtap key automatically
  switch (keycode) {
  case KC_A:
  case KC_S:
  case KC_D:
  case KC_F:
  //case KC_U:
  //case KC_I:
  //case KC_O:
  case KC_H:
  case KC_J:
  case KC_K:
  case KC_L:
  //case KC_M:
    return false;
  }

  switch (keycode) {
#    ifndef NO_AUTO_SHIFT_ALPHA
  case KC_A ... KC_Z:
#    endif
#    ifndef NO_AUTO_SHIFT_NUMERIC
  case KC_1 ... KC_0:
#    endif
#    ifndef NO_AUTO_SHIFT_SPECIAL
  case KC_TAB:
  case KC_MINUS ... KC_SLASH:
  case KC_NONUS_BACKSLASH:
#    endif
    return true;
  }
  return false;
}
*/
// Turn off TAPPING_FORCE_HOLD for certain dual function keys
// to revert to the default auto-repeat behavior for tap-then-hold
#if 0
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LT(MEDIA, KC_BSPC):
    return false;
  default:
    return true;
  }
}
#endif

#if 0
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LSFT_T(KC_D):
  case LSFT_T(KC_K):
    return true;
  default:
    return false;
  }
}
#endif

#ifdef AUTO_SHIFT_TIMEOUT_PER_KEY
// code only exists in upstream
uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_I:
            return get_generic_autoshift_timeout() + 30;
    }

    switch(keycode) {
        /* case AUTO_SHIFT_NUMERIC: */
        /*     return 2 * get_generic_autoshift_timeout(); */
        /* case AUTO_SHIFT_SPECIAL: */
        /*     return get_generic_autoshift_timeout() + 50; */
        /* case AUTO_SHIFT_ALPHA: */
        default:
            return get_generic_autoshift_timeout();
    }
}
#endif



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

#define WITHOUT_MODS(...) \
  do { \
    uint8_t _real_mods = get_mods(); \
    clear_mods(); \
    { __VA_ARGS__ } \
    set_mods(_real_mods); \
  } while (0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    switch (keycode) {
case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
    case ALTSPC:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_LALT(" "));
        } else {
            // when keycode QMKBEST is released
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

      #if 0
#ifdef CFQ_USE_SHIFT_QUOTES
    case KC_LSHFT:  /* '' */
      if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_RSFT)))) {
        WITHOUT_MODS({
            SEND_STRING("''" SS_TAP(X_LEFT) SS_DOWN(X_RSHIFT) SS_DOWN(X_LSHIFT));
          });
        return false;
      }
      break;
    case KC_RSHFT:  /* "" */
      if (record->event.pressed && (keyboard_report->mods & (MOD_BIT(KC_LSFT)))) {
        WITHOUT_MODS({
            SEND_STRING("\x22\x22" SS_TAP(X_LEFT) SS_DOWN(X_LSHIFT) SS_DOWN(X_RSHIFT));
          });
        return false;
      }
      break;
#endif  /* CFQ_USE_SHIFT_QUOTES */
      #endif

    case STR_A...STR_Z:
    {
      uint8_t shift_index = (keyboard_report->mods & (MOD_BIT(KC_RSFT) | MOD_BIT(KC_LSFT))) ? 1 : 0;
      const char *word = usr_str_lut[shift_index][keycode - STR_A];
      if (record->event.pressed) {
        if (*word) {
          WITHOUT_MODS({
              send_string(word);
            });
        }
        return false;
      }
      break;
    }

    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case LGUI_T(KC_A):
  case LGUI_T(KC_QUOT):
    return TAPPING_TERM;
  case LALT_T(KC_S):
  //case LALT_T(KC_DOT):
  case LALT_T(KC_L):
    return TAPPING_TERM + 50;
  case LSFT_T(KC_D):
  case LSFT_T(KC_K):
    return TAPPING_TERM ;
  /* case LSFT_T(KC_COMM): */
  /*   return TAPPING_TERM - 50; */
  //case LCTL_T(KC_F):
  //case LCTL_T(KC_M):
  case LCTL_T(KC_J):
    return TAPPING_TERM - 30;
  default:
    return TAPPING_TERM;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_D):
        case LSFT_T(KC_K):
            return true;
        default:
            return false;
    }
}

// Combos

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Home-row and other tight combos
        /* case tab: */
        /* case escape: */
        case scln:
        //case dquo:
        case coln:
        /* case enter: */
        /* case quot: */
        /* case circ: */
        /* case dlr: */
        /* case vsp: */
            return COMBO_TERM;
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

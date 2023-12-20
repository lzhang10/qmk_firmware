/* custom keycode */
#ifndef MY_KEYCODE_H_
#define MY_KEYCODE_H_

#define CFQ_USE_SHIFT_QUOTES

#define TRNS    KC_TRNS

/* Available special keys that do not interfere with system setting
  Mac:  F13         F16 F17 F18 F19
  Linux     F14 F15 F16 F17 F18     F20 F21 F22
  */
#define U_F13   KC_F13 //Tools: open Gnome Settings
#define M_CHAT  KC_F13
#define U_F14   KC_F14
#define U_EMACS KC_F16
#define U_FILE  KC_F15 // XF86Launch6
#define U_WTERM KC_F16
#define U_WEB   KC_F17
#define U_WEB2  LSFT(KC_F17)
#define U_MAIL  KC_F18
#define U_F19   KC_F19 // NoSymbol
#define U_TERM  KC_F20
#define M_TERM  KC_F19 // Mac version
#define U_CODE  KC_F21 // XF86TouchpadToggle
#define M_CODE  LSFT(KC_F13) // MAC version
#define U_F22   KC_F22 // XF86TouchpadOn

// after changing modtap keys below you may want to review & tweak
// get_auto_shifted_key()
// get_tapping_term()

// standard setting for win/linux. Mac needs to swap control/command in OS.
#define MTLCTL LCTL_T(KC_F)
#define MTLSFT LSFT_T(KC_D)
#define MTLALT LALT_T(KC_S)
#define MTLGUI LGUI_T(KC_A)

#define MTRCTL RCTL_T(KC_J)
#define MTRSFT RSFT_T(KC_K)
#define MTRALT RALT_T(KC_L)
#define MTRGUI RGUI_T(KC_MINS)

enum custom_keycodes {
  CTRL_ALT_DEL = SAFE_RANGE,
  CTRL_PGDN,
  CAPSWORD,
  NUMWORD,
  SNAKECASE,
  M_ARROW_RMINUS,
  M_ARROW_REQL,
  M_ARROW_RMINUS_BRACES,
  //REPEAT, // not useful so far

  // Layer management
  CANCEL, // Cancel SYMWORD and NUMWORD
  CLEAR, // Clear all WORD, one-shots and reset to BASE
  TO_NUM,
  NUM_G, // shift G in num layer for vim navigation
  WAKE_M32U, // wake, sleep, wake to get rid of M32U coil whine

  // TMUX window switch
  TMUX1,
  TMUX2,
  TMUX3,
  TMUX4,
  TMUX5,
  TMUX6,
  TMUX7,
  TMUX8,
  TMUX9,

  /* allow user defined words for each character:
   * use CFQ_STR_[A-Z] defines. */
  STR_A, STR_B, STR_C, STR_D, STR_E, STR_F,
  STR_G, STR_H, STR_I, STR_J, STR_K, STR_L,
  STR_M, STR_N, STR_O, STR_P, STR_Q, STR_R,
  STR_S, STR_T, STR_U, STR_V, STR_W, STR_X,
  STR_Y, STR_Z,
};

#ifndef USR_STR_A
#define USR_STR_A ""
#endif
#ifndef USR_STR_B
#define USR_STR_B ""
#endif
#ifndef USR_STR_C
#define USR_STR_C ""
#endif
#ifndef USR_STR_D
#define USR_STR_D ""
#endif
#ifndef USR_STR_E
#define USR_STR_E ""
#endif
#ifndef USR_STR_F
#define USR_STR_F ""
#endif
#ifndef USR_STR_G
#define USR_STR_G ""
#endif
#ifndef USR_STR_H
#define USR_STR_H ""
#endif
#ifndef USR_STR_I
#define USR_STR_I ""
#endif
#ifndef USR_STR_J
#define USR_STR_J ""
#endif
#ifndef USR_STR_K
#define USR_STR_K ""
#endif
#ifndef USR_STR_L
#define USR_STR_L ""
#endif
#ifndef USR_STR_M
#define USR_STR_M ""
#endif
#ifndef USR_STR_N
#define USR_STR_N ""
#endif
#ifndef USR_STR_O
#define USR_STR_O ""
#endif
#ifndef USR_STR_P
#define USR_STR_P ""
#endif
#ifndef USR_STR_Q
#define USR_STR_Q ""
#endif
#ifndef USR_STR_R
#define USR_STR_R ""
#endif
#ifndef USR_STR_S
#define USR_STR_S ""
#endif
#ifndef USR_STR_T
#define USR_STR_T ""
#endif
#ifndef USR_STR_U
#define USR_STR_U ""
#endif
#ifndef USR_STR_V
#define USR_STR_V ""
#endif
#ifndef USR_STR_W
#define USR_STR_W ""
#endif
#ifndef USR_STR_X
#define USR_STR_X ""
#endif
#ifndef USR_STR_Y
#define USR_STR_Y ""
#endif
#ifndef USR_STR_Z
#define USR_STR_Z ""
#endif



#endif // MY_KEYCODE_H_

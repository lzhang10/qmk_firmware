#ifndef MACRO_H_
#define MACRO_H_

#define CFQ_USE_SHIFT_QUOTES

enum custom_keycodes {
  ALTSPC = SAFE_RANGE,
  CAPSWORD,
  SNAKECASE,
  M_ARROW_RMINUS,
  M_ARROW_REQL,
  M_ARROW_RMINUS_BRACES,

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



#endif // MACRO_H_

#ifndef LAYOUT_H_
#define LAYOUT_H_

// reduce firmware size by using less rows
#define LAYOUT_ansi_15x16( \
    K29,K3A,K3B,K3C,K3D,K3E,K3F,K40,K41,K42,K43,K44,K45,      K46,K47,K48,                   \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,  K49,K4A,K4B,  K53,K54,K55,K56, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K31,  K4C,K4D,K4E,  K5F,K60,K61,     \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K28,                K5C,K5D,K5E,K57, \
    KE1,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        KE5,      K52,      K59,K5A,K5B,     \
    KE0,KE3,KE2,        K2C,                KE6,KE7,K65,KE4,  K50,K51,K4F,  K62,    K63,K58  \
) { \
    { KC_NO, KC_NO, KC_NO, KC_NO, K04,   K05,   K06,   K07,      /* 00-07 */ \
      K08,   K09,   K0A,   K0B,   K0C,   K0D,   K0E,   K0F    }, /* 08-0F */ \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,      /* 10-17 */ \
      K18,   K19,   K1A,   K1B,   K1C,   K1D,   K1E,   K1F    }, /* 18-1F */ \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,      /* 20-27 */ \
      K28,   K29,   K2A,   K2B,   K2C,   K2D,   K2E,   K2F    }, /* 28-2F */ \
    { K30,   K31,   KC_NO, K33,   K34,   K35,   K36,   K37,      /* 30-37 */ \
      K38,   K39,   K3A,   K3B,   K3C,   K3D,   K3E,   K3F    }, /* 38-3F */ \
    { K40,   K41,   K42,   K43,   K44,   K45,   K46,   K47,      /* 40-47 */ \
      K48,   K49,   K4A,   K4B,   K4C,   K4D,   K4E,   K4F    }, /* 48-4F */ \
    { K50,   K51,   K52,   K53,   K54,   K55,   K56,   K57,      /* 50-57 */ \
      K58,   K59,   K5A,   K5B,   K5C,   K5D,   K5E,   K5F    }, /* 58-5F */ \
    { K60,   K61,   K62,   K63,   KC_NO, K65,   KC_NO, KC_NO,    /* 60-67 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, }, /* 68-6F */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* 70-77 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, }, /* 78-7F */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* 80-87 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* 88-8F */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* 90-97 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* 98-9F */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* A0-A7 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* A8-AF */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* B0-B7 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* B8-BF */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* C0-C7 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* C8-CF */ \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,    /* D0-D7 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* D8-DF */ \
    { KE0,   KE1,   KE2,   KE3,   KE4,   KE5,   KE6,   KE7,      /* E0-E7 */ \
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO  }, /* E8-EF */ \
}
/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */


// Kinesis Advantage 2 default keyboard mapped to ANSI
/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */

// L42, which is intl-\, is mapped to kp-plus on Kinesis
/* ---------- LEFT HAND -----------          ---------- RIGHT HAND ----------    */
#define LAYOUT_kinesis(                                                           \
LF0,LF1,LF2,LF3,LF4,LF5,LF6,LF7,LF8,         RF0,RF1,RF2,RF3,RF4,RF5,RF6,RF7,RF8, \
            L00,L01,L02,L03,L04,L05,         R00,R01,R02,R03,R04,R05,             \
            L10,L11,L12,L13,L14,L15,         R10,R11,R12,R13,R14,R15,             \
            L20,L21,L22,L23,L24,L25,         R20,R21,R22,R23,R24,R25,             \
            L30,L31,L32,L33,L34,L35,         R30,R31,R32,R33,R34,R35,             \
                L41,L42,L43,L44,                 R41,R42,R43,R44,                 \
                               LT1,LT2,   RT1,RT2,                                \
                                   LT3,   RT3,                                    \
                           LT4,LT5,LT6,   RT4,RT5,RT6)                            \
LAYOUT_ansi_15x16( \
    LF0,LF1,LF2,LF3,LF4,LF5,LF6,LF7,LF8,RF0,RF1,RF2,RF3,          RF4,RF5,RF6,                   \
    L41,L01,L02,L03,L04,L05,R00,R01,R02,R03,R04,R05,L00,LT4,      XXX,LT3,RT3,  XXX,XXX,XXX,XXX, \
    L10,L11,L12,L13,L14,L15,R10,R11,R12,R13,R14,R43,R44,R15,      LT5,LT6,RT4,  XXX,XXX,XXX,     \
    L20,L21,L22,L23,L24,L25,R20,R21,R22,R23,R24,R25,RT5,                        XXX,XXX,XXX,L42, \
    L30,L31,L32,L33,L34,L35,R30,R31,R32,R33,R34,R35,                 R41,       XXX,XXX,XXX,     \
    LT1,XXX,LT2,        RT6,                XXX,RT1,XXX,RT2,      L43,R42,L44,  XXX,    XXX,XXX  \
)

// Apple Magic keyboard mapped to ANSI
/* ,---.   ,---------------. ,---------------. ,---------------. ,-----------.
 * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau|
 * `---'   `---------------' `---------------' `---------------' `-----------'
 * ,-----------------------------------------------------------. ,-----------. ,---------------.
 * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|    Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -|
 * |-----------------------------------------------------------| |-----------| |---------------|
 * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +|
 * |-----------------------------------------------------------| `-----------' |-----------|   |
 * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Return|               |  4|  5|  6|  +|
 * |-----------------------------------------------------------|     ,---.     |---------------|
 * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|Shift     |     |Up |     |  1|  2|  3|   |
 * |-----------------------------------------------------------| ,-----------. |-----------|   |
 * |Ctl|Gui|Alt|           Space               |Alt|Gui|App|Ctl| |Lef|Dow|Rig| |      0|  .|Ent|
 * `-----------------------------------------------------------' `-----------' `---------------'
 */
#define LAYOUT_magic(                                                           \
KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,KC_F11,  KC_F12, KC_EJECT,\
KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL, KC_BSPC,\
KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,KC_BSLS,\
KC_CAPS,KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,       KC_ENT, \
KC_LSFT,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,KC_UP, \
KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                KC_RGUI,KC_RALT,    KC_LEFT, KC_DOWN, KC_RGHT) \
LAYOUT_ansi_15x16( \
KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,KC_F11, KC_F12,            XXX,XXX,XXX,\
KC_GRV, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,  KC_0,  KC_MINS, KC_EQL, KC_BSPC,  XXX,XXX,XXX, XXX,XXX,XXX,XXX,\
KC_TAB, KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,  KC_LBRC, KC_RBRC,KC_BSLS,  XXX,XXX,XXX, XXX,XXX,XXX,\
KC_CAPS,KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,       KC_ENT,                XXX,XXX,XXX,XXX, \
KC_LSFT,   KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH,  KC_RSFT,             KC_UP,    XXX,XXX,XXX,\
KC_LCTL,KC_LGUI,KC_LALT,                KC_SPC,                  KC_RALT,KC_RGUI,XXX, XXX,         KC_LEFT, KC_DOWN, KC_RGHT, XXX,    XXX,XXX \
)

/* Miryoku mapped to ANSI */
#define LAYOUT_miryoku(\
            K00,  K01,  K02,  K03,  K04,        K05,  K06,  K07,  K08,  K09,\
            K10,  K11,  K12,  K13,  K14,        K15,  K16,  K17,  K18,  K19,\
            K20,  K21,  K22,  K23,  K24,        K25,  K26,  K27,  K28,  K29,\
            N30,  N31,  K32,  K33,  K34,        K35,  K36,  K37,  N38,  N39\
)\
LAYOUT_ansi_15x16( \
    KC_ESC,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,      XXX,XXX,XXX,                   \
    KC_GRV,KC_EXLM, KC_AT,   KC_HASH,KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,KC_9,KC_0,KC_MINS,KC_EQL,K33,         XXX,U_PST,XXX,  XXX,XXX,XXX,XXX, \
    KC_GRV,K00,K01,K02,K03,K04,K05,K06,K07,K08,K09,KC_LBRC,KC_RBRC,KC_MINS,              K34,K32,K37,  XXX,XXX,XXX, \
    CTRL_PGDN,K10,K11,K12,K13,K14,K15,K16,K17,K18,K19,KC_UNDS,    K35,                XXX,XXX,XXX,KC_BSLS, \
    KC_LSFT,K20,K21,K22,K23,K24,K25,K26,K27,K28,K29,        KC_RSFT,      KC_UP,      XXX,XXX,XXX,     \
    KC_LCTL,KC_LGUI,KC_LALT,        K36,                XXX,KC_LGUI,XXX,KC_RCTL,  KC_LEFT,KC_DOWN,KC_RIGHT,  XXX,    XXX,XXX \
)


#endif // LAYOUT_H_

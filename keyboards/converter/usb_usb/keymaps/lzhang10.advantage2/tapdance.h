#ifndef TAPDANCE_H_
#define TAPDANCE_H_

// Tap Dance declarations https://docs.qmk.fm/features/tap_dance
enum {
    TD_ESC_CAPS,
    TD_0_1,
    TD_CPY_CUT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_0_1] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_1),
    [TD_CPY_CUT] = ACTION_TAP_DANCE_DOUBLE(C(KC_C), C(KC_X)),
};

#endif

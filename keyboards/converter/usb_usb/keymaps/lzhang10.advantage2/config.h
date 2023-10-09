// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku
// generated from users/manna-harbour_miryoku/miryoku.org  -*- buffer-read-only: t -*-

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#ifdef CONSOLE_ENABLE
   // save space by only using uprintf() in keylogger in process_record_user()
   #define NO_DEBUG
   #define USER_PRINT
#endif
#define LSPO_KEYS KC_LSFT, KC_TRNS, KC_ESC

#undef COMBO_TERM
// default COMBO_TERM is 50
#define COMBO_TERM 70
// combo should fire only if tapped, useful for a Mod-Tap or a Layer-Tap key
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space
#define COMBO_ONLY_FROM_LAYER 0

// default but used in macros
// minimum amount of time a key must be held down to register a hold.
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY  // see get_tapping_term()

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// https://precondition.github.io/home-row-mods#tapping-force-hold
// This however does not work for nav keys of a QWERTY Vim user, use NAV layer for that
#define TAPPING_FORCE_HOLD

// This allows turn off TAPPING_FORCE_HOLD for certain keys such as Backspace
// For those keys use get_tapping_force_hold() to revert to the default auto-repeat behavior for tap-then-hold
//#define TAPPING_FORCE_HOLD_PER_KEY

// Auto Shift
// disable certain keys in get_auto_shifted_key()
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP // disable three special keys to adjujst autoshift on the fly
// #define AUTO_SHIFT_REPEAT // not that useful
#define AUTO_SHIFT_TIMEOUT_PER_KEY  // need to update to upstream, see get_autoshift_timeout()

// this is supposed to send shifted letter for mod-tap keys after a time
// I could not get it to work.
//#define RETRO_SHIFT

// allow certain mod-tap key to send the letter when released after TAPPING_TERM
// pros: one can use a shorter TAPPING_TERM for those keys
// cons: does not work with autoshift:
// see bool get_retro_tapping(uint16_t keycode, keyrecord_t *record)
//#define RETRO_TAPPING_PER_KEY

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4

// Mouse key speed and acceleration.
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY          0
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL       16
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY    0
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED      6
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX    64


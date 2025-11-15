/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

enum layers { COLEMAK, QWERTY, NAV, NUM, SYM, FUN, MBO, MEDIA, MOUSE};

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)

#define LCONTROL LCTL_T(KC_A)
#define LOPTION LALT_T(KC_S)
#define LCOMMAND LGUI_T(KC_D)
#define LSHIFT LSFT_T(KC_F)
#define RSHIFT RSFT_T(KC_J)
#define RCOMMAND RGUI_T(KC_K)
#define ROPTION RALT_T(KC_L)
#define RCONTROL RCTL_T(KC_QUOT)

#define C_LCONTROL LCTL_T(KC_A)
#define C_LOPTION LALT_T(KC_R)
#define C_LCOMMAND LGUI_T(KC_S)
#define C_LSHIFT LSFT_T(KC_T)
#define C_RSHIFT RSFT_T(KC_N)
#define C_RCOMMAND RGUI_T(KC_E)
#define C_ROPTION RALT_T(KC_I)
#define C_RCONTROL RCTL_T(KC_O)

#define MEDIA_ESC LT(MEDIA, KC_ESC)
#define NAV_TAB   LT(NAV, KC_TAB)
#define MOUSE_SPC LT(MOUSE, KC_SPC)
#define SYM_ENT   LT(SYM, KC_ENT)
#define NUM_BSPC  LT(NUM, KC_BSPC)
#define FUN_DEL   LT(FUN, KC_DEL)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT_miryoku(
      //,--------------------------------------------------------.                         ,---------------------------------------------------------.
          KC_Q,    KC_W,     KC_F,    KC_P,     KC_G,                                         KC_J,     KC_L,     KC_U,    KC_Y,    KC_QUOT,
      //|--------+---------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------+--------|
          C_LCONTROL,C_LOPTION,C_LCOMMAND,C_LSHIFT,KC_D,                                      KC_H,    C_RSHIFT,C_RCOMMAND,C_ROPTION,C_RCONTROL,
      //|--------+---------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------+--------|
          KC_Z,    KC_X,     KC_C,     KC_V,      KC_B,                                        KC_K,      KC_M,   KC_COMM,  KC_DOT,   KC_SLSH,
      //|--------+---------+--------+--------+----------+--------+------------|  |---------+---------+---------+---------+---------+--------+--------|
                                      MEDIA_ESC, NAV_TAB, MOUSE_SPC,                 SYM_ENT, NUM_BSPC, FUN_DEL,                    DF(QWERTY)
                                           //`--------------------------------'  `----------------------------'
    ),
  [QWERTY] = LAYOUT_miryoku(
    //,------------------------------------------------.                         ,------------------------------------------------.
         KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,                              KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,
    //|----------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------|
         LCONTROL,LOPTION, LCOMMAND, LSHIFT,    KC_G,                               KC_H,     RSHIFT, RCOMMAND, ROPTION,  RCONTROL,
    //|----------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------|
         KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,                              KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,
    //|----------+--------+--------+----------+--------+------------|  |---------+---------+---------+---------+---------+--------|
                            MEDIA_ESC, NAV_TAB, MOUSE_SPC,                         SYM_ENT, NUM_BSPC, FUN_DEL,          DF(COLEMAK)
                                //`--------------------------------'  `----------------------------'
  ),
  [NAV] = LAYOUT_miryoku(
        //,--------------------------------------------.                    ,------- ----------------------------------.
            QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,                        U_NA,  U_PST,   U_CPY,   U_CUT,   U_UND,
        //|--------+--------+--------+--------+--------|                    |------- -------+--------+--------+--------|
            KC_LCTL, KC_LALT,  KC_LGUI, KC_LSFT, U_NA,                        U_NA,  KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,
        //|--------+--------+--------+--------+--------|                    |------- -------+--------+--------+--------|
             U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,                        U_NA,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        //|--------+--------+--------+--------+--------+--------|  |--------+-------+--------+--------+--------+--------|
                                    U_NA,    U_NA,    U_NA,                    KC_ENT, KC_BSPC, KC_DEL, U_NA
                                    //`--------------------------'  `--------------------------'
  ),
  [NUM] = LAYOUT_miryoku(
        //,--------------------------------------------.                    ,--------------------------------------------.
            KC_LBRC,  KC_7,    KC_8,    KC_9,  KC_RBRC,                       U_NA,    U_NA,    U_NA,    U_NA,   RESET,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
            KC_SCLN,  KC_4,    KC_5,    KC_6,   KC_EQL,                        U_NA,  KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------|
            KC_GRV,   KC_1,    KC_2,    KC_3,   KC_BSLS,                      U_NA,   U_NA,    U_NA,   KC_ALGR,  U_NA,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------|
                                        KC_DOT,  KC_0,  KC_MINS,             U_NA,      U_NA,    U_NA,          U_NA
                                   //`--------------------------'  `--------------------------'
  ),
  [SYM] = LAYOUT_miryoku(
        //,--------------------------------------------.                    ,--------------------------------------------.
           KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RCBR,                      U_NA,    U_NA,    U_NA,    RESET,  U_NA,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                       U_NA, KC_LSFT,   KC_LGUI, KC_LALT, KC_LCTL,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                       U_NA,    U_NA,    U_NA,    U_NA,    U_NA,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                     KC_LPRN, KC_RPRN, KC_UNDS,               U_NA,    U_NA,     U_NA,           U_NA
                                 //`--------------------------'  `--------------------------'
  ),
  [FUN] = LAYOUT_miryoku(
        //,-------------------------------------------.                    ,--------------------------------------------.
           KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_PSCR,                       U_NA,    U_NA,    U_NA,    U_NA,  RESET,
        //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
           KC_F11,  KC_F4,   KC_F5,   KC_F6,  KC_SCROLL_LOCK,                U_NA, KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
        //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
           KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_PAUS,                       U_NA,     U_NA,  U_NA,    U_NA,     U_NA,
        //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+|
                                      KC_APP,  KC_SPC,  KC_TAB,             U_NA,       U_NA,    U_NA,           U_NA
                                  //`--------------------------'  `--------------------------'
  ),
  [MBO] = LAYOUT_miryoku(
       //,--------------------------------------------.                    ,---------------------------------------------.
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
          KC_LCTL, KC_LALT,  KC_LGUI, KC_LSFT, KC_TRNS,                      KC_TRNS,KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,
       //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
          U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,                         U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,
       //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+|
                               KC_BTN2, KC_BTN3, KC_BTN1,                    KC_BTN1, KC_BTN3, KC_BTN2,          U_NA
                                  //`--------------------------'  `--------------------------'
  ),
  [MEDIA] = LAYOUT_miryoku(
        //,-------------------------------------------.                    ,---------------------------------------------.
            RESET,   U_NA,    U_NA,    U_NA,    U_NA,                        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
        //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
           KC_LCTL, KC_LALT,  KC_LGUI, KC_LSFT, U_NA,                         U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        //|-------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
           U_NA,    U_NA,     U_NA,    U_NA,    U_NA,                         U_NU,    U_NU,    U_NU,    U_NU,    U_NU,
        //|-------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+|
                                    U_NA,    U_NA,    U_NA,                 KC_MSTP, KC_MPLY, KC_MUTE,           U_NA
                                 //`--------------------------'  `--------------------------'
  ),
  [MOUSE] = LAYOUT_miryoku(
        //,--------------------------------------------.                    ,---------------------------------------------.
            RESET,   U_NA,    U_NA,    U_NA,    U_NA,                         U_PST,   U_CPY,   U_CUT,   U_UND,  U_RDO,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
           KC_LCTL, KC_LALT,  KC_LGUI, KC_LSFT, U_NA,                         U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+|
            U_NA,    U_NA,    U_NA,    U_NA,    U_NA,                         U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+|
                                        U_NA,    U_NA,    U_NA,                KC_BTN1, KC_BTN3, KC_BTN2,        U_NA
                                    //`--------------------------'  `--------------------------'
  )
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif



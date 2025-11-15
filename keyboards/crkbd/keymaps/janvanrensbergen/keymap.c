/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

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

const uint16_t PROGMEM cpslk_combo[] = {C_LCONTROL, C_RCONTROL, COMBO_END};
combo_t key_combos[] = {
    COMBO(cpslk_combo, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT_split_3x6_3(
      //,--------------------------------------------------------.                         ,---------------------------------------------------------.
       DF(QWERTY),   KC_Q,    KC_W,     KC_F,    KC_P,     KC_G,                               KC_J,     KC_L,     KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
      //|--------+---------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------+--------|
          KC_LCTL, C_LCONTROL,C_LOPTION,C_LCOMMAND,C_LSHIFT,KC_D,                            KC_H,    C_RSHIFT,C_RCOMMAND,C_ROPTION,C_RCONTROL,KC_QUOT,
      //|--------+---------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------+--------|
          KC_LSFT, KC_Z,    KC_X,     KC_C,     KC_V,      KC_B,                              KC_K,      KC_M,   KC_COMM,  KC_DOT,   KC_SLSH, KC_ESC,
      //|--------+---------+--------+--------+----------+--------+------------|  |---------+---------+---------+---------+---------+--------+--------|
                                               MEDIA_ESC, NAV_TAB, MOUSE_SPC,      SYM_ENT, NUM_BSPC, FUN_DEL
                                           //`--------------------------------'  `----------------------------'
    ),
  [QWERTY] = LAYOUT_split_3x6_3(
      //,--------------------------------------------------------.                         ,---------------------------------------------------------.
      DF(COLEMAK),  KC_Q,     KC_W,    KC_E,    KC_R,      KC_T,                              KC_Y,     KC_U,     KC_I,    KC_O,      KC_P,   KC_BSPC,
      //|--------+---------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------+--------|
          KC_LCTL, LCONTROL,LOPTION, LCOMMAND, LSHIFT,    KC_G,                               KC_H,     RSHIFT, RCOMMAND, ROPTION,  RCONTROL, KC_QUOT,
      //|--------+---------+--------+--------+----------+--------|                         |---------+---------+---------+---------+--------+--------|
          KC_LSFT, KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,                              KC_N,     KC_M,    KC_COMM,  KC_DOT,   KC_SLSH, KC_ESC,
      //|--------+---------+--------+--------+----------+--------+------------|  |---------+---------+---------+---------+---------+--------+--------|
                                               MEDIA_ESC, NAV_TAB, MOUSE_SPC,      SYM_ENT, NUM_BSPC, FUN_DEL
                                           //`--------------------------------'  `----------------------------'
    ),

  [NAV] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             U_NA,    QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,                          U_NA, U_PST,   U_CPY,   U_CUT,   U_UND,  U_RDO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             U_NA,   KC_LCTL, KC_LALT,  KC_LGUI, KC_LSFT, U_NA,                          U_NA, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_CAPS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             U_NA,    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,                          U_NA, KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 U_NA,    U_NA,    U_NA,      KC_ENT, KC_BSPC, KC_DEL
                                             //`--------------------------'  `--------------------------'
  ),
  [NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            U_NA,    KC_LBRC,  KC_7,    KC_8,    KC_9,  KC_RBRC,                        U_NA,    U_NA,    U_NA,    U_NA,   QK_BOOT,   U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,    KC_SCLN,  KC_4,    KC_5,    KC_6,   KC_EQL,                        U_NA,   KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,  U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,    KC_GRV,   KC_1,    KC_2,    KC_3,   KC_BSLS,                       U_NA,   U_NA,    U_NA,   KC_ALGR,  U_NA,    U_NA,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_DOT,  KC_0,  KC_MINS,      U_NA,    U_NA,    U_NA
                                             //`--------------------------'  `--------------------------'
  ),
  [SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            U_NA,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RCBR,                      U_NA,    U_NA,    U_NA,    U_NA,    QK_BOOT,  U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                        U_NA,   KC_LSFT,   KC_LGUI, KC_LALT, KC_LCTL, U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                       U_NA,    U_NA,    U_NA,    KC_ALGR, U_NA, U_NA,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                 KC_LPRN, KC_RPRN, KC_UNDS,      U_NA,     U_NA,    U_NA
                                             //`--------------------------'  `--------------------------'
  ),
  [FUN] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            U_NA,    KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_PSCR,                        U_NA,    U_NA,    U_NA,    U_NA,  QK_BOOT,    U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,    KC_F11,  KC_F4,   KC_F5,   KC_F6,  KC_SCRL,                        U_NA,  KC_LSFT, KC_LGUI, KC_LALT, KC_LCTL,   U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,    KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_PAUS,                        U_NA,     U_NA,  U_NA,    KC_ALGR, U_NA,    U_NA,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_APP,  KC_SPC,  KC_TAB,      U_NA,    U_NA,    U_NA
                                             //`--------------------------'  `--------------------------'
  ),
  [MBO] = LAYOUT_split_3x6_3(
       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           U_NA,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, U_NA,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_TRNS,                       KC_TRNS, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,  U_NA,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           U_NA,   U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND,                         U_RDO,   U_PST,   U_CPY,   U_CUT,   U_UND, U_NA,
       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                              KC_BTN2, KC_BTN3, KC_BTN1,     KC_BTN1, KC_BTN3, KC_BTN2
                                            //`--------------------------'  `--------------------------'
  ),
  [MEDIA] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
             U_NA,    QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,                         RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             U_NA,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, U_NA,                         U_NU,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
             U_NA,   U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,                         U_NU,    U_NU,    U_NU,    U_NU,    U_NU,    U_NA,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                U_NA,    U_NA,    U_NA,        KC_MSTP, KC_MPLY, KC_MUTE
                                             //`--------------------------'  `--------------------------'
  ),
  [MOUSE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            U_NA,    QK_BOOT,   U_NA,    U_NA,    U_NA,    U_NA,                         U_PST,   U_CPY,   U_CUT,   U_UND,  U_RDO,   U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            U_NA,    KC_LCTL, KC_LALT,  KC_LGUI, KC_LSFT, U_NA,                         U_NU,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, U_NA,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_P,    U_NA,    KC_ALGR, U_NA,    U_NA,    U_NA,                         U_NU,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, U_NA,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                U_NA,    U_NA,    U_NA,       KC_BTN1, KC_BTN3, KC_BTN2
                                             //`--------------------------'  `--------------------------'
  )
};


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (biton32(layer_state)) {
        case NAV:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case NUM:
            oled_write_ln_P(PSTR("Numeric"), false);
            break;
        case SYM:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case FUN:
            oled_write_ln_P(PSTR("Function keys"), false);
            break;
        case MEDIA:
            oled_write_ln_P(PSTR("Media"), false);
            break;
        case MOUSE:
            oled_write_ln_P(PSTR("Mouse"), false);
            break;
        default:
            switch (biton32(default_layer_state)) {
                case COLEMAK:
                   oled_write_ln_P(PSTR("Colemak"), false); break;
                case QWERTY:
                    oled_write_ln_P(PSTR("Qwerty"), false); break;
                default:
                    oled_write_ln_P(PSTR("undefined"), false);
            }
    }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case C_LCONTROL:
    case C_LOPTION:
    case C_LCOMMAND:
    case C_LSHIFT:
    case C_RSHIFT:
    case C_RCOMMAND:
    case C_ROPTION:
    case C_RCONTROL:
        return TAPPING_TERM - 50;
    case MEDIA_ESC:
    case NAV_TAB:
    case MOUSE_SPC:
    case SYM_ENT:
    case NUM_BSPC:
    case FUN_DEL:
        return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    default:
        case C_LCONTROL:
        case C_LOPTION:
        case C_LCOMMAND:
        case C_LSHIFT:
        case C_RSHIFT:
        case C_RCOMMAND:
        case C_ROPTION:
        case C_RCONTROL:
            return true;
        case NAV_TAB:
        case MOUSE_SPC:
        case SYM_ENT:
        case NUM_BSPC:
        case FUN_DEL:
            return false;
      return true;
  }
}

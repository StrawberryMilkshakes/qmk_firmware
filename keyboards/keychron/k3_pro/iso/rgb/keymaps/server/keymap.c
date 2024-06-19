/* Copyright 2023 @ Keychron (https://www.keychron.com)
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


enum custom_keycodes {
     QWERTY_ae = SAFE_RANGE,  // ALT + 0228 / 132 check
     QWERTY_oe,               // ALT + 0246
     QWERTY_ue,               // ALT + 0252
     QWERTY_AE,               // ALT + 0196
     QWERTY_OE,               // ALT + 0214
     QWERTY_UE,               // ALT + 0220 
     QWERTY_sz,               // ALT + 0223
     QWERTY_CIRC,             // ALT + 0176
     QWERTY_PRGR,             // ALT + 0164
     QWERTY_BT,               // ALT + 0180 check
     QWERTY_EURO,             // ALT + 0128

     BIOS_MACRO,
};

#define QWERTY_y    KC_Y
#define QWERTY_z    KC_Z

#define QWERTY_A    LSFT(KC_A)
#define QWERTY_B    LSFT(KC_B)
#define QWERTY_C    LSFT(KC_C)
#define QWERTY_D    LSFT(KC_D)
#define QWERTY_E    LSFT(KC_E)
#define QWERTY_F    LSFT(KC_F)
#define QWERTY_G    LSFT(KC_G)
#define QWERTY_H    LSFT(KC_H)
#define QWERTY_I    LSFT(KC_I)
#define QWERTY_J    LSFT(KC_J)
#define QWERTY_K    LSFT(KC_K)
#define QWERTY_L    LSFT(KC_L)
#define QWERTY_M    LSFT(KC_M)
#define QWERTY_N    LSFT(KC_N)
#define QWERTY_O    LSFT(KC_O)
#define QWERTY_P    LSFT(KC_P)
#define QWERTY_Q    LSFT(KC_Q)
#define QWERTY_R    LSFT(KC_R)
#define QWERTY_S    LSFT(KC_S)
#define QWERTY_T    LSFT(KC_T)
#define QWERTY_U    LSFT(KC_U)
#define QWERTY_V    LSFT(KC_V)
#define QWERTY_W    LSFT(KC_W)
#define QWERTY_X    LSFT(KC_X)
#define QWERTY_Y    LSFT(QWERTY_y)
#define QWERTY_Z    LSFT(QWERTY_z)

#define QWERTY_GRV  LSFT(KC_6)
//#define QWERTY_CIRC
#define QWERTY_EXCL LSFT(KC_1)
#define QWERTY_DBQT LSFT(KC_QUOT)
//#define QWERTY_PRGR
#define QWERTY_DOLL LSFT(KC_4)
#define QWERTY_PERC LSFT(KC_5)
#define QWERTY_AND  LSFT(KC_7)
#define QWERTY_SLSH KC_SLSH
#define QWERTY_CBRO LSFT(KC_LBRC)
#define QWERTY_CBRC LSFT(KC_RBRC)
#define QWERTY_SBRO KC_LBRC
#define QWERTY_SBRC KC_RBRC
#define QWERTY_BRO  LSFT(KC_9)
#define QWERTY_BRC  LSFT(KC_0)
#define QWERTY_EQ   KC_EQL
#define QWERTY_QM   LSFT(KC_SLSH)
#define QWERTY_BSLS KC_BSLS
//#define QWERTY_BT
#define QWERTY_FT   KC_GRV
#define QWERTY_PLUS LSFT(KC_EQL)
#define QWERTY_ASTR LSFT(KC_8)
#define QWERTY_TILD LSFT(KC_GRV)
#define QWERTY_QUOT KC_QUOT
#define QWERTY_SHRP LSFT(KC_3)
#define QWERTY_LT   LSFT(KC_COMM)
#define QWERTY_GT   LSFT(KC_DOT)
#define QWERTY_OR   LSFT(KC_BSLS)
#define QWERTY_COMM KC_COMM
#define QWERTY_DOT  KC_DOT
#define QWERTY_SEMI KC_SCLN
#define QWERTY_DDOT LSFT(KC_SCLN)
#define QWERTY_MINS KC_MINS
#define QWERTY_UNDE LSFT(KC_MINS)
#define QWERTY_AT   LSFT(KC_2)
//#define QWERTY_EURO



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
          case QWERTY_ae:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("ae");
               }
               break;
          case QWERTY_AE:
               if (record->event.pressed) {
                    SEND_STRING("AE");
               } 
               break;
          case QWERTY_oe:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("oe");
               } 
               break;
          case QWERTY_OE:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("OE");
               } 
               break;
          case QWERTY_ue:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("ue");
               } 
               break;
          case QWERTY_UE:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("UE");
               } 
               break;
          case QWERTY_sz:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING("ss");
               } 
               break;
          case BIOS_MACRO:
               if (record->event.pressed) {
                    // when keycode QMKBEST is pressed
                    SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_F1) SS_TAP(X_F10) SS_TAP(X_DEL) SS_TAP(X_ENT));
               } else {

               }
               break;
     }
     return true;
};



// clang-format off
enum layers{
  QWERTZ,
  QWERTY,
  QWERTY_SHFT,
  QWERTY_ALT,
  FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTZ] = LAYOUT_iso_85(
     KC_ESC,           KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F6,         KC_F7,         KC_F8,         KC_F9,            KC_F10,        KC_F11,        KC_F12,        BIOS_MACRO,    XXXXXXX,      TO(QWERTY),
     KC_GRV,           KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_6,          KC_7,          KC_8,          KC_9,             KC_0,          KC_MINS,       KC_EQL,                KC_BSPC,             KC_INS ,
     KC_TAB,           KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          KC_Y,          KC_U,          KC_I,          KC_O,             KC_P,          KC_LBRC,       KC_RBRC,               KC_ENT,              KC_DEL ,
     KC_CAPS,          KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_H,          KC_J,          KC_K,          KC_L,             KC_SCLN,       KC_QUOT,       KC_BSLS,                                    KC_PGUP,
     KC_LSFT,          KC_NUBS,       KC_Z,          KC_X,          KC_C,          KC_V,          KC_B,          KC_N,          KC_M,          KC_COMM,          KC_DOT,        KC_SLSH,       KC_RSFT,               KC_UP,               KC_PGDN ,
     KC_LCTL,          KC_LGUI,       KC_LALT,                                                    KC_SPC,                                      KC_RALT,          MO(FN),        KC_RCTL,       KC_LEFT,               KC_DOWN,             KC_RGHT),

[QWERTY] = LAYOUT_iso_85(
     KC_ESC,           KC_F1,         KC_F2,         KC_F3,         KC_F4,         KC_F5,         KC_F6,         KC_F7,         KC_F8,         KC_F9,            KC_F10,        KC_F11,        KC_F12,        BIOS_MACRO,    TO(QWERTZ),   XXXXXXX,
     QWERTY_GRV,       KC_1,          KC_2,          KC_3,          KC_4,          KC_5,          KC_6,          KC_7,          KC_8,          KC_9,             KC_0,          XXXXXXX,       _______,               KC_BSPC,             KC_INS ,
     KC_TAB,           KC_Q,          KC_W,          KC_E,          KC_R,          KC_T,          QWERTY_z,      KC_U,          KC_I,          KC_O,             KC_P,          XXXXXXX,       QWERTY_PLUS,           KC_ENT,              KC_DEL ,
     TG(QWERTY_SHFT),  KC_A,          KC_S,          KC_D,          KC_F,          KC_G,          KC_H,          KC_J,          KC_K,          KC_L,             XXXXXXX,       XXXXXXX,       QWERTY_SHRP,                                KC_PGUP,
     MO(QWERTY_SHFT),  QWERTY_LT,     QWERTY_y,      KC_X,          KC_C,          KC_V,          KC_B,          KC_N,          KC_M,          QWERTY_COMM,      QWERTY_DOT,    QWERTY_MINS,   MO(QWERTY_SHFT),       KC_UP,               KC_PGDN,
     KC_LCTL,          KC_LGUI,       KC_LALT,                                                    KC_SPC,                                      MO(QWERTY_ALT),   MO(FN),        KC_RCTL,       KC_LEFT,               KC_DOWN,             KC_RGHT),

[QWERTY_SHFT] = LAYOUT_iso_85(
     _______,          _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,          _______,       _______,       _______,        _______,       _______,     _______,
     _______,          QWERTY_EXCL,   QWERTY_DBQT,   _______,       QWERTY_DOLL,   QWERTY_PERC,   QWERTY_AND,    QWERTY_SLSH,   QWERTY_BRO,    QWERTY_BRC,       QWERTY_EQ,     QWERTY_QM,     QWERTY_FT,             _______,             _______,
     _______,          QWERTY_Q,      QWERTY_W,      QWERTY_E,      QWERTY_R,      QWERTY_T,      QWERTY_Z,      QWERTY_U,      QWERTY_I,      QWERTY_O,         QWERTY_P,      XXXXXXX,       QWERTY_ASTR,           _______,             _______,
     _______,          QWERTY_A,      QWERTY_S,      QWERTY_D,      QWERTY_F,      QWERTY_G,      QWERTY_H,      QWERTY_J,      QWERTY_K,      QWERTY_L,         XXXXXXX,       XXXXXXX,       QWERTY_QUOT,                                _______,
     _______,          QWERTY_GT,     QWERTY_Y,      QWERTY_X,      QWERTY_C,      QWERTY_V,      QWERTY_B,      QWERTY_N,      QWERTY_M,      QWERTY_SEMI,      QWERTY_DDOT,   QWERTY_UNDE,   _______,               _______,             _______,
     _______,          _______,       _______,                                                    _______,                                     _______,          _______,       _______,       _______,               _______,             _______),

[QWERTY_ALT] = LAYOUT_iso_85(
     _______,          _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,          _______,       _______,       _______,        _______,       _______,     _______,
     _______,           _______,      _______,       _______,       _______,       _______,       _______,       QWERTY_CBRO,   QWERTY_SBRO,   QWERTY_SBRC,      QWERTY_CBRC,   QWERTY_BSLS,   _______,               _______,             _______,
     _______,          QWERTY_AT,     _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,          _______,       _______,       QWERTY_TILD,           _______,             _______,
     _______,          _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,          _______,       _______,       _______,                                    _______,
     _______,          QWERTY_OR,     _______,       _______,       _______,       _______,       _______,       _______,       _______,       _______,          _______,       _______,       _______,               _______,             _______,
     _______,          _______,       _______,                                                    _______,                                     _______,          _______,       _______,       _______,               _______,             _______),

[FN] = LAYOUT_iso_85(
     _______,          KC_BRID,       KC_BRIU,       KC_TASK,       KC_FILE,       RGB_VAD,       RGB_VAI,       KC_MPRV,       KC_MPLY,       KC_MNXT,          KC_MUTE,       KC_VOLD,       KC_VOLU,        _______,       _______,     RGB_TOG,
     _______,          BT_HST1,       BT_HST2,       BT_HST3,       _______,       _______,       _______,       _______,       _______,       _______,          _______,       _______,       _______,               _______,             _______,
     RGB_TOG,          RGB_MOD,       RGB_VAI,       RGB_HUI,       RGB_SAI,       RGB_SPI,       _______,       _______,       _______,       _______,          _______,       _______,       _______,               _______,             _______,
     _______,          RGB_RMOD,      RGB_VAD,       RGB_HUD,       RGB_SAD,       RGB_SPD,       _______,       _______,       _______,       _______,          _______,       _______,       _______,                                    _______,
     _______,          _______,       _______,       _______,       _______,       _______,       BAT_LVL,       NK_TOGG,       _______,       _______,          _______,       _______,       _______,               _______,             _______,
     _______,          _______,       _______,                                                    _______,                                     _______,          _______,       _______,       _______,               _______,             _______)
};

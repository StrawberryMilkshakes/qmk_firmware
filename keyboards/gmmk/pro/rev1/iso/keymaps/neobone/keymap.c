/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "keymap_german.h"

/***************************************************** Layers **********************************************************/

#define BONE_L1 0
#define BONE_L2 1
#define BONE_L3 2
#define BONE_L4 3

#define QWERTZ 4

#define FN 5

/***************************************************** Alpha Keys **********************************************************/


// letters
#define BONE_a                      DE_A
#define BONE_b                      DE_B
#define BONE_c                      DE_C
#define BONE_d                      DE_D
#define BONE_e                      DE_E
#define BONE_f                      DE_F
#define BONE_g                      DE_G
#define BONE_h                      DE_H
#define BONE_i                      DE_I
#define BONE_j                      DE_J
#define BONE_k                      DE_K
#define BONE_l                      DE_L
#define BONE_m                      DE_M
#define BONE_n                      DE_N
#define BONE_o                      DE_O
#define BONE_p                      DE_P
#define BONE_q                      DE_Q
#define BONE_r                      DE_R
#define BONE_s                      DE_S
#define BONE_t                      DE_T
#define BONE_u                      DE_U
#define BONE_v                      DE_V
#define BONE_w                      DE_W
#define BONE_x                      DE_X
#define BONE_y                      DE_Y
#define BONE_z                      DE_Z
#define BONE_ae                     DE_ADIA
#define BONE_ue                     DE_UDIA
#define BONE_oe                     DE_ODIA
#define BONE_sz                     DE_SS

#define BONE_A                      LSFT(DE_A)
#define BONE_B                      LSFT(DE_B)
#define BONE_C                      LSFT(DE_C)
#define BONE_D                      LSFT(DE_D)
#define BONE_E                      LSFT(DE_E)
#define BONE_F                      LSFT(DE_F)
#define BONE_G                      LSFT(DE_G)
#define BONE_H                      LSFT(DE_H)
#define BONE_I                      LSFT(DE_I)
#define BONE_J                      LSFT(DE_J)
#define BONE_K                      LSFT(DE_K)
#define BONE_L                      LSFT(DE_L)
#define BONE_M                      LSFT(DE_M)
#define BONE_N                      LSFT(DE_N)
#define BONE_O                      LSFT(DE_O)
#define BONE_P                      LSFT(DE_P)
#define BONE_Q                      LSFT(DE_Q)
#define BONE_R                      LSFT(DE_R)
#define BONE_S                      LSFT(DE_S)
#define BONE_T                      LSFT(DE_T)
#define BONE_U                      LSFT(DE_U)
#define BONE_V                      LSFT(DE_V)
#define BONE_W                      LSFT(DE_W)
#define BONE_X                      LSFT(DE_X)
#define BONE_Y                      LSFT(DE_Y)
#define BONE_Z                      LSFT(DE_Z)
#define BONE_AE                     LSFT(DE_ADIA)
#define BONE_UE                     LSFT(DE_UDIA)
#define BONE_OE                     LSFT(DE_ODIA)

// numbers
#define BONE_1                      DE_1
#define BONE_2                      DE_2
#define BONE_3                      DE_3
#define BONE_4                      DE_4
#define BONE_5                      DE_5
#define BONE_6                      DE_6
#define BONE_7                      DE_7
#define BONE_8                      DE_8
#define BONE_9                      DE_9
#define BONE_0                      DE_0

// punctuation
#define BONE_COMMA                  DE_COMM
#define BONE_DOT                    DE_DOT
#define BONE_CIRC                   DE_CIRC
#define BONE_DEGR                   DE_DEG    
#define BONE_PARA                   DE_SECT
#define BONE_DOLLAR                 DE_DLR
#define BONE_EURO                   DE_EURO
#define BONE_POUND                  XXXXXXX
#define BONE_YEN                    XXXXXXX
#define BONE_MINUS                  DE_MINS
#define BONE_UNDER                  DE_UNDS
#define BONE_DQUOTE                 DE_DQUO
#define BONE_THREEDOT               XXXXXXX
#define BONE_SQBRO                  DE_LBRC
#define BONE_SQBRC                  DE_RBRC          
#define BONE_EXCL                   DE_EXLM
#define BONE_LT                     DE_LABK
#define BONE_GT                     DE_RABK
#define BONE_EQ                     DE_EQL
#define BONE_AND                    DE_AMPR
#define BONE_SQUOTE                 DE_QUOT
#define BONE_BACKSL                 DE_BSLS
#define BONE_SLASH                  DE_SLSH
#define BONE_CUBRO                  DE_LCBR
#define BONE_CUBRC                  DE_RCBR
#define BONE_ASTRSK                 DE_ASTR
#define BONE_QM                     DE_QUES
#define BONE_BRO                    DE_LPRN
#define BONE_BRC                    DE_RPRN
#define BONE_DBDOT                  DE_COLN
#define BONE_AT                     DE_AT
#define BONE_HASH                   DE_HASH
#define BONE_OR                     DE_PIPE
#define BONE_TILDE                  DE_TILD
#define BONE_PLUS                   DE_PLUS
#define BONE_PERC                   DE_PERC
#define BONE_AIGU                   DE_ACUT
#define BONE_GRAVE                  DE_GRV
#define BONE_SEMIC                  DE_SCLN

/***************************************************** Unicode Map **********************************************************/

enum my_keycodes {
    KC_MINE = SAFE_RANGE,
    KC_LAMBDA,
    KC_MINE2,
    KC_MINE3,
    KC_MINE4,
};


void custom_key(char* unshifted, char* shifted, keyrecord_t *record) {
    if(record->event.pressed) {
        if( (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)) ) {
            unregister_code(KC_LSFT | KC_RSFT);
            SEND_STRING(shifted);
            register_code(KC_LSFT | KC_RSFT);
        } else if((get_mods() & (MOD_BIT(KC_LSFT))) == MOD_BIT(KC_LSFT)) {
            unregister_code(KC_LSFT);
            SEND_STRING(shifted);
            register_code(KC_LSFT);
        } else if((get_mods() & (MOD_BIT(KC_RSFT))) == MOD_BIT(KC_RSFT)) {
            unregister_code(KC_RSFT);
            SEND_STRING(shifted);
            register_code(KC_RSFT);
        } else {
            SEND_STRING(unshifted);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_MINE:
            custom_key("n", ":", record);
            return true;
        case KC_LAMBDA:
            if(record->event.pressed) {
                SEND_STRING("λ");
            }
            return true;
        case KC_MINE2:
            if(record->event.pressed) {
                SEND_STRING("test");
            }
            return true;
        case KC_MINE3:
            if(record->event.pressed)
                SEND_STRING("öäü");
            return true;
        case KC_MINE4:
            if(record->event.pressed)
                SEND_STRING("ß?");
            return true;
        default:
            return true;
    }
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]                          PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "        #        Enter             PgDn
//      Sh_L     /        Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backspace. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.

   [BONE_L1] = LAYOUT(
        //┌───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┐      ┌───────────────┐
            KC_ESC            , KC_F1         , KC_F2         , KC_F3         , KC_F4             , KC_F5         , KC_F6         , KC_F7         , KC_F8             , KC_F9         , KC_F10        , KC_F11        , KC_F12            , TO(QWERTZ)           , KC_MUTE       ,
        //├───────────────┼───┴───────────┬───┴───────────┬───┴───────────┬───┴───────────┬───┴───┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬───────┴───┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┴───────────────┤      ├───────────────┤
            BONE_CIRC     , BONE_1        , BONE_2        , BONE_3        , BONE_4        , BONE_5        , BONE_6        , BONE_7        , BONE_8        , BONE_9        , BONE_0        , BONE_MINUS    , BONE_DQUOTE   , KC_BSPC                              , KC_INS        ,
        //├───────────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────────────────────┤      ├───────────────┤
            KC_TAB               , BONE_j        , BONE_d        , BONE_u        , BONE_a        , BONE_x        , BONE_p        , BONE_h        , BONE_l        , BONE_m        , BONE_w        , BONE_sz       , BONE_SQUOTE                                   , KC_DEL        ,
        //├──────────────────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┐                    |      ├───────────────┤
            MO(BONE_L3)              , BONE_c        , BONE_t        , BONE_i        , BONE_e        , BONE_o        , BONE_b        , BONE_n        , BONE_r        , BONE_s        , BONE_g        , BONE_q        , MO(BONE_L3)   , KC_ENT                    , KC_PSCR       ,
        //├───────────────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴───────────────┬──────┬─────────────┴─┐    ├───────────────┤
            MO(BONE_L2)       , MO(BONE_L4)   , BONE_f        , BONE_v        , BONE_ue       , BONE_ae       , BONE_oe       , BONE_y        , BONE_z        , BONE_COMMA    , BONE_DOT      , BONE_k        , MO(BONE_L2)                 , KC_UP              , MO(FN)        ,
        //├───────────────────┼───────────────┴───┬───────────┴───────┬───────┴───────────────┴───────────────┴───────────────┴───────────────┴───────────────┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬─────┬────────┴──────┼───────────────┼────┴──────────┬────┘
            KC_LCTL           , KC_LGUI           , KC_LALT           ,                                            KC_SPACE                                           , KC_RALT       , KC_RGUI       , KC_RCTL             , KC_LEFT       , KC_DOWN       , KC_RGHT
        //└───────────────────┴───────────────────┴───────────────────┴───────────────────────────────────────────────────────────────────────────────────────────────┴───────────────┴───────────────┴───────────────┘     └───────────────┴───────────────┴───────────────┘
    ),

    [BONE_L2] = LAYOUT(
        //┌───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┐      ┌───────────────┐
            _______           , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______           , XXXXXXX              , KC_MUTE       ,
        //├───────────────┼───┴───────────┬───┴───────────┬───┴───────────┬───┴───────────┬───┴───┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬───────┴───┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┴───────────────┤      ├───────────────┤
            BONE_DEGR     , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , BONE_UNDER    , XXXXXXX       , _______                              , _______       ,
        //├───────────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────────────────────┤      ├───────────────┤
            _______              , BONE_J        , BONE_D        , BONE_U        , BONE_A        , BONE_X        , BONE_P        , BONE_H        , BONE_L        , BONE_M        , BONE_W        , BONE_sz       , XXXXXXX                                       , _______       ,
        //├──────────────────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┐                    |      ├───────────────┤
            XXXXXXX                  , BONE_C        , BONE_T        , BONE_I        , BONE_E        , BONE_O        , BONE_B        , BONE_N        , BONE_R        , BONE_S        , BONE_G        , BONE_Q        , XXXXXXX       , LSFT(KC_ENT)              , _______       ,
        //├───────────────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴───────────────┬──────┬─────────────┴─┐    ├───────────────┤
            _______           , XXXXXXX       , BONE_F        , BONE_V        , BONE_UE       , BONE_AE       , BONE_OE       , BONE_Y        , BONE_Z        , XXXXXXX       , XXXXXXX       , BONE_K        , _______                     , _______            , _______       ,
        //├───────────────────┼───────────────┴───┬───────────┴───────┬───────┴───────────────┴───────────────┴───────────────┴───────────────┴───────────────┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬─────┬────────┴──────┼───────────────┼────┴──────────┬────┘
            _______           , _______           , _______           ,                                            _______                                            , XXXXXXX       , _______       , _______             , _______       , _______       , _______
        //└───────────────────┴───────────────────┴───────────────────┴───────────────────────────────────────────────────────────────────────────────────────────────┴───────────────┴───────────────┴───────────────┘     └───────────────┴───────────────┴───────────────┘
    ),

    [BONE_L3] = LAYOUT(
        //┌───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┐      ┌───────────────┐
            _______           , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______           , _______              , KC_MUTE       ,
        //├───────────────┼───┴───────────┬───┴───────────┬───┴───────────┬───┴───────────┬───┴───┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬───────┴───┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┴───────────────┤      ├───────────────┤
            XXXXXXX       , BONE_PARA     , BONE_DOLLAR   , BONE_EURO     , BONE_POUND    , BONE_YEN      , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______                              , _______       ,
        //├───────────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────────────────────┤      ├───────────────┤
            _______              , BONE_THREEDOT , BONE_UNDER    , BONE_SQBRO    , BONE_SQBRC    , BONE_CIRC     , BONE_EXCL    , BONE_LT        , BONE_GT       , BONE_EQ       , BONE_AND      , XXXXXXX       , XXXXXXX                                       , _______       ,
        //├──────────────────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┐                    |      ├───────────────┤
            _______                  , BONE_BACKSL   , BONE_SLASH    , BONE_CUBRO    , BONE_CUBRC    , BONE_ASTRSK   , BONE_QM       , BONE_BRO      , BONE_BRC      , BONE_MINUS    , BONE_DBDOT    , BONE_AT       , _______       , _______                   , _______       ,
        //├───────────────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴───────────────┬──────┬─────────────┴─┐    ├───────────────┤
            XXXXXXX           , XXXXXXX       , BONE_HASH     , XXXXXXX       , BONE_OR       , BONE_TILDE    , XXXXXXX       , BONE_PLUS     , BONE_PERC     , BONE_AIGU     , BONE_GRAVE    , BONE_SEMIC    , XXXXXXX                     , _______            , _______       ,
        //├───────────────────┼───────────────┴───┬───────────┴───────┬───────┴───────────────┴───────────────┴───────────────┴───────────────┴───────────────┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬─────┬────────┴──────┼───────────────┼────┴──────────┬────┘
            _______           , _______           , _______           ,                                            _______                                            , XXXXXXX       , _______       , _______             , _______       , _______       , _______
        //└───────────────────┴───────────────────┴───────────────────┴───────────────────────────────────────────────────────────────────────────────────────────────┴───────────────┴───────────────┴───────────────┘     └───────────────┴───────────────┴───────────────┘
    ),

    [BONE_L4] = LAYOUT(
        //┌───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┐      ┌───────────────┐
            _______           , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______           , _______       , _______       , _______       , _______           , _______              , KC_MUTE       ,
        //├───────────────┼───┴───────────┬───┴───────────┬───┴───────────┬───┴───────────┬───┴───┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬───────┴───┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┴───────────────┤      ├───────────────┤
            XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______                              , _______       ,
        //├───────────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────────────────────┤      ├───────────────┤
            _______              , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , KC_LAMBDA     , KC_MINE2      , KC_MINE3      , KC_MINE4      , XXXXXXX                                       , _______       ,
        //├──────────────────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┐                    |      ├───────────────┤
            XXXXXXX                  , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX                   , _______       ,
        //├───────────────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴───────────────┬──────┬─────────────┴─┐    ├───────────────┤
            XXXXXXX           , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX                     , _______            , _______       ,
        //├───────────────────┼───────────────┴───┬───────────┴───────┬───────┴───────────────┴───────────────┴───────────────┴───────────────┴───────────────┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬─────┬────────┴──────┼───────────────┼────┴──────────┬────┘
            _______           , _______           , _______           ,                                            _______                                            , _______       , _______       , _______             , _______       , _______       , _______
        //└───────────────────┴───────────────────┴───────────────────┴───────────────────────────────────────────────────────────────────────────────────────────────┴───────────────┴───────────────┴───────────────┘     └───────────────┴───────────────┴───────────────┘
    ),

    
    [QWERTZ] = LAYOUT(
        //┌───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┐      ┌───────────────┐
            KC_ESC            , KC_F1         , KC_F2         , KC_F3         , KC_F4             , KC_F5         , KC_F6         , KC_F7         , KC_F8             , KC_F9         , KC_F10        , KC_F11        , KC_F12            , TO(BONE_L1)          , KC_MUTE       ,
        //├───────────────┼───┴───────────┬───┴───────────┬───┴───────────┬───┴───────────┬───┴───┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬───────┴───┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┴───────────────┤      ├───────────────┤
            KC_GRV        , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_MINS       , KC_EQL        , KC_BSPC                              , KC_INS        ,
        //├───────────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────────────────────┤      ├───────────────┤
            KC_TAB               , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_LBRC       , KC_RBRC                                       , KC_DEL        ,
        //├──────────────────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┐                    |      ├───────────────┤
            KC_CAPS                  , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCLN       , KC_QUOT       , KC_NUHS       , KC_ENT                    , KC_PSCR       ,
        //├───────────────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴───────────────┬──────┬─────────────┴─┐    ├───────────────┤
            KC_LSFT           , KC_NUBS       , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          , KC_N          , KC_M          , KC_COMM       , KC_DOT        , KC_SLSH       , KC_RSFT                     , KC_UP              , MO(FN)        ,
        //├───────────────────┼───────────────┴───┬───────────┴───────┬───────┴───────────────┴───────────────┴───────────────┴───────────────┴───────────────┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬─────┬────────┴──────┼───────────────┼────┴──────────┬────┘
            KC_LCTL           , KC_LGUI           , KC_LALT           ,                                            KC_SPC                                             , KC_RALT       , KC_RGUI       , KC_RCTL             , KC_LEFT       , KC_DOWN       , KC_RGHT
        //└───────────────────┴───────────────────┴───────────────────┴───────────────────────────────────────────────────────────────────────────────────────────────┴───────────────┴───────────────┴───────────────┘     └───────────────┴───────────────┴───────────────┘
    ),

    [FN] = LAYOUT(
        //┌───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┬───────────────┬───────────────┬───────────────┐   ┌───────────────┐      ┌───────────────┐
            XXXXXXX           , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX              , KC_MUTE       ,
        //├───────────────┼───┴───────────┬───┴───────────┬───┴───────────┬───┴───────────┬───┴───┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬───────┴───┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┴───────────────┤      ├───────────────┤
            XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , QK_BOOT                              , XXXXXXX       ,
        //├───────────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────┴──────┬────────────────────────┤      ├───────────────┤
            XXXXXXX              , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX                                       , XXXXXXX       ,
        //├──────────────────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┬───────────┴───┐                    |      ├───────────────┤
            XXXXXXX                  , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX                   , XXXXXXX       ,
        //├───────────────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴────────┬──────┴───────────────┬──────┬─────────────┴─┐    ├───────────────┤
            XXXXXXX           , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX                     , XXXXXXX            , XXXXXXX       ,
        //├───────────────────┼───────────────┴───┬───────────┴───────┬───────┴───────────────┴───────────────┴───────────────┴───────────────┴───────────────┴───────┬───────┴───────┬───────┴───────┬───────┴───────┬─────┬────────┴──────┼───────────────┼────┴──────────┬────┘
            XXXXXXX           , XXXXXXX           , XXXXXXX           ,                                            XXXXXXX                                            , XXXXXXX       , XXXXXXX       , XXXXXXX             , XXXXXXX       , XXXXXXX      , XXXXXXX
        //└───────────────────┴───────────────────┴───────────────────┴───────────────────────────────────────────────────────────────────────────────────────────────┴───────────────┴───────────────┴───────────────┘     └───────────────┴───────────────┴───────────────┘
    )
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [2] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [4] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [5] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif


#include QMK_KEYBOARD_H

#undef UNICODE_SELECTED_MODES
#define UNICODE_SELECTED_MODES UC_MAC, UC_LNX, UC_WIN, UC_WINC

extern keymap_config_t keymap_config;

#define _QWERTY 0

#define _BONE 1
#define _BONE_SHIFT 2
#define _BONE_SYM 3
#define _BONE_NAV 4
#define _BONE_GREEK 5
#define _BONE_MATH 6

#define _ADJUST 7

#define KC_BKSL KC_BSLASH

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

enum my_keycodes {
  KC_BNCP = SAFE_RANGE,
  KC_BNM4,
  KC_EN_UC_WIN
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_RSFT:
        layer_invert(_BONE_SHIFT);
        update_tri_layer(_BONE_SYM, _BONE_SHIFT, _BONE_GREEK);
        return true;
    case KC_BNCP:
        layer_invert(_BONE_SYM);
        update_tri_layer(_BONE_SYM, _BONE_SHIFT, _BONE_GREEK);
        update_tri_layer(_BONE_NAV, _BONE_SYM, _BONE_MATH);
        return false; 
    case KC_BNM4:
        layer_invert(_BONE_NAV);
        update_tri_layer(_BONE_NAV, _BONE_SYM, _BONE_MATH);
        return false; 
    case KC_EN_UC_WIN:
        if(record->event.pressed)
            SEND_STRING("reg add \"HKCU\\Control Panel\\Input Method\" -v EnableHexNumpad -t REG_SZ -d 1");
        return false;
    default:
         return true;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_INS   ,                         DF(_BONE),KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_EQL  ,                          KC_RBRC ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_ADPU ,KC_PGDN ,        KC_HOME ,KC_ADEN ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_LSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      KC_LCTL,KC_HYPR ,KC_LGUI ,KC_LALT ,     KC_ESC  ,   KC_SPC   , KC_ENT ,        KC_BSPC, KC_LSFT ,    KC_RALT ,     KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_F11  ,KC_F12  ,KC_F13  ,KC_F14  ,KC_F15  ,XXXXXXX ,                          XXXXXXX ,KC_F16  ,KC_F17  ,KC_F18  ,KC_F19  ,KC_F20  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,UC_M_LN ,UC_M_MA ,UC_M_WI ,UC_M_WC ,XXXXXXX ,XXXXXXX ,                       XXXXXXX,KC_EN_UC_WIN,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,UC_MOD  ,UC_RMOD ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_BONE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_1     ,KC_2   ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_J    ,KC_D    ,KC_U    ,KC_A    ,KC_X    , XXXXXXX,                       DF(_QWERTY), KC_P   ,KC_H    ,KC_L    , KC_M   ,KC_W    ,UC(L'ß'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BNCP , KC_C   ,KC_T    , KC_I   , KC_E   , KC_O   , XXXXXXX,                           XXXXXXX, KC_B   , KC_N   , KC_R   , KC_S   , KC_G   , KC_Q, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_RSFT , KC_F   , KC_V   ,UC(L'ü'),UC(L'ä'),UC(L'ö'), KC_ADPU, KC_PGDN,        KC_HOME , KC_ADEN, KC_Y   , KC_Z   , KC_COMM, KC_DOT , KC_K   , KC_RSFT, 
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      KC_LCTL,KC_HYPR ,KC_LGUI ,KC_LALT,        KC_ESC,     KC_SPC , KC_ENT ,         KC_BSPC, KC_RSFT,     KC_BNM4,      KC_LEFT,KC_DOWN , KC_UP  , KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_BONE_SHIFT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,UC(L'°'),UC(L'§'),UC(L'ℓ'),UC(L'»'),UC(L'«'),                                            KC_DLR  ,UC(L'€'),UC(L'„'),UC(L'“'),UC(L'”'),UC(L'—'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,UC(L'ẞ'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,UC(L'Ü'),UC(L'Ä'),UC(L'Ö'),_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_BONE_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5,                                                 KC_F6, KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, XXXXXXX, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, _______,                           _______, KC_EXLM, KC_LT  , KC_GT  , KC_EQL , KC_AMPR, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_ASTR, _______,                           _______, KC_QUES, KC_LPRN, KC_RPRN, KC_MINS, KC_COLN, KC_AT, 
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_RSFT,KC_HASH , KC_DLR , KC_PIPE, KC_TILD, KC_GRV , _______, _______,         _______, _______, KC_PLUS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, XXXXXXX, 
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______,     _______,      _______, _______,         _______, _______,      _______,     _______, _______, _______, _______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_BONE_NAV] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       _______, _______, _______, _______, _______, _______,                                             _______, _______, _______, _______, _______, _______, 
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_PGUP, KC_BSPC, KC_UP  , KC_DEL , KC_PGDN, XXXXXXX,                           XXXXXXX, XXXXXXX, KC_P7  , KC_P8  , KC_P9  , KC_PPLS, KC_PMNS, 
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END , XXXXXXX,                           XXXXXXX, XXXXXXX, KC_P4  , KC_P5  , KC_P6  , KC_PDOT, KC_COMM, 
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       _______, KC_ESC , KC_TAB , KC_INS , KC_ENT , KC_UNDO, _______, _______,         _______, _______, KC_COLN, KC_P1  , KC_P2  , KC_P3  , KC_SCLN, _______, 
   //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______ 
   //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_BONE_GREEK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,UC(L'₁'),UC(L'₂'),UC(L'₃'),UC(L'♀'),UC(L'♂'),                                            UC(L'⚥'),UC(L'ϰ'),UC(L'⟨'),UC(L'⟩'),UC(L'₀'),UC(L'‑'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,UC(L'θ'),UC(L'δ'),UC(L'λ'),UC(L'α'),UC(L'ξ'), XXXXXXX,                           XXXXXXX,UC(L'π'),UC(L'ψ'),UC(L'λ'),UC(L'μ'),UC(L'ω'),UC(L'ς'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______,UC(L'χ'),UC(L'τ'),UC(L'ι'),UC(L'ε'),UC(L'ο'), XXXXXXX,                           XXXXXXX,UC(L'β'),UC(L'ν'),UC(L'ρ'),UC(L'σ'),UC(L'γ'),UC(L'ϕ'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______,UC(L'φ'),UC(L'ϵ'),UC(L'η'),XXXXXXX , XXXXXXX, _______, _______,        _______ , _______,UC(L'υ'),UC(L'ζ'),UC(L'ϱ'),UC(L'ϑ'),UC(L'κ'), _______, 
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______,     _______,      _______, _______,         _______, _______,      _______,     _______, _______, _______, _______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
   [_BONE_MATH] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,UC(L'¬'),UC(L'∨'),UC(L'∧'),UC(L'⊥'),UC(L'∡'),                                            UC(L'∥'),UC(L'→'),UC(L'∞'),UC(L'∝'),UC(L'∅'), XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,UC(L'Θ'),UC(L'Δ'),UC(L'⊂'),UC(L'∀'),UC(L'Ξ'), XXXXXXX,                           XXXXXXX,UC(L'Π'),UC(L'Ψ'),UC(L'Λ'),UC(L'⇔'),UC(L'Ω'),UC(L'∘'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______,UC(L'ℂ'),UC(L'∂'),UC(L'∫'),UC(L'∃'),UC(L'∈'), XXXXXXX,                           XXXXXXX,UC(L'⇐'),UC(L'ℕ'),UC(L'ℝ'),UC(L'Σ'),UC(L'Γ'),UC(L'ℚ'),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______,UC(L'Φ'),UC(L'√'),UC(L'∪'),XXXXXXX , XXXXXXX, _______, _______,        _______ , _______,UC(L'∇'),UC(L'ℤ'),UC(L'⇒'),UC(L'↦'),UC(L'×'), _______, 
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______,     _______,      _______, _______,         _______, _______,      _______,     _______, _______, _______, _______
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )
};

/* vim: set et ts=2: */
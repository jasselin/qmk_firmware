#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _ACCENTS = 1,
  _FN = 2,
  _SYMWM = 3,
  _MEDIA = 4,
};

enum custom_keycodes {
    ACC_AGRV = SAFE_RANGE,
    ACC_ACRC,
    ACC_EGRV,
    ACC_ECRC,
    ACC_CCED,
    ACC_UCRC,
    ACC_UGRV,
    ACC_UTRM,
    ACC_ICRC,
    ACC_ITRM,
    ACC_OCRC,
    ACC_OTRM
};

#define CW_LEFT LGUI(LCTL(KC_LEFT))
#define CW_RIGHT LGUI(LCTL(KC_RIGHT))
#define CS_M LCTL(LSFT(KC_M))
#define SH_ESC MT(MOD_LSFT, KC_ESC)
#define CTL_ESC MT(MOD_LCTL, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,       KC_8,    KC_9,    KC_0,    KC_BSPC, 
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,       KC_I,    KC_O,    KC_P,    KC_BSLS,
    CTL_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN, OSL(_ACCENTS),
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, CS_M,               KC_HOME, KC_N,    KC_M,       KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
                       KC_LGUI, KC_LALT, MO(_FN), LT(_MEDIA,KC_ENT),                 KC_SPC,  MO(_SYMWM), KC_NO,   KC_RGUI
    ),
    [_ACCENTS] = LAYOUT(
        KC_NO, KC_NO,    KC_NO, ACC_ECRC, KC_NO, KC_NO,                      KC_NO, ACC_UCRC, KC_NO,    KC_NO,    KC_NO, KC_NO,
        KC_NO, ACC_ACRC, KC_NO, ACC_EGRV, KC_NO, KC_NO,                      KC_NO, ACC_UGRV, ACC_ICRC, ACC_OCRC, KC_NO, KC_NO,
        KC_NO, ACC_AGRV, KC_NO, KC_NO,    KC_NO, KC_NO,                      KC_NO, ACC_UTRM, ACC_ITRM, ACC_OTRM, KC_NO, TO(_QWERTY),
        KC_NO, KC_NO,    KC_NO, ACC_CCED, KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, 
                         KC_NO, KC_NO,    KC_NO, KC_NO,                      KC_NO, KC_NO,    KC_NO,    KC_NO
    ),
    [_FN] = LAYOUT(
        LALT(KC_F4), KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                                                    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_PSCR, 
        KC_NO,       KC_NO,         LCTL(KC_F4),   LGUI(KC_UP),   LCTL(KC_F5),   KC_NO,                                    KC_NO,   KC_F10,  KC_F11,  KC_F12,  KC_NO,  KC_PAUS, 
        KC_NO,       SGUI(KC_LEFT), LGUI(KC_LEFT), LGUI(KC_DOWN), LGUI(KC_RGHT), SGUI(KC_RGHT),                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,  KC_NO,
        KC_NO,       KC_NO,         CW_LEFT,       LGUI(KC_TAB),  CW_RIGHT,      KC_NO,     KC_NO,                 KC_END, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, 
                                    KC_NO,         KC_NO,         KC_TRNS,       KC_NO,                                             KC_DEL,  KC_WBAK, KC_WFWD, KC_NO
    ),
    [_SYMWM] = LAYOUT(
        LALT(KC_GRV), KC_NO,      LALT(KC_2), KC_NO,      KC_NO,      KC_NO,                        KC_NO, KC_NO,      KC_MINS, KC_EQL, KC_NO, KC_NO, 
        HYPR(KC_GRV), HYPR(KC_Q), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T),                   KC_NO, KC_NO,      KC_NO,   KC_NO,  KC_NO, KC_NO, 
        KC_NO,        HYPR(KC_A), HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G),                   KC_NO, KC_NO,      KC_NO,   KC_NO,  KC_NO, KC_NO, 
        KC_NO,        HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), KC_NO,     KC_NO, KC_NO, HYPR(KC_M), KC_NO,   KC_NO,  KC_NO, KC_NO, 
                                KC_NO,        KC_NO,      KC_NO,      KC_NO,                        KC_NO, KC_TRNS,    KC_NO,   KC_NO
    ),
    [_MEDIA] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLU,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_VOLD,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
                            KC_NO,   KC_NO,   KC_NO,   KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO
    )
};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    #ifdef OLED_ENABLE
        set_keylog(keycode, record);
    #endif
    //bool shiftPressed = (keyboard_report->mods & MOD_BIT (KC_LSFT)) || (keyboard_report->mods & MOD_BIT (KC_RSFT));
    // set_timelog();
    switch (keycode) {
        case ACC_AGRV:
            SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_A));
        break;
        case ACC_ACRC:
            SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_A));
        break;
        case ACC_EGRV:
            SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_E));
        break;
        case ACC_ECRC:
            SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_E));
        break;
        case ACC_CCED:
            /*if (shiftPressed) {
                SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_C));
            }
            else {*/
                SEND_STRING(SS_TAP(X_RBRACKET) SS_DELAY(100) SS_TAP(X_C));
            //}
        break;
        case ACC_UCRC:
            SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_U));
        break;
        case ACC_UGRV:
            SEND_STRING(SS_TAP(X_QUOTE) SS_DELAY(100) SS_TAP(X_U));
        break;
        case ACC_UTRM:
            SEND_STRING(SS_RSFT(SS_TAP(X_RBRACKET)) SS_DELAY(100) SS_TAP(X_U));
        break;
        case ACC_ICRC:
            SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_I));
        break;
        case ACC_ITRM:
            SEND_STRING(SS_RSFT(SS_TAP(X_RBRACKET)) SS_DELAY(100) SS_TAP(X_I));
        break;
        case ACC_OCRC:
            SEND_STRING(SS_TAP(X_LBRACKET) SS_DELAY(100) SS_TAP(X_O));
        break;
        case ACC_OTRM:
            SEND_STRING(SS_RSFT(SS_TAP(X_RBRACKET)) SS_DELAY(100) SS_TAP(X_O));
        break;
    }
  }
  return true;
}
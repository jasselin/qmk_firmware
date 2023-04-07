#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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

#define CW_LF     LGUI(LCTL(KC_LEFT))
#define CW_RG     LGUI(LCTL(KC_RIGHT))
#define CS_M      LCTL(LSFT(KC_M))
#define CS_O      LCTL(LSFT(KC_O))
#define SH_ESC    MT(MOD_LSFT, KC_ESC)
#define CTL_ESC   MT(MOD_LCTL, KC_ESC)
#define SH_HOME   MT(MOD_LSFT, KC_HOME)
#define SCR_LF    SGUI(KC_LEFT)
#define SCR_RG    SGUI(KC_RIGHT)
#define WND_UP    LGUI(KC_UP)
#define WND_DW    LGUI(KC_DOWN)
#define WND_LF    LGUI(KC_LEFT)
#define WND_RG    LGUI(KC_RIGHT)
#define WND_DSK   LGUI(KC_TAB)
#define SPC_MED   LT(_MEDIA, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_8    ,KC_9    ,KC_0    ,KC_MINS, KC_EQL  ,KC_BSPC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,KC_6    ,                          KC_7    ,KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,KC_NO   ,                          KC_NO   ,KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,OSL(_ACCENTS),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,CS_M    ,KC_DEL  ,        KC_DEL  ,CS_O    ,KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     KC_LCTL ,KC_LGUI ,KC_NO   ,KC_LALT ,     MO(_FN) ,    SPC_MED ,KC_ENT  ,        KC_ENT  ,KC_SPC  ,    MO(_SYMWM),  KC_NO    ,KC_NO   ,KC_RGUI ,KC_NO 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_ACCENTS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RESET   ,XXXXXXX ,XXXXXXX ,ACC_ECRC,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,ACC_UCRC ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,ACC_ACRC,XXXXXXX ,ACC_EGRV,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,ACC_UGRV,ACC_ICRC,ACC_OCRC,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,ACC_AGRV,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,ACC_UTRM,ACC_ITRM,ACC_OTRM,XXXXXXX ,TO(_QWERTY) ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,ACC_CCED ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_FN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LALT(KC_F4),KC_F1,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_PSCR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,LCTL(KC_F4),WND_UP ,LCTL(KC_F5),XXXXXXX ,KC_F6   ,                          KC_F7 ,KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,XXXXXXX ,KC_PAUS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,SCR_LF  ,WND_LF  ,WND_DW  ,WND_RG  ,SCR_RG  ,XXXXXXX ,                          XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,CW_LF   ,WND_DSK  ,CW_RG  ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    KC_WBAK ,     KC_WFWD ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
  [_SYMWM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     LALT(KC_F4) ,XXXXXXX ,RALT(KC_2) ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                     XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     HYPR(KC_GRV) ,HYPR(KC_Q) ,HYPR(KC_W) ,HYPR(KC_E) ,HYPR(KC_R) ,HYPR(KC_T) ,XXXXXXX ,      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,HYPR(KC_A) ,HYPR(KC_S) ,HYPR(KC_D) ,HYPR(KC_F) ,HYPR(KC_G) ,XXXXXXX ,           XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,HYPR(KC_Z) ,HYPR(KC_X) ,HYPR(KC_C) ,HYPR(KC_V) ,HYPR(KC_B) ,_______, XXXXXXX ,XXXXXXX ,_______ , XXXXXXX ,HYPR(KC_M) ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
   [_MEDIA] = LAYOUT(
   //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MUTE ,                                            XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_VOLU ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_VOLD ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_MPRV ,KC_MNXT ,KC_MPLY ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
   //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
   //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
   )
//   [_EMPTY] = LAYOUT(
//   //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                          XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX  ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,        XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//   //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//      XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,     XXXXXXX ,    XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX 
//   //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
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
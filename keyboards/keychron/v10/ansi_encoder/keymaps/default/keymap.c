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

#include "quantum/keymap_extras/keymap_canadian_multilingual.h"

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    WIN_WMSYM
};

#define CM_EXIT  LALT(KC_F4)
#define CM_QUIT  LCTL(KC_F4)

#define WM_SSMS  HYPR(KC_Q)
#define WM_TEAMS HYPR(KC_T)
#define WM_ANTI  HYPR(KC_A)
#define WM_EXCL  HYPR(KC_X)
#define WM_WORD  HYPR(KC_W)
#define WM_RDP   HYPR(KC_R)
#define WM_OUTL  HYPR(KC_E)
#define WM_SPOT  HYPR(KC_S)
#define WM_FORK  HYPR(KC_F)
#define WM_SHRT  HYPR(KC_Z)
#define WM_VS    HYPR(KC_V)
#define WM_VSC   HYPR(KC_C)
#define WM_CHRM  HYPR(KC_B)
#define WM_EDGE  HYPR(KC_G)
#define WM_MIN   HYPR(KC_M)
#define WM_TODO  HYPR(KC_D)

#define SM_BSLH RALT(KC_GRV)
#define SM_AT   RALT(KC_2)

#define SM_LBRC ALGR(KC_LBRC)
#define SM_RBRC ALGR(KC_RBRC)
#define SM_LCBR ALGR(KC_QUOTE)
#define SM_RCBR ALGR(KC_BACKSLASH)

#define WN_SCRL LGUI(LSFT(KC_LEFT))
#define WN_SCRR LGUI(LSFT(KC_RIGHT))
#define WN_WNDL LGUI(KC_LEFT)
#define WN_WNDR LGUI(KC_RIGHT)
#define WN_WNDU LGUI(KC_UP)
#define WN_WNDD LGUI(KC_DOWN)

#define MC_TMUT LCTL(LSFT(KC_M))
#define MC_RUN LCTL(KC_F5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_PSCR,            KC_PAUS,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,            KC_LCMD,  KC_SPC,  MO(MAC_FN),                     KC_SPC,             KC_RCMD,                      KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_89(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                      _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_89(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_PSCR,            KC_PAUS,
        MC_TMUT,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_DEL,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_HOME,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_END,
        _______,  KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),                     KC_SPC,             MO(WIN_WMSYM),                KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  CM_EXIT,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  _______,  CM_QUIT,  WN_WNDU,  MC_RUN,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  WN_SCRL,  WN_WNDL,  WN_WNDD,  WN_WNDR,  WN_SCRR,   KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT,  _______,  _______,             _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                       _______,  _______,  _______),

    [WIN_WMSYM] = LAYOUT_ansi_89(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  SM_BSLH,  _______,  SM_AT,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,            _______,
        _______,  _______,  WM_SSMS,  WM_WORD,  WM_OUTL,  WM_RDP,   WM_TEAMS,  _______,  _______,  _______,  _______,  _______,  SM_LBRC,  SM_RBRC,   _______,            _______,
        _______,  _______,  WM_ANTI,  WM_SPOT,  WM_TODO,  WM_FORK,  WM_EDGE,   _______,  _______,  _______,  _______,  SM_LCBR,  SM_RCBR,             _______,            _______,
        _______,  _______,            WM_SHRT,  WM_EXCL,  WM_VSC,   WM_VS,     WM_CHRM,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  
        QK_BOOTLOADER,  _______,  _______,            _______,  _______,  _______,                       _______,            _______,                 _______,  _______,  _______),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][1][2] = {
    [MAC_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]    = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_WMSYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif // ENCODER_MAP_ENABLE

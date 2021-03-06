/* Copyright 2020 globalista-dev
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

enum layer_names {
    _QWERTY,
    _RAISE,
	_LOWER,
};

#define LOWER OSL(_LOWER)
#define RAISE TT(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
	/* QWERTY
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * | ESC    | 1      | 2      | 3      | 4      | 5      | 6      | 7      | 8      | 9      | 0      | -      | =      | BACKSP |  PGUP  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
     * | TAB    | Q      | W      | E      | R      | T      | Y      | U      | I      | O      | P      | ´      | [      | \      |  PGDN  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
     * | CAP LK | A      | S      | D      | F      | G      | H      | J      | K      | L      | Ç      | ~      | ]      | ENTER  |  HOME  |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
     * | LSHIFT | Z      | X      | C      | V      | B      | N      | M      | ,      | .      | ;      | /      | UP     | RSHIFT |  END   |
     * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
     * | LCTRL  | WIN    | LALT   | LOWER  |      SPACE      |      SPACE      | RAISE  | PRINT  |  DEL   | LEFT   | DOWN   | RIGHT  |  INS   |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_QWERT] = LAYOUT_globalista_75( /* QWERTY */
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUBS, KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_ENT,  KC_HOME,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_COMM, KC_RO,   KC_RSFT, KC_END,
        KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_NO,   KC_NO,   KC_SPC,  RAISE,   KC_PSCR, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_INS
    ),

    /* RAISE
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        |        |        |        |        |        |        |        |        |        |        |    -   |    =   |  BKSPC |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |   /    |   ?    |        |        |        |        |        |        |        |   7    |    8   |    9   |    /   |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |   4    |    5   |    6   | ENTER  |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * |        |        |        |        |        |        |        |        |        |        |   1    |    2   |    3   |   *    |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | RESET  |        |        |  RALT  |        |        |        |        |        |        |   0    |    .   |    ,   |   +    |        |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_globalista_75( /* RAISE */
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_BSPC, _______,
        _______, KC_RO,   S(KC_RO), _______, _______, _______, _______, _______, _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PENT, _______,
        _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PAST, _______,
        RESET,   _______, _______,  KC_RALT, _______, _______, _______, _______, _______, _______, KC_P0,   KC_PDOT, KC_PCMM, KC_PPLS, _______
    ),

    /* LOWER
     * .--------------------------------------------------------------------------------------------------------------------------------------.
     * |        | F1     | F2     | F3     | F4     | F5     | F6     | F7     | F8     | F9     |  F10   |  F11   |  F12   |        |        |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | STOP   |        |        |        |        |        |        |        |        |        |        |        | HUE -  | HUE -  | RGB TG |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL+   |        |        |        |        |        |        |        |        |        |        |        | SAT -  | SAT -  | RGB MD |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | VOL-   |        |        |        |        |        |        |        |        |        |        |        | BRT -  | BRT -  | RGB MI |
     * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
     * | MUTE   |        |        |        |      PAUSE      |      SPACE      |        |        |        |        | EFF -  | EFF -  | BL TG  |
     * '--------------------------------------------------------------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_globalista_75( /* LOWER */
		_______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______,
        KC_MSTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI, RGB_TOG,
        KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, RGB_MOD,
        KC_VOLD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_RMOD,
        KC_MUTE, _______, _______, _______, KC_MPLY, _______, _______, _______, _______, _______, _______, _______, RGB_SPD, RGB_SPI, BL_TOGG
    )
};
